//
//  TankEntity.cpp
//  tank_multiplayer
//
//  Created by 李崧榕 on 16/2/26.
//
//

#include "TankEntity.hpp"
#include "Display.hpp"
#include "BulletEntity.hpp"
#include "MapManager.hpp"
#include "MoveComponent.hpp"

TankEntity* TankEntity::create(MapManager* mapManager)
{
    TankEntity* entity = new TankEntity();
    if(entity && entity->init(mapManager))
    {
        entity->autorelease();
        return entity;
    }
    CC_SAFE_DELETE(entity);
    return NULL;
}

TankEntity::TankEntity()
: _fireComponent(NULL)
, _moveComponent(NULL)
{
    
}

TankEntity::~TankEntity()
{
    
}

bool TankEntity::init(MapManager* mapManager)
{
    if(Entity::init(mapManager))
    {
        _dir = EDirection_Up;
        
        this->addDisplay();
        this->addFireComponent();
        this->addMoveComponent();
        
        return true;
    }
    return false;
}

void TankEntity::addDisplay()
{
    _display = Display::createAnimation("Entity/tank_1.png");
    this->addChild(_display);
    
    _display->playWalkAnimation(_dir);
}

void TankEntity::addFireComponent()
{
    _fireComponent = FireComponent::create(this);
    this->addChild(_fireComponent);
    _fireComponent->setFireInterval(1.5f);
}

void TankEntity::addMoveComponent()
{
    _moveComponent = MoveComponent::create(this);
    this->addChild(_moveComponent);
    _moveComponent->setSpeedDirection(_dir);
    _moveComponent->setSpeedValue(100.0f);
}

// override
void TankEntity::updateTransform(float dt)
{
    _fireComponent->updateTransform(dt);
}

void TankEntity::fire()
{
//    CCLOG("tank: fire()");
    BulletEntity* bullet = BulletEntity::create(_mapManager);
    _mapManager->addChild(bullet);
    _mapManager->addBullet(bullet);
    bullet->setPosition(this->getPosition());
    bullet->shoot(300, _dir);
}