#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int n, j=0, i=0, count=1;
    cin>>n;

    int **p;
    p=new int*[n];
    for(i=0;i<n;++i)
        p[i] = new int[n];

    int tmp=n;
    j=0;
    i=0;
    while(tmp/2<n)
    {
        for(;j<n;++j)
            p[i][j]=count++;
        for(++i,j--; i<n ; ++i)
            p[i][j]=count++;
        for(--j,--i;j>=tmp-n;--j)
            p[i][j]=count++;
        for(--i,++j;i>tmp-n;--i)
            p[i][j]=count++;
        --n;
        ++j;
        ++i;
    }
    for(i=0;i<tmp;++i)
   {
        for(j=0;j<tmp;++j)
            cout<<setw(6) <<p[i][j]<<' ';
        cout<<'\n';
   }

    for(i=0;i<n;++i)
        delete [] p[i];
    delete [] p;
    return 0;
}