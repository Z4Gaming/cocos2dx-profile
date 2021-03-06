/*
 Copyright (C) 2012-2015 Soomla Inc.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#ifndef COCOS2DXPROFILE_CCSOOMLAGOOGLEPLUSCONFIGBUILDER_H
#define COCOS2DXPROFILE_CCSOOMLAGOOGLEPLUSCONFIGBUILDER_H

#include "CCSoomlaProfileSNConfigBuilder.h"

namespace soomla {
    class CCSoomlaGooglePlusConfigBuilder : public CCSoomlaProfileSNConfigBuilder {
    public:
        CCSoomlaGooglePlusConfigBuilder();
        CCProvider getProvider();
        static CCSoomlaGooglePlusConfigBuilder *create();
        CCSoomlaGooglePlusConfigBuilder *setClientId(const char *clientId);
    };
}


#endif //COCOS2DXPROFILE_CCSOOMLAGOOGLEPLUSCONFIGBUILDER_H
