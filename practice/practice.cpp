#include <iostream>
#define N 50

using namespace std;

void quicksort(int left,int right);

int n;
int a[N];

int main()
{
    int i;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quicksort(0,n-1);
    for(i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}

void quicksort(int left,int right)
{   
    int i,j,k;
    i = left;
    j = right + 1;
    if(left < right)
    {
        while(1)
        {
            while(i < n -1 && a[++i] < a[left]);
            while(j > 0 && a[--j] > a[left]);
            if(i >= j)
            {
                break;
            }
            k = a[i];
            a[i] = a[j];
            a[j] = k;
        }
        k = a[j];
        a[j] = a[left];
        a[left] = k;
        quicksort(left,j-1);
        quicksort(j+1,right);
    }
    
}