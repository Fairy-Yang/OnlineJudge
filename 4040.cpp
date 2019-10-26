#include<iostream>

int main()
{
    using namespace std;
    int a, b, c, d, sum=0, num;
    cin>>a>>b;

    if(a>b||a<2|| b>200000)
        flag=1;
    else
    {
        for(num=a; num<=b; ++num)
        {
            d=num;
            while(d!=0)
            {
                c=d%10;
                d/=10;
                sum+=c*c*c;
            }
            if(sum==num)
            {
                cout<<num<<" ";
            }
        }
    }
}
