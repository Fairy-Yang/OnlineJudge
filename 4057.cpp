#include <iostream>
using namespace std;
const int Len=10000;
int main()
{
    char a[Len+1]={'0'},b[Len];
    int i,j,m,k,n,count1=0,count2=0;
    cin.getline(a,Len+1);
    for(k=0; (a[k]<='z'&&a[k]>='a')||(a[k]<='Z'&&a[k]>='A'); ++k);

    for(i=0; i<k-1; ++i)
    {
        for(j=k-1; j>i; --j)
        {
            count2=0;
            if(a[j]==a[i])      //找出自i之后最远的与j相同的项，一共后推了count1次
            {
                count2=j-i+1;
                for(n=1; n<=(j-i)/2; ++n)
                {
                    if(a[i+n]!=a[j-n])
                    {
                        count2=0;
                        break;
                    }
                }
                if(count2>count1)
                {
                for(m=0,n=i; m<count2; ++m,++n)
                    b[m]=a[n];
                count1=count2;
                }
            }
        }
    }
    if(count1>1)
    {
        cout<<count1<<endl;
        for(m=0; m<count1; ++m)
            cout<<b[m];
    }
    if(count1==0)
        cout<<"0";
}
