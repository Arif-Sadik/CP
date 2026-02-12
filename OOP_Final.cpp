#include <iostream>
using namespace std;

int main()
{

    int b = 66;
    int &a = b;

    // cout << a << endl;
    // cout << b << endl;

    a = 77;

    //  cout << a << endl;
    // cout << b << endl;

     int c = 99;
     a = c;


     cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    a++;

   cout << a << endl;
   cout << b << endl;
   cout << c << endl;


    return 0;
}
