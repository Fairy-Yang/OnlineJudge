#include <climits>
#include <cfloat>
#include <iostream>
using namespace std;

int main()
{
    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LONG_LONG_MAX;

    //size of type or of variable in bytes
    cout << "size in bytes\n";
    cout << "int " << sizeof(int) << '\n';
    cout << "short " << sizeof n_short << '\n';
    cout << "long " << sizeof n_long << '\n';
    cout << "long long " << sizeof(long long) << '\n';
    cout << "double " << sizeof(double) << '\n';
    cout << "float " << sizeof(float) << '\n';

    //maximum value of types
    cout << "int " << n_int << '\n';
    cout << "short " << n_short << '\n';
    cout << "long " << n_long << '\n';
    cout << "long long " << n_llong << '\n';
    cout << "double " << DBL_MAX << '\n';
    cout << "float" << FLT_MAX << '\n';
    system("pause");
    return 0;
}