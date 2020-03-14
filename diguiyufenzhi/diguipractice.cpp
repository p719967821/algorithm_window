#include<iostream>
#include<cmath>
using namespace std;
 
/*
1. 用一个一维数组来表示八皇后的摆放情况
   x[i]表示第i个皇后放在第i行的第x[i]列
2.剪枝条件
  不同行    每一行放一个皇后
  不同列    x[i] != x[j]
  不同斜线  |i - j| != |x[i] - x[j]|  即 abs(i - j) != abs(x[i] - x[j])
*/
 
int num;  //皇后的个数
int *x;   //数组x[num+1]
int sum;  //八皇后解的个数
 
bool check(int k){  //用来判断是否要进行剪枝
    for(int j=1;j<k;j++){
        if( abs(k - j) == abs(x[k] - x[j]) || x[j] == x[k] )  //判断条件
            return false;   //如果同列同斜线 则返回false
    }
    return true;
}
 
void backtrack(int t){
    if(t > num){   //num是皇后的数目
        sum++;   //sum用来统计有多少种解法
        for(int m=1; m<=num; m++){
            cout<<"<"<<m<<"，"<<x[m]<<">";  //输出当递归到八叉树的叶节点的时候的一个可行解
        }
        cout<<endl;
    }
    else{
        for(int i=1; i<=num; i++){
            x[t] = i;  //t从1开始 也就是第一行 第一个皇后
            if( check(t) ){
                backtrack(t+1);  //如果check函数返回为true，即判断成立 则进入下一行 下一级递归
            }
        }
    }
}
 
int main(){
    num = 8;
    sum = 0;
    x = new int [num+1];
    for(int i=0; i<=num; i++){
        x[i] = 0;
    }
    backtrack(1);
    cout<<"方案共有"<<sum<<"种"<<endl;
    delete []x;
}