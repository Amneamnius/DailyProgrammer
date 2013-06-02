#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct people{
    int p;
    int pan_eat;

    // Using improper comparison to have a descending list, not ascending
    bool operator<(const people& a) const
    {
        return pan_eat > a.pan_eat;
    }
};

int main()
{
    std::vector<people> person (10);

    for(int i = 0; i < 10; i++)
    {
        person[i].p = i + 1;
        cout << "How many pancakes did Person " << person[i].p << " eat? ";
        cin >> person[i].pan_eat;
    }

    cout << endl;

    std::sort(person.begin(), person.end());

    for(int i = 0; i < 10; i++)
    {
        cout << "Person " << person[i].p << ": ate " <<
        person[i].pan_eat << " pancakes" << endl;
    }

    return 0;
}
