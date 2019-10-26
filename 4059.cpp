//问题描述
//输入n个不相同的正整数（0<n<100），设计一个函数，求其最大值以及最大值所在的位置
//输入输出描述
//输入
//输入一个正整数n,以及一行n个数，n+1个数之间以空格分隔
//输出
//两个数，前一个是最大值，后一个是位置，两个数之间以一个空格分隔
//程序运行实例
//Sample Input
//5 6 7 3 4 21
//Sample Output
//21 5

#include<iostream>
using namespace std;

class Fmax{
private:
    int a[101];
    int n;
public:
    void create(){
        int m;
        cin>>m;
        for(int i=0; i<m;++i)
            cin>>a[i];
        n=m;
    }

    void Max(){
        int Max=-1,j;
        for(int i=0; i<n; ++i)
            if(a[i]>Max)
               {
                   Max=a[i];
                    j=i;
               }
            cout<<Max<<" "<<j+1;
    }
};

int main()
{
    Fmax a;
    a.create();
    a.Max();
}
