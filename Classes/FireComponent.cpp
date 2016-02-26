//
//  FireComponent.cpp
//  tank_multiplayer
//
//  Created by 李崧榕 on 16/2/26.
//
//

#include "FireComponent.hpp"

FireComponent* FireComponent::create(FireComponentDelegate *delegate)
{
    FireComponent* component = new FireComponent();
    if(component && component->init(delegate))
    {
        component->autorelease();
        return component;
    }
    CC_SAFE_DELETE(component);
    return NULL;
}

FireComponent::FireComponent()
: _delegate(NULL)
, _time_interval(0.0f)
, _time_free(0.0f)
{
    
}

FireComponent::~FireComponent()
{
    
}

bool FireComponent::init(FireComponentDelegate *delegate)
{
    if(CCNode::init())
    {
        _delegate = delegate;
        
        return true;
    }
    return false;
}

void FireComponent::updateTransform(float dt)
{
    _time_free += dt;
    
    if(_time_free >= _time_interval)
    {
        _time_free = 0;
        _delegate->fire();
    }
}

// public interface
CCPoint FireComponent::getSpeedByDirection(float speed, EDirection dir)
{
    CCPoint pSpeed;
    
    if(dir == EDirection_Up)
        pSpeed.y = 1;
    else if(dir == EDirection_Down)
        pSpeed.y = -1;
    else if(dir == EDirection_Left)
        pSpeed.x = -1;
    else if(dir == EDirection_Right)
        pSpeed.x = 1;
    
    return pSpeed * speed;
}