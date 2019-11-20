#include<iostream>
using namespace std;

int A[3000000]={0};

int main()
{
  long long num;
  cin >> num;

  long long i, j;

  for (i = 2; i<=num; ++i)
    if(A[i] == 0)
    {
      cout << i <<' ';
      for (j = i+i; j <= num; j+=i)
        A[j] = -1;
    }
  return 0;
}