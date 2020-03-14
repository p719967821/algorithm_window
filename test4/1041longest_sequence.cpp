#include <iostream>
#include <string>

using namespace std;

string m1,m2;
int n1,n2;//代表m1,m2的长度
int memo[101][101];

void findmin();

int main()
{
    int i;
    cin >> m1 >> m2;
    n1 = m1.length();
    n2 = m2.length();
    findmin();
    cout << memo[n1][n2] << endl;
    return 0;
}

void findmin()
{
    int i,j;
    for(i = 0; i < n1; i++)
    {
        for(j = 0; j < n2; j++)
        {
            if(m1[i] == m2[j])
            {
              memo[i+1][j+1] = memo[i+1-1][j+1-1] + 1;//i，j分别加一代表memo从1开始记，其目的是为了防止溢出             
            }
            else
            {
                memo[i+1][j+1] = max(memo[i+1][j+1-1],memo[i+1-1][j+1]);
            }
            
        }
    }
}
