#include<iostream>
using namespace std;

struct node{
  int row;
  int line;
  node *next;
};

class Queue{
private:
  node *head;
  node *rear;
  int current_size;
public:
  Queue() 
  {
    head = new node;
    rear = head;
    current_size = 0;
  }
  ~Queue()
  {
    for (int i = 0; i < current_size; ++i)
    {
      node *tmp=head->next;
      delete head;
      head = tmp;
    }
  }

  void push(int &row, int &line)
  {
    rear->next = new node;
    rear = rear->next;
    rear->row = row;
    rear->line = line;
    ++current_size;
  }

  void pop()
  {
    node *tmp = head->next;
    delete head;
    head = tmp;
    --current_size;
  }

  node gethead()
  {
    return *head->next;
  }

  bool isEmpty()
  {
    return current_size == 0;
  }

  int size()
  {
    return current_size;
  }
};

void generate(int **c, int i, int j, int l, int &empty_Num, Queue &que)
{
  if(j+1 < l && c[i][j+1] == 0)
  {
    empty_Num--;
    c[i][j + 1] = 1;
    int tmp = j + 1;
    que.push(i, tmp);
  }
  if(i+1 < l && c[i+1][j] == 0)
  {
    empty_Num--;
    c[i+1][j] = 1;
    int tmp = i + 1;
    que.push(tmp, j);
  }
  if(j-1 >= 0 && c[i][j-1] == 0)
  {
    empty_Num--;
    c[i][j - 1] = 1;
    int tmp = j - 1;
    que.push(i, tmp);
  }
  if(i-1 >= 0 && c[i-1][j] == 0)
  {
    empty_Num--;
    c[i-1][j] = 1;
    int tmp = i - 1;
    que.push(tmp, j);
  }
}

int main()
{
  int l;
  int **c;
  Queue que;

  cin >> l;
  c = new int* [l];
  for (int i = 0; i < l; i++)
    c[i] = new int[l];

  int empty_NUM = 0;
  for (int i = 0; i < l; ++i)
    for (int j = 0; j < l; ++j)
    {
      cin >> c[i][j];
      if(c[i][j] == 0)
        empty_NUM++;
      if(c[i][j] == 1)
        que.push(i, j);
    }
  int generate_num=0;
  while(empty_NUM != 0)
  {
    int num = que.size();
    while(num-->0)
    {
      node tmp = que.gethead();
      int i = tmp.row, j = tmp.line;
      que.pop();
      generate(c, i, j, l, empty_NUM, que);
    }
    generate_num++;
  }
  cout << generate_num;

  return 0;
}