#include<iostream>
using namespace std;

int main()
{
    int Budget[12], Result=0, PocketMoney=0, tmp=0;

    for(int i=0; i<12; ++i)
        cin>>Budget[i];

    for(int i=0;i<12 ;++i )
    {
        PocketMoney += 300;
        tmp = PocketMoney - Budget[i];
        if(tmp < 0)
        {
            Result = -(i+1);
            break;
        }
        else
        {
            PocketMoney = PocketMoney - Budget[i];
            PocketMoney %= 100;
            Result += tmp - tmp%100;
        }
    }

    if(Result<0)
        cout<<Result;
    else
        cout<<PocketMoney+(Result/5*6);

    return 0;
}