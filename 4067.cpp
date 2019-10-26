#include<iostream>
#include<cstring>
using namespace std;
void fx(char a[],int);

int main()
{
    char a[80];
    cin.get(a,80);
    fx(a,strlen(a));
    if(a[0]=='0')
    cout<<'1'<<a;
    else
    cout<<a;
}

void fx(char a[],int i)
{
    if(a[i-1]+1>'9')
        {
            a[i-1]='0';
            fx(a,i-1);
        }
    else
        a[i-1]+=1;
}
