#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    long a, b;
    int x, y, z, p ,q, n;
    bool flag=true;

    cin>>a>>b;

    if(a<1 || b>99999 ||a>b)
        cout<<"error";
    else
    {
        for(int i=a; i<=b; ++i)
        {
            x=i/10000;
            y=(i%10000)/1000;
            z=(i%1000)/100;
            p=(i%100)/10;
            q=i%10;

            if(i<10)
                n=1;
            else if(i<100)
                n=2;
            else if(i<1000)
                n=3;
            else if(i<10000)
                n=4;
            else
                n=5;

            if(pow(x,n)+pow(y,n)+pow(z,n)+pow(p,n)+pow(q,n)==i){
                cout<<i<<endl;
                flag=false;}
            else
                continue;
        }
        if(flag)
            cout<<"no";
    }
}
