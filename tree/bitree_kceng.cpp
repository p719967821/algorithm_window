#include <iostream>

using namespace std;

typedef struct tagnode
{
    int data;
    struct tagnode* lchild;
    struct tagnode* rchild;
}node,*lnode;

int main()
{
    creattree();
    searchk();
    return 0;
}

void creattree()
{
    int i;
    
}