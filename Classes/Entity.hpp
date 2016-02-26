//
//  Entity.hpp
//  tank_multiplayer
//
//  Created by 李崧榕 on 16/2/26.
//
//

#ifndef Entity_hpp
#define Entity_hpp

#include "cocos2d.h"
USING_NS_CC;
#include "Config.h"

class MapManager;
class Display;

class Entity : public CCNode
{
public:
    
    inline EGroup getGroup() { return _group;}
    
    virtual void updateTransform(float dt);
    
protected:
    
    Entity();
    virtual ~Entity();
    bool init(MapManager* mapManager);
    
protected:
    
    MapManager* _mapManager;
    
    EGroup _group;
    EDirection _dir;
    
    Display* _display;
};

#endif /* Entity_hpp */
