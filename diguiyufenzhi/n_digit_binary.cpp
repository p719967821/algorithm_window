#include <iostream>

using namespace std;

int n,c[20];

void search(int m)
{
    int i;
    if(n == m)
    {
        for(i = 0; i < n ;i++)
        {
            cout << c[i];
        }
        cout << endl;
    }
    else
    {
        c[m] = 0;
        search(m+1);
        c[m] = 1;
        search(m+1);
    }
    
}

int main()
{
    cin >> n;
    search(0);
    return 0;
}