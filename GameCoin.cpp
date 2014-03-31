
#include "GameCoin.h"

GameCoin::~GameCoin()
{
}

GameCoin::GameCoin()
:   _type(0),
_state(GameCoin::LIVE)
{
}

GameCoin* GameCoin::spriteWitheFile(const char* pszFileName)
{
    GameCoin* sprite = new GameCoin();
    if( sprite && sprite->initWithFile(pszFileName)) {
        sprite->autorelease();
        return sprite;
    }
    
    CC_SAFE_DELETE(sprite);
    return NULL;
    
    //테스트다다다
    //
}