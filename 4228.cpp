//time limit exceeded
#include<iostream>
#include<string>
using namespace std;

//root and all lchild stores email address
//rbrother stores name
template<class T>
class Trie{
private:
  struct node{
    node *lchild=nullptr, *rbrother=nullptr;
    T data;
  };

  node *root = nullptr;
public:
  Trie()
  {
    root = new node;
  }
  ~Trie(){}

  void insert(T &name, T &address)
  {
    node *tmp = root;

    while(tmp->lchild!=nullptr)
    {
      tmp = tmp->lchild;
      if (tmp->data == address)
      {
        while(tmp->rbrother != nullptr)
          tmp = tmp->rbrother;
        tmp->rbrother = new node();
        tmp->rbrother->data = name;
        return;
      }
    }

    tmp->lchild = new node;
    tmp->lchild->data = address;
    tmp->lchild->rbrother = new node;
    tmp->lchild->rbrother->data = name;
  }

  void traverse()
  {
    node *tmp = root;
    while(tmp!=nullptr)
    {
      node *t = tmp->rbrother;
      while(t!=nullptr)
      {
        cout << t->data <<' ';
        t = t->rbrother;
      }
        
      cout << '\n';
      tmp = tmp->lchild;
    }
  }
};

int main()
{
  Trie<string> ss;
  int n;
  cin >> n;
  while(n-->0)
  {
    string name, address;
    cin >> name >> address;
    ss.insert(name, address);
  }
  ss.traverse();
  return 0;
}