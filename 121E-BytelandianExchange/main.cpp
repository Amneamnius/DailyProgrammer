// Challenge #121 [Easy]

#include <iostream>

int ExchangeMachine(int);

int main()
{
    int initVal;
    int numZeroVal = 0;

    std::cout << "Enter initial coin value: ";
    std::cin >> initVal;

    numZeroVal = ExchangeMachine(initVal);

    std::cout << "You receive " << numZeroVal <<
    " 0-valued coins.";

    return 0;
}

int ExchangeMachine(int Value)
{
    //Cannot accept 0-valued coins
    if(Value == 0)
        return 1;

    //Change coin into 3 lower valued
    return ExchangeMachine(Value/2) + ExchangeMachine(Value/3) +
    ExchangeMachine(Value/4);
}
