#include "GamePlayScene.h"

USING_NS_CC;

CCScene* GamePlayScene::scene()
{
    CCScene *scene = CCScene::create();
    GamePlayScene *layer = GamePlayScene::create();
    scene->addChild(layer);
    return scene;
}

bool GamePlayScene::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    // =========== set background ===========
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    CCPoint kValue;
    kValue.setPoint(visibleSize.width / baseWidth, visibleSize.height / baseHeight);
    
    CCSprite* pSprite = CCSprite::create("pokopang_back.png");
    pSprite->CCNode::setScale(kValue.x, kValue.y);
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pSprite, 0);
    // ---------- set background ------------
    
    initGameCoin();
    
    return true;
}

GamePlayScene::~GamePlayScene()
{
    CC_SAFE_RELEASE(_gameCoins);
}

void GamePlayScene::initGameCoin()
{
    int coinXPos = 0;
    int coinYPos = 0;
    int diffX = 104;
    int diffY = 120;
    int initCoinXPos = 72;
    int initCoinYPos = 778;
    
    GameCoin* gameCoin;
    
    // init array
    _gameCoins = CCArray::createWithCapacity(BOARDX * BOARDY);
    _gameCoins->retain();
    
    // init gameCoin
    for( int xIndex = 0; xIndex < BOARDX; xIndex++){
        coinXPos = initCoinXPos + (xIndex * diffX);
        coinYPos = initCoinYPos;
        if(xIndex % 2 == 0)
            coinYPos -= diffY/2;
        
        for(int yIndex = 0; yIndex < BOARDY; yIndex++) {
            gameCoin = createGameCoin(ccp(coinXPos, coinYPos),
                                      rand() % TOTALCOINTYPE + 1,
                                      GameCoin::LIVE);
            
            _gameCoins->addObject(gameCoin);
            
            coinYPos -= diffY;
        }
    }
}

GameCoin* GamePlayScene::createGameCoin(const CCPoint &pos, int type, int state)
{
    
    GameCoin* gameCoin;
    CCString* name;

    name = CCString::createWithFormat("coin_0%i.png", type);
    gameCoin = GameCoin::spriteWitheFile(name->getCString());
    gameCoin->setVisible(true);
    gameCoin->setPosition(pos);
    gameCoin->setState(state);
    gameCoin->setType(type);
    this->addChild(gameCoin);
    
    return gameCoin;
    //
}


