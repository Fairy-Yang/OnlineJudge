#include<iostream>
using namespace std;

template<typename T>
class linkQueue{
private:
  struct node{
    T data;
    node *next=nullptr;
  };

  node *head = nullptr;
  node *rear = nullptr;

  int _size;

public:
  linkQueue() 
  {
    head = new node;
    rear = head;
    _size = 0;
  }

  bool IsEmpty() const
  {
    return head->next == NULL;
  }

  void enQueue(const T &x)
  {
    rear->next = new node;
    rear = rear->next;
    rear->data = x;
    ++_size;
  }

  void deQueue()
  {
    if(head->next == nullptr)
      return ;

    auto tmp = head->next;
    delete head;
    head = tmp;

    --_size;
  }

  T getHead() const
  {
    return head->next->data;
  }
};

template<typename T>
class Tree{
private:
  struct node{
    T data;
    node *parent = nullptr;
    node *lchild = nullptr;
    node *rchild = nullptr;
  };

  node *root = nullptr;
  node **nodelist = nullptr;
  int length_Of_nodelist;

public:
  void Create_Tree(int num)
  {
    nodelist = new node *[num + 1]{nullptr};
    length_Of_nodelist = num;
  }

  void Create_Node(int nodeNum, const int &lval, const int &rval)
  {
    if(nodelist[nodeNum] == nullptr)
      nodelist[nodeNum] = new node;
    
    if(lval != 0)
    {
      if(nodelist[lval] == nullptr)
        nodelist[lval] = new node;

      nodelist[lval]->parent = nodelist[nodeNum];
      nodelist[nodeNum]->lchild = nodelist[lval];
    }

    if(rval != 0)
    {
      if(nodelist[rval] == nullptr)
        nodelist[rval] = new node;

      nodelist[rval]->parent = nodelist[nodeNum];
      nodelist[nodeNum]->rchild = nodelist[rval];
    }
  }

  void Create_Root()
  {
    for(int i=1; i<=length_Of_nodelist; ++i)
    {
      if(nodelist[i]->parent == NULL)
       { root = nodelist[i]; break;}
    }
  }

  bool isCBD()
  {
    if(root == nullptr)
      return false;

    linkQueue<node *> Queue;
    Queue.enQueue(root);
    bool flag = false;

    while(!Queue.IsEmpty())
    {
      node *tmp = Queue.getHead();
      Queue.deQueue();

      if(tmp->lchild == nullptr && tmp->rchild != nullptr)
        return false;

      if(!flag)
      {
        //left and right are both empty;
        if(tmp->rchild == nullptr && tmp->lchild == nullptr)
        {
          flag = true;
          continue;
        }

        //left and right are not empty;
        if(tmp->lchild !=nullptr && tmp->rchild != nullptr)
        {
          Queue.enQueue(tmp->lchild);
          Queue.enQueue(tmp->rchild);
        }

        if (tmp->lchild != nullptr && tmp->rchild == nullptr)
        {
          flag = true;
          Queue.enQueue(tmp->lchild);
        }
      }
      // chect if tmp is leaf node;
      else
      {
        if(tmp->lchild != nullptr || tmp->rchild!=nullptr)
          return false;
      }
    }

    return true;
  }
};
int main()
{
  Tree<int> Trie;
  int num;
  cin >> num;
  Trie.Create_Tree(num);
  for (int i = 1; i <= num; ++i)
  {
    int a, b;
    cin>>a>>b;
    Trie.Create_Node(i, a, b);
  }

  Trie.Create_Root();
  cout << (Trie.isCBD() ? 'Y' : 'N');
  return 0;
}