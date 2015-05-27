/************************************************************************
\file BuildConfigurationSettingId.h
\brief Enum BuildConfigurationSettingId
\author rueckerc, Bernecker+Rainer Industrie Elektronik Ges.m.b.H.
\date 27-Apr-2015 12:00:00
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
#if !defined BUILD_CONFIGURATION_SETTING_ID_H
#define BUILD_CONFIGURATION_SETTING_ID_H

#include <cstdint>

namespace IndustrialNetwork
{
	namespace POWERLINK
	{
		namespace Core
		{
			namespace Configuration
			{
				/**
				\brief Represents the supported build configuration settings.
				\author rueckerc, Bernecker+Rainer Industrie Elektronik Ges.m.b.H.
				*/
				enum BuildConfigurationId
				{
					GENERATE_MN_MAPPING_FOR_NODES, ///< Generate the MN mapping for nodes in the POWERLINK network.
					GENERATE_MN_NODE_ASSIGNMENT_FOR_NODES, ///< Generate the MN node assignment for all nodes in the POWERLINK network.
					GENERATE_MN_PRES_TIMEOUT_FOR_NODES, ///< Generate the MN PRes timeouts for all nodes in the POWERLINK network.
				};

				static const std::string BuildConfigurationIdName[] =
				{
					"GENERATE_MN_MAPPING_FOR_NODES", ///< Generate the MN mapping for nodes in the POWERLINK network.
					"GENERATE_MN_NODE_ASSIGNMENT_FOR_NODES", ///< Generate the MN node assignment for nodes in the POWERLINK network.
					"GENERATE_MN_PRES_TIMEOUT_FOR_NODES", ///< Generate the MN PRes timeouts for nodes in the POWERLINK network.
				};

				static const std::string BuildConfigurationIdDescription[] =
				{
					"Generate the MN mapping for nodes in the POWERLINK network.",
					"Generate the MN node assignment for nodes in the POWERLINK network.",
					"Generate the MN PRes timeouts for nodes in the POWERLINK network.",
				};
			}
		}
	}
}

#endif