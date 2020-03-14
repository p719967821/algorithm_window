#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int m,n;
    double sum,each;//代表总长度
    while(cin >> n)
    {
        int i;
        cin >> m;
        for(i = 0; i < n; i++)
        {
            each = (m + n) / n * i;
            sum = sum + abs((each + 0.5) - each);
        }
        sum =  sum * 10000 / (m + n);
    }
    return 0;
}