#include <iostream>
#include <queue>

using namespace std;


int sw,ew;//开始和结束的位置
int used[40000];
int step[40000];//记录到这个位置已经走了多少步
int times;
int dirw[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};//代表不同的八个方向
queue<int> q;

int bfs();
bool cango(int x, int dir);
int go(int x, int dir);

int main()
{
    int n,k,i,sr,sc,er,ec,num[10001];
    cin >> n;
    for(k = 0; k < n; k++)
    {
        cin >> sr >> sc;
        cin >> er >> ec;
        sw = (sr - 1) * 200 + (sc - 1);
        ew = (er - 1) * 200 + (ec - 1);
        times++;
        q.push(sw);
        used[sw] = 1;
        num[times] = bfs();
    }
    for(i = 1; i <= times; i++)
    {
        cout << num[i] << endl;
    }
    return 0;
}

int bfs()
{
    int i,x,y;
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        for(i = 0; i < 8; i++)
        {
            if(cango(x,i))
            {
                y = go(x,i);
                if(y == ew)
                {
                    return  (step[x] + 1);
                }
                used[x] = 1;
                q.push[x];
                step[y] = step[x] + 1;
            }
        }
    }
    return -1;
}

bool cango(int x, int dir)
{
    int row,col,n;
    row = x / 200 + dirw[dir][0];
    col = x % 200 + dirw[dir][1];
    n = row * 200 + col;
    if(row >= 0 && row < 200 && col >= 0 && col < 200 && used[n] == 0)
    {
        return true;
    }
    else
    {
        return false; 
    }
    
}

int go(int x, int dir)
{
    int row,col;
    row = x / 200 + dirw[dir][0];
    col = x % 200 + dirw[dir][1];
    return (row * 200 + col);
}