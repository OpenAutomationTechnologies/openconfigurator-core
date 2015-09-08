/************************************************************************
\file CProcessImageGenerator.cpp
\brief Implementation of the Class CProcessImageGenerator
\author rueckerc, Bernecker+Rainer Industrie Elektronik Ges.m.b.H.
\date 01-May-2015 12:00:00
************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2015, Bernecker+Rainer Industrie-Elektronik Ges.m.b.H. (B&R)
All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the copyright holders nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
------------------------------------------------------------------------------*/
#include "CProcessImageGenerator.h"

using namespace IndustrialNetwork::POWERLINK::Core::ObjectDictionary;
using namespace IndustrialNetwork::POWERLINK::Core::Node;
using namespace IndustrialNetwork::POWERLINK::Core::NetworkHandling;
using namespace IndustrialNetwork::POWERLINK::Core::ErrorHandling;
using namespace IndustrialNetwork::POWERLINK::Core::Utilities;

CProcessImageGenerator::CProcessImageGenerator() : ProcessImageGenerator(),
	processImageStream()
{}

CProcessImageGenerator::~CProcessImageGenerator()
{}

CProcessImageGenerator& CProcessImageGenerator::GetInstance()
{
	static CProcessImageGenerator instance;
	return instance;
}

const std::string CProcessImageGenerator::Generate(std::uint8_t nodeid, std::shared_ptr<Network> network)
{
	//clear PI stream
	this->processImageStream.str(std::string());

	std::shared_ptr<BaseNode> node;
	network->GetBaseNode(nodeid, node);

	this->WriteCHeader(node);

	this->WriteCProcessImage(Direction::RX, node);
	this->WriteCProcessImage(Direction::TX, node);

	this->processImageStream << "#endif" << std::endl;
	return this->processImageStream.str();
}

const std::string CProcessImageGenerator::PrintChannel(const std::string& name, const IEC_Datatype, const std::uint32_t size, const std::uint32_t, const boost::optional<std::uint32_t>&)
{
	std::stringstream channel;
	channel << "\tunsigned " << name << ":";
	channel << std::dec << size;
	channel << ";" << std::endl;
	return channel.str();
}

void CProcessImageGenerator::WriteCHeader(const std::shared_ptr<BaseNode>& node)
{
	std::ostringstream dateTime;
	const boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();
	//No deletion needed : http://stackoverflow.com/questions/17779660/who-is-responsible-for-deleting-the-facet
	boost::posix_time::time_facet* const f = new boost::posix_time::time_facet("%d-%b-%Y %H:%M:%S");
	dateTime.imbue(std::locale(dateTime.getloc(), f));
	dateTime << now;

	this->processImageStream << "/*" << std::endl << "* This file was autogenerated by openCONFIGURATOR-";
	this->processImageStream << kVersionMajor << "." << kVersionMinor << "." << kVersionFix << " on " << dateTime.str() << std::endl;
	this->processImageStream << "* Application process for " << node->GetName() << "(";
	this->processImageStream << std::dec << (std::uint32_t) node->GetNodeId();
	this->processImageStream << ")" << std::endl << "*/" << std::endl;
	this->processImageStream << "#ifndef XAP_h" << std::endl;
	this->processImageStream << "#define XAP_h" << std::endl << std::endl;
}

void CProcessImageGenerator::WriteCOutputSizeHeader(const std::shared_ptr<BaseNode>& node)
{
	std::uint32_t totalSize = node->GetReceiveProcessImageSize();
	if (totalSize % 32 != 0)
		totalSize += (32 - (totalSize % 32));

	this->processImageStream << "# define COMPUTED_PI_OUT_SIZE " << totalSize / 8 << std::endl;
	this->processImageStream << "typedef struct" << std::endl;
	this->processImageStream << "{" << std::endl;
}

void CProcessImageGenerator::WriteCInputSizeHeader(const std::shared_ptr<BaseNode>& node)
{
	std::uint32_t totalSize = node->GetTransmitProcessImageSize();
	if (totalSize % 32 != 0)
		totalSize += (32 - (totalSize % 32));

	this->processImageStream << "# define COMPUTED_PI_IN_SIZE " << totalSize / 8 << std::endl;
	this->processImageStream << "typedef struct" << std::endl;
	this->processImageStream << "{" << std::endl;
}

void CProcessImageGenerator::WriteCProcessImage(const Direction dir, const std::shared_ptr<BaseNode>& node)
{
	std::vector<std::shared_ptr<BaseProcessImageObject>> processImage;
	std::uint16_t paddingCount = 1;
	std::uint32_t piSize = 0;

	if (dir == Direction::RX)
	{
		piSize = node->GetReceiveProcessImageSize();
		processImage = node->GetReceiveProcessImage();

	}
	else if (dir == Direction::TX)
	{
		piSize = node->GetTransmitProcessImageSize();
		processImage = node->GetTransmitProcessImage();
	}

	if (piSize != 0)
	{
		if (dir == Direction::RX)
			this->WriteCOutputSizeHeader(node);
		else if (dir == Direction::TX)
			this->WriteCInputSizeHeader(node);

		for (auto& piEntry : processImage)
		{
			this->processImageStream << PrintChannel(piEntry->GetName(), piEntry->GetDataType(), piEntry->GetSize(), piEntry->GetPiOffset(), piEntry->GetBitOffset());
		}
		if (piSize % 32 != 0)
		{
			std::uint32_t totalSize = piSize;
			while (totalSize % 32 != 0)
			{
				std::stringstream paddingVarName;
				paddingVarName << "PADDING_VAR_" << paddingCount;
				this->processImageStream << PrintChannel(paddingVarName.str(), IEC_Datatype::USINT, 8, 0, boost::optional<std::uint32_t>());
				paddingCount++;
				totalSize += 8;

			}
		}
		if (dir == Direction::RX)
			this->processImageStream << "} PI_OUT" << std::endl << std::endl;
		else if (dir == Direction::TX)
			this->processImageStream << "} PI_IN" << std::endl << std::endl;
	}
}
