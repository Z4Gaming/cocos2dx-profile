//
// Created by Fedor Shubin on 5/20/13.
//

#include "CCProfileController.h"
#include "CCNdkBridge.h"
#include "CCDomainFactory.h"
#include "CCBadgeReward.h"
#include "CCRandomReward.h"
#include "CCSequenceReward.h"
#include "CCVirtualItemReward.h"

using namespace cocos2d;
typedef DictElement CCDictElement;

namespace soomla {
    #define TAG "SOOMLA StoreController"

    USING_NS_CC;

    static CCProfileController *sInstance = NULL;

    CCProfileController *CCProfileController::getInstance() {
        if (!sInstance)
        {
            sInstance = new CCProfileController();
            sInstance->retain();
        }
        return sInstance;
    }

    CCProfileController::CCProfileController() {
        mInited = false;
    }

    bool CCProfileController::init() {
        mInited = true;
        return true;
    }

    void CCProfileController::login(const char *provider, CCReward *reward, CCError **soomlaError) {
        CC_ASSERT(mInited);
        __Dictionary *params = __Dictionary::create();
        params->setObject(__String::create("CCProfileController::login"), "method");
        params->setObject(__String::create(provider), "provider");
        params->setObject(reward->toDictionary(), "reward");
        CCNdkBridge::callNative(params, soomlaError);
    }

    void CCProfileController::login(const char *provider, CCError **soomlaError) {
        CC_ASSERT(mInited);
        __Dictionary *params = __Dictionary::create();
        params->setObject(__String::create("CCProfileController::login"), "method");
        params->setObject(__String::create(provider), "provider");
        CCNdkBridge::callNative(params, soomlaError);
    }

    void CCProfileController::logout(const char *provider, CCError **soomlaError) {
        CC_ASSERT(mInited);
        __Dictionary *params = __Dictionary::create();
        params->setObject(__String::create("CCProfileController::logout"), "method");
        params->setObject(__String::create(provider), "provider");
        CCNdkBridge::callNative(params, soomlaError);
    }

    CCUserProfile *CCProfileController::getStoredUserProfile(const char *provider, CCError **soomlaError) {
        CC_ASSERT(mInited);
        __Dictionary *params = __Dictionary::create();
        params->setObject(__String::create("CCProfileController::getStoredUserProfile"), "method");
        params->setObject(__String::create(provider), "provider");
        __Dictionary *retParams = (__Dictionary *) CCNdkBridge::callNative(params, NULL);
        CCUserProfile *retValue = (CCUserProfile *) retParams->objectForKey("return");
        return retValue;
    }

    void CCProfileController::updateStatus(const char *provider, const char *status, CCReward *reward, CCError **soomlaError) {
        CC_ASSERT(mInited);
        __Dictionary *params = __Dictionary::create();
        params->setObject(__String::create("CCProfileController::updateStatus"), "method");
        params->setObject(__String::create(provider), "provider");
        params->setObject(__String::create(status), "status");
        if (reward) {
            params->setObject(reward->toDictionary(), "reward");
        }
        CCNdkBridge::callNative(params, soomlaError);
    }

    void CCProfileController::updateStory(const char *provider, const char *message, const char *name,
            const char *caption, const char *description, const char *link, const char *picture,
            CCReward *reward, CCError **soomlaError) {

        CC_ASSERT(mInited);
        __Dictionary *params = __Dictionary::create();
        params->setObject(__String::create("CCProfileController::updateStory"), "method");
        params->setObject(__String::create(provider), "provider");
        params->setObject(__String::create(message), "message");
        params->setObject(__String::create(name), "name");
        params->setObject(__String::create(caption), "caption");
        params->setObject(__String::create(description), "description");
        params->setObject(__String::create(link), "link");
        params->setObject(__String::create(picture), "picture");
        params->setObject(reward->toDictionary(), "reward");
        CCNdkBridge::callNative(params, soomlaError);
    }

    void CCProfileController::uploadImage(const char *provider, const char *message, const char *filePath,
            CCReward *reward, CCError **soomlaError) {

        CC_ASSERT(mInited);
        __Dictionary *params = __Dictionary::create();
        params->setObject(__String::create("CCProfileController::uploadImage"), "method");
        params->setObject(__String::create(provider), "provider");
        params->setObject(__String::create(message), "message");
        params->setObject(__String::create(filePath), "filePath");
        params->setObject(reward->toDictionary(), "reward");
        CCNdkBridge::callNative(params, soomlaError);
    }

    void CCProfileController::getContacts(const char *provider, CCReward *reward, CCError **soomlaError) {

        CC_ASSERT(mInited);
        __Dictionary *params = __Dictionary::create();
        params->setObject(__String::create("CCProfileController::getContacts"), "method");
        params->setObject(__String::create(provider), "provider");
        params->setObject(reward->toDictionary(), "reward");
        CCNdkBridge::callNative(params, soomlaError);
    }
}
