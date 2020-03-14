#include <iostream>
#define N 11
using namespace std;

int n,c,m;
int v[N];
int w[N];
int p[N];
int record[1000];//用于储存数据，便于一次全部输出

void bag()
{
    int i,j;
    //清零v，防止不同数据之间的干扰
    for(i = 0; i < N; i++)
    {
        v[i] = 0;
    }
    for(i = 1; i <= n; i++)
    {
        for(j = c; j >= 1; j--)//一定要注意逆序
        {
            if(j >= w[i] && v[j] < v[j-w[i]]+ p[i])
            {
                v[j] = v[j-w[i]] + p[i];
            }
        }
    }
    record[m] = v[c]; 
    m++;
}

int main()
{
    int i;
    while (1)
    {
        cin >> n >> c;
        if(n != 0 && c != 0)
        {
          for(i = 1; i < n + 1; i++)
          {
            cin >> w[i];
          }
          for(i = 1; i < n + 1; i++)
          {
            cin >> p[i];
          } 
          bag();
        }
        else
        {
            for(i = 0; i < m; i++)
            {
                cout << record[i] << endl;
            }
            break;
        } 
    } 
   
    return 0;
}