//��������
//����n������ͬ����������0<n<100�������һ���������������ֵ�Լ����ֵ���ڵ�λ��
//�����������
//����
//����һ��������n,�Լ�һ��n������n+1����֮���Կո�ָ�
//���
//��������ǰһ�������ֵ����һ����λ�ã�������֮����һ���ո�ָ�
//��������ʵ��
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
