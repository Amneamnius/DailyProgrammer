#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int maxRang = 100;
    int minRang = 1;
    int compGuess;
    int cntr = 0;

    char uinput = 'l';

    cout << "Pick a random number between (1-100). I will try to guess it." <<
        endl;

    while (uinput != 'c')
    {
        compGuess = minRang + ( (maxRang - minRang) / 2);

        cntr++;

        cout << "My guess is " << compGuess << ". Is this (h)igh,(l)ow, or (c)orrect? ";
        cin >> uinput;

        if (uinput == 'h')
            maxRang = compGuess - 1;
        else
            minRang = compGuess + 1;
    }

    cout << "It took me " << cntr << " tries to guess your number." << endl;

    /*
    int maxRang = 100;
    int minRang = 1;
    int range = maxRang - minRang;
    int cntr = 0;

    int compGuess;
    char uinput;

    cout << "Pick a random number between (1-100). I will try to guess it." <<
        endl;

    while (uinput != 'c')
    {
        compGuess = rand() % range + minRang;

        cntr++;

        cout << "My guess is " << compGuess << " Is this (h)igh/(l)ow or (c)orrect? ";
        cin >> uinput;

        if (uinput == 'h')
        {
            maxRang = compGuess - 1;
            range = maxRang - minRang;
        }
        else if (uinput == 'l')
        {
            minRang = compGuess + 1;
            range = maxRang - minRang;
        }

    }

    cout << "It took me " << cntr << " tries to guess your number." << endl;
    */
    /*
    int ranNum = rand()%100 + 1;
    int guess = 0;
    int cntr = 0;

    while (guess != ranNum)
    {
        cout << "Enter your guess (1-100): ";
        cin >> guess;

        if (guess > ranNum)
            cout << "Too high";
        else if (guess < ranNum)
            cout << "Too low";
        else
        {
            cout << "Correct! The number was " << ranNum << endl;
            cout << "It took you " << cntr << " tries to find it.";
        }

        cout << endl;
        cntr++;

    }
    */
    return 0;
}
