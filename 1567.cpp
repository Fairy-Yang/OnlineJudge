//Description
//����һ���ַ��ͶԽ��߳�������һ����б���õ����Ρ�
//Input Format
//����ֻ��һ�У� ����һ���ַ���һ������n����ʾ�ø��ַ����������Σ���Խ��߳�Ϊn�� ��֤�Խ��߳�nΪ������
//Output Format
//����ø��ַ����ɵ����Ρ�
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
