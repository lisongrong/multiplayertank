//
//  AdapteHelper.cpp
//  GameTemplate
//
//  Created by 李崧榕 on 15/11/6.
//
//

#include "AdapteHelper.hpp"

EScreenProfile AdapteHelper::_profile_screen = EScreenProfile_1280_720;

void AdapteHelper::registScreenProfile(cocos2d::CCSize size_screen)
{
    float k_1280_720 = 1280.0f / 720.f;  // 1.78
    float k_800_480 = 800.0f / 480.0f;   // 1.66666
    float k_960_640 = 960.0f / 640.0f;   // 1.5
    float k_1024_768 = 1024.0f / 768.0f; // 1.3333
    
    float k_screen = size_screen.width / size_screen.height;
    
    if(k_screen >= (k_1280_720 + k_800_480) * 0.5)
    {
        _profile_screen = EScreenProfile_1280_720;
    }
    else if(k_screen >= (k_800_480 + k_960_640) * 0.5)
    {
        _profile_screen = EScreenProfile_800_480;
    }
    else if(k_screen >= (k_960_640 + k_1024_768) * 0.5)
    {
        _profile_screen = EScreenProfile_960_640;
    }
    else
    {
        _profile_screen = EScreenProfile_1024_768;
    }
    
    // aply adapte setting
    if(_profile_screen == EScreenProfile_1024_768) // ipad
    {
        CCEGLView::sharedOpenGLView()->setDesignResolutionSize(640, 1136, kResolutionShowAll);
    }
    else // normal
    {
        CCEGLView::sharedOpenGLView()->setDesignResolutionSize(640, 1136, kResolutionFixedWidth);
    }
}