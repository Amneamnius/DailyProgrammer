#include <iostream>
#include <stdlib.h>

using namespace std;

bool isValid(const char board[3][3], const int crow, const int ccol)
{
    return (board[crow][ccol] == '.');
}

void compMove(char board[3][3])
{
    int crow, ccol;
    int validMove = 0;

    while(validMove == 0)
    {
        //block the player if they are near a win
        for(int i = 0; i < 3; i++)
        {
            if((board[i][0] == 'o') && (board[i][0] == board[i][1]))
            {
                crow = i;
                ccol = 2;
                validMove = isValid(board,crow,ccol);
                if(validMove)
                    break;
            }
            if((board[i][2] == 'o') && (board[i][1] == board[i][2]))
            {
                crow = i;
                ccol = 0;
                validMove = isValid(board,crow,ccol);
                if(validMove)
                    break;
            }
            if((board[0][i] == 'o') && (board[0][i] == board[1][i]))
            {
                crow = 2;
                ccol = i;
                validMove = isValid(board,crow,ccol);
                if(validMove)
                    break;
            }
            if((board[2][i] == 'o') && (board[1][i] == board[i][2]))
            {
                crow = 0;
                ccol = i;
                validMove = isValid(board,crow,ccol);
                if(validMove)
                    break;
            }
        }

        if(validMove)
            break;

        //check diagonals
        if((board[0][0] == 'o') && (board[0][0] == board[1][1]))
        {
            crow = 2;
            ccol = 2;
            validMove = isValid(board,crow,ccol);
            if(validMove)
                break;
        }
        if((board[2][2] == 'o') && (board[1][1] == board[2][2]))
        {
            crow = 0;
            ccol = 0;
            validMove = isValid(board,crow,ccol);
            if(validMove)
                break;
        }
        if((board[0][2] == 'o') && (board[0][2] == board[1][1]))
        {
            crow = 2;
            ccol = 0;
            validMove = isValid(board,crow,ccol);
            if(validMove)
                break;
        }
        if((board[2][0] == 'o') && (board[1][1] == board[2][0]))
        {
            crow = 0;
            ccol = 2;
            validMove = isValid(board,crow,ccol);
            if(validMove)
                break;
        }

        //Random Movement
        crow = rand() % 3;
        ccol = rand() % 3;

        validMove = isValid(board,crow,ccol);
    }

    cout << "Computer move: " << crow << " " << ccol << endl;
    board[crow][ccol] = 'x';
}

char checkWin(const char board[3][3], int &won)
{
        //Check 3 rows
        //Check 3 colums
        //Check 2 diagonals
        for(int i = 0; i < 3; i++)
        {
            if((board[i][0] != '.') && (board[i][0] == board[i][1]) && (board[i][0] == board[i][2]))
            {
               won = 1;
               return board[i][0];
            }

            if((board[0][i] != '.') && (board[0][i] == board[1][i]) && (board[0][i] == board[2][i]))
            {
                won = 1;
                return board[0][i];
            }
        }

        if((board[0][0] != '.') && (board[0][0] == board[1][1]) && (board[0][0] == board[2][2]))
        {
            won = 1;
            return board[0][0];
        }
        if((board[0][2] != '.') && (board[0][2] == board[1][1]) && (board[0][2] == board[2][0]))
        {
            won = 1;
            return board[0][2];
        }
}

int main()
{
    char board[3][3];
    int urow, ucol, won = 0;
    char whoWon;

    cout << "Initializing game board: " << endl;
    //initialize the board
    for(int i = 0; i < 3; i++)
    {
        for(int k = 0; k < 3; k++)
        {
            board[i][k] = '.';
            cout << board[i][k];
        }
        cout << endl;
    }

    cout << "Player (o) select your move, row col: ";
    cin >> urow >> ucol;

    board[urow][ucol] = 'o';

    while(won == 0)
    {
        compMove(board);

        //display current board
        for(int i = 0; i < 3; i++)
        {
            for(int k = 0; k < 3; k++)
            cout << board[i][k];

            cout << endl;
        }

        cout << "Player (o) select your move, row col: ";
        cin >> urow >> ucol;

        if(board[urow][ucol] == 'x')
        {
            cout << "Invalid move, try again." << endl;
            continue;
        }

        board[urow][ucol] = 'o';

        whoWon = checkWin(board, won);
    }

    for(int i = 0; i < 3; i++)
    {
        for(int k = 0; k < 3; k++)
        cout << board[i][k];

        cout << endl;
    }

    cout << "Player " << whoWon << " won. Thanks for playing.";

    return 0;
}
