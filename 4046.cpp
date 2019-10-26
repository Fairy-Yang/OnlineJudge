#include<iostream>

int main()
{
    using namespace std;

    int A[10][10]={0}, B[10][10]={0};
    int m, n, i, j;

    cin>>m>>n;
    for(j=0; j<m; ++j)
    {
        for(i=0; i<n; ++i)
            cin>>A[j][i];
    }

    for(i=0; i<m; ++i)
    {
        for(j=0; j<n; ++j)
        {
            B[j][m-1-i]=A[i][j];   //将对应行放在指定位置；
        }
    }

    cout<<n<<" "<<m<<endl;

    for(j=0; j<n; ++j)
    {
        for(i=0; i<m; ++i)
        {
            cout<<B[j][i];
            if(i!= m-1)
                cout<<" ";
        }
        if(j!=n-1)
            cout<<endl;
    }
}
