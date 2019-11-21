//when compling in vscode, ignore three warnings
#include<iostream>
//do not try to use cin and cout, scanf and printf have better speed
//using c in_output, the last three tles are solved finally;
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
  int n, max_index = 0, max_value=0;
  scanf("%d", &n);
  int data[50005]{0};
  char operation[10];
  while(true)
  {
    scanf("%s", operation);
    if(strcmp(operation, "add") == 0)
    {
      int i, j;
      scanf("%d %d",&i,&j);
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
      printf("%d %d\n", max_index, max_value);
    }
    else
      break;
  }
  return 0;
}
