#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

int m;//代表输入的六个数组成的一个整数
int times;
queue<int> q;
int used[654321];

int bfs();
bool canplace(int x,int type);
int place(int x,int type);
int exchangea(int x);
int exchangeb(int x);

int main()
{
	int i,first,n,num[10001];//每次检验每行的第一个数看是否结束
    while(scanf("%d",&first) != EOF)
	{
		m = first;
		for(i = 0; i < 5; i++)
		{
			cin >> n;
			m = m * 10 + n;
		}
		times++;
		q.push(m);
		used[m] = 1;
		num[times] = bfs();
	}
	for(i = 1; i <= times; i++)
	{
		if(num[i] == 1)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << " No" << endl;
		}
	}
	return 0;
}

int bfs()
{
	int i,x,y,z=0;
	while(!q.empty())
	{
	      x = q.front();
            q.pop();
		for(i = 0; i < 2; i++)
		{
			if(canplace(x,i))
			{
				y = place(x,i);
				if(y == 123456)
				{
					return 1;
				}
				used[y] = 1;
				q.push(y);
			}
		}
	}
	return z;
}

bool canplace(int x,int type)
{
	int y;
	y = place(x,type);
	if(used[y] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int place(int x,int type)
{
	if(type == 0)
	{
		x = exchangea(x);
	}
	if(type == 1)
	{
		x = exchangeb(x);
	}
	return x;
}

int exchangea(int x)
{
	int a,b,c,d,e,f,t;
	f = x % 10;
	x /= 10;
	e = x % 10;
	x /= 10;
	d = x % 10;
	x /= 10;
	c = x % 10;
	x /= 10;
	b = x % 10;
	x /= 10;
	a = x % 10;
	t = a;
	a = d;
	d = e;
	e = b;
	b = t;
	return (a*100000+b*10000+c*1000+d*100+e*10+f);
}

int exchangeb(int x)
{
	int a,b,c,d,e,f,t;
	f = x % 10;
	x /= 10;
	e = x % 10;
	x /= 10;
	d = x % 10;
	x /= 10;
	c = x % 10;
	x /= 10;
	b = x % 10;
	x /= 10;
	a = x % 10;
	t = b;
	b = e;
	e = f;
	f = c;
	c = t;
	return (a*100000+b*10000+c*1000+d*100+e*10+f);
}
