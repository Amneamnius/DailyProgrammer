//Challenge #127 [Easy]

#include <iostream>

void M(int &Value)
{
    if(Value > 100)
    {
        std::cout << "M(" << (Value-10) << ") since " << Value <<
        " is greater than 100" << std::endl;
        Value -= 10;
    }
    else
    {
        std::cout << "M(M(" << (Value+11) << ")) since " << Value <<
        " is equal to or less than 100" << std::endl;
        M(Value += 11);
        M(Value);
    }
}

int main()
{
    int val = 99;
    std::cout << "M(" << val << ")" << std::endl;

    M(val);
    std::cout << val << std::endl;
    return 0;
}
