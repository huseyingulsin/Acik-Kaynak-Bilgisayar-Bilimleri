#include "Hex.h"


Hex::Hex() // default constructor
{
    size = 0;
    gameType = 0;
    turn = player1;
    gameState = active;
    activeGames++;
    allGames++;
    Welcome();
    playGame();
}

// take filename, load game and play
Hex::Hex(string filename)
{

    ifstream fp(filename);
	if(fp.is_open() == false)
    {
		cerr << "Couldn't open file.\n";  return;
	}

    activeGames++;
    allGames++;
    gameState = active;
    loadGame(filename);
    printTable();
    playGame();
}

// take filename, load game do not paly
Hex::Hex(string filename, bool valTest) :test(valTest)
{
    ifstream fp(filename);
	if(fp.is_open() == false)
    {
		cerr << "Couldn't open file.\n";  return;
	}

    activeGames++;
    allGames++;
    gameState = active;
    loadGame(filename);
    
}

void Hex::Welcome()
{
    cout << endl << endl
    << "First Select the game type you want from following." << endl
    << "1- P vs P \n2- P vs CPU"  << endl
    << "Enter ypur choice:";

    if (gameType == 0)
        cin >> gameType;
    else
        cout << gameType << " (entered from constructor)" << endl;

    // prevent false size or entering a char.
    while(gameType != PvP && gameType != PvCPU)
    {
        cerr << "Your input is invalid" << endl << "Enter Again:";
        cin.clear();
        cin.ignore(100,'\n');
        cin >> gameType;
    }
}

void Hex::allCommands() const
{
    cout << endl << endl <<  "Commands List" << endl
    << "[Coordinate]: your coordinate e.g -> A5" << endl
    << "[SAVE] [filename] " << endl <<  "[LOAD] [filename]" << endl 
    <<  "   Save or Load your game e.g -> SAVE myGame.txt" << endl
    << "[Q] -> Quit current active game." << endl
    << "[P] -> Print currnet Hex table" << endl
    << "[H] -> See this help massage" << endl << endl;
}

void Hex::createTable()
{
    for (int i = 0; i < size; i++)
    {
        hexCells.push_back(vector<Cell>());
        keepUppercase.push_back(vector<Cell>());
        for (int j = 0; j < size; j++)
        {
            hexCells[i].push_back(Cell());
            keepUppercase[i].push_back(Cell());
        }
    }
    //hexCells.reserve(size);
    // keepUppercase.reserve(size);
    // for (int i = 0; i < size; i++)
    // {
    //     //hexCells[i].reserve(size);
    //     keepUppercase[i].reserve(size);
    // }
    // for (int i = 0; i < size; i++)
    //     for (int j = 0; j < size; j++)
    //     {
    //         // hexCells[i][j].setState(dot);
    //         keepUppercase[i][j].setState(dot);
    //     }
}

void Hex::printTable() const
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
            cout << " " << hexCells[i][j].getState();
        }
        cout << endl;
    }
}

void Hex::play()
{
    // CPU plays random
    setPlayer(player2);
    random_device randomCreator;
    mt19937 rand(randomCreator());
    uniform_int_distribution<mt19937::result_type> randRange(0, size -1);
    int row = randRange(randomCreator);
    int column = randRange(randomCreator);
    while (hexCells[row][column].getState() != dot)
    {
        row = randRange(randomCreator);
        column = randRange(randomCreator);
    }
    char column_c = column + 'A';
    cout << "Your Turn " << turn << endl;
    cout << "Computer Entered: " << column_c << row + 1 << endl;
    hexCells[row][column].setState(turn);
    printTable();
}

void Hex::play(Cell position)
{
    turn = position.getState();
    hexCells[position.getColumn()][position.getRow()].setState(position.getState());
    printTable();
}

