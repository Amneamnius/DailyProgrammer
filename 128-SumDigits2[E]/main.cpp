//Challenge #128 - Sum-the-Digits, Part2 [Easy]

#include <iostream>
#include <string>
#include <sstream>

template <class T>
inline std::string to_string(const T& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

void sum(std::string);

int main()
{
    std::string input;

    std::cout << "Enter the string of digits to add up: ";
    std::cin >> input;

    sum(input);

    return 0;
}

void sum(std::string numbers)
{
    int RunTotal;

    RunTotal = 0;

    for(int i = 0; i < numbers.size(); i++)
    {
        RunTotal += int(numbers[i] - '0');
    }

    std::cout << RunTotal << std::endl;

    numbers = to_string(RunTotal);

    if(numbers.size() > 1)
        sum(numbers);
}
