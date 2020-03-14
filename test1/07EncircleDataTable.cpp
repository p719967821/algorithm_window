#include <iostream>

using namespace std;

void gametable(int n)
{
    int i, j, k,sum = 2;
    int a[150][150];
    //初始化只有两个人的情况，可以直接给出
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 2;
    a[1][1] = 1;
    for(k = 1; k < n; k++)
    {
        //先计算2^k
        for(i = 0; i < k - 1; i++)
        {
            sum *= 2;
        }
        //写出左下角
        for(i = 0; i < sum; i++)
         for(j =0; j < sum; j++)
         {
             a[i+sum][j] = a[i][j] + sum;
         }
         //把左下角写到右上角
        for(i = 0; i < sum; i++)
         for(j =0; j < sum; j++)
         {
             a[i][j+sum] = a[i+sum][j];
         }
         //把左上角写到右下角
       for(i = 0; i < sum; i++)
         for(j =0; j < sum; j++)
         {
             a[i+sum][j+sum] = a[i][j];
         }
         sum = 2;
    }
    //输出
    for(i = 0; i < n - 1; i++)
        {
            sum *= 2;
        }
    for(i = 0; i < sum; i++)
     {
        for(j =0; j < sum; j++)
        {
         cout << a[i][j] << " ";
        }
        cout << endl;
     }
}

int main()
{
    int n;
    cin >> n;
    gametable(n);
    return 0;
}