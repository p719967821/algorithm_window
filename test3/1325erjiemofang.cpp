#include <iostream>
#include <queue>

using namespace std;

struct node//用结构体的目的是为了queue入队时传入与传出
{
    int state[6][4];//代表魔方的六个面（上下左右前后），每个面分别从上到下，从左到右记为0123，后面的面的0123是通过前面的面透视看过去的状态定义的
    //int num[6];//代表每一位的四个数组成的二进制编码变成十进制的数
};

struct node a;
queue<node> q;

int main()
{
    int i,j,num;
    for(i = 0; i < 6; i++)//这里输入可能有问题
    {
        for(j = 0; j < 4; j++)
        {
            cin >> a.state[i][j];
        }
    }
    q.push(a);
    num = bfs();
    cout << num << endl;
    return 0;
}

int bfs()
{
    int i;
    struct node x,y;
    while(!q.empty())
    {
        x =  q.front();
    }
}

