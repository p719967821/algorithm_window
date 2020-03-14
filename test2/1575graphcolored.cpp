#include <iostream>

using namespace std;

int g[25][25];//用领接矩阵来表示图
int color[25];//表示涂过的颜色，0表示未图，1到m表示相应的颜色
int sum;
int n, r, m;

void dfs(int num);
bool canadd(int num);

int main()
{
    int  i, j, x, y;
    cin >> n >> r >> m;
    for(i = 0; i < r; i++)
    {
         cin >> x >> y;
         g[x][y] = 1;
         g[y][x] = 1;
    }
    dfs(0);
    cout << sum << endl;
    return 0;
}

bool canadd(int num)
{
    int i;
    for(i = 0; i < 25; i++)
    {
        if(g[num][i] == 1 && color[num] == color[i])
        {
            return false;
        }
    }
    return true;
}

void dfs(int num)
{
    int i;
    if(num == n)
    {
       sum++;
       return;
    }
    else
    {
        for(i = 1; i <= m; i++)
        {
            color[num] = i;
            if(canadd(num))
            {
                dfs(num + 1);
            }
            color[num] = 0;
        }
    }
}

