#include<iostream>
using namespace std;

int main()
{
  int **nut;
  int L, W;
  int l, w;
  cin >> L >> W;

  nut = new int *[L];
  for (int i = 0; i < L; ++i)
    nut[i] = new int[W];

  for (int i = 0; i < L;++i)
    for (int j = 0; j < W; ++j)
      cin >> nut[i][j];

  cin >> l >> w;
  int max_sum=-1, tmp_sum=0;
  for (int i = 0; i + l - 1 < L; ++i)
  {
    for (int j = 0; j + w - 1 < W; ++j)
    {
      tmp_sum = 0;
      for (int k = 0; k < l; ++k)
        for (int s = 0; s < w; ++s)
          tmp_sum += nut[i + k][j + s];
      
      if(max_sum < 0) 
        max_sum = tmp_sum;
      else
        if(max_sum < tmp_sum)
          max_sum = tmp_sum;
    }
  }

  cout<<max_sum;
  return 0;
}