#include <iostream>

using namespace std;

int n;
int jw[1001];//代表jerry是否会赢，1代表jerry先会赢，0代表后会赢

int dp(int x);

int main()
{
    while (cin >> n && n)
    {
        cout << dp(n) << endl; 
    }
    return 0;
}

int dp(int x)
{
    int i,j,m = 2;
    jw[1] = 0;
    for(i = 2; i <= x; i++)
    {
        jw[i] = 1;
        for(j = 1; j < m; j++)
        {
            if(jw[j] == 1)
            {
                jw[i] = 0;
            }
            else
            {
                jw[i] = 1;
            }
        } 
        m *= 2; 
    }
    return (jw[x]);
}