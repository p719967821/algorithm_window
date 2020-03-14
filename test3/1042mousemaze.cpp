#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int used[200];//记录是否走过
int step[200];//代表到这个位置已经走了多少步
int sr,sc;//开始的行和列
int er,ec;//结束的行和列

int bfs();
bool cango(int m, int dir);
int go(int m, int dir);

int main()
{
	int i,j,num;
	char s;
	cin >> sr >> sc;
	cin >> er >> ec;
	for(i = 0; i < 12; i++)
	{
		for(j = 0; j < 12; j++)
		{
			cin >> s;
			if(s == 'X')
			{
				used[i * 12 +j] = 1;
			}
		}
	}
	used[(sr - 1) * 12 +(sc - 1)] = 1;
	num = bfs();
	cout << num << endl;
	return 0;
}

int bfs()
{
	int i,st,et,n,m;
	//从0开始，所以行列数都减一
	st = (sr - 1) * 12 +(sc - 1);
	et = (er - 1) * 12 +(ec - 1);
	q.push(st);
	while(!q.empty())
	{
		m = q.front();
		q.pop();
		for(i = 0; i < 4; i++)
		{
			if(cango(m,i))
			{
				n = go(m,i);
				used[m] = 1;
				if(n == et)
				{
					return (step[m] + 1);
				}
				step[n] = step[m] + 1;
                        q.push(n);
			}
		}
	}
	return -1;
}

bool cango(int m, int dir)//这个地方一定要注意，不能直接套go函数，因为用go后传回来的n经过/12、%12 仍是满足条件的，这样的话下面的下面的判断row和col就失去了意义
{
	int row,col,n;
	row = m / 12;
	col = m % 12;
	if(dir == 0)//上
	{
		row--;
	}
	if(dir == 1)//右
	{
		col++;
	}
	if(dir == 2)//下
	{
		row++;
	}
	if(dir == 3)//左
	{
		col--;
	}
	n = row * 12 + col;
    if(row >=0 && row < 12 && col >=0 && col <12 && used[n] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int go(int m, int dir)
{
	int row,col;
	row = m / 12;
	col = m % 12;
	if(dir == 0)//上
	{
		row--;
	}
	if(dir == 1)//右
	{
		col++;
	}
	if(dir == 2)//下
	{
		row++;
	}
	if(dir == 3)//左
	{
		col--;
	}
	return (row * 12 + col);
}


