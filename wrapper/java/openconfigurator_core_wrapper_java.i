/*################################################################################
#
# Project: openCONFIGURATOR core library Java wrapper interface
#
# (c) Bernecker + Rainer Industrie-Elektronik Ges.m.b.H.
#     B&R Strasse 1, A-5142 Eggelsberg
#     www.br-automation.com
#
#
# License:
#
#   Redistribution and use in source and binary forms, with or without
#   modification, are permitted provided that the following conditions
#   are met:
#
#   1. Redistributions of source code must retain the above copyright
#      notice, this list of conditions and the following disclaimer.
#
#   2. Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in the
#      documentation and/or other materials provided with the distribution.
#
#   3. Neither the name of the copyright holders nor the names of its
#      contributors may be used to endorse or promote products derived
#      from this software without prior written permission. For written
#      permission, please contact office@br-automation.com.
#
#   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
#   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
#   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
#   FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
#   COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
#   INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
#   BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
#   LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
#   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
#   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
#   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
#   POSSIBILITY OF SUCH DAMAGE.
#
#   Severability Clause:
#
#       If a provision of this License is or becomes illegal, invalid or
#       unenforceable in any jurisdiction, that shall not affect:
#       1. the validity or enforceability in that jurisdiction of any other
#          provision of this License; or
#       2. the validity or enforceability in other jurisdictions of that or
#          any other provision of this License.
#
################################################################################*/
%module openconfigurator_core_wrapper_java

#define DLLEXPORT
#define __attribute__(x)
#if defined(_WIN32) && defined(_MSC_VER)
	 #undef DllExport
	 #define DllExport __declspec(dllexport)
#endif

%include typemaps.i
%include std_map.i
%include std_pair.i
%include std_except.i
%include std_string.i
%include std_vector.i
%include <std_shared_ptr.i>
%include "enums.swg"
%include windows.i
%include std_string_ref.i
%include stdint.i

%apply std::string &INOUT { std::string & activeConfiguration };
%apply std::string &INOUT { std::string & defaultValue };
%apply std::string &INOUT { std::string & configurationOutput };
%apply std::string &INOUT { std::string & actualValueReturn };
%apply std::string &INOUT { std::string & parameterName };
%apply std::string &INOUT { std::string & processImageCOutput };
%apply std::string &INOUT { std::string & processImageXMLOutput };
%apply std::string &INOUT { std::string & processImageNETOutput };

%apply unsigned int& OUTPUT { unsigned int& size };
%apply unsigned int& OUTPUT { unsigned int& size };
%apply unsigned int& OUTPUT { unsigned int& cycleTime };
%apply unsigned short& OUTPUT { unsigned short& asyncMtu };
%apply unsigned short& OUTPUT { unsigned short& multiplexedCycleLength };
%apply unsigned short& OUTPUT { unsigned short& prescaler };
%apply unsigned int& OUTPUT { unsigned int& asyncSlotTimeout };
%apply unsigned short& OUTPUT { unsigned short& asndMaxNr };
%apply unsigned int& OUTPUT { unsigned int& presTimeout };
%apply unsigned int& OUTPUT { unsigned int& lossOfSocTolerance };
%apply unsigned int& OUTPUT { unsigned int& waitNotActive };
%apply unsigned int& OUTPUT { unsigned int& priority };
%apply unsigned int& OUTPUT { unsigned int& gapSize };
%apply unsigned int& OUTPUT { unsigned int& objectId };
%apply unsigned short& OUTPUT { unsigned short& subObjectId };
%apply unsigned int& OUTPUT { unsigned int& returnIndex };
%apply unsigned int& OUTPUT { unsigned int& offset };
%apply int& OUTPUT { int& returnSubIndex };
%apply bool& OUTPUT { bool& conditionMet };

%ignore GetNetworkManagement();
%ignore PlkFeatureDefaultValues;
%ignore DirectionTypeValues;
%ignore GetPlkDataTypeName();
%ignore GetNodeAssignmentName();
%ignore PlkFeatureStrings;
%ignore SetComplexDataType(std::shared_ptr<Parameter>& parameter);
%ignore SetComplexDataType(std::shared_ptr<ParameterGroup>& parameterGrp);
%ignore GetReferencedParameter() const;
%ignore GetReferencedParameterGroup() const;
%ignore GetRmnIds();
%ignore IECDatatypeValues;
%ignore ParameterAccessValues;
%ignore PDOMappingValues;
%ignore AccessTypeValues;

