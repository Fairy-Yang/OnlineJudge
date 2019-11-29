#include<iostream>
using namespace std;

int main()
{

    double tmp=0, tax=0;
    cin>>tmp;
    tmp -= 3500;
    if(tmp<=0) ;
    else if(tmp <= 1500)
        tax = tmp * 0.03;
    else if(tmp <= 4500)
        tax = (tmp-1500)*0.1 + 45;
    else if(tmp <= 9000)
        tax = (tmp-4500)*0.2 + 345;
    else if(tmp <= 35000)
        tax = (tmp-9000)*0.25 + 1245;
    else if(tmp <= 55000)
        tax = (tmp-35000)*0.3 + 7745;
    else if(tmp <= 80000)
        tax = (tmp-55000)*0.35 + 13745;
    else
        tax = (tmp-80000)*0.45 + 22495;

    cout<<int(tax);
    return 0;
}