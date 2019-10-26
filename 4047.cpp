#include<iostream>
int A[2000000]={0};
int main()
{
    using namespace std;
    long i,j,n;
    int k=0;
    cin>>n;
    for(i=0; i<=n; ++i)
        A[i]=i;

    for(i=2; i<n; ++i)
    {
        if(A[i]!=0)
        {
            for(j=2;j<=n/i;++j)
            {
                A[i*j]=0;
            }
        }
    }

    for(i=2;i<=n;++i)
    {
        if(A[i]!=0)
        {
            ++k;
            cout<<A[i]<<" ";}
        else
            continue;
    }
    cout<<k;
    system("pause");
}
