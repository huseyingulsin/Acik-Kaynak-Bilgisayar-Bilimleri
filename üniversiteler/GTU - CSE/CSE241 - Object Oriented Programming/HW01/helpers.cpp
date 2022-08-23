#include "helpers.h"

int getType()
{
    cout << "Welcome The Most Excited Game In The World" << endl
    << "-------->>>>>>>>> HEX <<<<<<<<<--------\n" << endl
    << "Rules are simple. Connect your team border to" << endl
    << "the other side and win the game.\n" << endl
    << "X wins when connected from top to bottom" << endl
    << "O wins when connected from left to right\n" << endl 
    << "First Select the game type you want from following." << endl
    << "1- P vs P \n2- P vs CPU\n3- CPU vs CPU (bonus, You can check quickly with this hocam :) )"  << endl
    << "Enter ypur choice:";

    int type;
    cin >> type;
    // prevent false size or entering a char.
    while(type != 1 && type != 2 && type != 3)
    {
        cerr << "Your input is invalid" << endl << "Enter Again:";
        cin.clear();
        cin.ignore(100,'\n');
        cin >> type;
    }
    return type;
}

int getSize()
{
    cout << "\nNow select size of the table from following" << endl
    << "6x6, 7x7, 8x0, 9x9 \n10x10, 11x11, 12x12  \nSelect (e.g: 6 for 6x6):";

    int size;
    cin >> size;
    // prevent false range or entering a char.
    while(size < 6 || size > 12)
    {
        cerr << "Your input is invalid" << endl << "Enter Again:";
        cin.clear();
        cin.ignore(100,'\n');
        cin >> size;
    }
    return size;
}

int ** createTable(int size)
{
    int **table = new int *[size];
    for (int i = 0; i < size; i++)
        table[i] = new int[size];

    // assign all value to points
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            table[i][j] = '.';
            
    return table;
}

void deleteTable(int **table, int size)
{
    //Free each sub-array
    for(int i = 0; i < size; ++i) {
        delete[] table[i];   
    }
    //Free the array of pointers
    delete[] table;
}

void printTable(int **table ,int size)
{
    // these things just showing a beautiful table. 
    cout << "  ";
    for (int i = 0; i < size; i++) cout << static_cast<char> ('a' + i)  << " ";
    cout << endl; 
    for (int i = 0; i < size; i++)
    {
        if (i < 9)
            cout << i+1 << " ";
        else
            cout << i+1;
        for (int k = 0; k < i; k++) cout << " ";
        for (int j = 0; j < size; j++)
        {
            cout << " " << static_cast<char>(table[i][j]);
        }
        cout << endl;
    }
}

void playTurn(int **table, int size, char player)
{
    string coordinate;
    cout << "Your Turn " << player << endl;
    cout << "Enter your coordinates (e.g: A1):";
    cin >> coordinate;
    int row = coordinate[0] - 'A';
    int column = coordinate[1] - '1';
    if (coordinate.length() == 3)
    {
        column = (coordinate[1] - '0') * 10 + (coordinate[2] - '1');
    }
    // check for if is input is correct
    while ((coordinate.length() != 2 && coordinate.length() != 3) || row > size - 1 || row < 0 || column < 0 || column > size - 1)
    {
        cout << "Your input is not correct. Be aware this game is case sensitive" << endl
        << "Enter your coordinates (e.g: A1):";
        cin.clear();
        cin.ignore(100, '\n');
        cin >> coordinate;
        row = coordinate[0] - 'A';
        column = coordinate[1] - '1';
        if (coordinate.length() == 3)
        {
            column = (coordinate[1] - '0') * 10 + coordinate[2] - '1';
        }
    }

    // check for if selected field is empty
    while (table[column][row] != '.')
    {
        cerr << "This field is not empty" << endl 
        << "Enter your coordinates (e.g: A1):";
        cin.clear();
        cin.ignore(100, '\n');
        cin >> coordinate;
        row = coordinate[0] - 'A';
        column = coordinate[1] - '1';
        if (coordinate.length() == 3)
        {
            column = (coordinate[1] - '0') * 10 + coordinate[2] - '1';
        }
    }

    table[column][row] = player;
}

void playComputer(int **table, int size, char player)
{
    random_device randomCreator;
    mt19937 rand(randomCreator());
    uniform_int_distribution<mt19937::result_type> randRange(0, size -1);
    int row = randRange(randomCreator);
    int column = randRange(randomCreator);
    while (table[row][column] != '.')
    {
        row = randRange(randomCreator);
        column = randRange(randomCreator);
    }
    char column_c = column + 'A';
    cout << "Your Turn " << player << endl;
    cout << "Computer Entered: " << column_c << row + 1 << endl;
    table[row][column] = player;
}

void copyUppercaseArray(int **a, int **b, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (b[i][j] != '.')
                a[i][j] = b[i][j];
        }
    }
}

bool checkWinner(int **table, int x, int y, int **keepPositions, int size, char player) 
{
    // if player is x then every time look for
    // up to down
    // this means start looking for x values from top
    // to bottom till found an x value 
    if (player == 'x')
    {
        for (int i = 0; i < size; i++)
        {
            if(check(table, x + i, y, keepPositions, size, player))
                return true;
        }
    }
    // if player is o then everytime look
    // right to left
    // this means start looking for o values from left side and then
    // search till end of the size to right
    else if (player == 'o')
    {
        for (int i = 0; i < size; i++)
        {
            if(check(table, x, y + i, keepPositions, size, player))
                return true;
        }
    }
    return false;
}

// helper Function for checkWinner
bool isValid(int **table, int x, int y, int size, char player) 
{ 
    // if this field is valid return true
    if (x >= 0 && x < size && y >= 0 && y < size && table[x][y] == player)
        return true; 

    return false; 
} 

// helper function for checkWinner
bool check(int **table, int x, int y, int **keepPositions, int size, char player) 
{ 
    if (player == 'x')
    {
        if (y == size - 1 && x >= 0 && table[x][y] == player) {
            keepPositions[x][y] = player - 32; 
            return true; 
        }
    }
    else if (player == 'o')
    {
        if (x == size - 1 && y >= 0 && table[x][y] == player) {
            keepPositions[x][y] = player - 32; 
            return true; 
        }
    }
  
    if (isValid(table, x, y, size, player)) { 
        keepPositions[x][y] = player - 32; 
  
        // move down
        if (check(table, x + 1, y, keepPositions, size, player)) 
            return true; 
  
        // move right
        if (check(table, x, y + 1, keepPositions, size, player)) 
            return true; 

        // if player is x then move up right corner
        if (player == 'x')
        {
            if (check(table, x - 1, y + 1, keepPositions, size, player)) 
                return true; 
        }
        // if player is o then move down left corner
        else if (player == 'o')
        {
            if (check(table, x + 1, y - 1, keepPositions, size, player)) 
                return true; 
        }

        // if none of them can return true then clear data from keepPoints array
        keepPositions[x][y] = '.'; 
        return false; 
    } 
  
    return false; 
} 
