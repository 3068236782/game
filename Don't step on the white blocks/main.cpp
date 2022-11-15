#include <easyx.h>      //图形库,绘制图形,输出文字
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



#define INTERVAL 100        //上面现实标题的高度
#define GRID_W 100
#define GRID_H 150


//定义数组用来存储黑块
int flags[] = {2,1,0,3};
//统计成功点了多少个黑块
int gCount = 0;


void init()
{
    //设置随机数种子
    srand(time(NULL));

    //随机生成黑块
    for (int i = 0; i < 4; i++) {
        flags[i] = rand()%4;        //  0   1   2   3
    }
}

void draw()
{
     setlinestyle(PS_SOLID,2);

     //线条的颜色默认是白色
     setlinecolor(BLACK);

    for (int i = 0; i < 5; i++) {
        //画横线
        line(0,i*GRID_H+INTERVAL,400,i*GRID_H+INTERVAL);
        //画竖线
        line(i*GRID_W,INTERVAL,i*GRID_W,700);
    }

    //设置文字样式
    settextstyle(38,0,"Arial");
    //设置文字颜色
    settextcolor(BLACK);

    //输出标题
//    printf("别踩白块儿");
    const char* title = "别踩白块儿";
    int spaceH = (getwidth()-textwidth(title))/2;
    int spaceV = (INTERVAL-textheight(title))/2;
    outtextxy(spaceH,spaceV,title);



    setfillcolor(BLACK);
    //根据flags数组绘制黑块
    for (int i = 0; i < 4; i++) {
        //求出黑块的左上角的坐标
        int x = flags[i]*GRID_W;
        int y = flags[i]*GRID_H+INTERVAL;
        if (i == 3) setfillcolor(RGB(156,156,156));
        //绘制一个矩形
        fillrectangle(x,y,x+GRID_W,y+GRID_H);
    }


    settextstyle(26,0,"微软雅黑");
    char score[30] = {0};
//    sprintf_s(score,"Score:%d",gCount);
    //输出分数
    outtextxy(20,40,score);
}


//处理鼠标点击
bool mousePressMsg(ExMessage* msg)
{
    //获取下标为2的黑块的坐标
    int x = flags[2]*GRID_W;
    int y = 2 * GRID_H+INTERVAL;

    //判断是不是点击下标为2的黑块
    if (msg->x>x && msg->x<x + GRID_W && msg->y>y && msg->y<y+GRID_H)
    {
        //黑块从上往下移动
        for (int i = 3;i>0;i--) flags[i] = flags[i-1];
        flags[0] = rand() % 4;
        gCount++;
        printf("你点击了正确的黑块\n");
        return true;
    }
    return false;
}

void gameOverHit(int w, int h)
{
    setlinecolor(GREEN);
    setfillcolor(RGB(93,107,153));

    //画一个矩形
    int spaceH = (getwidth() - w)/2;
    int spaceV = (getheight() - h)/2;

    fillrectangle(spaceH,spaceV,spaceH+w,spaceV+h);

    outtextxy(spaceH,spaceV,"GameOver!!!Bye~~");
}


int main()
{
    //图形窗口
    initgraph(400, 700, 0);
    //设置背景颜色
    setbkcolor(WHITE);
    cleardevice();
    setbkmode(TRANSPARENT);
    init();

    ExMessage msg = {0};
    //游戏主循环
    bool isDone = false;
    while (!isDone)
    {
        //消息处理
        if (peekmessage(&msg))
               switch (msg.message) {
                case WM_KEYDOWN:
                    if (msg.vkcode == VK_ESCAPE)
                    {
                        printf("quit\n");
                        isDone = true;
                    }
                    break;
                case WM_LBUTTONDOWN:
                    if (!mousePressMsg(&msg))   isDone = true;
                    break;
            }

        //绘制
        BeginBatchDraw();
        cleardevice(); //清屏
        draw();

        EndBatchDraw();
    }

    gameOverHit(200,100);
    getchar();

    return 0;

}


