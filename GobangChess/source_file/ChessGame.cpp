//
// Created by 30682 on 2022/11/12.
//

#include "../header_file/ChessGame.h"



ChessGame::ChessGame(Man *man, AI *ai, Chess *chess) {
    this->man = man;
    this->ai = ai;
    this->chess = chess;
}

/**
 * 对局   开始游戏
 * */
void ChessGame::play()
{

    chess->init();

    while (1)
    {
        //先由棋手走棋
        man->go();
        if (chess->checkOver())
        {
            chess->init();
            continue;
        }

        //再由AI走棋
        ai->go();
        if (chess->checkOver())
        {
            chess->init();
            chess->checkOver();
        }
    }
}


