//not solved//

#include<iostream>
#include<stack>
using namespace std;

template<class T>
class node{
public: 
  T val;
  int index;
  node(){}
  node(T d, int n)
  {
    val = d;
    index = n;
  }

  bool operator<(const node &t)
  {
    return val < t.val;
  }

  bool operator>(node &t)
  {
    return val > t.val;
  }

  node operator=(const node &t)
  {
    if(this == &t)
      return *this;
    val = t.val;
    index = t.index;
    return *this;
  }
};

template<class T>
class Priority_Queue{
private:
  T *data = nullptr;
  int size = 1000;
  int Current_Size = 0;
public:
  Priority_Queue(const int &s = 1000)
  {
    size = s;
    Current_Size = 0;
    data = new T [s+1];
  }
  ~Priority_Queue(){}

  void enQueue(T &x);
  void deQueue();
  T getHead();
  void percolate_Down(int i);
};

template <class T>
void Priority_Queue<T>::enQueue(T &x)
{
  int i= ++Current_Size;
  for (; i > 1 && x < data[i/2]; i/=2)
    data[i] = data[i/2];
  data[i] = x;
}

template<class T>
void Priority_Queue<T>::deQueue()
{
  data[1] = data[Current_Size--];
  percolate_Down(1);
}

template<class T>
void Priority_Queue<T>::percolate_Down(const int index)
{
  int i;
  int child;
  T tmp = data[index];
  for (i = index; i*2 <= Current_Size; i=child)
  {
    child = i * 2;
    if(child < Current_Size && data[child] > data[child+1])
      child++;
    if(data[child] < tmp)
      data[i] = data[child];
    else
      break;
  }
  data[i] = tmp;
}

template<class T>
T Priority_Queue<T>::getHead()
{
  return data[1];
}

class fx{
private:
  int a;
  int b;
  int c;
public:
  void set(int A, int B, int C)
  {
    a = A;
    b = B;
    c = C;
  }

  int val(int x)
  {
    return x * x * a + x * b + c;
  }
};

int main()
{
  int n, k;
  int a, b, c;

  cin >> n >> k; 

  Priority_Queue<int> result(k);
  Priority_Queue<node<int>> function(n);

  int x[n];
  int test[n];
  fx *Fx;
  Fx = new fx[n];

  for (int i = 0; i < n; ++i)
  {
    cin >> a >> b >> c;
    int mid = (-b) / a / 2;
    Fx[i].set(a, b, c);
    if(Fx[i].val(mid) <= Fx[i].val(mid+1))
    {
      x[i] = mid;
      test[i] = 1;
    }
    else
    {
      x[i] = mid + 1;
      test[i] = -1;
    }

    node<int> tmp(Fx[i].val(x[i]), i);
    function.enQueue(tmp);
  }

  for (int i = 0; i < k; ++i)
  {
    int lest_val_now = function.getHead().val;
    function.deQueue();
    result.enQueue(lest_val_now);

    int tmp_value = Fx[0].val(x[0]+test[0]);
    int tmp_index = 0;
    for (int j = 1; j < n; ++j)
    {
      if(Fx[j].val(x[j] + test[j]) < tmp_value)
      {
        tmp_value = Fx[j].val(x[j] + test[j]);
        tmp_index = j;
      }
    }
    node<int> tmp(tmp_value, tmp_index);
    function.enQueue(tmp);
    x[tmp_index] += test[tmp_index];
    if(test[tmp_index] > 0)
    {
      test[tmp_index]++;
      test[tmp_index] = -test[tmp_index];
    }
    else
    {
      test[tmp_index]--;
      test[tmp_index] = -test[tmp_index];
    }
  }

  for (int i = 0; i < k;++i)
  {
    cout<<result.getHead()<<' ';
    result.deQueue();
  }
  return 0;
}