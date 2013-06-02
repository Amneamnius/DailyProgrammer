#include <iostream>

using namespace std;

int main()
{
    int grade;

    cout << "Enter grade (0-100): ";
    cin >> grade;

    switch(grade/10)
    {
    case(10):
        cout << "Perfect Score!" << endl;
    case(9):
        cout << "You got an A.";
        break;
    case(8):
        cout << "You got a B.";
        break;
    case(7):
        cout << "You got a C.";
        break;
    case(6):
        cout << "You got a D.";
        break;
    case(5):
    case(4):
    case(3):
    case(2):
    case(1):
    case(0):
        cout << "You got an F.";
        break;
    default:
        cout << "Unkown input";
        break;
    }

    cout << endl;
    return 0;
}
