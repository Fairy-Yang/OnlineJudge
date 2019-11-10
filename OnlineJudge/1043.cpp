#include<iostream>
#include<queue>
using namespace std;

class Binary_Tree{
private:
  struct node{
    node *left = nullptr;
    node *right = nullptr;
    node *parent = nullptr;
  };

  node *root = nullptr;
  node **nodelist = nullptr;
  int capacity;
  int Current_Size;

public:
  Binary_Tree(int n)
  {
    capacity = n;
    nodelist = new node *[n]{nullptr};
    Current_Size = 0;
  }
  ~Binary_Tree(){}

  void insert(const int &x)
  {
    Current_Size++;
    if(nodelist[Current_Size] == nullptr)
      nodelist[Current_Size] = new node;
    if(nodelist[x] == nullptr)
      nodelist[x] = new node;

    nodelist[Current_Size]->parent = nodelist[x];
    if(nodelist[x]->left == nullptr)
      nodelist[x]->left = nodelist[Current_Size];
    else
      nodelist[x]->right = nodelist[Current_Size];
    
  }

  void Find_root()
  {
    for (int i = 0; i < capacity; ++i)
      if(nodelist[i]->parent == nullptr)
      {
        root = nodelist[i];
        return;
      }
  }

  bool is_CBT()
  {
    if(root == nullptr)
      return false;

    queue<node *> que;
    que.push(root);
    bool flag = false;
    while(!que.empty())
    {
      node *n = que.front();
      que.pop();

      if (n->left == nullptr && n->right != nullptr)
        return false;
      
      if(!flag)
      {
        if(n->left != nullptr && n->right == nullptr)
        {
          que.push(n->left);
          flag = true;
          continue;
        }

        if(n->left != nullptr && n->right != nullptr)
        {
          que.push(n->left);
          que.push(n->right);
        }

        if (n->left == nullptr && n->right == nullptr)
        {
          flag = true;
          continue;
        }
      }
      else
      {
        if(n->left != nullptr || n->right != nullptr)
          return false;
      }
    }

    return true;
  }
};

int main()
{
  int n;
  cin >> n;

  if(n == 0)
  {
    cout << "false";
    return 0;
  }
  if(n==1)
  {
    cout << "true";
    return 0;
  }
  Binary_Tree trie(n);
  while(n-->1)
  {
    int tmp;
    cin>>tmp;
    trie.insert(tmp);
  }

  trie.Find_root();
  cout << (trie.is_CBT() ? "true" : "false");
  return 0;
}