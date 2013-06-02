//Challenge #119 [Easy]

#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;

void calcChange(int);

int main()
{
    float money;
    int moneyInt;

    cout << "Enter amount: ";
    cin >> money;

    moneyInt = int(floor(money * 100 + 0.5));

    calcChange(moneyInt);

    return 0;
}

void calcChange(int Value)
{
    int numQ, numD, numN, numP;

    numQ = Value / 25;
    Value %= 25;

    numD = Value / 10;
    Value %= 10;

    numN = Value / 5;
    Value %= 5;

    numP = Value;

    if(numQ != 0)
        cout << "Quarters: " << numQ << endl;
    if(numD != 0)
        cout << "Dimes: " << numD << endl;
    if(numN != 0)
        cout << "Nickles: " << numN << endl;
    if(numP != 0)
        cout << "Pennies: " << numP << endl;
}
