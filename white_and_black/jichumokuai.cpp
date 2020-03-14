#include <iostream>

using namespace std;

//代码是为了求
//对于将要下某种颜色当前棋盘状态共有多少处可以落子。
//输出可以落子的位置个数总数

int search(int a[8][8], int row, int column, int color);

int main()
{
  int a[8][8],row,column,color,sum = 0;
  int i,j,k,p;
  for(i=0; i<8; i++)
    for(j=0; j<8; j++)
     {
       cin >> a[i][j];
     }
  cin >> color;
  for(i=0; i<8; i++)
    for(j=0; j<8; j++)
     {
        sum += search(a, i, j, color);
     }
  cout << sum << endl;
  return 0;
}

int search(int a[8][8], int row, int column, int color)
{
  int i,j,k,p;
      for(i = row-1; i>-1; i--)//方向：上
      {
          if(a[i][column] != color && a[i][column] != 0)//找到被包的棋子
          {
              for(; i>-1; i--)
              {
                  if(a[i][column] == color)//找到相同的棋子
                  {
                     return 1;
                  }
              }
          }
      }
      i = row - 1;
      j = column + 1; 
      while(i > -1 && j < 8)//方向：右上
      {
          if(a[i][j] != color && a[i][j] != 0)//找到被包
          {
              while(i > -1 && j < 8)
              {
                  if(a[i][j] == color)
                  {
                     return 1;
                  }
                  i--;
                  j++;
              }
          }
          i--;
          j++;
      }
      for(i = column+1; i<8; i++)//方向：右
      {
          if(a[row][i] != color && a[row][i] != 0)
          {
              for(; i<8; i++)
              {
                  if(a[row][i] == color)
                  {
                     return 1;
                  }
              }
          }
      }
      i = row + 1;
      j = column + 1;
       while(i < 8 && j < 8)//方向：右下
      {
          if(a[i][j] != color && a[i][j] != 0)
          {
              while(i < 8 && j < 8)
              {
                  if(a[i][j] == color)
                  {
                      return 1;
                  }
                  i++;
                  j++;
              }
          }
          i++;
          j++;
      }
      for(i = row+1; i<8; i++)//方向：下
      {
          if(a[i][column] != color && a[i][column] != 0)
          {
              for(; i<8; i++)
              {
                  if(a[i][column] == color)
                  {
                      return 1;
                  }
              }
          }
      }
      i = row + 1;
      j = column - 1;
     while(i < 8 && j > -1)//方向：左下
      {
          if(a[i][j] != color && a[i][j] != 0)
          {
              while(i < 8 && j > -1)
              {
                  if(a[i][j] == color)
                  {
                       return 1;
                  }
                  i++;
                  j--;
              }
          }
          i++;
          j--;
      }
      for(i = column-1; i>-1; i--)//方向：左
      {
          if(a[row][i] != color && a[row][i] != 0)
          {
              for(; i>-1; i--)
              {
                  if(a[row][i] == color)
                  {
                       return 1;
                  }
              }
          }
      }
      i = row - 1;
      j = column - 1;
      while(i > -1 && j > -1)//方向：左上
      {
          if(a[i][j] != color && a[i][j] != 0)
          {
              while(i > -1 && j > -1)
              {
                  if(a[i][j] == color)
                  {
                       return 1;
                  }
                  i--;
                  j--;
              }
          }
          i--;
          j--;
      }
    return 0;
}