void Hex::playGame()
{
    // Size first time asigned here as expected in PDF

    // default size is sended 0, so it will certain execute this loop
    if (size < 6)
    {
        while(size < 6)
        {
            cout << "\nNow select table size. min 6 allowed." << endl
            << "Select (for 6x6 table, type 6):";
            cin >> size; if (size > 5) break;
            cerr << "Your input is invalid" << endl << "Enter Again:";
            cin.clear();
            cin.ignore(100,'\n');
        }
        createTable();
    }

    string coordinate;
    Cell tempCell;
    while(true)
    {
        // There are some code repetition :()
        
        // Send tempcell to a while loop, till checkTurn function
        // returns a false value, it means a correct coordinate entered
        tempCell.setState(player1);
        while(checkTurn(coordinate, tempCell)); 
        // If gamestate turns to passive, then retrun to main
        if (gameState == passive) return;
        play(tempCell);
        // if there is a winner, break
        if (checkWinner()) break;

        // if gametype is PvCPU
        if (gameType == PvCPU)
            play();
        else
        {
            tempCell.setState(player2);
            while(checkTurn(coordinate, tempCell));
            if (gameState == passive) return;
            // if gameType has changed
            if (gameType == PvCPU){ printTable(); continue; }
            play(tempCell);
        }
        if (checkWinner()) break;
    }
    
    // it means there is a winner
    if (gameState == winner)
        coppyToUpper();
}

bool Hex::checkTurn(string coordinate, Cell& tempCell)
{
    cout << endl << "Your Turn " << tempCell.getState() << endl;
    cout << "Type H for all Commands" << endl << "Command: ";
    cin >> ws;
    getline(cin, coordinate);

    if (coordinate[0] == 'H' && coordinate.length() == 1)
    {
        allCommands();
        return checkTurn(coordinate, tempCell);
    }
    else if (coordinate[0] == 'Q' && coordinate.length() == 1)
    {
        cout << "Quiting... " << endl;

        gameState = passive;
        cout << "This game will be active in background" << endl;
        cout << "There are " << activeGames << " active games now" << endl;
        return false;

    }
    else if (coordinate[0] == 'P' && coordinate.length() == 1)
    {
        printTable();
        return checkTurn(coordinate, tempCell);
    }
    if (saveOrLoad(coordinate))
        return true;

    // in load circumtance, this func should return false.
    else if(coordinate.compare(0, 4, "LOAD", 0 ,4) == 0 && coordinate.size() > 5) return false;
    else
    {
        int row = coordinate[0] - 'A';
        int column = coordinate[1] - '1';
        if (coordinate.length() == 3)
            column = (coordinate[1] - '0') * 10 + (coordinate[2] - '1');
        if ((coordinate.length() != 2 && coordinate.length() != 3) || row > size - 1 || row < 0 || column < 0 || column > size - 1)
        {
            cerr << "Your input is not correct. Be aware this game is case sensitive" << endl;
            return checkTurn(coordinate, tempCell);
        }
        if (hexCells[column][row].getState() != dot)
        {   
            cerr << "this filed is not empty" << endl;
            return checkTurn(coordinate, tempCell);
        }
        tempCell.setRow(row);
        tempCell.setColumn(column);
        return false;
    }
}

bool Hex::saveOrLoad(string str)
{
    // look to type of command
    if(str.compare(0, 4, "SAVE", 0 ,4) == 0 && str.size() > 5)
    {
        saveGame(str.substr(5));
        return 1;
    }
    else if(str.compare(0, 4, "LOAD", 0 ,4) == 0 && str.size() > 5)
    {
        loadGame(str.substr(5));
        return 0;
    }

    return 0;
}

void Hex::saveGame(string filename)
{
    // writing mode
	ofstream fp(filename);
	if(fp.is_open() == false)
    {
		cerr << "Could not open the file\n";  return;
	}

    // write those to file
	fp << gameType << endl << size << endl << turn << endl;

    // write table as type of char
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            fp << hexCells[i][j].getState();
        fp << endl;
    }

	cout << "Game saved as -> " + filename << endl;
	fp.close();  return;
}

void Hex::loadGame(string filename)
{
    // rading mode
	ifstream fp(filename);
	if(fp.is_open() == false)
    {
		cerr << "Couldn't open file.\n";  return;
	}

    // keep old gameType 
    int tempType = gameType;

    // read variables from file
	fp >> gameType >> size  >> turn;

    // resize table
    hexCells.resize(size);
    keepUppercase.resize(size);
    for (int i = 0; i < size; i++)
    {   
        keepUppercase[i].resize(size);
        hexCells[i].resize(size);
    }
 
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            char temp;
            fp >> temp;
            hexCells[i][j].setState(temp);
        }
    }
	
    fp.close();

    
    if (gameType == 2)
        turn = player1;
    cout << "Game Loaded from -> " + filename << endl;

    if (!test)
    {
        // if gameType changed, inform the user.
        if (tempType != gameType)
            cout << "Game Type is changed" << endl;
        cout << "There is new table" << endl;
    }
    
    
    // printTable();
}

