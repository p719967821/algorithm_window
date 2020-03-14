#include <iostream>
#define N 10005

using namespace std;

int a[N];
int m;

void searchsort(int n,int left,int right)
{
    int i,j,t;
    i = left;
    j = right + 1;
    if(left < right)
    {
        while(1)
        {
            while (i < n - 1 && a[left] > a[++i]);
            while (j > 0 && a[left] < a[--j]);
            if(i >= j)break;
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
        t = a[left];
        a[left] = a[j];
        a[j] = t;
        if(j < m)
        {
            searchsort(n,j+1,right);
        }
        else if (j > m)
        {
           searchsort(n,left,j-1);
        }
        else
        {
             cout << a[j] << endl;
        }
    }
}

int main ()
{
    int n,i;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    m = m - 1;
    searchsort(n,0,n-1);
    return 0;
}