#include<iostream>
using namespace std;

template<typename T>
class linkQueue{
private:
	struct node{
		T data;
		node *next;
	};

	node *head = nullptr;
	node *rear = nullptr;

	int _size;
public:
	linkQueue() 
	{ 
		rear = new node;
		head = rear;
	}
	~linkQueue(){}

	bool IsEmpty()
	{
		return head == rear;
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

	T getHead()
	{
		return head->next->data;
	}

};

template<typename T>
class Binary_Tree{
private:
	struct node{
		T data;
		node *parent=nullptr;
		node *lchild = nullptr;
		node *rbrother = nullptr;
	};

	node *root = nullptr;
	node **nodelist = nullptr;
	int length_Of_nodelist;
public:
	Binary_Tree(){}
	~Binary_Tree(){}
	void Create_tree(int num)
	{
		nodelist = new node *[num + 1]{nullptr};
		length_Of_nodelist = num;
	}

	void Create_Node(int Node_Num, int lchild, int rbrother, T &val)
	{
		if(nodelist[Node_Num] == nullptr)
			nodelist[Node_Num] = new node;
		nodelist[Node_Num]->data = val;

		if(lchild != 0)
		{
			if(nodelist[lchild] == nullptr)
				nodelist[lchild] = new node;

			nodelist[lchild]->parent = nodelist[Node_Num];
			nodelist[Node_Num]->lchild = nodelist[lchild];
		}	

		if(rbrother != 0)
		{
			if(nodelist[rbrother] == nullptr)
				nodelist[rbrother] = new node;
			nodelist[rbrother]->parent = nodelist[Node_Num];
			nodelist[Node_Num]->rbrother = nodelist[rbrother];
		}
	}

	void Create_Root()
	{
		for (int i = 1; i <= length_Of_nodelist; ++i)
			if(nodelist[i]->parent == nullptr)
			{
				root = nodelist[i];
				break;
			}
	}

	void pre_order() { pre_order(root); }
	void pre_order(node *n) 
	{
		if(n!=nullptr)
			cout << n->data<<' ';
		if(n->lchild != nullptr)
			pre_order(n->lchild);
		
		if(n->rbrother != nullptr)
			pre_order(n->rbrother);
	}

	void post_order() { post_order(root); }
	void post_order(node *n)
	{		
		if(n->lchild != nullptr)
			post_order(n->lchild);		
		if(n->rbrother != nullptr)
			post_order(n->rbrother);
		if (n != nullptr)
			cout<< n->data << ' ';
	}
	
	void mid_order() { mid_order(root); }
	void mid_order(node *n)
	{
		if(n->lchild != nullptr)
			mid_order(n->lchild);
		if (n != nullptr)
			cout<< n->data << ' ';
		if(n->rbrother != nullptr)
			mid_order(n->rbrother);
	}


	void level_order()
	{
		if(root==nullptr)
			return;

		linkQueue<node *> Queue;
		Queue.enQueue(root);
		while(!Queue.IsEmpty())
		{
			node *tmp = Queue.getHead();
			Queue.deQueue();
			cout << tmp->data<<' ';
			for (auto p = tmp->lchild; p!=nullptr; p=p->rbrother)
				Queue.enQueue(p);
		}
	}
};

	

int main()
{
	Binary_Tree<int> trie;
	int num;
	cin>>num;
	trie.Create_tree(num);
	for (int i = 1; i<=num; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		trie.Create_Node(i, a, b, c);
	}
	trie.Create_Root();
	trie.pre_order();
	cout << '\n';
	trie.mid_order();
	cout << '\n';
	trie.level_order();
	return 0;
}