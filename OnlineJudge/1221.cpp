#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
#include<stack>
using namespace std;

template<class T>
class linkQueue{
private:
  struct node{
    T data;
    node *next = nullptr;

    node(){}
    node(const T &x, node *n=nullptr) 
    {
      data = x;
      next = n;
    }
  };

  node *front = nullptr;
  node *rear = nullptr;
public:
  linkQueue()
  {
    rear = new node;
    front = rear;
  }
  ~linkQueue(){}

  bool isEmpty()
  {
    return front->next == nullptr;
  }

  void enQueue(const T &x)
  {
    rear->next = new node(x);
    rear = rear->next;
  }

  void deQueue()
  {
    node *tmp = front->next;
    delete front;
    front = tmp;
  }

  T gethead()
  {
    return front->next->data;
  }
};

template<class T>
class Binary_Search_Tree{
private:
  struct node{
    T data;
    node *left = nullptr;
    node *right = nullptr;

    node(const T &x, node *l=nullptr, node *r=nullptr)
    {
      data = x;
      left = l;
      right = r;
    }
  };

  node *root = nullptr;

  void insert(const T &x, node *&n);
  void Delete (const T &x, node *&n);
  bool find(const T &x, node *n);
  T find_ith(node *n, int i);
public:
  Binary_Search_Tree(){}
  ~Binary_Search_Tree(){}

  bool isEmpty();

  void insert(const T &X);
  void Delete(const T &x);
  void Delete_less_than(const T &x);
  void Delete_larger_than(const T &x);
  void Delete_interval(const T &a, const T &b);
  bool find(const T &x);
  T find_ith(int i);
};

int main()
{
  int num;
  cin >> num;
  string operation;
  Binary_Search_Tree<int> Trie;
  while(num-->0)
  {
    cin >> operation;
    if(operation == "insert")
    {
      int val;
      cin >> val;
      Trie.insert(val);
    }
    else if(operation == "delete")
    {
      int val;
      cin >> val;
      Trie.Delete(val);
    }
    else if(operation == "delete_less_than")
    {
      int val;
      cin >> val;
      Trie.Delete_less_than(val);
    }
    else if(operation == "delete_greater_than")
    {
      int val;
      cin >> val;
      Trie.Delete_larger_than(val);
    }
    else if(operation == "delete_interval")
    {
      int lval, rval;
      cin>>lval>>rval;
      Trie.Delete_interval(lval, rval);
    }
    else if(operation == "find")
    {
      int val;
      cin >> val;
      if(Trie.find(val))
        cout << 'Y'<<'\n';
      else
        cout << 'N'<<'\n';
    }
    else
    {
      int val;
      cin >> val;
      try{
        cout<<Trie.find_ith(val)<<'\n';
      }
      catch(int)
      {
        cout << 'N'<<'\n';
      }
    }
  }
  return 0;
}

template<class T>
bool Binary_Search_Tree<T>::isEmpty()
{
  return root == nullptr;
}

template<class T>
void Binary_Search_Tree<T>::insert(const T &x)
{
  insert(x, root);
}

template<class T>
void Binary_Search_Tree<T>::insert(const T &x, node *&n)
{
  if(n == nullptr)
    {
      n = new node(x);
      return;
    }

  if (n->data > x)
    insert(x, n->left);
  if(n->data <= x)
    insert(x, n->right);
}

template<class T>
void Binary_Search_Tree<T>::Delete(const T &x)
{
  Delete (x, root);
}

template<class T>
void Binary_Search_Tree<T>::Delete(const T &x, node *&n)
{
  if(n == nullptr)
    return;

  if(n->data > x)
    Delete(x, n->left);
  if(n->data < x)
    Delete(x, n->right);

  if(n->data == x)
  {
      if(n->left != nullptr && n->right != nullptr)
      {
        node *tmp = n->right;
        while(tmp->left != nullptr)
          tmp = tmp->left;
        n->data = tmp->data;
        Delete(n->data, n->right);
      }
      else
      {
        node *tmp = n;
        n = (n->left == nullptr ? n->right : n->left);
        delete tmp;
      }
  }
}

template<class T>
void Binary_Search_Tree<T>::Delete_less_than(const T &x)
{
  if(root == nullptr)
    return;

  stack<node *> Stak;
  linkQueue<node *> Queue;
  Queue.enQueue(root);
  while(!Queue.isEmpty())
  {
    node *tmp = Queue.gethead();
    Queue.deQueue();
    if(tmp->left != nullptr)
      Queue.enQueue(tmp->left);
    if(tmp->right != nullptr)
      Queue.enQueue(tmp->right);

    if(tmp->data < x)
      Stak.push(tmp);
  }

  while(!Stak.empty())
  {
    node *tmp = Stak.top();
    Stak.pop();
    Delete(tmp->data);
  }
}

template<class T>
void Binary_Search_Tree<T>::Delete_larger_than(const T &x)
{
  if(root == nullptr)
   return;

  stack<node *> Stak;
  linkQueue<node *> Queue;
  Queue.enQueue(root);
  while(!Queue.isEmpty())
  {
    node *tmp = Queue.gethead();
    Queue.deQueue();
    if(tmp->left != nullptr)
      Queue.enQueue(tmp->left);
    if(tmp->right != nullptr)
      Queue.enQueue(tmp->right);

  if(tmp->data > x)
      Stak.push(tmp);
  }

  while(!Stak.empty())
  {
    node *tmp = Stak.top();
    Stak.pop();
    Delete(tmp->data);
  }
}

template<class T>
void Binary_Search_Tree<T>::Delete_interval(const T &a, const T &b)
{
  if(root == nullptr)
   return;

  stack<node *> Stak;
  linkQueue<node *> Queue;
  Queue.enQueue(root);
  while(!Queue.isEmpty())
  {
    node *tmp = Queue.gethead();
    Queue.deQueue();
    if(tmp->left != nullptr)
      Queue.enQueue(tmp->left);
    if(tmp->right != nullptr)
      Queue.enQueue(tmp->right);

    if(tmp->data > a && tmp->data < b)
      Stak.push(tmp);
  }

  while(!Stak.empty())
  {
    node *tmp = Stak.top();
    Stak.pop();
    Delete(tmp->data);
  }
}

template<class T>
bool Binary_Search_Tree<T>::find(const T &x)
{
  return find(x, root);
}

template<class T>
bool Binary_Search_Tree<T>::find(const T &x, node *n)
{
  if(n==nullptr)
    return false;

  if (n->data < x)
    return find(x, n->right);
  if(n->data > x)
    return find(x, n->left);

  return true;
}

template<class T>
T Binary_Search_Tree<T>::find_ith(int i)
{
  //mid_Order traverse to get i_th smallest num;
  return find_ith(root, i);
}

template<class T>
T Binary_Search_Tree<T>::find_ith(node *n, int i)
{
  if(n == nullptr)
    throw 233;

  int count = 0;
  stack<node *> Stak;
  while( n != nullptr || !Stak.empty())
  {
    while(n != nullptr)
    {
      Stak.push(n);
      n = n->left;
    }

    n = Stak.top();
    Stak.pop();
    count++;
    if(count == i)
      return n->data;
    
    n = n->right;
  }
    
  throw 233;
}