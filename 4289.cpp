#include<iostream>
#include<cstdio>
using namespace std;

const int MAXN = 20000010;
int a[MAXN];
int seed, Ta, Tb;
int n, k;
int Generate()
{
     return seed = seed * Ta + Tb;
}

int divide(int  a[], int pivot, int low, int high)
{
  if(low == high)
    return low;

  int tmp = a[low];
  a[low] = a[pivot];
  a[pivot] = tmp;
  tmp = a[low];
  do{
    while(low<high && a[high]>=tmp)
      high--;
    if(low<high)
    {
      a[low] = a[high];
      low++;
    }
    while(low<high && a[low] <= tmp)
      low++;
    if(low<high)
    {
      a[high] = a[low];
      high--;
    }
  } while (low != high);

  a[low] = tmp;
  return low;
}

int find(int a[], int low ,int high, int k)
{
  if(low == high)
    return a[low];

  int mid = rand() % (high+1-low)+low;

  int pivot = divide(a, mid, low, high);
  if(pivot==k)
    return a[pivot];
  
  if(pivot > k)
    return find(a, low, pivot - 1, k);
  else
    return find(a, pivot + 1, high, k);
}

int main()
{
  cin >> n >> k;
  cin >> seed >> Ta >> Tb;
  for (int i = 0;i < n;++i) 
      a[i] = Generate();
  cout<<find(a, 0, n-1, k-1);
  return 0;
}