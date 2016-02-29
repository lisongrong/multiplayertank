//
//  MoveComponent.hpp
//  tank_multiplayer
//
//  Created by 李崧榕 on 16/2/26.
//
//

#ifndef MoveComponent_hpp
#define MoveComponent_hpp

#include "cocos2d.h"
USING_NS_CC;
#include "Config.h"

class MoveComponent : public CCNode
{
public:
    
    static MoveComponent* create(CCNode* target);
    
    void updateTransform(float dt);
    
    // public interface
    inline void start() { _in_move = true;}
    inline void stop() { _in_move = false;}
    inline void pause() { _in_pause = true;}
    inline void resume() { _in_pause = false;}
    
    // get && set
    inline void setSpeedValue(float speed) { _speed = speed;}
    void setSpeedDirection(EDirection dir);
    void setSpeed(CCPoint speed);
    
protected:
    
    MoveComponent();
    virtual ~MoveComponent();
    bool init(CCNode* target);
    
protected:
    
    CCNode* _target;
    float _speed;
    CCPoint _speed_dir;
    
    bool _in_pause;
    bool _in_move;
};

#endif /* MoveComponent_hpp */
