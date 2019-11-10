#include<iostream>
#include<algorithm>
using namespace std;

template<class T>
class Priority_Queue{
private:
  T *data = nullptr;
  int Current_Size;
  int capacity;
public:
  Priority_Queue(int n)
  {
    data = new T[n + 1];
    Current_Size = 0;
    capacity = n;
  }
  ~Priority_Queue() { delete[] data; }

  void push(const T &x)
  {
    data[++Current_Size] = x;
    int parent, child=Current_Size;
    for (parent = Current_Size / 2; parent > 0; parent = child/2)
    {
      if(data[parent] > data[child])
        swap(data[parent], data[child]);
      child /= 2;
    }
  }

  void percolate_down(int i)
  {
    int child, parent;
    for (child = i * 2, parent = i; child <= Current_Size; parent=child, child*=2)
    {
      if(child != Current_Size)
       if(data[child] > data[child+1])
         child++;
      if(data[child] < data[parent])
        swap(data[child], data[parent]);
    }
  }

  void pop()
  {
    data[1] = data[Current_Size--];
    percolate_down(1);
  }

  T gethead()
  {
    return data[1];
  }

  bool isEmpty()
  {
    return Current_Size == 0;
  }
};


int main()
{
  unsigned long long n, result=0;
  cin >> n;
  Priority_Queue<int> Queue(n);
  for (int i = 0; i < n; ++i)
  {
    int x;
    cin >> x;
    Queue.push(x);
  }


  while(true)
  {
    int a, b;
    a = Queue.gethead();
    Queue.pop();
    if(Queue.isEmpty())
      {result = a;
      break;}
    b = Queue.gethead();
    Queue.pop();
    result = result + a + b;
    if(Queue.isEmpty())
      break;
    Queue.push(a + b);
  }
  cout << result;
  return 0;
}