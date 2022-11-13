//
// Created by 30682 on 2022/11/12.
//

#ifndef TEST_CHESSGAME_H
#define TEST_CHESSGAME_H


#include "Man.h"
#include "AI.h"

class ChessGame
{
public:

    ChessGame(Man* man, AI* ai, Chess* chess);

    [[noreturn]] void play(); //开始对局

private:
    Man* man;
    AI* ai;
    Chess* chess;
};


#endif //TEST_CHESSGAME_H
