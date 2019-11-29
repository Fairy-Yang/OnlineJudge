#include <cstring>
#include <iostream>
using namespace std;

class IntPlusOne
{
private:
  char a[100];
  int i;

public:
  IntPlusOne()
  {
    cin.getline(a, 100);
    i = strlen(a) - 1;
  }
  void Plus()
  {
    if (a[i] == '9')
    {
      a[i] = '0';
      --i;
      Plus();
    }
    else
      a[i] += 1;
  }
  void Output()
  {
    if (a[0] == '0')
      cout << '1' << a;
    else
      cout << a;
  }
};

int main()
{
  IntPlusOne n;
  n.Plus();
  n.Output();
  return 0;
}
