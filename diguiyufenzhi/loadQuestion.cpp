#include <iostream>

using namespace std;

int  all,sum;
int a[10];
int c1,c2,n;

void search(int i)
{
    int j;
    if(i == n)
    {
        if(all <= c1 && sum - all <= c2)
        {
            cout << "Yes" << endl;
        }
    }
    else
    {
        if(all <= c1)
        {
            all += a[i];
            search(i + 1);
        }
        else
        {
            i--;//这一步和下一步很重要，目的先要把之前的还原。在递归时因为是search（i+1）来的，所以要先i--处理。
            all -= a[i];
            search(i + 1);
        }
        
    }
    
}

int main()
{
    int i;
    while(1)
    {
        cin >> c1 >> c2 >> n;
        if(c1 == 0 &&  c2 == 0 && n == 0)
        {
            return 0;
        }
        else
        {
            for(i = 0; i < n; i++)
            {
                cin >> a[i];
                sum = a[i];
            }  
            for(i = 0; i < n; i++)
            {
                search(i);
            }
            cout << "No" << endl;
        }
    }
    return 0;
}