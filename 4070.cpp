/*�������ɸ��ַ���(ÿ���ַ����ĳ��Ȳ�����30����
�����ַ�������������30)����һ��Ӣ���ַ�ch�� Ҫ
�� - ɾ��ÿ���ַ����е��ַ�ch(���ִ�Сд)����
���µ��ַ��� - ���µ��ַ��������ֵ�������������*/

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    unsigned int i=0,m,j,n;
    char ch;
    cin>>ch;
    char str[35][35], tmp[35];

    for(i=0;i<30;++i)               //����ÿ���ַ�����ֱ��@Ϊֹ��
    {
        cin.getline(tmp,31);
        if(tmp[0]=='@') break;
        else strcpy(str[i],tmp);
    }
    n = i;

    for( i=0 ; i<n ; ++i )          //ɾ����ɾ���ַ�
        for( j=0; str[i][j] != '\0' ; ++j)
        if(str[i][j]==ch)
        {
            for( m=j;str[i][m]!='\0';m++)
                str[i][m]=str[i][m+1];
            --j;    //��ֹ���ּ�����ɾ���ַ�����һ������
        }

    for(i=0;i<n-1;++i)              //ð�������ַ�����
        for( j=0;j<n-i-1;++j)
            if( strcmp(str[j], str[j+1]) < 0)
            {
                strcpy(tmp,str[j+1]);
                strcpy(str[j+1],str[j]);
                strcpy(str[j],tmp);
            }


    for(i=0;i<n-1;++i)              //����������ַ���
    {
        for(j=0; j<strlen(str[i]) ;++j)
          cout<<str[i][j];
        if(i<n-1)
           cout<<endl;
    }
}
