//
//  BulletEntity.cpp
//  tank_multiplayer
//
//  Created by 李崧榕 on 16/2/26.
//
//

#include "BulletEntity.hpp"
#include "Display.hpp"

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
{
    
}

BulletEntity::~BulletEntity()
{
    
}

bool BulletEntity::init(MapManager* mapManager)
{
    if(Entity::init(mapManager))
    {
        _display = Display::createSprite("Bullet/bullet.png");
        this->addChild(_display);
        
        return true;
    }
    return false;
}

void BulletEntity::shoot(cocos2d::CCPoint speed)
{
    // TODO: Speed Component
    this->runAction(CCMoveBy::create(1, speed));
}