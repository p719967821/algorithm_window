#include <iostream>
#define N 101
using namespace std;

int n;
int a[N];//代表输入的数组
int dp[N];//代表每个位置上当前所有的最长减序列的个数
int tem[N];//代表每一次的最长减序列的个数，跟着外循环会不断的刷新
int k;//记输入的多少次

void init();

int main()
{
    int i,j;
    while(cin >> n && n)
    {
    for(i = 0; i < n; i++) 
    {
        cin >> a[i];
    }
    init();
    tem[k] = 1;
    for(i = n - 1; i >= 0; i--)
    {
        for(j = n - 1; j >= i; j--)//循环一遍后找到第i个数的最大减序列
        {
            if(a[i] >= a[j] && i != j)
            {
                dp[i] = max(dp[j] + 1,dp[i]);
            }
        }
        tem[k] = max(tem[k], dp[i]);
    }
    k++;
    }
    for(i = 0; i < k; i++)
    {
        cout << tem[i] << endl; 
    }
    return 0;
}

void init()
{
    for(int i = 0; i < n; i++)//起始状态是最长减序列的个数都为一，自己
    {
        dp[i] = 1;
    }
}