#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int n, i=0;
    (cin>>n).get();
    while(i++<n)
    {
        unsigned int j=0;
        int num=0;
        char ch[110];
        cin.getline(ch, 110, '\n');
        while(j < strlen(ch))
        {
            if(ch[j]=='(')
                num++;
            if(ch[j]==')')
                num--;
            if(num<0)
            {
                cout<<"NO"<<'\n';
                break;
            }
            j++;
        }
        if(num>0)
            cout<<"NO"<<'\n';
        if(num==0)
            cout<<"YES"<<'\n';
    }
    return 0;
}
