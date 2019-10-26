/*输入若干个字符串(每个字符串的长度不超过30个字
符，字符串总数不超过30)，和一个英文字符ch。 要
求： - 删除每个字符串中的字符ch(区分大小写)，得
到新的字符串 - 将新的字符串按照字典逆序排序后输出*/

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    unsigned int i=0,m,j,n;
    char ch;
    cin>>ch;
    char str[35][35], tmp[35];

    for(i=0;i<30;++i)               //读入每个字符串，直到@为止；
    {
        cin.getline(tmp,31);
        if(tmp[0]=='@') break;
        else strcpy(str[i],tmp);
    }
    n = i;

    for( i=0 ; i<n ; ++i )          //删除待删除字符
        for( j=0; str[i][j] != '\0' ; ++j)
        if(str[i][j]==ch)
        {
            for( m=j;str[i][m]!='\0';m++)
                str[i][m]=str[i][m+1];
            --j;    //防止出现几个待删除字符连在一起的情况
        }

    for(i=0;i<n-1;++i)              //冒泡排序字符数组
        for( j=0;j<n-i-1;++j)
            if( strcmp(str[j], str[j+1]) < 0)
            {
                strcpy(tmp,str[j+1]);
                strcpy(str[j+1],str[j]);
                strcpy(str[j],tmp);
            }


    for(i=0;i<n-1;++i)              //输出处理后的字符串
    {
        for(j=0; j<strlen(str[i]) ;++j)
          cout<<str[i][j];
        if(i<n-1)
           cout<<endl;
    }
}
