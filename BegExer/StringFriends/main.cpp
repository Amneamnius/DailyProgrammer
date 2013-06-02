#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void replaceVowelwZ(string &input)
{
    replace(input.begin(),input.end(),'a','z');
    replace(input.begin(),input.end(),'e','z');
    replace(input.begin(),input.end(),'i','z');
    replace(input.begin(),input.end(),'o','z');
    replace(input.begin(),input.end(),'u','z');
}

int main()
{
    string FName, LName, FullName;
    string ReverseName;

    cout << "Enter your first name: ";
    cin >> FName;
    cout << "Enter your last name: ";
    cin >> LName;
    FullName = FName + " " + LName;

    replaceVowelwZ(FullName);
    ReverseName = string(FullName.rbegin(), FullName.rend());

    cout << "Hello " << FullName << "." << endl;
    cout << "Hello " << ReverseName << "." << endl;

    return 0;
}