bool Hex::checkWinner()
{
    int x = 0, y = 0;
    // if player is x then every time look for
    // up to down
    // this means start looking for x values from top
    // to bottom till found an x value 
    if (turn == player1)
    {
        for (int i = 0; i < size; i++)
        {
            if(check(x + i, y))
            {
                gameState = winner;
                return true;
            }
        }
    }
    // if player is o then everytime look
    // right to left
    // this means start looking for o values from left side and then
    // search till end of the size to right
    else if (turn == player2)
    {
        for (int i = 0; i < size; i++)
        {
            if(check(x, y + i))
            {
                gameState = winner;
                return true;
            }
        }
    }
    return false;
}

bool Hex::check(int x, int y)
{
    if (turn == player1)
    {
        if (y == size - 1 && x >= 0 && hexCells[x][y].getState() == turn) {
            keepUppercase[x][y].setState(turn - 32); 
            return true; 
        }
    }
    else if (turn == player2)
    {
        if (x == size - 1 && y >= 0 && hexCells[x][y].getState() == turn) {
            keepUppercase[x][y].setState(turn - 32); 
            return true; 
        }
    }
  
    if (isValid(x, y)) { 
        keepUppercase[x][y].setState(turn - 32); 
  
        // move down
        if (check(x + 1, y)) 
            return true; 
  
        // move right
        if (check(x, y + 1)) 
            return true; 

        // if player is x then move up right corner
        if (turn == player1)
        {
            if (check(x - 1, y + 1)) 
                return true; 
        }
        // if player is o then move down left corner
        else if (turn == player2)
        {
            if (check(x + 1, y - 1)) 
                return true; 
        }

        // if none of them can return true then clear data from keepPoints array
        keepUppercase[x][y].setState(dot); 
        return false; 
    } 
  
    return false; 
}

bool Hex::isValid(int x, int y)
{
    // if this field is valid return true
    if (x >= 0 && x < size && y >= 0 && y < size && hexCells[x][y].getState() == turn)
        return true; 

    return false; 
}

void Hex::coppyToUpper()
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (keepUppercase[i][j].getState() != dot)
                hexCells[i][j] = keepUppercase[i][j];
    
    cout << endl << "You win  ->>>>> " << static_cast<char>(turn - 32) << " <<<<<<<-  " << endl<< "Congrats You are the Pro Hex Player <3<3" << endl << endl;
    printTable();
    gameState = winner;
    cout << "This game is passive now" << endl;
    activeGames--;
    cout << "There are " << activeGames << " active games now" << endl; 
}

int Hex::countMarked(Hex another)
{
    int count = 0;

    for (int i = 0; i < another.getSize(); i++)
    {
        for (int j = 0; j < another.size; j++)
        {
            if (another.hexCells[i][j].getState() != dot)
                count++;
        }
    }
    return count;
} 

int Hex::countMarked(vector<Hex> Games)
{
    int gameCount = Games.size();
    int totalCount = 0;
    for (int i = 0; i < gameCount; i++)
    {
        if (Games[i].getStatus() != winner)
            totalCount += countMarked(Games[i]);
    }
    return totalCount;
}

bool Hex::compareMarked(Hex another) const
{
    cout << "1st object has " << countMarked(*this) << " place" << endl;
    cout << "2nd object has " << countMarked(another) << " place" << endl;

    if (countMarked(*this) > countMarked(another) )
    {
        cout << "First one has more marked cells than second one" << endl;
        return true;
    }
    else if (countMarked(*this) < countMarked(another))
    {
        cout << "Second one has more marked cells than first one" << endl;
        return false;
    }
    else 
    {
        cout << "They are same have amount of Cell " << endl;
        return false;
    }
}

Hex::Cell::Cell()
{
    column = 0;
    row = 0;
    state = dot;
}

Hex::Cell::Cell(char valState)
{
    state = valState;
}

Hex::Cell::Cell(int setRow, int setColumn, char setState) :row(setRow), column(setColumn), state(setState)
{
    // TODO
}
