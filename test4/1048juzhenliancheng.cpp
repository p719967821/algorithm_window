/********************************
    1. 一开始没有看到Ai与Ai+1是可乘的这句话，还把这个题当成是线性的，是一个个独立的，所以用了memo【】是错误的，因为连乘是两个矩阵之间才能表现的，
       所以得用二位memo【】【】，来代表矩阵之间的连乘
    2.真正明白了，从原问题向子问题分析，写代码时从子问题向原问题写的意思。这是动态规划的精髓，因为动态规划问题都是最简单的问题可以直接写出，然后
      一系列可以写出的子问题可以在解决一个次子问题，最后就能到达原问题，而写代码的这个过程就是通过几个for循环表示的，所以在写代码时要想的就是通过
      几个for循环包裹之后最中心的把最简单的问题解决就行了。
    3.还有就是这个题最关键的一点，memo中存的是连乘，所以是用【i】【k】部分+【k】【k+1】部分+【k+1】【j】部分，而【k】【k+1】部分
      就是（k的行）*（k的列）*（k+1的行）
**********************************/
#include <iostream>
#include <limits.h>
#define N 10

using namespace std;

int n;
int row[N],col[N];
int memo[N][N];

void init();
void dp();

int main()
{
    int i;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> row[i] >> col[i];
    }
    init();
    dp();
    return 0;
}

void init()
{
    int i,j;
    for (i = 0; i < n; i++)
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
    int len,i,j,k;//代表i，j之间各的距离
    for(len = 1; len < n; len++)
    {
        for(i = 0,j = len +i; j < n; i++,j++)
        {
            for(k = i; k < j; k++)
            {
                memo[i][j] = min(memo[i][j],memo[i][k]+row[i]*col[k]*col[j]+memo[k+1][j]);//相乘时用row【i】，是因为k截断处的前半部分看成一
            }                                                                             //个整体时，对切断部分的乘积第一个就是row【i】的行
        }
    }
    cout << memo[0][n-1] << endl;
}


/********递归*********
#include <iostream>
#define N 100

using namespace std;

int s[N][N];
int p[N];//p从0到n可以代表n个矩阵的行和列，p0，p1为第一个矩阵的行和列，p1，p2为第二个矩阵的行和列

int chain(int i ,int j);

int main()
{
    int n,y;
    cin >> n;
    for(int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }
    y = chain(1,n);
    return 0;
}

int chain(int i ,int j)
{
    if(i == j)return 0;
    int u =chain(i+1,j)+p[i-1]*p[i]*p[j];
    s[i][j] = i;
    for(int k = i + 1; k < j; k++)
    {
        int t =chain(i,k)+p[i-1]*p[k]*p[j]+chain(k+1,j);
        if(t < u)
        {
            u = t;
            s[i][j] = k;
        }
    }
    return u;
}
*******************/


/********备忘录*********
#include <iostream>
#define N 100

using namespace std;

int s[N][N];
int p[N];

int chain(int i ,int j);

int main()
{
    int n,y;
    cin >> n;
    for(int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }
    y = chain(1,n);
    return 0;
}

int chain(int i ,int j)
{
    if(s[i][j] > 0)return (s[i][j]);
    if(i == j)return 0;
    int u =chain(i+1,j)+p[i-1]*p[i]*p[j];
    s[i][j] = i;
    for(int k = i + 1; k < j; k++)
    {
        int t =chain(i,k)+p[i-1]*p[k]*p[j]+chain(k+1,j);
        if(t < u)
        {
            u = t;
            s[i][j] = k;
        }
    }
    s[i][j] = u;
    return u;
}
*******************/