//
//  BulletEntity.cpp
//  tank_multiplayer
//
//  Created by 李崧榕 on 16/2/26.
//
//

#include "BulletEntity.hpp"
#include "Display.hpp"
#include "MoveComponent.hpp"
#include "MapManager.hpp"

BulletEntity* BulletEntity::create(MapManager* mapManager)
{
    BulletEntity* bullet = new BulletEntity();
    if(bullet && bullet->init(mapManager))
    {
        bullet->autorelease();
        return bullet;
    }
    CC_SAFE_DELETE(bullet);
    return NULL;
}

BulletEntity::BulletEntity()
: _moveComponent(NULL)
{
    
}

BulletEntity::~BulletEntity()
{
    
}

bool BulletEntity::init(MapManager* mapManager)
{
    if(Entity::init(mapManager))
    {
        this->addDisplay();
        this->addMoveComponent();
        
        return true;
    }
    return false;
}

void BulletEntity::addDisplay()
{
    _display = Display::createSprite("Bullet/bullet.png");
    this->addChild(_display);
}

void BulletEntity::addMoveComponent()
{
    _moveComponent = MoveComponent::create(this);
    this->addChild(_moveComponent);
}

// override
void BulletEntity::updateTransform(float dt)
{
    _moveComponent->updateTransform(dt);
    CCPoint pos = this->getPosition();
    
    if(pos.x < 0 || pos.y < 0 || pos.x > _mapManager->getContentSize().width || pos.y > _mapManager->getContentSize().height)
    {
        this->removeFromParent();
        _mapManager->removeBullet(this);
    }
}

void BulletEntity::shoot(float speed, EDirection dir)
{
    // TODO: Speed Component
    _moveComponent->setSpeedValue(speed);
    _moveComponent->setSpeedDirection(dir);
    _moveComponent->start();
}