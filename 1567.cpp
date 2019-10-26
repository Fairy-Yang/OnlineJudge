//Description
//给定一个字符和对角线长，构造一个倾斜放置的菱形。
//Input Format
//输入只有一行， 包含一个字符和一个整数n。表示用该字符来构造菱形，其对角线长为n。 保证对角线长n为奇数。
//Output Format
//输出用该字符构成的菱形。
//Sample Input
//* 5
//Sample Output
//  *
// ***
//*****
// ***
//  *

#include<iostream>
using namespace std;

int main()
{
    char ch;
    int n;

    cin>>ch;
    cin>>n;

    int b=n/2;
    for(int i=0; i<n; ++i,--b)
    {
        for(int j=0; j<(b>0?b:-b); ++j)
            cout<<' ';
        for(int k=0; k<1+(n/2-(b>0?b:-b))*2;++k)
            cout<<ch;
        cout<<'\n';
    }

    return 0;
}
