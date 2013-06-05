//Challenge #123 [Intermediate]

#include <iostream>

int compYears(int, int);

int main()
{
    int JYears, LMon;
    int D2Synch;

    std::cout << "Enter - Julian Years Lunar Months: ";
    std::cin >> JYears >> LMon;

    D2Synch = compYears(JYears, LMon);

    std::cout << D2Synch << std::endl;

    for(int i = 1; i < 1000; i++)
    {
        D2Synch = compYears(i, LMon);
        if(D2Synch != 0)
            std::cout << "(" << i << "," << LMon <<
            "), " << D2Synch << std::endl;
    }

    return 0;
}

int compYears(int Years, int Months)
{
    static const float JDaysperYear = 365.25;
    static const float LDaysperMonth = 29.53059;

    int Years2Day = int(JDaysperYear * Years);
    int LunarMo = int(Years2Day / LDaysperMonth + 0.5);

    return (LunarMo == Months) ? Years2Day : 0;
}
