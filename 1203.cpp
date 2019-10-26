#include<iostream>
#include<cstring>
using namespace std;

template<class T>
class list{
public:
    virtual void clear()=0;
    virtual int length() const=0;
    virtual void insert(int i, const T &x)=0;
    virtual void remove(int i)=0;
    virtual int search(const T &x) const=0;
    virtual T visit(int i) const=0;
    virtual void traverse()const=0;
    virtual ~list(){};
};

template<class T>
class seqList: public list<T>{
private:
    T *data;
    int currentLength;
    int Maxsize;
    void doublespace();
public:
    seqList(int Maxsize = 20000);
    ~seqList();
    void clear();
    int length()const;
    void insert(int i, const T &x);
    void remove(int i);
    int search(const T &x) const;
    T visit(int i) const;
    void traverse() const;
};

template<class T>
void func(char []);

int main()
{
    char ch[10];
    cin.getline(ch,10);
    if(strcmp(ch, "int")==0)
        func<int> (ch);
    else if(strcmp(ch, "char")==0)
        func<char>(ch);
    else
        func<double>(ch);
    return 0;
}

template<class T>
void func(char ch[])
{
    seqList<T> result;
    T t;
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n+m;++i){
        cin>>t;
        result.insert(i, t);
    }
    result.traverse();
}

template<class T>
seqList<T>::seqList(int initsize)
{
    data = new T[initsize];
    Maxsize = initsize;
    currentLength = 0;
}

template<class T>
seqList<T>::~seqList()
{
    delete []data;
}

template<class T>
void seqList<T>::clear()
{
    currentLength=0;
}

template<class T>
int seqList<T>::length()const
{
    return currentLength;
}

template<class T>
void seqList<T>::insert(int i, const T &x)
{
    if(currentLength == Maxsize) doublespace();
    //其实对i还要做参数检查，防止下标越界
    for(int j=currentLength; j>i; j--)
        data[j]=data[j-1];
    data[i]=x;
    ++currentLength;
}

template<class T>
void seqList<T>::remove(int i)
{
    for(;i<currentLength-1;++i)
        data[i]=data[i+1];

    --currentLength;
}

template<class T>
int seqList<T>::search(const T &x)const
{
    int i=0;
    for(i=0; i<currentLength; ++i)
    {
        if(data[i] == x)
            return i;
    }

    return -1;
}

template<class T>
T seqList<T>::visit(int i) const
{
    //省略了参数检查
    return data[i];
}

template <class T>
void seqList<T>::traverse() const
{
    for(int i=0; i<currentLength; ++i)
        cout<<data[i]<<' ';
}

template <class T>
void seqList<T>::doublespace()
{
    int i=0;
    T *tmp=data;
    Maxsize*=2;
    data = new T[Maxsize];
    for(i=0; i<currentLength; ++i);
        data[i] = tmp[i];

    delete []tmp;
}
