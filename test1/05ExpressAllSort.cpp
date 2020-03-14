#include <iostream>
#define N 10

using namespace std;

int n;
char a[N]={'a','b','c','d','e','f','g','h','i','j'};

void swap(int x,int y)
{
    int t;
    t = a[x];
    a[x] = a[y];
    a[y] = t;
}

void search(int k)
{
    int i;
    if(k == n)
    {
        for(i = 0; i < n; i++)
        {
            cout << a[i];
        }
        cout << endl;
    }
    else
    {
        for(i = k; i < n; i++)//关键步骤，思路即为只看众多循环中的其中平凡一步，k代表此循环的关键元素，此元素之前的部分代表已经排好，
        {                     //我们要做的只是把当前这个元素与后面的每一个元素交换（包括自己），所以用了for循环，并从k开始到n
            swap(k,i+1);      //当然在k与后面的每一元素交换时都会衍生出一大串内容，为了使k与后面的每一元素的交换互不影响，所以要换回来
            search(k+1);
            swap(k,i+1);
        } 
    }
}

int main()
{
    cin >> n;
    search(0);
    return 0;
}