#include <iostream>

constexpr uintmax_t maxVal(uintmax_t a, uintmax_t b)
{
    return (a > b) ? a : b;
}

constexpr uintmax_t ExchangeMachine(uintmax_t Value)
{
    return (Value == 0) ? 0 : maxVal(Value,
                                     (ExchangeMachine(Value/2) +
                                      ExchangeMachine(Value/3) +
                                      ExchangeMachine(Value/4)));
}

int main()
{
    constexpr uintmax_t n = 10000000000;
    constexpr uintmax_t n_result = ExchangeMachine(n);

    std::cout << "You can receive coins valued at " <<
    n_result << ", by starting with a " << n <<
    "-valued coin." << std::cout;

    return 0;
}
