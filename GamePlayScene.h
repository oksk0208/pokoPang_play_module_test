#ifndef __pokoPang_play_module__GamePlayScene__
#define __pokoPang_play_module__GamePlayScene__

#include <iostream>
#include "cocos2d.h"
#include "GameCoin.h"
#include "Global.h"

class GamePlayScene : public cocos2d::CCLayer
{
private:
    CCArray* _gameCoins;
    
public:
    enum {
        BOARDX = 6,
        BOARDY = 6,
        TOTALCOINTYPE = 5,
    };
    
    virtual bool init();
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    CREATE_FUNC(GamePlayScene);
    
    ~GamePlayScene(void);
    
    void initGameCoin(void);
    GameCoin* createGameCoin(const CCPoint &pos, int type, int state);
};

#endif /* defined(__pokoPang_play_module__GamePlayScene__) */
//
