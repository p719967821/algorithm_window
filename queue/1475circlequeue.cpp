#include <iostream>
#include <queue>
#define N 100

using namespace std;

queue<int> q;

int main()
{
    int i,n,m,a[N],qsize,firstnum;
    cin >> n >> m;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(i = 0; i < n; i++)
    {
        qsize = q.size();
        if(a[i] == 0)
        {
           firstnum = q.front();
           q.pop();
           cout << firstnum << endl;
        }
        else
        {
            if(qsize < m)
            {
            q.push(a[i]);
            }
            else
            {
             cout << "No" << endl;
            }
        }
    }
    return 0;
}
