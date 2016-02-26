//
//  GameScene.hpp
//  tank_multiplayer
//
//  Created by 李崧榕 on 16/2/26.
//
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include "cocos2d.h"
USING_NS_CC;

class MapManager;

class GameScene : public CCLayer
{
public:
    
    static CCScene* scene();
    
    // override
    virtual void onEnter();
    virtual void onEnterTransitionDidFinish();
    virtual void onExit();
    virtual bool ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent);
    
    virtual void update(float dt);
    
    // game about
    void startGame();
    
protected:
    
    static GameScene* create(CCScene* scene);
    
    GameScene();
    virtual ~GameScene();
    bool init(CCScene* scene);
    
    void addManager();
    
protected:
    
    CCScene* _scene;
    CCSize _screenSize;
    MapManager* _mapManager;
};

#endif /* GameScene_hpp */
