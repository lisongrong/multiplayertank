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

class BulletEntity : public Entity
{
public:
    
    static BulletEntity* create(MapManager* mapManager);
    
    void shoot(CCPoint speed);
    
protected:
    
    BulletEntity();
    virtual ~BulletEntity();
    bool init(MapManager* mapManager);
    
protected:
    
    
};

#endif /* BulletEntity_hpp */
