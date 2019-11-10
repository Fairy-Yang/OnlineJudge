#include<iostream>
#include<string>
using namespace std;

template<class T>
class Priority_Queue{
private:
  int Current_Size;
  T *array;
  int Max_Size;
public:
  //in main, the integer 'm' determines there are m numbers in the Queue at most;
  //So i don't write doublespace() here and in enQueue();
  Priority_Queue(int Capacity = 100){
    Max_Size = Capacity;
    array = new T[Max_Size];
    Current_Size = 0;
  }
  ~Priority_Queue() { delete[] array; }

  bool IsEmpty()
  {
    return Current_Size == 0;
  }

  T getHead()
  {
    return array[1];
  }

  void enQueue(const T &x)
  {
    //OJ doesn't consider about the same number should be ignored in enQueue();
    //the following notes are code to solve the same number enQueue for sevral times;
    //  int i = Current_Size+1;
    //  for (; i > 1 && x < array[i / 2]; i /= 2)
    //   ;

    //  if(array[i/2] == x)
    //   return;

    int i = ++Current_Size;
    for (; i > 1 && x < array[i / 2]; i/=2)
      array[i] = array[i / 2];
    array[i] = x;
  }

  void deQueue()
  {
    array[1] = array[Current_Size];
    Current_Size--;
    percolate_Down(1);
  }

  void percolate_Down(int k)
  {
    T tmp = array[k];
    int child, i;
    for (i = k; i * 2 <= Current_Size; i = child)
    {
      child = i * 2;
      if (child < Current_Size && array[child] > array[child+1])
        child++;
      if(array[child] < tmp)
        array[i] = array[child];
      else
        break;
    }
    array[i] = tmp;
  }
};

int main()
{
  int m;
  cin >> m;
  Priority_Queue<int> Queue(m+1);
  string operation;
  while(m-->0)
  {
    cin >> operation;
    if(operation == "insert")
    {
      int num;
      cin >> num;
      Queue.enQueue(num);
    }
    else if(operation == "delete")
      Queue.deQueue();
    else
      cout << Queue.getHead()<<'\n';
  }
}