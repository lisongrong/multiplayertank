//
//  BulletEntity.hpp
//  tank_multiplayer
//
//  Created by 李崧榕 on 16/2/26.
//
//

#ifndef BulletEntity_hpp
#define BulletEntity_hpp

#include "Entity.hpp"

class MoveComponent;

class BulletEntity : public Entity
{
public:
    
    static BulletEntity* create(MapManager* mapManager);
    
    // override
    virtual void updateTransform(float dt);
    
    void shoot(float speed, EDirection dir);
    
protected:
    
    BulletEntity();
    virtual ~BulletEntity();
    bool init(MapManager* mapManager);
    
    void addDisplay();
    void addMoveComponent();
    
protected:
    
    MoveComponent* _moveComponent;
};

#endif /* BulletEntity_hpp */
