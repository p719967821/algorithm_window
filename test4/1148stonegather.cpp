/*************************
 1.对于突然插入的变量（起for循环中i的功能）用完一定要注意清零

**************************/
#include <iostream>
#include <limits.h>
#define N 50

using namespace std;

int n;
int a[N];
int memo[N][N];
int mincout[N];
int times;

void init();
void dp();

int main()
{
    int i;
    for(i = 0; i < N; i++)
    {
       mincout[i] = INT_MAX;
    }
    while (cin >> n && n) 
    {
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if(n==1)
        {
            mincout[times] = 0;
            times++;
        }
        else
        {
            init();
            dp();
            times++;
        }
    }
    for(i = 0; i < times; i++)
    {
        cout << mincout[i] << endl;
    }
    return 0;
}

void init()
{
    int i,j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j)
            {
                memo[i][j] = 0;
            }
            else
            {
                memo[i][j] = INT_MAX;
            }
            
        }
    }
}

void dp()
{
    int len,l = 0,i,j,k,x = 0,y;
    for(len = 1; len < n; len++)
    {
        for(i = 0,j = i + len;l != n; i++,j++)//用l来代替循环，每次都要循环n次
        {
            for(y = i; y <= j; y++)//算出i到j这一段的和
            {
                x += a[y % n];
            }
            for(k = i; k < j; k++)
            {
                memo[i][j % n] = min(memo[i][j % n],memo[i][k % n] + x + memo[(k+1) % n][j % n]);
            }
            l++;
            x = 0;//用这种变量时一定要注意清零
        }
        l = 0;
    }
    for(i = 0; i < n; i++)//因为是循环，所以得在最大的几个原问题中找出最小值
    {
        mincout[times] = min(mincout[times],memo[i][(i+n-1)%n]);
    }
}
