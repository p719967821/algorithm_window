#include <iostream>

using namespace std;

int ns;//start用一个数字表示
int ne;//end用一个数字表示
//int maze[20][20];//注意清空
int used[400];
int m,x,times;//用于判断是输出yes还是no

int go(int step, int wz)
{
    int i,row,col;
    row = wz / 20;
    col = wz % 20;
    if(step == 0)
    {
        row--;
        return row*20+col;
    }
    if(step == 1)
    {
        col++;
        return row*20+col;
    }
    if(step == 2)
    {
        row++;
        return row*20+col;
    }
    if(step == 3)
    {
        col--;
        return row*20+col;
    }
}

bool cango(int wz)
{
     int i,row,col;
     row = wz / 20;
     col = wz % 20;  
     if(row >= 0 && row < 20 && col >= 0 && col < 20 && used[wz] == 0)
     {
         return true;
     }
     else
     {
         return false;
     }
     
}

void search(int n)
{
    int i,newn;
    if(n == ne)
    {
        m = 1;
        return;
    }
    else
    {
        used[n] = 1;
        for(i = 0; i < 4; i++)
        {
            newn = go(i,n);
            if(cango(newn))
            {
                 search(newn);
            }
        }
    }
    
}

int main()
{
    int n,i,j,x1,x2,y1,y2,k;
    char s;
    int a[10000];//用于储存各个测例的结果，便于一起输出
    cin >> n;
    for(k = 0; k < n; k++)
    {
        cin >> x1 >> y1;
        ns = x1 * 20 + y1;
        cin >> x2 >> y2;
        ne =x2 * 20 + y2;
        for(i = 0; i < 20; i++)
        {
            for(j = 0; j < 20; j++)
            {
                cin >> s;
                if(s == 'X')
                {
                    used[i*20+j] = 1;
                }
                
            }
        }
        search(ns);
        if(m == 1)
        {
            a[times] = 1;
        }
        else
        {
            a[times] = 0;
        }
        times++;
        //清空数据,m和uesd【i】
        for(i = 0; i < 400; i++)
        {
            used[i] = 0;
        }
        m = 0;
    }
    for(i = 0; i < times; i++)
    {
        if(a[i] == 0)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}