%ignore kMsgLoggingInitialised;
%ignore kMsgDateTimeNotInitialised;
%ignore kMsgExistingNetwork;
%ignore kMsgNonExistingNetwork;
%ignore kMsgNetworkCreated;
%ignore kMsgNetworkRemoved;
%ignore kMsgSupportedSettingIds;
%ignore kMsgNetworkListCleared;
%ignore kMsgExistingNode;
%ignore kMsgNonExistingNode;
%ignore kMsgNonManagingNode;
%ignore kMsgNoManagingNode;
%ignore kMsgRemoveManagingNode;
%ignore kMsgNonControlledNode;
%ignore kMsgNonRedundantManagingNode;
%ignore kMsgNodeCreated;
%ignore kMsgNodeRemoved;
%ignore kMsgNodeObjectCount;
%ignore kMsgNodeObjectCountSize;
%ignore kMsgManagingNodeDisable;
%ignore kMsgNodeDisable;
%ignore kMsgMultiplexingNotSupported;
%ignore kMsgChainingNotSupported;
%ignore kMsgMultiplexCycleAssignInvalid;
%ignore kMsgMultiplexCycleAlreadyAssigned;
%ignore kMsgInsufficientMappingObjects;
%ignore kMsgExistingObject;
%ignore kMsgExistingSubObject;
%ignore kMsgObjectCreated;
%ignore kMsgSubObjectCreated;
%ignore kMsgObjectNoActualValue;
%ignore kMsgSubObjectNoActualValue;
%ignore kMsgNonExistingObject;
%ignore kMsgNonExistingSubObject;
%ignore kMsgForceObject;
%ignore kMsgForceSubObject;
%ignore kMsgSetObjectActualValue;
%ignore kMsgSetSubObjectActualValue;
%ignore kMsgDatatypeMismatch;
%ignore kMsgBaseObjectDataTypeMismatch;
%ignore kMsgActualValueDatatypeError;
%ignore kMsgDefaultValueDatatypeError;
%ignore kMsgHighLimitDatatypeError;
%ignore kMsgLowLimitDatatypeError;
%ignore kMsgBaseObjectLowLimitError;
%ignore kMsgBaseObjectHighLimitSubObjectError;
%ignore kMsgBaseObjectLowLimitSubObjectError;
%ignore kMsgBaseObjectHighLimitError;
%ignore kMsgBaseObjectDataTypeError;
%ignore kMsgBaseObjectDefaultValue;
%ignore kMsgBaseObjectActualValue;
%ignore kMsgBaseObjectValueSupport;
%ignore kMsgBaseSubObjectValueSupport;
%ignore kMsgBaseObjectHighLimit;
%ignore kMsgBaseObjectLowLimit;
%ignore kMsgBaseObjectDoesNotSupportLimits;
%ignore kMsgBaseObjectDoesNotSupportValues;
%ignore kMsgConfigurationSettingNotSupported;
%ignore kMsgConfigurationNonExisting;
%ignore kMsgConfigurationExisting;
%ignore kMsgConfigurationAdded;
%ignore kMsgConfigurationRemoved;
%ignore kMsgActiveConfigurationRemove;
%ignore kMsgConfigurationActive;
%ignore kMsgConfigurationRenamed;
%ignore kMsgConfigurationSettingNonExisting;
%ignore kMsgConfigurationSettingExisting;
%ignore kMsgConfigurationSettingAdded;
%ignore kMsgConfigurationSettingRemoved;
%ignore kMsgConfigurationSettingEnabled;
%ignore kMsgComplexDatatypeNotFoundOnNode;
%ignore kMsgComplexDatatypeNotFound;
%ignore kMsgComplexDataTypeAlreadyExist;
%ignore kMsgComplexDataTypeSizeInvalid;
%ignore kMsgComplexDataTypeCreated;
%ignore kMsgStructDatatypeNotFound;
%ignore kMsgEnumValueExists;
%ignore kMsgVarDeclarationExists;
%ignore kMsgParameterCreated;
%ignore kMsgParameterReturned;
%ignore kMsgParameterNotFound;
%ignore kMsgParameterAlreadyExist;
%ignore kMsgParameterActualValueDoesNotExist;
%ignore kMsgParameterDefaultValueDoesNotExist;
%ignore kMsgParameterGroupAlreadyExist;
%ignore kMsgParameterTemplateAlreadyExist;
%ignore kMsgParameterGroupNonExisting;
%ignore kMsgParameterGroupEmpty;
%ignore kMsgParameterTemplateNonExisting;
%ignore kMsgNodeIdInvalid;
%ignore kMsgSubIndexInvalid;
%ignore kMsgIndexInvalid;
%ignore kMsgUnsupportedAttributeType;
%ignore kMsgCycleTimeOnMnNotSet;
%ignore kMsgCycleTimeDefaultValue;
%ignore kMsgForcedValueOverwriteObject;
%ignore kMsgForcedValueOverwriteSubObject;
%ignore kMsgWriteManagingNodeObjectCount;
%ignore kMsgWriteNodeAssignment;
%ignore kMsgWriteRedundantManagingNode;
%ignore kMsgWriteManagingNode;
%ignore kMsgWriteControlledNode;
%ignore kMsgWriteMappingObjects;
%ignore kMsgWriteMappingObjectsNrOfEntries;
%ignore kMsgWriteMappingObjectsNrOfEntriesZero;
%ignore kMsgWriteCommunicationRangeObjects;
%ignore kMsgWriteUserDefinedRangeObjects;
%ignore kMsgGeneralFeatureDatatypeError;
%ignore kMsgCnFeatureDatatypeError;
%ignore kMsgMnFeatureDatatypeError;
%ignore kMsgFeatureActualValue;
%ignore kMsgNodeAssignmentNotSupported;
%ignore kMsgNodeAssignmentAlreadyExists;
%ignore kMsgDynamicChannelNotFound;
%ignore kMsgNonExistingMappedObject;
%ignore kMsgNonExistingMappedSubObject;
%ignore kMsgMappedObjectSizeInvalid;
%ignore kMsgAccessTypeForParameterInvalid;
%ignore kMsgAccessTypeForParameterGroupInvalid;
%ignore kMsgMappingTypeForPdoInvalid;
%ignore kMsgAccessTypeForPdoInvalid;
%ignore kMsgPdoOffsetInvalid;
%ignore kMsgNoNodesConfigured;
%ignore kMsgLowCnPresTimeout;
%ignore kMsgLowCnPresTimeoutDefault;
%ignore kMsgDefaultCnPresTimeout;
%ignore kMsgParameterValueInvalid;
%ignore kMsgParameterMinMaxValueInvalid;
%ignore kMsgParameterDataTypeInvalid;
%ignore kMsgManagingNodeTransmitPres;
%ignore kMsgMappingOperationNotSupported;
%ignore kMsgMappingObjectInvalid;
%ignore kMsgNrOfEntriesInvalid;
%ignore kMsgDynamicChannelExceeded;
%ignore kMsgChannelExceeded;
%ignore kMsgCycleTimeMin;
%ignore kMsgCycleTimeMax;
%ignore kMsgCycleTimeGran;
%ignore kMsgIsochronousMaxPayloadExceeded;
%ignore kMsgChainingRmnNotSupported;
%ignore kMsgChainingMnNotSupported;
%ignore kMsgMultiplexingMnNotSupported;
%ignore kMsgNodeIsNotAModularControlledNode;
%ignore kMsgInterfaceDoesNotExists;
%ignore kMsgInterfaceAlreadyExists;
%ignore kMsgRangeAlreadyExists;
%ignore kMsgRangeDoesNotExists;
%ignore kMsgRangeInvalid;
%ignore kMsgRangeHasNoFreeObjects;
%ignore kMsgRangeIndexAlreadyTaken;
%ignore kMsgModuleDoesNotExists;
%ignore kMsgModuleAlreadyExists;
%ignore kMsgModuleDoesNotMatch;
%ignore kMsgModulePositionOccupied;
%ignore kMsgModuleAddressOccupied;
%ignore kMsgInterfaceDoesNotSupportManualAddressing;
%ignore kMsgInvalidProcessImage;
%ignore kMsgInvalidMappingOffset;
%ignore kMsgInvalidMappingRecalculated;
%ignore kMsgInvalidMappingReference;
%ignore kMsgMappingSizeZero;

