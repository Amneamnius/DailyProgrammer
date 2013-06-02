//Challenge #121 [Intermediate]

#include <iostream>
#include <map>

typedef unsigned long long myType;

myType ExchangeMachine(myType);

int main()
{
    myType initVal = 0;
    myType maxExch = 0;

    std::cout << "Enter initial coin value: ";
    std::cin >> initVal;

    maxExch = ExchangeMachine(initVal);

    std::cout << "You can receive coins valued at " <<
    maxExch << "." << std::endl;

    return 0;
}

myType ExchangeMachine(myType Value)
{
    //Setup storage for the Values and their result (hash table)
    static std::map<myType, myType> memo;
    myType maximum;

    //base case, Value > exchanged coins
    // otherwise unkown
    if(Value < 12)
        return Value;

    //memoization case
    // Search for Value in memo
    //if .find(Value) == .end() then it is not found
    auto it = memo.find(Value);
    if (it != memo.end())
        //Same as memo[Value]
        return it -> second;

    //recursive case

    myType sum = ExchangeMachine(Value/2) +
    ExchangeMachine(Value/3) + ExchangeMachine(Value/4);

    maximum = (sum > Value) ? sum : Value;

    //Store this result for future reference
    memo[Value] = maximum;

    return maximum;
}
