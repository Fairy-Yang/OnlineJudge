//i dont know how to improve it
//my code is almost the same as the code written by xiezhe which can be accepted;

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
  int n, max_index = 0, max_value=0;
  cin >> n;
  int data[60000]{0};
  char operation[10];
  while(true)
  {
    cin >> operation;
    if(strcmp(operation, "add") == 0)
    {
      int i, j;
      cin >> i >> j;
      ++data[j];
      if(data[j] == max_value && j < max_index)
        max_index = j;

      if(data[j] > max_value)
      {
        max_index = j;
        max_value = data[j];
      }
    } 
    else if(strcmp(operation, "query")==0)
    {
      cout << max_index << ' ' << max_value <<'\n';
    }
    else
      break;
  }
  return 0;
}
