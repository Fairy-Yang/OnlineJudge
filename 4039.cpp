#include<iostream>

int main()
{
    using namespace std;

    int N,i;
    cin>>N;

    for(i=2;i<=N;++i)
        for(;N%i==0;N/=i)
        {
            cout<<" "<<i;
        }

        return 0;
}
