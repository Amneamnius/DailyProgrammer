#include <iostream>

using namespace std;

int main()
{
    int uinput;

    int cntr = 0;

    do
    {
        cout << "Please enter a number other than " << cntr << ": ";
        cin >> uinput;

        if (uinput == cntr)
            break;

        cntr++;
    }//while(uinput != 5 && cntr != 10);
    while(1);
    /*
    if (cntr == 10)
        cout << "Wow you're more paitient than I am, you win." << endl;
    else
        cout << "Hey! You weren't supposed to enter 5!" << endl;
    */

    return 0;
}
