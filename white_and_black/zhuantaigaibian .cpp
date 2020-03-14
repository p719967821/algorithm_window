#include <iostream>

using namespace std;

//代码是为了求
//当在一个位置落子后周围的哪些棋子要翻面
//输出翻面后棋盘的状态

int main()
{
  int a[8][8],row,column,color;
  int i,j,k,p;
  for(i=0; i<8; i++)
    for(j=0; j<8; j++)
     {
       cin >> a[i][j];
     }
  cin >> row >> column >> color;
  if(a[row][column] != 0) 
   {
      cout << "impossible" << endl;
   }
   else
   {
      a[row][column] = color;
      for(i = row-1; i>-1; i--)//方向：上
      {
          if(a[i][column] != color && a[i][column] != 0)//找到被包的棋子
          {
              for(; i>-1; i--)
              {
                  if(a[i][column] == color)//找到相同的棋子
                  {
                      for(k=row-1; k>=i; k--)
                         {
                             if(a[k][column] != 0)
                             {
                                 a[k][column] = color;
                             }
                         }
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
                      for(k=row-1,p=column+1; k>=i; k--)
                         {
                             if(a[k][p] != 0)
                             {
                                 a[k][p] = color;
                             }
                             p++;
                         }
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
                     for(k=column+1; k<=i; k++)
                         {
                             if(a[row][k] != 0)
                             {
                                 a[row][k] = color;
                             }
                         } 
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
                      for(k=row+1,p=column+1; k<=i; k++)
                         {
                             if(a[k][p] != 0)
                             {
                                 a[k][p] = color;
                             }
                             p++;
                         }
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
                     for(k=row+1; k<=i; k++)
                         {
                             if(a[k][column] != 0)
                             {
                                 a[k][column] = color;
                             }
                         }
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
                      for(k=row+1,p=column-1; k<=i; k++)
                         {
                             if(a[k][column-1] != 0)
                             {
                                 a[k][column-1] = color;
                             }
                             p--;
                         }
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
                      for(k=column-1; k>=i; k--)
                         {
                             if(a[row][k] != 0)
                             {
                                 a[row][k] = color;
                             }
                         }
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
                      for(k=row-1,p=column-1; k>=i; k--)
                         {
                             if(a[k][column-1] != 0)
                             {
                                 a[k][column-1] = color;
                             }
                             p--;
                         }
                  }
                  i--;
                  j--;
              }
          }
          i--;
          j--;
      }
   }
   for(i=0; i<8; i++)
    {
      for(j=0; j<8; j++)
       {
       cout << a[i][j] << " ";
       }
       cout << endl;
    }
    return 0;
}