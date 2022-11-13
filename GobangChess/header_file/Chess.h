//
// Created by 30682 on 2022/11/12.
//

#ifndef TEST_CHESS_H
#define TEST_CHESS_H

/**
 * 棋盘的行  列   棋盘中的位置
 * */
struct ChessPos{
    int row;
    int col;
};

/**
 * 棋子的分类
 * */
typedef enum {
    CHESS_WHITE = -1, //白棋
    CHESS_BLACK = 1, //黑棋
}chess_kind_t;


class Chess
{
public:
    void init();//初始化，加载相关资源

    bool clickBoard(int x, int y,ChessPos* pos); //检查是否有效点击

    void chessDown(ChessPos *pos, chess_kind_t kind); //棋盘的位置 pos  落子 kind

    int getGradeSize(); //获取棋盘大小（13，15，19）

    //获取指定位置的棋子
    int getChessData(ChessPos* pos);

    int getChessData(int row, int col);

    bool checkOver(); //检查棋局是否结束


};


#endif //TEST_CHESS_H
