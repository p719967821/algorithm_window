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
    int i;
    for(i = 1; i <= 10; i++)
    {
        if(i % 2 == 0)
        {
            jw[i] = 1;
        }
    }
    for(i = 11; i <= x; i++)
    {
        if(jw[i-1] == 1 && jw[i-5] == 1 && jw[i-10] == 1)
        {
            jw[i] = 0;
        }
        else
        {
            jw[i] = 1;
        }
    }
    return (jw[x]);
}