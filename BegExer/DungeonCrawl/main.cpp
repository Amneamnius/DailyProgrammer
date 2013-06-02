#include <iostream>
#include <stdlib.h>

using namespace std;

//Initialize the grid, (0,0) is player start. (9,9) is exit.
//Traps are located randomly
void gridInit(char grid[10][10], int Mloc[2][5])
{
    int Mcntr = 0;

    for(int i = 0; i < 10; i++)
        for(int k = 0; k < 10; k++)
        {
            //Spawn a trap if a random number = 5
            if((rand() % 10) == 5)
                grid[i][k] = 'T';
            else if (((rand() %10) == 8) && Mcntr < 5)
            {
                Mloc[0][Mcntr] = i;
                Mloc[1][Mcntr] = k;
                Mcntr++;

                grid[i][k] = 'M';
            }
            else
                grid[i][k] = '.';
        }

    grid[0][0] = 'G';
    grid[9][9] = 'X';
}

//Output the grid to the user
void displayGrid(const char grid[10][10])
{
    for(int i = 0; i < 10; i++)
    {
        for(int k = 0; k < 10; k++)
            cout << grid[i][k];
        cout << endl;
    }


}

int userMove(char grid[10][10], char umove)
{
    static int plocrow = 0;
    static int ploccol = 0;
    int oldplocrow = plocrow;
    int oldploccol = ploccol;

    if(umove == 'u')
    {
        if(plocrow - 1 >= 0)
            plocrow--;
        else
            return -1;
    }
    if(umove == 'd')
    {
        if(plocrow + 1 < 10)
            plocrow++;
        else
            return -1;
    }
    if(umove == 'l')
    {
        if(ploccol - 1 >= 0)
            ploccol--;
        else
            return -1;
    }
    if(umove == 'r')
    {
        if(ploccol + 1 < 10)
            ploccol++;
        else
            return -1;
    }

    grid[oldplocrow][oldploccol] = '.';

    if(grid[plocrow][ploccol] == 'T')
        return -2;
    if(grid[plocrow][ploccol] == 'X')
        return 1;

    grid[plocrow][ploccol] = 'G';
    return 0;
}

int MonMove(char grid[10][10], int Mloc[2][5])
{
    int MonMovement;

    for(int i = 0; i < 5; i++)
    {
        MonMovement = rand() % 4;

        if(MonMovement == 0) //Try to move up
        {
            if((Mloc[0][i] - 1) >= 0)
            {
                switch(grid[Mloc[0][i] - 1][Mloc[1][i]])
                {
                case 'G':
                    return 0;
                case 'M':
                    continue;
                case 'T':
                    continue;
                }
                grid[Mloc[0][i]][Mloc[1][i]] = '.';
                Mloc[0][i]--;
                grid[Mloc[0][i]][Mloc[1][i]] = 'M';
            }
        }else
        if(MonMovement == 1) //Try to move down
        {
            if((Mloc[0][i] + 1) < 9)
            {
                switch(grid[Mloc[0][i] + 1][Mloc[1][i]])
                {
                case 'G':
                    return 0;
                case 'M':
                    continue;
                case 'T':
                    continue;
                }
                grid[Mloc[0][i]][Mloc[1][i]] = '.';
                Mloc[0][i]++;
                grid[Mloc[0][i]][Mloc[1][i]] = 'M';
            }
        }else
        if(MonMovement == 2) //Try to move left
        {
            if((Mloc[1][i] - 1) >= 0)
            {
                switch(grid[Mloc[0][i]][Mloc[1][i] - 1])
                {
                case 'G':
                    return 0;
                case 'M':
                    continue;
                case 'T':
                    continue;
                }
                grid[Mloc[0][i]][Mloc[1][i]] = '.';
                Mloc[1][i]--;
                grid[Mloc[0][i]][Mloc[1][i]] = 'M';
            }
        }else
        if(MonMovement == 3) //Try to move right
        {
            if((Mloc[1][i] + 1) < 9)
            {
                switch(grid[Mloc[0][i]][Mloc[1][i] + 1])
                {
                case 'G':
                    return 0;
                case 'M':
                    continue;
                case 'T':
                    continue;
                }
                grid[Mloc[0][i]][Mloc[1][i]] = '.';
                Mloc[1][i]++;
                grid[Mloc[0][i]][Mloc[1][i]] = 'M';
            }
        }
    }

    return 1;
}

int main()
{
    char grid[10][10];
    char umove;
    int ureachX = 0;
    int Mloc[2][5]; //Only 5 monsters can exist
    int safeFromMon = 1;

    //Initialize the Grid
    gridInit(grid, Mloc);

    cout << "Hello Traveler, in order to win you must avoid all the trap and reach the tile labeled X." << endl;

    displayGrid(grid);

    while (!ureachX)
    {
        cout << "What will you do? Move (u)p/(d)own/(l)eft/(r)ight? ";
        cin >> umove;

        ureachX = userMove(grid, umove);
        if(ureachX == -2)
        {
            cout << "You hit a trap! Try again." << endl;
            return 0;
        }
        if(ureachX == 1)
        {
            cout << "You've reached the Treasure!" << endl;
            return 0;
        }
        if(ureachX == -1)
        {
            cout << "Invalid move, try again." << endl;
            ureachX = 0;
        }

        safeFromMon = MonMove(grid, Mloc);

        if(!safeFromMon)
        {
            cout << "A monster killed you, try again." << endl;
            return 0;
        }

        displayGrid(grid);
    }

    return 0;
}
