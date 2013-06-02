#include <iostream>

using namespace std;

int main()
{
    char board [3][3];

    cout << "Initializing game board: " << endl;
    //initialize the board
    for(int i = 0; i < 3; i++)
    {
        for(int k = 0; k < 3; k++)
        {
            board[i][k] = '.';
        }
    }

    char playturn = 'o';
    int urow;
    int ucol;
    int won = 0;
    char playwon;

    while (won == 0)
    {
        //display current board
        for(int i = 0; i < 3; i++)
        {
            for(int k = 0; k < 3; k++)
            cout << board[i][k];

            cout << endl;
        }

        if (playturn == 'o')
            cout << "Player o input your move, row col ";
        else
            cout << "Player x input your move, row col ";

        cin >> urow >> ucol;

        if(board[urow][ucol] == '.')
        {
            board[urow][ucol] = playturn;
            if(playturn == 'o')
                playturn = 'x';
            else
            playturn = 'o';
        }
        else
            cout << "Invalid move. Try again." << endl;

        //Check if someone's won
        //Check 3 rows
        //Check 3 colums
        //Check 2 diagonals
        for(int i = 0; i < 3; i++)
        {
            if((board[i][0] != '.') && (board[i][0] == board[i][1]) && (board[i][0] == board[i][2]))
            {
               won = 1;
               playwon = board[i][0];
            }

            if((board[0][i] != '.') && (board[0][i] == board[1][i]) && (board[0][i] == board[2][i]))
            {
                won = 1;
                playwon = board[0][i];
            }
        }

        if((board[0][0] != '.') && (board[0][0] == board[1][1]) && (board[0][0] == board[2][2]))
        {
            won = 1;
            playwon = board[0][0];
        }
        if((board[0][2] != '.') && (board[0][2] == board[1][1]) && (board[0][2] == board[2][0]))
        {
            won = 1;
            playwon = board[0][2];
        }

    }

    for(int i = 0; i < 3; i++)
    {
        for(int k = 0; k < 3; k++)
        cout << board[i][k];

        cout << endl;
    }

    cout << "Congratulations player " << playwon << ". You won!";
    return 0;
}
