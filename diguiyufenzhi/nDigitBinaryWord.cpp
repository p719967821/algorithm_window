#include <iostream>

using namespace std;

int n;
char A[10] = {'a','b','c','d','e','f','g','h','i','j'};

void swap(int i, int j)
{
    int s;
    s = A[i];
    A[i] = A[j];
    A[j] = s; 
}

void search(int m)
{
    int i;
    if(m == n)
    {
        for(i = 0; i < n; i++)
        {
            cout << A[i]; 
        }
        cout << endl;
    }
    else
    {
        for(i = m; i < n; i++) 
         {
            swap(i,m);
            search(m+1);
            swap(i,m);
         }
    }
    
}

int main()
{
    cin >> n;
    search(0);
    return 0;
}