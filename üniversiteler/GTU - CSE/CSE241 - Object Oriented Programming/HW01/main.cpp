#include "helpers.h"

int main()
{
    int type = getType();
    int size = getSize();
    // checks for if this player is winner
    bool checkX = 0;
    bool checkO = 0;
    // checks for equality
    int draw = 0;
    int **table = createTable(size);
    // for keeping winner players position create another table
    int **keepWinnerPositions = createTable(size);


    while(true)
    {
        // X's turn
        printTable(table, size);

        // P vs P || P vs CPU
        if (type == 1 || type == 2)
            playTurn(table, size, 'x');
        // CPU vs CPU
        else if (type == 3)
            playComputer(table, size, 'x');

        checkX = checkWinner(table, 0, 0, keepWinnerPositions, size, 'x');
        if (checkX) break;

        // O's turn
        printTable(table, size);
        
        // P vs P
        if (type == 1)
            playTurn(table, size, 'o');
        // P vs CPU || CPU vs CPU
        else if (type == 2 || type == 3)
            playComputer(table, size, 'o');

        checkO = checkWinner(table, 0, 0, keepWinnerPositions, size, 'o');
        if (checkO) break;

        // if there is an equality break the loop
        draw += 2;
        if (draw >= size * size ) break;
    }

    if (draw >= size * size)
        cout << endl <<" --->>DRAW<<--- " << endl <<
        "WELL DONE BOTH OF YOU" << endl;
    else if (checkX == 1)
        cout << endl << "PLAYER X WINS" << endl
        << "WELL DONE X :)" << endl;
    else if (checkO == 1)
        cout << endl << "PLAYER O WINS" << endl
        << "WELL DONE O :)" << endl;

    copyUppercaseArray(table, keepWinnerPositions, size);
    printTable(table, size);

    deleteTable(table, size);
    deleteTable(keepWinnerPositions, size);
    
}