#include <iostream>
#include <cmath>
#define NUM 8//NUM是几就是几皇后

using namespace std;

int qnum;//皇后数量
int A[NUM+1];//用一维数组代表八皇后8*8阵
int nnum;//代表第n个满足的阵

bool judge(int x)
{
   int i;
   for(i = 1; i < x; i++)
   {
       if(A[i] == A[x] || abs(x - i) == abs(A[x] - A[i]))
       {
            return false;
       }
   }
   return true;
}

void backstack(int x)
{
    int i,j;
    if(x > NUM)
    {
        nnum++;
        cout << "NO" << nnum << ":" << endl;
         for(i = 1; i <= NUM; i++)
           {
               for(j = 1; j <= NUM; j++)
             {
               if(A[i] != j)
               {
                   cout << "." << " ";
               }
               else
               {
                   cout << "A" << " ";
               }
              }
              cout << endl;
           }
    }
    else
    {
        for(i = 1; i < NUM + 1; i++)
        {
            A[x] = i;
            if(judge(x))
            {
               backstack(x+1);
            }
        }
        
    }
    
}

int main()
{
    backstack(1);
    return 0;
}