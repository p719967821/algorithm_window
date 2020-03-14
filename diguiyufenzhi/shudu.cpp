#include <iostream>

using namespace std;

int a[9][9];

void output();
int canplace(int num,int i);

void search(int num)
{
    int i;
    if(num == 80)
    {
        output();
    }
    else
    {
        if(a[num / 9][num % 9] != 0)
        {
            search(num + 1);
        }
        else
        {
            for(i = 1; i <= 9; i++)//代表可以放的数字1~9
            {
                if(canplace(num,i))
                {
                  a[num / 9][num % 9] = i;
                  search(num + 1);
                  a[num / 9][num % 9] = 0;
                }
            }
            
        }
        
    }
    
}

int main()
{
    int i,j;
    char s[50];
    for(i = 0; i < 9; i++)
    {
        cin >> s;//输入一行只能以字符串的形式
        for(j = 0;j < 9; j++)
        {
            a[i][j] = s[j] - '0';
        }
    }
    search(0);
}

void output()
{
   int i,j;
   for(i = 0; i < 9; i++)
    {
     for (j = 0; j < 9; j++)
     {
        cout << a[i][j];
     }
     cout << endl;
    }
}

int canplace(int num,int i)//num代表是位置数，i代表放在此位置的数是几
{
  int row,col;
  int j,k;
  int flag = 1;
  row = num / 9;
  col = num % 9;
  for(j = 0; j < 9; j++)
  {
      if(a[j][col] == i || a[row][j] == i)
      {
          return flag = 0;
      }
  }
  for(j = row / 3 * 3; j < row / 3 * 3 + 3; j++)
    {
     for(k = col / 3 * 3; k < col / 3 * 3 + 3; k++)
          {
                if(a[j][k] == i)
                {
                  return flag = 0;              
                }
          }
     }
  
  return flag;
}