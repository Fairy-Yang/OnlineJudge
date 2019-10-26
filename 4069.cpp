//输入一个字符串str，统计str中字符ch出现的位置
//普通版
//#include<iostream>
//using namespace std;
//void find(char a[], char);
//int main()
//{
//    char str[37],ch;
//    cin.getline(str, 37, ' ');
//    cin>>ch;
//    find(str, ch);
//}
//
//void find(char a[],char ch)
//{
//    int i;
//    bool flag = true;
//    for(i=0;a[i+1]!='\0';++i)
//    {
//        if(a[i]==ch)
//        {
//            cout<<i<<" ";
//            flag=false;}
//    }
//    if(flag)
//            cout<<"NULL";
//}


//指针版
#include<iostream>
using namespace std;
void find(char a[], char);
int main()
{
    char str[37],ch;
    cin.getline(str, 37, ' ');
    cin>>ch;
    find(str, ch);
}

void find(char a[],char ch)
{
    int i;
    bool flag = true;
    for(i=0;a[i+1]!='\0';++i)
    {
        if(a[i]==ch)
        {
            cout<<i<<" ";
            flag=false;}
    }
    if(flag)
            cout<<"NULL";
}
