#include <iostream>
#include <cmath>

using namespace std;
//
//动态规划问题
//
int w[11];//代表每个物品的重量
int p[11];//代表每个物品的价值
int v[11];//之前用的是二维数组，但可以优化，代表当前的价值最大的情况，如v【1】【2】代表第一个物品在背包容量为2时满足情况的最大价值
          //其实因为每次都只是用该循环的上一个，所以只用一维即可
int path[11];//代表是否要选择这个商品，1代表选择，0代表不选

void searchmax(int num,int wei)
{
  int i,j;
  for(i = 1; i <= num; i++)
  {
     /*for(j = 1; j <=wei; j++)
     {
        if(w[i] > j)
        {
           v[i][j] = v[i-1][j];
        }
        else
        {
           v[i][j] = max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
        }
     }*/
     //改为下面代码
     for(j = wei; j > 0; j--)//这里要非常注意，要反序，否则先对于数组的改动会影响到后面的改动
     {
        if(w[i] <= j && v[j] < v[j-w[i]]+p[i])
        {
           v[j] = v[j-w[i]]+p[i];
        }
     }
  }
  //cout << v[num][wei] << endl;
  cout << v[wei] << endl;
}

//一维数组的缺点就是不能输出路径，因为路径已经被掩盖了
/*void searchpath(int num,int wei)
{
   int i,j;
   i = num;
   j = wei;
   while(i != 0)
   {
      if(v[i][j] != v[i-1][j])
      {
         path[i-1] = 1;
         j = j - w[i]; 
         i = i - 1;
      }
      else
      {
        i--;
      }
   }

   for(i = 0; i <= num; i++)
   {
      if(path[i] != 0)
      {
         cout << i+1 << " ";
      }
   }
   cout << endl;
   for(i = 0; i <= num; i++)//清0，为下一次做准备
   {
      path[i] = 0; 
   }
}*/

int main()
{
   int i,wei,num;
   while (1)
   {
      cin >> num >> wei;
      if(num == 0 && wei == 0)
      {
         return 0;
      }
      else
      {
         for(i = 1; i <= num; i++)
         {
            cin >> w[i];
         }
         for(i = 1; i <= num; i++)
         {
            cin >> p[i];
         }
         searchmax(num , wei);
       //  searchpath(num , wei);
      }
      
   }
   
}