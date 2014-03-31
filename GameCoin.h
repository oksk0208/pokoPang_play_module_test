
#ifndef __pokoPang_play_module__GameCoin__
#define __pokoPang_play_module__GameCoin__

#include <iostream>
#include "cocos2d.h"

using namespace cocos2d;

class GameCoin : public CCSprite
{
private:
    
public:
    enum gameState {
        LIVE,
        DEAD,
        SELCECT,
    };
    
    CC_SYNTHESIZE(int, _type, Type);
    CC_SYNTHESIZE(int, _state, State);
    
    static GameCoin* spriteWitheFile(const char* pszFileName);
    
    
    GameCoin();
    ~GameCoin();
    //
};


#endif /* defined(__pokoPang_play_module__GameCoin__) */
