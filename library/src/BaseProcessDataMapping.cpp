/************************************************************************
\file BaseProcessDataMapping.cpp
\brief Implementation of the Class BaseProcessDataMapping
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
#include "BaseProcessDataMapping.h"

using namespace IndustrialNetwork::POWERLINK::Core::ObjectDictionary;
using namespace IndustrialNetwork::POWERLINK::Core::Utilities;


BaseProcessDataMapping::BaseProcessDataMapping(std::uint32_t object, std::uint32_t subobject, const std::shared_ptr<BaseObject>& obj, std::uint32_t index, std::uint16_t subindex, std::uint16_t offset, std::uint16_t length, std::uint16_t nodeId, bool staticMapping) :
	object(object),
	subobject(subobject),
	relatedObject(obj),
	destinationNode(nodeId),
	index(index),
	subindex(subindex),
	offset(offset),
	length(length),
	staticMapping(staticMapping),
	active(true)
{}

BaseProcessDataMapping::BaseProcessDataMapping(std::uint32_t object, std::uint32_t subobject, const std::shared_ptr<BaseObject>& obj, std::uint64_t actualValue, std::uint16_t nodeId, bool staticMapping) :
	object(object),
	subobject(subobject),
	relatedObject(obj),
	destinationNode(nodeId),
	index(0),
	subindex(0),
	offset(0),
	length(0),
	staticMapping(staticMapping),
	active(true)
{
	InitMappingObject(actualValue);
}

BaseProcessDataMapping::BaseProcessDataMapping(std::uint32_t object, std::uint32_t subobject, const std::shared_ptr<BaseObject>& obj, const std::string& actualValue, std::uint16_t nodeId, bool staticMapping) :
	object(object),
	subobject(subobject),
	relatedObject(obj),
	destinationNode(nodeId),
	index(0),
	subindex(0),
	offset(0),
	length(0),
	staticMapping(staticMapping),
	active(true)
{
	InitMappingObject(actualValue);
}

BaseProcessDataMapping::BaseProcessDataMapping(const std::string& actualValue, std::uint16_t nodeId, bool staticMapping) :
	object(0),
	subobject(0),
	relatedObject(0),
	destinationNode(nodeId),
	index(0),
	subindex(0),
	offset(0),
	length(0),
	staticMapping(staticMapping),
	active(true)
{
	InitMappingObject(actualValue);
}

BaseProcessDataMapping::~BaseProcessDataMapping()
{}

void BaseProcessDataMapping::InitMappingObject(std::uint64_t actualValue)
{
	std::stringstream valueStr;
	valueStr << std::hex << std::uppercase << actualValue;

	InitMappingObject(valueStr.str());
}

void BaseProcessDataMapping::InitMappingObject(const std::string& actualValue)
{
	//Strip prefix
	std::uint32_t start = 0;
	if (actualValue.substr(0, 2) == "0x")
		start = 2;

	//Split into 4 octets pieces
	std::vector<std::string> splitVector;
	for (std::uint32_t i = start; i < actualValue.size();)
	{
		splitVector.push_back(actualValue.substr(i, 4).insert(0, "0x"));
		i += 4;
	}
	this->length = HexToInt<uint16_t>(splitVector.at(0));
	this->offset = HexToInt<uint16_t>(splitVector.at(1));
	this->subindex = HexToInt<uint16_t>(splitVector.at(2));
	this->index = HexToInt<uint32_t>(splitVector.at(3));
}

std::uint16_t BaseProcessDataMapping::GetDestinationNode() const
{
	return this->destinationNode;
}

void BaseProcessDataMapping::SetDestinationNode(std::uint16_t nodeId)
{
	this->destinationNode = nodeId;
}

std::uint32_t BaseProcessDataMapping::GetMappingIndex() const
{
	return this->index;
}

void BaseProcessDataMapping::SetMappingIndex(std::uint32_t index)
{
	this->index = index;
}

std::uint16_t BaseProcessDataMapping::GetMappingSubIndex() const
{
	return this->subindex;
}

void BaseProcessDataMapping::SetMappinSubgIndex(std::uint16_t subindex)
{
	this->subindex = subindex;
}

std::uint32_t BaseProcessDataMapping::GetMappingOffset() const
{
	return this->offset;
}

void BaseProcessDataMapping::SetMappingOffset(std::uint32_t offset)
{
	this->offset = offset;
}

std::uint32_t BaseProcessDataMapping::GetMappingLength() const
{
	return this->length;
}

void BaseProcessDataMapping::SetMappingLength(std::uint32_t length)
{
	this->length = length;
}

const std::string BaseProcessDataMapping::ToString(bool addPrefix)
{
	std::stringstream mappingObj;
	if (addPrefix)
		mappingObj << "0x";

	//Write mapping length
	mappingObj << std::uppercase << std::hex << std::setw(4) << std::setfill('0') << std::right << length;
	//Write mapping offset
	mappingObj << std::uppercase << std::hex << std::setw(4) << std::setfill('0') << std::right << offset;
	//Write alignment
	mappingObj << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << "";
	//Write mapping subindex
	mappingObj << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << std::right << subindex;
	//Write mapping index
	mappingObj << std::uppercase << std::hex << std::setw(4) << std::setfill('0') << std::right << index;

	return mappingObj.str();
}

std::uint64_t BaseProcessDataMapping::GetValue()
{
	return HexToInt<uint64_t>(this->ToString(true));
}

bool BaseProcessDataMapping::GetActive()
{
	return this->active;
}

void BaseProcessDataMapping::SetActive(bool active)
{
	this->active = active;
}

std::uint32_t BaseProcessDataMapping::GetObject()
{
	return this->object;
}

std::uint32_t BaseProcessDataMapping::GetSubObject()
{
	return this->subobject;
}

std::shared_ptr<BaseObject>& BaseProcessDataMapping::GetRelatedObject()
{
	return this->relatedObject;
}

void BaseProcessDataMapping::SetRelatedObject(std::shared_ptr<BaseObject>& object)
{
	this->relatedObject = object;
}