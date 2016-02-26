//
//  TankEntity.hpp
//  tank_multiplayer
//
//  Created by 李崧榕 on 16/2/26.
//
//

#ifndef TankEntity_hpp
#define TankEntity_hpp

#include "Entity.hpp"
#include "FireComponent.hpp"

class TankEntity : public Entity, public FireComponentDelegate
{
public:
    
    static TankEntity* create(MapManager* mapManager);
    
    // override
    virtual void updateTransform(float dt);
    virtual void fire();
    
protected:
    
    TankEntity();
    virtual ~TankEntity();
    bool init(MapManager* mapManager);
    
    void addDisplay();
    void addFireComponent();
    
protected:
    
    FireComponent* _fireComponent;
};

#endif /* TankEntity_hpp */
