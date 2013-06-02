//Challenge #123 [Easy]

#include <iostream>

using namespace std;

int SumDigits(const int Value)
{
    int val = Value;
    int sum;

    do{
        sum = 0;
        while(val != 0)
        {
            //Add the right most digit
            sum += val % 10;
            //Keep the left most digits
            val /= 10;
        }
        val = sum;
    }while(sum / 10 != 0);

    return sum;
}

int SumDigRecur(int Value)
{
    while(Value > 9)
        Value = Value % 10 + SumDigRecur(Value/10);

    return Value;
}

int main()
{
    int inputVal;
    int digRoot;

    cout << "Please enter a number: ";
    cin >> inputVal;

    //digRoot = SumDigits(inputVal);
    digRoot = SumDigRecur(inputVal);

    cout << "The digital root of " << inputVal <<
    " is " << digRoot << "." << endl;
    return 0;
}
