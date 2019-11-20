#include<iostream>
#include<string>
using namespace std;

template<class T>
class linkQueue{
private:
  struct node{
    T data;
    node *next=nullptr;
  };

  node *head=nullptr;
  node *rear=nullptr;
  int Current_size;

public:
  linkQueue()
  {
    head = new node;
    rear = head;
  }
  ~linkQueue(){}

  bool isEmpty()
  {
    return head->next == nullptr;
  }

  void enQueue(const T &x)
  {
    rear->next = new node;
    rear = rear->next;
    rear->data = x;
  }

  void deQueue()
  {
    if(head->next == nullptr)
      return;
    node *tmp = head->next;
    delete head;
    head = tmp;
  }

  T gethead()
  {
    return head->next->data;
  }
};

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

  int find(const T& x)
  {
    if(Current_Size == 0)
      return -1;

    int index = Current_Size+1;
    bool flag = false;
    for (int i = 1; i <= Current_Size; ++i)
    {
      if(!flag){
        if(array[i] > x)
        {
          index = i;
          flag = true;
        }
      }
      else
      {
        if(array[i]>x && array[i] < array[index])
          index = i;
      }
    }
    return index;
  }

  void decrease(int i,const T& v)
  {
    array[i] -= v;
    for (int i = Current_Size / 2; i > 0; i--)
      percolate_Down(i);
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
    else if(operation == "find")
    {
      int i;
      cin >> i;
      cout<<Queue.find(i)<<'\n';
    }  
    else
    {
      int i, v;
      cin >> i >> v;
      Queue.decrease(i, v);
    }
  }
}