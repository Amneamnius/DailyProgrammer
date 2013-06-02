#include <iostream>

using namespace std;

int main()
{
    int selection;

    cout << "Choose your drink.(1-5)" << endl;
    cout << "1. Coke" << endl << "2. Water" << endl << "3. Sprite" <<
    endl << "4. Dr. Pepper" << endl << "5. Juice" << endl;

    cin >> selection;

    switch(selection)
    {
    case(1):
        cout << "Here is your Coca-Cola.";
        break;
    case(2):
        cout << "Here is your water.";
        break;
    case(3):
        cout << "Here is your Sprite.";
        break;
    case(4):
        cout << "Here is your Dr. Pepper.";
        break;
    case(5):
        cout << "Here is your juice.";
        break;
    default:
        cout << "Error. Choice was not valid, here is your money back.";
        break;
    }

    cout << endl;

    return 0;
}
