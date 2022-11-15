//
// Created by 30682 on 2022/11/12.
//

#include "../header_file/ChessGame.h"

int main(void )
{
    Man man;
    Chess chess;
    AI ai;
    ChessGame game(&man, &ai, &chess);

    game.play();

    return 0;

}