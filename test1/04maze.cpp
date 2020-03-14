#include <iostream>
#define N 20

using namespace std;

int m,n;
int a[N][N];
int sr,sc;//起始点的行和列
int er,ec;//终止点的行和列
int flag = 0;

bool cango(int x,int y)
{
    if(x < m && x >= 0 && y < n && y >= 0 && a[x][y] == 0)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

void go(int nr,int nc)
{
    if(nr == er && nc == ec)
    {
        flag = 1;
    }
    else
    {
        a[nr][nc] = 2;
       if(cango(nr-1,nc))//上
       go(nr-1,nc);
       if(cango(nr,nc+1))//右
       go(nr,nc+1);
       if(cango(nr+1,nc))//下
       go(nr+1,nc);
       if(cango(nr,nc-1))//左
       go(nr,nc-1);
    }
}

int main()
{
    int i,j;
    cin >> m >> n;
    cin >> sr >> sc;
    cin >> er >> ec;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            {
               cin >> a[i][j];
            }
    go(sr,sc);
    if(flag == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
