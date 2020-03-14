#include <iostream>

using namespace std;

int c1,c2,n;
int a[11];//a[i]代表第i个物品的重量
int v[10000];//代表动态规划的数组
int c[10000];//将每组数据的结果先记录下来，放在c中
int m;//m代表共输入了多少组数据

void judge(int x)//x代表c1中最大能装多少东西
{
    int i,sum = 0,b;
    for(i = 1; i <= n; i++)
    {
        sum += a[i];
    }
    b = sum - x;
    if(b > c2)
    {
        c[m] = 0; 
    }
    else
    {
        c[m] = 1;
    }
    m++;
}

void canplace()
{
    int i,j;
    for(i = 1; i <= n; i++)
    {
        for(j = c1; j >= 0; j--)//注意要倒叙
        {
            if(j >= a[i] && v[j] < v[j - a[i]] + a[i])
            {
                v[j] = v[j - a[i]] + a[i];
            }
        }
    }
    judge(v[c1]); 
    for(i = 1; i <= c1; i++)//因为是全局变量，所以要清零，保证各项之间不影响
    {
        v[i] = 0;
    }
}

int main()
{
    int i;
    while(1)
    {
        cin >> c1 >> c2 >> n;
        if(c1 == 0 && c2 == 0 && n == 0)
        {
            for(i = 0; i < m; i++)
            {
                if(c[i] == 0)
                {
                    cout << "No" << endl;
                }
                else
                {
                    cout << "Yes" << endl;
                }
                
            }
            return 0;
        }
        else
        {
            for(i = 1; i <= n; i++)
            {
                cin >> a[i];
            }
            canplace();
        }
        
    }
}