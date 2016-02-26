//
//  Entity.cpp
//  tank_multiplayer
//
//  Created by 李崧榕 on 16/2/26.
//
//

#include "Entity.hpp"
#include "Display.hpp"
#include "MapManager.hpp"

Entity::Entity()
: _mapManager(NULL)
, _group(EGroup_None)
, _dir(EDirection_None)
, _display(NULL)
{
    
}

Entity::~Entity()
{
    
}

bool Entity::init(MapManager* mapManager)
{
    if(CCNode::init())
    {
        _mapManager = mapManager;
        
        return true;
    }
    return false;
}

void Entity::updateTransform(float dt)
{
    
}