%{

#include "Language.h"
#include "DynamicChannelAccessType.h"
#include "ErrorCode.h"
#include "IEC_Datatype.h"
#include "ParameterAccess.h"
#include "IEC_Datatype.h"
#include "ObjectType.h"
#include "PDOMapping.h"
#include "PlkDataType.h"
#include "NodeAssignment.h"
#include "DynamicChannel.h"
#include "Result.h"
#include "Network.h"
#include "Direction.h"
#include "PlkConfiguration.h"
#include "BuildConfigurationSetting.h"
#include "BaseNode.h"
#include "BaseObject.h"
#include "Object.h"
#include "SubObject.h"
#include "ControlledNode.h"
#include "ManagingNode.h"
#include "PlkFeatureEnum.h"
#include "PlkOperationMode.h"
#include "SortEnums.h"
#include "OpenConfiguratorCore.h"

%}

%include "Language.h"
%include "ErrorCode.h"
%include "IResult.h"
%template(intResult) IndustrialNetwork::Fieldbus::IResult<IndustrialNetwork::POWERLINK::Core::ErrorHandling::ErrorCode>;
%include "Result.h"

%include "IEC_Datatype.h"
%include "ParameterAccess.h"
%include "AccessType.h"
%include "DynamicChannelAccessType.h"
%include "ObjectType.h"
%include "PDOMapping.h"
%include "PlkDataType.h"
%include "NodeAssignment.h"
%include "DynamicChannel.h"
%include "Network.h"
%include "Direction.h"

