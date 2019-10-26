//动态规划问题



#include<iostream>
#include<algorithm>
using namespace std;

int Initial[1000][1000], Temp[1000][1000];

int main()
{
    int RowNum;
    cin>>RowNum;

    int i, j;

    for(i=0; i<RowNum; i++)
    {
        for(j=0; j<=i; j++)
        {
            cin>>Initial[i][j];
        }
    }

    for(i=0; i<RowNum; ++i)
    {
        Temp[RowNum-1][i] = Initial[RowNum-1][i];
    }


    for(i=RowNum-1; i>0; --i)
    {
        for(j=0; j<i; ++j)
        {
            Temp[i-1][j] = Initial[i-1][j] + max(Temp[i][j], Temp[i][j+1]);
        }
    }

    cout<<Temp[0][0];
    return 0;
}
