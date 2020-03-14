#include <iostream>

using namespace std;

int main()
{
  int a[8][8],m,n,sum = 1;
  int i,j;
  for(i=0; i<8; i++)
   for(j=0; j<8; j++)
   {
       cin >> a[i][j];
   }
  cin >> m >> n;
  while(m < 8 && n > -1)
  {
       if(a[m][n] == a[--m][++n])
       {
           sum += 1;
       }
       else
       {
          break;
       }
       
  }
  cout << sum << endl;
    return 0;
}