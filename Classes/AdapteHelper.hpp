//
//  AdapteHelper.hpp
//  GameTemplate
//
//  Created by 李崧榕 on 15/11/6.
//
//

#ifndef AdapteHelper_hpp
#define AdapteHelper_hpp

#include "cocos2d.h"
USING_NS_CC;

enum EScreenProfile
{
    EScreenProfile_1280_720,  // 1.78      iphone 5s/iphone 6/iphone 6plus 960 * 540
    EScreenProfile_800_480,   // 1.6666666
    EScreenProfile_960_640,   // 1.5       iphone 4
    EScreenProfile_1024_768,  // 1.3333333 ipad
};

class AdapteHelper
{
public:
    
    // ScreenProfile
    static void registScreenProfile(CCSize size_screen);
    static inline EScreenProfile getScreenProfile(){return _profile_screen;}
    
private:
    
    static EScreenProfile _profile_screen;
};

#endif /* AdapteHelper_hpp */
