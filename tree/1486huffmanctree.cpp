#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
#define N 101

using namespace std;

typedef struct taghuffmantree
{
    int parent;
    int lchild;
    int rchild;
    int weight;
}huffmancode,*lhftree;

int n;
int s1,s2;//代表构建哈夫曼树时找出的最小的两个数的位置
int letterw[N];//字符串的权值
char letter[N];//字符串
char target[N];//要翻译的目标字符串
lhftree ht;
string hd[N];//用于记录每个字母的编码

void output();
void creathftree();
void creathd();
void findmin(int m);
void init();

int main()
{
    init();
    creathftree();
    creathd();
    output();
    return 0;
}

void output()
{
    int i,j,num;
    num = strlen(target);
    for(i = 1; i <= num; i++)
    {
        for(j = 1; j <= n ; j++)
        {
            if(target[i] == letter[j])
            {
                cout << hd[j];
            }
        }
    }
    cout << endl;
    cout << target <<endl;
}

void creathftree()
{
    int i,m,a,b;
    m = 2 * n - 1;
    ht = (lhftree)malloc((m + 1)*sizeof(huffmancode));
    //给每一个节点初始化
    for(i = 1; i <= m; i++)
    {
        ht[i].lchild = 0;
        ht[i].rchild = 0;
        ht[i].parent = 0;
        if(i <= m)
        {
            ht[i].weight = letterw[i];
        }
        else
        {
            ht[i].weight = 0;
        }
    }
    //建立哈夫曼树
     for(i = n + 1; i <= m; i++)
     {
         findmin(i - 1);//在前i-1个元素中找
         ht[s1].parent = i;
         ht[s2].parent = i;
         ht[i].weight = ht[s1].weight + ht[s2].weight;
         ht[i].lchild = s1;
         ht[i].rchild = s2; 
     }
}

void creathd()
{
    int i,x,y;
    for(i = 1; i <= n; i++)
    {
        y = i;
        while(ht[y].parent != 0)
        {
            x = ht[y].parent;
            if(ht[x].lchild == y)
            {
                hd[i] = '0' + hd[i];
            }
            else
            {
                hd[i] = '1' + hd[i];
            }
            y = x;
        }
    }
}

 void findmin(int m)
 {
    int i;
    s1 = 1;
    s2 = 1;
    //寻找最小的权的位置s1
    while (ht[s1].parent != 0)
    {
        s1++;
    }
    for(i = 1; i <= m; i++)
    {
        if(ht[i].weight < ht[s1].weight && ht[i].parent == 0)
        {
            s1 = i;
        }
    }
    //寻找次小的权的位置s2
    while (ht[s2].parent != 0 || s2 == s1)
    {
        s2++;
    }
    for(i = 1; i <= m; i++)
    {
        if(ht[i].weight < ht[s2].weight && i != s1 && ht[i].parent == 0)
        {
            s2 = i;
        }
    }
 }

void init()
{
     int i;
     cin  >> n;
      for(i = 1; i <= n; i++)
      {
            cin >> letter[i];
      }
      for(i = 1; i <= n; i++)
      {
          cin >> letterw[i];
      }
      cin >> target;
}