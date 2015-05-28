/************************************************************************
\file BaseNode.h
\brief Implementation of the Class BaseNode
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
#if !defined BASE_NODE_H
#define BASE_NODE_H

#include <vector>
#include <cstdint>
#include <memory>
#include <boost/filesystem.hpp>
#include "Constants.h"
#include "ApplicationProcess.h"
#include "NetworkManagement.h"
#include "DynamicChannel.h"
#include "Object.h"
#include "IFieldbusNode.h"
#include "TxProcessDataMappingObject.h"
#include "RxProcessDataMappingObject.h"
#include "NodeAssignment.h"
#include "Result.h"

namespace IndustrialNetwork
{
	namespace POWERLINK
	{
		namespace Core
		{
			namespace Node
			{
				/**
				\brief Represents the common basis for all POWERLINK node.
				\author rueckerc, Bernecker+Rainer Industrie Elektronik Ges.m.b.H.
				*/
				class DLLEXPORT BaseNode : public IndustrialNetwork::Fieldbus::IFieldbusNode<std::uint8_t, std::uint32_t, IndustrialNetwork::POWERLINK::Core::ObjectDictionary::Object>
				{

					public:
						BaseNode(std::uint8_t nodeId, const std::string& nodeName = "");
						virtual ~BaseNode();

						const std::string& GetName();
						void SetName(const std::string& name);
						std::uint8_t GetNodeIdentifier();
						void SetNodeIdentifier(std::uint8_t nodeId);
						const std::unordered_map<std::uint32_t, std::shared_ptr<IndustrialNetwork::POWERLINK::Core::ObjectDictionary::Object>>& GetObjectDictionary();
						void SetObjectDictionary(const std::unordered_map<uint32_t, std::shared_ptr<IndustrialNetwork::POWERLINK::Core::ObjectDictionary::Object>>& od);

						IndustrialNetwork::POWERLINK::Core::ErrorHandling::Result AddObject(std::shared_ptr<IndustrialNetwork::POWERLINK::Core::ObjectDictionary::Object>& objRef);
						IndustrialNetwork::POWERLINK::Core::ErrorHandling::Result AddSubObject(std::uint32_t objectId, std::shared_ptr<IndustrialNetwork::POWERLINK::Core::ObjectDictionary::SubObject>& subObjRef);
						IndustrialNetwork::POWERLINK::Core::ErrorHandling::Result ForceObject(std::uint32_t nodeId, std::string actualValue = "");
						IndustrialNetwork::POWERLINK::Core::ErrorHandling::Result SetObjectActualValue(std::uint32_t nodeId, std::string actualValue);
						IndustrialNetwork::POWERLINK::Core::ErrorHandling::Result GetObject(std::uint32_t nodeId, IndustrialNetwork::POWERLINK::Core::ObjectDictionary::Object& objRef);

						virtual bool AddNodeAssignement(NodeAssignment) = 0;
						virtual bool RemoveNodeAssignment(NodeAssignment) = 0;
						virtual std::uint32_t GetNodeAssignmentValue() = 0;

					private:
						std::uint8_t nodeId;
						std::string name;
						std::unordered_map<std::uint32_t, std::shared_ptr<IndustrialNetwork::POWERLINK::Core::ObjectDictionary::Object>> objectDictionary;
						std::shared_ptr<IndustrialNetwork::POWERLINK::Core::ObjectDictionary::ApplicationProcess> applicationProcess;

						std::vector<IndustrialNetwork::POWERLINK::Core::Node::NodeAssignment> nodeAssignment;
						std::shared_ptr<NetworkManagement> networkManagement;
						std::vector<std::shared_ptr<DynamicChannel>> dynamicChannelList;
						std::vector<std::shared_ptr<IndustrialNetwork::POWERLINK::Core::ObjectDictionary::TxProcessDataMappingObject>> transmitMapping;
						std::vector<std::shared_ptr<IndustrialNetwork::POWERLINK::Core::ObjectDictionary::RxProcessDataMappingObject>> receiveMapping;

				};

			}

		}

	}

}
#endif
