//
//  PanelDirectionControl.hpp
//  tank_multiplayer
//
//  Created by 李崧榕 on 16/2/26.
//
//

#ifndef PanelDirectionControl_hpp
#define PanelDirectionControl_hpp

#include "cocos2d.h"
USING_NS_CC;

class PanelDirectionControl : public CCNode
{
public:
    
    static PanelDirectionControl* create();
    
protected:
    
    PanelDirectionControl();
    virtual ~PanelDirectionControl();
    bool init();
    
protected:
    
    
};

#endif /* PanelDirectionControl_hpp */
