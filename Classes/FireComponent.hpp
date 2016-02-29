//
//  FireComponent.hpp
//  tank_multiplayer
//
//  Created by 李崧榕 on 16/2/26.
//
//

#ifndef FireComponent_hpp
#define FireComponent_hpp

#include "cocos2d.h"
USING_NS_CC;
#include "Config.h"

class FireComponentDelegate
{
public:
    virtual void fire() = 0;
};

class FireComponent : public CCNode
{
public:
    
    static FireComponent* create(FireComponentDelegate* delegate);
    
    void updateTransform(float dt);
    
    // get && set
    inline void setFireInterval(float interval) { _time_interval = interval;}
    
protected:
    
    FireComponent();
    virtual ~FireComponent();
    bool init(FireComponentDelegate* delegate);
    
protected:
    
    FireComponentDelegate* _delegate;
    
    float _time_interval;
    float _time_free;
};

#endif /* FireComponent_hpp */
