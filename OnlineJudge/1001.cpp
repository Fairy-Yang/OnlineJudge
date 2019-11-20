#include<iostream>

using namespace std;

int main()
{
  int person, chair, num, fruit;
  int m=0;
  cin >> person >> chair >> num;
  int height = person + chair;
  for (int i = 0; i < num; ++i)
  {
    cin >> fruit;
    if(fruit <= height)
      m++;
  }
  cout << m;
  return 0;
}