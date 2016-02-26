//
//  GameScene.cpp
//  tank_multiplayer
//
//  Created by 李崧榕 on 16/2/26.
//
//

#include "GameScene.hpp"
#include "MapManager.hpp"

CCScene* GameScene::scene()
{
    CCScene* scene = CCScene::create();
    GameScene* game = GameScene::create(scene);
    scene->addChild(game);
    return scene;
}

GameScene* GameScene::create(cocos2d::CCScene *scene)
{
    GameScene* game = new GameScene();
    if(game && game->init(scene))
    {
        game->autorelease();
        return game;
    }
    CC_SAFE_DELETE(game);
    return NULL;
}

GameScene::GameScene()
{
    
}

GameScene::~GameScene()
{
    
}

bool GameScene::init(cocos2d::CCScene *scene)
{
    if(CCLayer::init())
    {
        _scene = scene;
        _screenSize = CCDirector::sharedDirector()->getWinSize();
        
        this->addManager();
        
        return true;
    }
    return false;
}

void GameScene::addManager()
{
    _mapManager = MapManager::create();
    this->addChild(_mapManager);
    
    _mapManager->setPosition(ccp((_screenSize.width - _mapManager->getContentSize().width) * 0.5, _screenSize.height - 50 - _mapManager->getContentSize().height));
}

// override
void GameScene::onEnter()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    CCLayer::onEnter();
}

void GameScene::onEnterTransitionDidFinish()
{
    CCLayer::onEnterTransitionDidFinish();
    
    this->startGame();
}

void GameScene::onExit()
{
    CCLayer::onExit();
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

bool GameScene::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    return true;
}

void GameScene::update(float dt)
{
    _mapManager->updateTransform(dt);
}

// game about
void GameScene::startGame()
{
    this->scheduleUpdateWithPriority(0);
}