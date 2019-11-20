#include<iostream>

using namespace std;

int divide(int A[], int low, int high)
{
  int tmp = A[low];
  do
  {
    while(low<high && A[high] >= tmp) high--;
    if(low<high)
     {
       A[low] = A[high];
       low++;
     } 
    while(low<high && A[low] <= tmp)
      low++;
    if(low<high)
    {
      A[high] = A[low];
      high--;
    }
  } while (low != high);

  A[low] = tmp;
  return low;
}

void Quick_Sort(int A[], int low, int high)
{
  if(low >= high )
    return;
  int mid = divide(A, low, high);
  Quick_Sort(A, low, mid-1);
  Quick_Sort(A, mid+1, high);
}

int main()
{
  int n;
  cin >> n;
  int *array;
  array = new int[n];
  for (int i = 0; i < n; ++i)
    cin >> array[i];
  Quick_Sort(array, 0, n - 1);
  for (int i = 0; i < n; ++i)
   cout << array[i]<<' ';
  return 0;
}