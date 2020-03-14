#include <iostream>

using namespace std;

int main()
{
  int a[8][8],row,column,color;
  int i,j;
  for(i=0; i<8; i++)
    for(j=0; j<8; j++)
     {
       cin >> a[i][j];
     }
  cin >> row >> column >> color;
  if(a[row][column] != 0) 
   {
      cout << "no" << endl;
   }
   else
   {
      for(i = row-1; i>-1; i--)//方向：上
      {
          if(a[i][column] != color && a[i][column] != 0)
          {
              for(; i>-1; i--)
              {
                  if(a[i][column] == color)
                  {
                      cout << "yes";
                      return 0;
                  }
              }
          }
      }
      i = row - 1;
      j = column + 1; 
      while(i > -1 && j < 8)//方向：右上
      {
          if(a[i][j] != color && a[i][j] != 0)
          {
              while(i > -1 && j < 8)
              {
                  if(a[i][j] == color)
                  {
                      cout << "yes";
                      return 0;
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
                      cout << "yes";
                      return 0;
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
                      cout << "yes";
                      return 0;
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
                      cout << "yes";
                      return 0;
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
                      cout << "yes";
                      return 0;
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
                      cout << "yes";
                      return 0;
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
                      cout << "yes";
                      return 0;
                  }
                  i--;
                  j--;
              }
          }
          i--;
          j--;
      }
   }
   cout << "no" << endl;
    return 0;
}