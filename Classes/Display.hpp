//
//  Display.hpp
//  tank_multiplayer
//
//  Created by 李崧榕 on 16/2/26.
//
//

#ifndef Display_hpp
#define Display_hpp

#include "cocos2d.h"
USING_NS_CC;
#include "Config.h"

class Display : public CCNode
{
public:
    
    static Display* createAnimation(std::string name);
    static Display* createSprite(std::string name);
    
    void playWalkAnimation(EDirection dir);
    
protected:
    
    Display();
    virtual ~Display();
    bool initAnimation(std::string name);
    bool initSprite(std::string name);
    
    std::string getAnimationKey(EAnimateType type, EDirection dir);
    
protected:
    
    CCSprite* _content;
    CCDictionary* _dic_animate;
};

#endif /* Display_hpp */
