#include<iostream>
using namespace std;
void quicksort(int a[], int, int);
int divide(int b[], int, int);
int TIME(int c[], int);

int main()
{
    int num, time[100], sum=0;
    cin>>num;
    for(int i=0; i<num; ++i)
    {
        cin>>time[i];
    }

    quicksort(time, 0, num-1);

    sum=TIME(time, num);
    cout<<sum;
}

//1 2 3 4 5
//1,2过河1回来，5，4过河2回来；以此类推
int TIME(int c[], int m)
{
    int total=0;

    if(m==1) return c[0];
    else if(m==2) return c[1];
    else if(m==3) return c[0]+c[1]+c[2];
    else
    {
        total = c[0] + c[1] + c[m-1] + c[1] + TIME(c,m-2);
        return total;
    }
}

void quicksort(int a[], int low, int high)
{
    int mid;

    if(low>=high)return;
    mid = divide(a, low, high);
    quicksort(a, low, mid-1);
    quicksort(a, mid+1, high);
}

int divide(int b[], int low, int high)
{
    int k= b[low];

    do{
        while(low<high && b[high]>=k) --high;
        if(low<high)    {b[low]=b[high];++low;}
        while(low<high && b[low]<=k) ++low;
        if(low<high)    {b[high]=b[low];--high;}
    }while(low!=high);
    return low;
}
