//
//  NotificationManager.hpp
//  GameTemplate
//
//  Created by 李崧榕 on 15/11/6.
//
//

#ifndef NotificationManager_hpp
#define NotificationManager_hpp

#include "cocos2d.h"
USING_NS_CC;
#include "NotificationConfig.h"

class NotificationObserver;

#define Notify NotificationManager::getInstance()

class NotificationManager : public CCObject
{
public:
    
    static NotificationManager* getInstance();
    static void destroyInstance();
    
    void addObserver(CCObject* target, SEL_CallFuncO selector, NotifyMsgId id, CCObject* obj = NULL);
    
    void removeObserver(CCObject* target, NotifyMsgId id);
    int removeAllObservers(CCObject* target);
    
    void postNotification(NotifyMsgId id, CCObject* obj = NULL, bool immediately = false);
    
    virtual void update(float dt);
    
protected:
    
    NotificationManager();
    virtual ~NotificationManager();
    bool init();
    
    NotificationObserver* getObserver(CCObject *target, NotifyMsgId id);
    
private:
    
    static NotificationManager* _instance;
    
    CCArray* _arr_observer;
    CCArray* _arr_temp_remove;
    CCArray* _arr_temp_add;
    bool _lock_post;
    
    std::vector<std::pair<NotifyMsgId, CCObject*> > _vec_msg;
};

/**
 * class NotificationObserver
 */
class NotificationObserver : public CCObject
{
public:
    
    NotificationObserver(CCObject* target, SEL_CallFuncO selector, NotifyMsgId id, CCObject* obj);
    
    void performSelector(CCObject* obj);
    
    inline CCObject* getTarget(){return _target;}
    inline SEL_CallFuncO getSelector(){return _selector;}
    inline NotifyMsgId getId(){return _id;}
    inline CCObject* getObject(){return _obj;}
    
private:
    
    CCObject* _target;
    SEL_CallFuncO _selector;
    NotifyMsgId _id;
    CCObject* _obj;
};
#endif /* NotificationManager_hpp */
