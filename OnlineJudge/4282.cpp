#include<iostream>
#include<string>
using namespace std;

void print(char &x)
{
  char tmp;
  tmp = cin.get();
  if(tmp != '\n')
    print(tmp);
  cout << x;
}

int main()
{
  int type;
  cin >> type;
  char tmp;
  cin >> tmp;
  print(tmp);
  return 0;
}