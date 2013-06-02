#include <iostream>

using namespace std;

void sayHello(const int cntr)
{
    for(int i = 0; i < cntr; i++)
        cout << "Hello World!" << endl;
}

int product(const int num1, const int num2)
{
    return num1*num2;
}

void half(int &num)
{
    cout << num << endl;

    num /= 2;

    if(num > 0)
        half(num);
}

int main()
{
    int number = 100;
    sayHello(3);
    cout << "3 * 4 = " << product(3, 4) << "." << endl;
    half(number);
    return 0;
}
