#include<iostream>
using namespace std;

int main()
{
  int m, t, u, f, d;
  int time = 0, num = 0;
  cin >> m >> t >> u >> f >> d;
  for (int i = 0; i < t; ++i)
  {
    char ti;
    cin >> ti;
    if(ti=='u' || ti == 'd')
      time = time + u + d;
    else
      time = time + 2 * f;
    if(time > m)
      break;
    else
      ++num;
  }
  cout << num;
  return 0;
}