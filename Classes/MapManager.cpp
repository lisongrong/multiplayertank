//
//  MapManager.cpp
//  tank_multiplayer
//
//  Created by 李崧榕 on 16/2/26.
//
//

#include "MapManager.hpp"
#include "Config.h"
#include "TankEntity.hpp"
#include "BulletEntity.hpp"

MapManager* MapManager::create()
{
    MapManager* manager = new MapManager();
    if(manager && manager->init())
    {
        manager->autorelease();
        return manager;
    }
    CC_SAFE_DELETE(manager);
    return NULL;
}

MapManager::MapManager()
: _dic_tank(NULL)
, _dic_bullet(NULL)
{
    
}

MapManager::~MapManager()
{
    CC_SAFE_RELEASE_NULL(_dic_tank);
    CC_SAFE_RELEASE_NULL(_dic_bullet);
}

bool MapManager::init()
{
    if(CCNode::init())
    {
        this->initContains();
        this->addTileMap();
        this->addTankPlayer();
        
        return true;
    }
    return false;
}

void MapManager::initContains()
{
    _dic_tank = CCDictionary::create();
    _dic_tank->retain();
    _dic_bullet = CCDictionary::create();
    _dic_bullet->retain();
}

void MapManager::addTileMap()
{
    _tileMap = CCTMXTiledMap::create("Maps/map_demo.tmx");
    this->addChild(_tileMap);
    _tileMap->setScale(KFactor_TileMapScale);
    
    this->setContentSize(_tileMap->getContentSize() * KFactor_TileMapScale);
}

void MapManager::addTankPlayer()
{
    _tank_player = TankEntity::create(this);
    this->addChild(_tank_player);
    _tank_player->setPosition(this->getContentSize() * 0.5);
    
    this->addTank(_tank_player);
}

// public interface
void MapManager::updateTransform(float dt)
{
    // update tank transform
    CCDictElement* element_tank = NULL;
    CCDICT_FOREACH(_dic_tank, element_tank)
    {
        CCArray* arr_tank = dynamic_cast<CCArray*>(element_tank->getObject());
        for(int i = 0; i < arr_tank->count(); ++i)
        {
            TankEntity* tank = dynamic_cast<TankEntity*>(arr_tank->objectAtIndex(i));
            tank->updateTransform(dt);
        }
    }
    
    // update bullet transform
    CCDictElement* element_bullet = NULL;
    CCDICT_FOREACH(_dic_bullet, element_bullet)
    {
        CCArray* arr_bullet = dynamic_cast<CCArray*>(element_bullet->getObject());
        for(int i = 0; i < arr_bullet->count(); ++i)
        {
            BulletEntity* bullet = dynamic_cast<BulletEntity*>(arr_bullet->objectAtIndex(i));
            bullet->updateTransform(dt);
        }
    }
}

// manager entity interface
void MapManager::addTank(TankEntity *tank)
{
    CCArray* arr = dynamic_cast<CCArray*>(_dic_tank->objectForKey(tank->getGroup()));
    if(arr == NULL)
    {
        arr = CCArray::create();
        _dic_tank->setObject(arr, tank->getGroup());
    }
    if(arr->indexOfObject(tank) == CC_INVALID_INDEX)
        arr->addObject(tank);
}

void MapManager::removeTank(TankEntity *tank)
{
    CCArray* arr = dynamic_cast<CCArray*>(_dic_tank->objectForKey(tank->getGroup()));
    if(arr != NULL)
        arr->removeObject(tank);
}

void MapManager::addBullet(BulletEntity *bullet)
{
    CCArray* arr = dynamic_cast<CCArray*>(_dic_bullet->objectForKey(bullet->getGroup()));
    if(arr == NULL)
    {
        arr = CCArray::create();
        _dic_bullet->setObject(arr, bullet->getGroup());
    }
    if(arr->indexOfObject(bullet) == CC_INVALID_INDEX)
        arr->addObject(bullet);
}

void MapManager::removeBullet(BulletEntity *bullet)
{
    CCArray* arr = dynamic_cast<CCArray*>(_dic_bullet->objectForKey(bullet->getGroup()));
    if(arr != NULL)
        arr->removeObject(bullet);
}