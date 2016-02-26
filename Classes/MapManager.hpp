//
//  MapManager.hpp
//  tank_multiplayer
//
//  Created by 李崧榕 on 16/2/26.
//
//

#ifndef MapManager_hpp
#define MapManager_hpp

#include "cocos2d.h"
USING_NS_CC;

class TankEntity;
class BulletEntity;

class MapManager : public CCNode
{
public:
    
    static MapManager* create();
    
    // public interface
    void updateTransform(float dt);
    
    // manage entity interface
    void addTank(TankEntity* tank);
    void removeTank(TankEntity* tank);
    void addBullet(BulletEntity* bullet);
    void removeBullet(BulletEntity* bullet);
    
protected:
    
    MapManager();
    virtual ~MapManager();
    bool init();
    
    void initContains();
    void addTileMap();
    void addTankPlayer();
    
protected:
    
    CCTMXTiledMap* _tileMap;
    
    TankEntity* _tank_player;
    
    CCDictionary* _dic_tank;
    CCDictionary* _dic_bullet;
};

#endif /* MapManager_hpp */
