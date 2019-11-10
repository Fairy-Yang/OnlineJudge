#include<iostream>
using namespace std;

int main()
{
    //initialize the array in different ways
    int test[4] {1,2,3,4};  //c++11
    unsigned int counts[10] = {};    //all Aents set to 0;
    float A[] {};    //all Aents set to 0;
    char dogs[2]={'a','b'};


    cout<<"abc" "cde\n";  //output should be abccde, the two const strings are linked together;
    
    //"cin<<" operation doesn't read '\n', and remain it in the buffer;
    cout<<"input the year:\n";
    int year;
    (cin>>year).get();  //We use cin.get() to get '\n' to start a new line;
    char adress[80];
    cin.getline(adress, 80);
    cout<<adress;

    system("pause");
    return 0;
}