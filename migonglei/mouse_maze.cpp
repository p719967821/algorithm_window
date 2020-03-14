#include <iostream>
#include <queue>

using namespace std;

int a[13][13];//代表迷宫，只用1到12，其中0代表路，1代表墙
int step[12][12];//代表走到要的步数
queue<int> q;

int moveto(int u, int dir)
{
    int row,column;
    row = u / 12 + 1;
    column = u % 12; 
    switch(dir)
    {
      case 0:{
               ++row; 
               return (row-1)*12+column;//向下
             }
      case 1:{
               --column; 
               return (row-1)*12+column;//向左
             }
      case 2:  {
               ++column; 
               return (row-1)*12+column;//向右
             }
      case 3:{
               --row; 
               return (row-1)*12+column;//向上
             }             
    }
}

int searchroad(int x1, int x2, int y1, int y2)
{
    int i,m1,m2,v,u,sr,sc;
    m1 = (x1-1) * 12 + y1;
    m2 = (x2-1) * 12 + y2;
    step[x1][y1] = 1;
    q.push(m1);
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(i=0; i<4; i++)
        {
            v = moveto(u,i);
            sr = v / 12 + 1;
            sc = v % 12;
            if(sr>0 && sr<13 && sc>0 && sc<13 && v==m2)
            {
                return step[u/12+1][u%12]+1;
            }
            if(sr>0 && sr<13 && sc>0 && sc<13 && a[sr][sc]==0 && step[sr][sc]==0)//避免出界,有路，不回找
            {
                q.push(v);
                step[sr][sc] = step[u/12+1][u%12] + 1;
            }
        }
    }
}

int main()
{
    int x1,x2,y1,y2,key,i,j;
    char x;
    cin >> x1 >> y1 >> x2 >> y2;
    for(i=0; i<12; i++)
      for(j=0; j<12; j++)
        {
            cin >> x;
            if(x == 'X') a[i+1][j+1] = 1;
            else a[i+1][j+1] = 0;
        }
    key = searchroad(x1,x2,y1,y2);
    cout << key << endl;
    return 0;
}