#include<iostream>
using namespace std;

int main()
{
    int n,array[100];
    int location=1, max;
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        cin>>array[i];
    }
    max=array[0];
    for(int i=1;i<n;++i)
    {
        if(array[i]>max)
        {
            location=i+1;
            max=array[i];
        }
    }
    cout<<max<<" "<<location;
}
