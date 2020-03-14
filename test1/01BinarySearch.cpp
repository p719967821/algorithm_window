#include <iostream>
#define N 10005
#define M 50005//一直WA，问题就是范围不够，有的监测数据没有包含在内，所以要看题，把所有的范围都写进去

using namespace std;

void binarysearch(int a[], int k, int m)
{
     int low,upper,middle;
     low = 0;
     upper = m - 1;
     middle = (low + upper) / 2;
     while(low <= upper)
     {
         if(a[middle] == k)
         {
             cout << "Yes" << endl;
             return ;
         }
         if(a[middle] > k)
         {
             upper = middle - 1;
             middle = (low + upper) / 2;
         }
         if(a[middle] < k)
         {
             low = middle + 1;
             middle = (low + upper) / 2;
         }
     }
     cout << "No" << endl;
}

int main()
{
    int i;
    int m,n;
    int a[N],b[M];
    cin >> m;
    for(i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for(i = 0; i < n; i++)
    {
        binarysearch(a, b[i], m);
    }
    return 0;
}
