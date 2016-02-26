//
//  NotificationManager.cpp
//  GameTemplate
//
//  Created by 李崧榕 on 15/11/6.
//
//

#include "NotificationManager.hpp"

NotificationManager* NotificationManager::_instance = NULL;

NotificationManager* NotificationManager::getInstance()
{
    if(!_instance)
    {
        _instance = new NotificationManager();
        _instance->init();
        
        // perform update in frame end
        CCDirector::sharedDirector()->getScheduler()->scheduleUpdateForTarget(_instance, INT_MAX, false);
    }
    return _instance;
}

void NotificationManager::destroyInstance()
{
    if(_instance)
    {
        CCDirector::sharedDirector()->getScheduler()->unscheduleAllForTarget(_instance);
        
        delete _instance;
        _instance = NULL;
    }
}

NotificationManager::NotificationManager()
: _arr_observer(NULL)
, _arr_temp_remove(NULL)
, _arr_temp_add(NULL)
, _lock_post(false)
{
    
}

NotificationManager::~NotificationManager()
{
    CC_SAFE_RELEASE_NULL(_arr_observer);
    CC_SAFE_RELEASE_NULL(_arr_temp_remove);
    CC_SAFE_RELEASE_NULL(_arr_temp_add);
}

bool NotificationManager::init()
{
    _arr_observer = CCArray::create();
    _arr_observer->retain();
    _arr_temp_remove = CCArray::createWithCapacity(1);
    _arr_temp_remove->retain();
    _arr_temp_add = CCArray::createWithCapacity(1);
    _arr_temp_add->retain();

//    this->scheduleUpdateWithPriority(INT_MAX); // perform update in frame end
    
    return true;
}

NotificationObserver* NotificationManager::getObserver(cocos2d::CCObject *target, NotifyMsgId id)
{
    for(int i = 0; i < _arr_observer->count(); ++i)
    {
        NotificationObserver* observer = (NotificationObserver*)_arr_observer->objectAtIndex(i);
        if(observer->getTarget() == target && observer->getId() == id)
            return observer;
    }
    return NULL;
}

void NotificationManager::addObserver(cocos2d::CCObject *target, SEL_CallFuncO selector, NotifyMsgId id, CCObject* obj/*NULL*/)
{
    NotificationObserver* observer = this->getObserver(target, id);
    if(!observer)
    {
        NotificationObserver* observer = new NotificationObserver(target, selector, id, obj);
        observer->autorelease();
        
        if(_lock_post)
            _arr_temp_add->addObject(observer);
        else
            _arr_observer->addObject(observer);
    }
    else
    {
        _arr_temp_remove->removeObject(observer);
    }
}

void NotificationManager::removeObserver(cocos2d::CCObject *target, NotifyMsgId id)
{
    NotificationObserver* observer = this->getObserver(target, id);
    if(observer)
    {
        if(_lock_post)
            _arr_temp_remove->removeObject(observer);
        else
            _arr_observer->removeObject(observer);
    }
}

int NotificationManager::removeAllObservers(cocos2d::CCObject *target)
{
    int count = 0;
    
    if(_lock_post)
    {
        for(int i = _arr_observer->count() - 1; i >= 0; --i)
        {
            NotificationObserver* observer = (NotificationObserver*)_arr_observer->objectAtIndex(i);
            if(observer->getTarget() == target)
            {
                ++count;
                _arr_temp_remove->addObject(observer);
                _arr_temp_add->removeObject(observer);
            }
        }
    }
    else
    {
        for(int i = _arr_observer->count() - 1; i >= 0; --i)
        {
            NotificationObserver* observer = (NotificationObserver*)_arr_observer->objectAtIndex(i);
            if(observer->getTarget() == target)
            {
                ++count;
                _arr_observer->removeObject(observer);
            }
        }
    }
    
    return count;
}

void NotificationManager::postNotification(NotifyMsgId id, CCObject* obj/*NULL*/, bool immediately/*false*/)
{
    if(immediately)
    {
        _lock_post = true;
        
        for(int i = _arr_observer->count() - 1; i >= 0; --i)
        {
            NotificationObserver* observer = dynamic_cast<NotificationObserver*>(_arr_observer->objectAtIndex(i));
            if(observer->getId() == id &&
               (observer->getObject() == observer || observer->getObject() == NULL || observer == NULL) &&
               _arr_temp_remove->indexOfObject(obj) == CC_INVALID_INDEX)
            {
                observer->performSelector(obj);
            }
        }
        
        for(int i = _arr_temp_add->count() - 1; i >= 0; --i)
        {
            _arr_observer->addObject(_arr_temp_add->objectAtIndex(i));
            _arr_temp_add->removeObjectAtIndex(i);
        }
        
        for(int i = _arr_temp_remove->count() - 1; i >= 0; --i)
        {
            _arr_observer->removeObject(_arr_temp_remove->objectAtIndex(i));
            _arr_temp_remove->removeObjectAtIndex(i);
        }
        
        _lock_post = false;
    }
    else
    {
        _vec_msg.push_back(std::pair<NotifyMsgId, CCObject*>(id, obj));
    }
}

void NotificationManager::update(float dt)
{
    for(int i = 0; i < _vec_msg.size(); ++i)
    {
        std::pair<NotifyMsgId, CCObject*> pair_msg = _vec_msg[i];
        this->postNotification(pair_msg.first, pair_msg.second, true);
    }
    _vec_msg.clear();
}

/**
 * class NotificationObserver
 */
NotificationObserver::NotificationObserver(CCObject* target, SEL_CallFuncO selector, NotifyMsgId id, CCObject* obj)
{
    _target = target;
    _selector = selector;
    _id = _id;
    _obj = obj;
}

void NotificationObserver::performSelector(CCObject* obj)
{
    if(_target)
    {
        if(obj)
            (_target->*_selector)(obj);
        else
            (_target->*_selector)(_obj);
    }
}