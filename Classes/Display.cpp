//
//  Display.cpp
//  tank_multiplayer
//
//  Created by 李崧榕 on 16/2/26.
//
//

#include "Display.hpp"
#include "StringHelper.hpp"

Display* Display::createAnimation(std::string name)
{
    Display* display = new Display();
    if(display && display->initAnimation(name))
    {
        display->autorelease();
        return display;
    }
    CC_SAFE_DELETE(display);
    return NULL;
}

Display* Display::createSprite(std::string name)
{
    Display* display = new Display();
    if(display && display->initSprite(name))
    {
        display->autorelease();
        return display;
    }
    CC_SAFE_DELETE(display);
    return NULL;
}

Display::Display()
: _dic_animate(NULL)
{
    
}

Display::~Display()
{
    CC_SAFE_RELEASE_NULL(_dic_animate);
}

bool Display::initAnimation(std::string name)
{
    if(CCNode::init())
    {
        CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage(name.c_str());
        if(texture == NULL)
            return false;
        
        CCSize size = texture->getContentSize();
        CCSize size_unit = size / 4;
        _content = CCSprite::createWithTexture(texture, CCRectMake(0, 0, size_unit.width, size_unit.height));
        this->addChild(_content);
        
        vector<EDirection> vec_dir;
        vec_dir.push_back(EDirection_Down);
        vec_dir.push_back(EDirection_Left);
        vec_dir.push_back(EDirection_Right);
        vec_dir.push_back(EDirection_Up);
        
        _dic_animate = CCDictionary::create();
        _dic_animate->retain();
        
        for(int i = 0; i < vec_dir.size(); ++i)
        {
            CCArray* arr = new CCArray();
            arr->initWithCapacity(KCount_AnimateFrame);
            for(int j = 0; j < KCount_AnimateFrame; ++j)
            {
                CCSpriteFrame* frame = CCSpriteFrame::createWithTexture(texture, CCRectMake(j * size_unit.width, i * size_unit.height, size_unit.width, size_unit.height));
                arr->addObject(frame);
            }
            
            CCAnimation* animation = CCAnimation::createWithSpriteFrames(arr);
            animation->setDelayPerUnit(KInterval_Animate);
            animation->setLoops(INT_MAX);
            CCAnimate* animate = CCAnimate::create(animation);
            arr->release();
            _dic_animate->setObject(animate, this->getAnimationKey(EAnimateType_Walk, vec_dir[i]));
        }
        
        return true;
    }
    return false;
}

bool Display::initSprite(std::string name)
{
    if(CCNode::init())
    {
        _content = CCSprite::create(name.c_str());
        this->addChild(_content);
        
        return true;
    }
    return false;
}

void Display::playWalkAnimation(EDirection dir)
{
    CCAnimate* animte = dynamic_cast<CCAnimate*>(_dic_animate->objectForKey(this->getAnimationKey(EAnimateType_Walk, dir)));
    _content->stopAllActions();
    _content->runAction(animte);
}

std::string Display::getAnimationKey(EAnimateType type, EDirection dir)
{
    return "animte" + StringHelper::intToString(type) + StringHelper::intToString(dir);
}