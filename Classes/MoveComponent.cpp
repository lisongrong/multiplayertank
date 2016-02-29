//
//  MoveComponent.cpp
//  tank_multiplayer
//
//  Created by 李崧榕 on 16/2/26.
//
//

#include "MoveComponent.hpp"

MoveComponent* MoveComponent::create(cocos2d::CCNode *target)
{
    MoveComponent* component = new MoveComponent();
    if(component && component->init(target))
    {
        component->autorelease();
        return component;
    }
    CC_SAFE_DELETE(component);
    return NULL;
}

MoveComponent::MoveComponent()
: _target(NULL)
, _speed(0.0f)
, _in_pause(false)
, _in_move(false)
{
    
}

MoveComponent::~MoveComponent()
{
    
}

bool MoveComponent::init(cocos2d::CCNode *target)
{
    if(CCNode::init())
    {
        _target = target;
        
        return true;
    }
    return false;
}

void MoveComponent::updateTransform(float dt)
{
    if(_in_move && !_in_pause)
    {
        CCPoint diff = _speed_dir * (_speed * dt);
        _target->setPosition(_target->getPosition() + diff);
    }
}

// public interface


// get && set
void MoveComponent::setSpeedDirection(EDirection dir)
{
    _speed_dir = CCPointZero;
    
    if(dir == EDirection_Up)
        _speed_dir.y = 1.0f;
    else if(dir == EDirection_Down)
        _speed_dir.y = -1.0f;
    else if(dir == EDirection_Left)
        _speed_dir.x = -1.0f;
    else if(dir == EDirection_Right)
        _speed_dir.x = 1.0f;
}

void MoveComponent::setSpeed(cocos2d::CCPoint speed)
{
    _speed = speed.getLength();
    _speed_dir = speed.normalize();
}