#include<iostream>
#include<string>
using namespace std;

int main()
{
  string st1, st2;
  cin >> st1 >> st2;
  int m = st1.find('.')+2;
  int n = st2.find('.')+2;

  char s1[205], s2[205];
  int tmp = 0;
  for (int i = 0; i<=m; ++i)
    if(st1[i]!='.')
      s1[tmp++] = st1[i];
  tmp = 0;
  for (int i = 0; i<=n; ++i)
    if(st2[i]!='.')
      s2[tmp++] = st2[i];

  int i = 0;
  n--;
  m--;
  char result[205]{0};
  while(n>=0 && m>=0)
  {
    result[i] = s1[m] - '0' + s2[n] + result[i];
    if(result[i]>'9')
    {
      result[i] -= '0';
      result[i + 1] = result[i] / 10;
      result[i] %= 10;
      result[i] += '0';
    }
    i++;
    n--;
    m--;
  }

  if(n<0)
  {
    while(m>=0)
    {
      result[i] = s1[m] + result[i];
      if(result[i]>'9')
      {
        result[i] -= '0';
        result[i + 1] = result[i] / 10;
        result[i] %= 10;
        result[i] += '0';
      }
      m--;
      i++;
    }
  }
  else
  {
    while(n>=0)
    {
      result[i] = s2[n] + result[i];
      if(result[i]>'9')
      {
        result[i] -= '0';
        result[i + 1] = result[i] / 10;
        result[i] %= 10;
        result[i] += '0';
      }
      n--;
      i++;
    }
  }

  if(result[i]!=0)
    result[i] += '0';
  else
    i--;
  tmp = 0;
  while(i>=0)
  {
    if(i == 1)
    {
      cout << '.' << result[1] << result[0];
      break;
    }
    cout << result[i];
    i--;
  }
  return 0;
}

