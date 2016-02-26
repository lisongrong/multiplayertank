//
//  Config.h
//  tank_multiplayer
//
//  Created by 李崧榕 on 16/2/26.
//
//

#ifndef Config_h
#define Config_h

const float KFactor_TileMapScale = 0.9f;
const int KCount_AnimateFrame = 4;
const float KInterval_Animate = 0.1f;

/**
 * 阵营枚举
 */
enum EGroup
{
    EGroup_None,
    EGroup_Player,
    EGroup_Oppose,
    EGroup_Ally,
};

/**
 * 动画枚举
 */
enum EAnimateType
{
    EAnimateType_None,
    EAnimateType_Walk,
};

/**
 * 方向枚举
 */
enum EDirection
{
    EDirection_None,
    EDirection_Up,
    EDirection_Down,
    EDirection_Left,
    EDirection_Right,
};

#endif /* Config_h */