%include "IFieldbusNode.h"
%template(intFieldBusNode) IndustrialNetwork::Fieldbus::IFieldbusNode<unsigned char, unsigned int, IndustrialNetwork::POWERLINK::Core::ObjectDictionary::Object>;
%include "BaseNode.h"

%include "IBuildConfigurationSetting.h"
%include "BuildConfigurationSetting.h"
%include "IBuildConfiguration.h"
%template(intBuildConfiguration) IndustrialNetwork::Fieldbus::IBuildConfiguration<IndustrialNetwork::POWERLINK::Core::Configuration::BuildConfigurationSetting>;
%include "PlkConfiguration.h"

%include "IBaseObject.h"
%template(intBaseObject) IndustrialNetwork::Fieldbus::IBaseObject<unsigned int, IndustrialNetwork::POWERLINK::Core::ObjectDictionary::ObjectType>;
%include "BaseObject.h"

%include "Object.h"
%include "SubObject.h"
%include "ControlledNode.h"
%include "RedundantManagingNode.h"
%include "ManagingNode.h"
%include "PlkFeatureEnum.h"
%include "PlkOperationMode.h"
%include "SortEnums.h"
%include "OpenConfiguratorCore.h"

namespace std {
   %template(StringCollection) std::vector<std::string>;
   %template(ConfigurationCollection) std::vector<IndustrialNetwork::POWERLINK::Core::Configuration::PlkConfiguration>;
   %template(SettingsCollection) std::vector<IndustrialNetwork::POWERLINK::Core::Configuration::BuildConfigurationSetting>;
   %template(ByteCollection) std::vector<unsigned char>;
   %template(AssignmentCollection) std::vector<unsigned int>;
}

%typemap(javainterfaces) MapIterator "java.util.Iterator<String>"
%typemap(javacode) MapIterator %{
  public void remove() throws UnsupportedOperationException {
    throw new UnsupportedOperationException();
  }

  public String GetValue(){
   return getValue();
  }

  public ObjectPair GetKey(){
    return getKey();
  }

  public String next() throws java.util.NoSuchElementException {
    if (!hasNext()) {
      throw new java.util.NoSuchElementException();
    }
    return nextImpl();
  }
%}

#%javamethodmodifiers MapIterator::getValue "private";
#%javamethodmodifiers MapIterator::getKey "private";
%javamethodmodifiers MapIterator::nextImpl "private";
%inline %{
  struct MapIterator {
    typedef std::map<std::pair<unsigned int, int>, std::string> map_t;
    MapIterator(const map_t& m) : it(m.begin()), map(m) {}

    bool hasNext() const {
      return it != map.end();
    }

	const std::pair<unsigned int, int> getKey(){
		const std::pair<std::pair<unsigned int, int>, std::string>& ret = *it;
		return ret.first;
	}

    const std::string getValue() {
      const std::pair<std::pair<unsigned int, int>, std::string>& ret = *it;
      return ret.second;
    }

	const std::string nextImpl() {
      const std::pair<std::pair<unsigned int, int>, std::string>& ret = *it++;
      return ret.second;
    }

  private:
    map_t::const_iterator it;
    const map_t& map;
  };
%}

%typemap(javainterfaces) std::map<std::pair<unsigned int, int>,std::string> "Iterable<String>"

%newobject std::map<std::pair<unsigned int, int>,std::string>::iterator() const;
%extend std::map<std::pair<unsigned int, int>,std::string> {
  MapIterator *iterator() const {
    return new MapIterator(*$self);
  }
}

%template(ObjectPair) std::pair<unsigned int, int>;
%template(ObjectCollection) std::map<std::pair<unsigned int, int> , std::string>;
