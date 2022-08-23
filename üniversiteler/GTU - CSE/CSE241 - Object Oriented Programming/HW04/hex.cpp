#include "Hex.h"

namespace HexOguz
{

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
    fp.close();

    activeGames++;
    allGames++;
    gameState = active;
    loadGame(filename);
    std::cout << *this;
    playGame();
}

// take filename, load game do not play
Hex::Hex(string filename, bool valTest) :test(valTest)
{
    ifstream fp(filename);
	if(fp.is_open() == false)
    {
		cerr << "Couldn't open file.\n";  return;
	}
    fp.close();

    activeGames++;
    allGames++;
    gameState = active;
    loadGame(filename);
    
}

// Copy Consturctor
Hex::Hex(const Hex& copyHex)
{
    size = copyHex.size;
    gameType = copyHex.gameType;
    turn = copyHex.turn;
    gameState = active;
    moveCount = copyHex.moveCount;
    test = copyHex.test;

    createTable();
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            hexCells[i][j] = copyHex.hexCells[i][j];
    
    for (int i = 0; i < moveCount; i++)
        moves[i] = copyHex.moves[i];

}

// Take game size and play
Hex::Hex(int size)
{
    this->size = size;
    gameType = 0;
    turn = player1;
    gameState = active;
    activeGames++;
    allGames++;
    Welcome();
    createTable();
    playGame();
}

// Conversion Constructor
Hex::Hex(string filename, char guest)
{
    ifstream fp(filename);
	if(fp.is_open() == false)
    {
		cerr << "Couldn't open file.\n";  return;
	}
    fp.close();

    gameState = active;
    loadGame(filename);
}

// Destructor
Hex::~Hex()
{	// Call this function. It has all things for deleting
    deleteHelper();
}

// Helps Destructor and Assignment operator
void Hex::deleteHelper()
{
    for (int i = 0; i < size; i++)
    {
        delete[] hexCells[i];
        delete[] keepUppercase[i];
    }
    delete hexCells;
    delete keepUppercase;
    delete[] moves;
}

// Write Welcome and set Type of Game
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
    <<  "  -Save or Load your game e.g -> SAVE mygame.txt" << endl
    << "[Q] -> Quit current active game." << endl
    << "[P] -> Print currnet Hex table" << endl
    << "[UNDO]: Remove last played cell" << endl
    << "   -Not (if PvsCPU play, than remove last 2 played Cell)" << endl
    << "[SCORE]: Show score for both player" << endl
    << "[H] -> See this help massage" << endl << endl;
}

void Hex::createTable()
{
    hexCells = new Cell*[size];
    keepUppercase = new Cell*[size];
    moves = new Cell[size * size];
    for (int i = 0; i < size; i++)
    {
        hexCells[i] = new Cell[size];
        keepUppercase[i] = new Cell[size];
    }

}

Hex::Cell Hex::play()
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
    //hexCells[row][column].setState(turn);
    //printTable();
    return Cell(row, column, turn);
}

Hex::Cell Hex::play(Cell position)
{
    turn = position.getState();
    //hexCells[position.getColumn()][position.getRow()].setState(position.getState());
    //printTable();
    return Cell(position.getColumn(),position.getRow(), turn);
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
        // There are some code repeatition :(
        
        // Send tempcell to a while loop, till checkTurn function
        // returns a false value, it means a correct coordinate entered
        tempCell.setState(player1);
        while(checkTurn(coordinate, tempCell)); 
        // If gamestate turns to passive, then retrun to main
        if (gameState == passive) return;
        tempCell = play(tempCell);
        if(tempCell.getState() != dot)
        { 
            moves[moveCount] = tempCell;
            moveCount++; 
            hexCells[tempCell.getRow()][tempCell.getColumn()] = tempCell;
        }
        cout << *this;
        // if there is a winner, break
        if (checkWinner()) break;

        // if gametype is PvCPU
        if (gameType == PvCPU)
        {
            if (tempCell.getState() != dot)
            {
                Cell temp2 =  play();
                moves[moveCount] = temp2;
                moveCount++;
                hexCells[temp2.getRow()][temp2.getColumn()] = temp2;
                cout << *this;
            }
        }
        else
        {
            tempCell.setState(player2);
            while(checkTurn(coordinate, tempCell));
            if (gameState == passive) return;
            // if gameType has changed
            if (gameType == PvCPU){ cout << *this; continue; }
            tempCell = play(tempCell);
            if(tempCell.getState() != dot)
            {
                moves[moveCount] = tempCell;
                moveCount++;
                hexCells[tempCell.getRow()][tempCell.getColumn()] = tempCell;
            }
            cout << *this;
        }
        if (checkWinner()) break;
    }
    
    // it means there is a winner
    if (gameState == winner)
        coppyToUpper();
}

bool Hex::checkTurn(string coordinate, Cell &tempCell)
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
        cout << *this;
        return checkTurn(coordinate, tempCell);
    }
    else if(coordinate == "UNDO" && coordinate.length() == 4)
    {
        if (moveCount == 0)
        {
            cout << "You are at starting point now, can not undo" << endl;
        }
        else
        {
            if (gameType == PvP)
            {
                (*this)--;
                cout << "Undo Completed Sir!" << endl;
                tempCell.setState(dot);
                return false;
            }
            else
            {
                --(*this);
                cout << "Undo Completed Sir!" << endl;
                cout << *this;
                return checkTurn(coordinate, tempCell);
            }
            
        }   
        
    }
    else if(coordinate == "SCORE" && coordinate.length() == 5)
    {
        cout << endl << "|||--SCORE TABLE--|||" << endl
		<< 		"----------------------" << endl;
        cout << "||| X Score = " << score_x << "   |||" << endl;
        cout << "||| O Score = " << score_o << "   |||" << endl;
		cout << "----------------------" << endl;
        return checkTurn(coordinate, tempCell);
    }
    if (saveOrLoad(coordinate))
        return true;

    // in load circumtance, this func should return false.
    else if(coordinate.compare(0, 4, "LOAD", 0 ,4) == 0 && coordinate.size() > 5)
    {
        tempCell.setState(dot);
        return false;
    } 
        
    else
    {
        int row = coordinate[0] - 'A';
        int column = coordinate[1] - '1';
        if (coordinate.length() == 3)
            column = (coordinate[1] - '0') * 10 + (coordinate[2] - '1');
        if ((coordinate.length() != 2 && coordinate.length() != 3) || row > size - 1 || row < 0 || column < 0 || column > size - 1)
        {
            cerr << "Your input is not correct." << endl;
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

    // function overload << for reading file.
    fp << *this;

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

    // operator overloading >>
    fp >> *this;

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
        score_x = 0;
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
        score_o = 0;
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
            score_x ++;
            return true; 
        }
    }
    else if (turn == player2)
    {
        if (x == size - 1 && y >= 0 && hexCells[x][y].getState() == turn) {
            keepUppercase[x][y].setState(turn - 32); 
            score_o++;
            return true; 
        }
    }
  
    if (isValid(x, y)) { 
        keepUppercase[x][y].setState(turn - 32); 
        if (turn == player1)
            score_x++;
        else
            score_o++;
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
    
    cout << endl << "You win  ->>>>> " << static_cast<char>(turn - 32) << " <<<<<<<-  " << endl<< "Congrats You are the Pro Hex Player <3<3" << endl << endl << "You reached 9999 points. Because It is the max score. And you deserve it <3" << endl;
	if (turn == player1)
		score_x = 9999;
	else
		score_o = 9999;
	
	cout << endl << "|||--SCORE TABLE--|||" << endl
	<< 		"----------------------" << endl;
	cout << "||| X Score = " << score_x << "   |||" << endl;
	cout << "||| O Score = " << score_o << "   |||" << endl;
	cout << "----------------------" << endl;

    cout << *this;
    gameState = winner;
    cout << "This game is passive now" << endl;
    activeGames--;
    cout << "There are " << activeGames << " active games now" << endl; 
}

int Hex::countMarked()
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (hexCells[i][j].getState() != dot)
                count++;
        }
    }
    return count; 
} 

int Hex::countMarked(vector<Hex*> Games)
{
    int gameCount = Games.size();
    int totalCount = 0;
    for (int i = 0; i < gameCount; i++)
    {
        if (Games[i]->getStatus() != winner)
            totalCount += Games[i]->countMarked();
    }
    return totalCount;
}

void Hex::operator--(int garbage)
{
    moveCount--;
    moves[moveCount].setState(dot);
    undo_helper();
    return;
}

void Hex::operator--()
{
    moveCount--;
    moves[moveCount].setState(dot);
    undo_helper();
    moveCount--;
    moves[moveCount].setState(dot);
    undo_helper();
    return;
}

void Hex::undo_helper()
{
    for (int i = 0; i < moveCount + 1; i++)
        hexCells[moves[i].getRow()][moves[i].getColumn()].setState(moves[i].getState());
}

const Hex& Hex::operator=(const Hex& rightSide)
{
    if (this == &rightSide)
        return *this;
    else
    {
        // delete all values of left side
        deleteHelper();
        // get size of right side to left side
        this->size = rightSide.size;
        // re allocate all values of left side due to new size
        createTable();

        // assign all values to left side from right side
        size = rightSide.size;
        gameType = rightSide.gameType;
        turn = rightSide.turn;
        gameState = active;
        moveCount = rightSide.moveCount;
        test = rightSide.test;

        this->moveCount = rightSide.moveCount;

        // assign array values to left side from right side
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                hexCells[i][j] = rightSide.hexCells[i][j];
        for (int i = 0; i < moveCount; i++)
            moves[i] = rightSide.moves[i];

        return *this;
    }
}

std::ostream& operator<<(std::ostream& myOstream, const Hex& hex)
{
    myOstream << "  ";
    for (int i = 0; i < hex.size; i++) myOstream << static_cast<char> ('a' + i)  << " ";
    myOstream << endl; 
    for (int i = 0; i < hex.size; i++)
    {
        if (i < 9)
            myOstream << i+1 << " ";
        else
            myOstream << i+1;
        for (int k = 0; k < i; k++) myOstream << " ";
        for (int j = 0; j < hex.size; j++)
        {
            myOstream << " " << hex.hexCells[i][j].getState();
        }
        myOstream << endl;
    }
    return myOstream;
}

std::ofstream& operator<<(std::ofstream& myOfstream, const Hex& hex)
{
    // write those to file
	myOfstream << hex.gameType << endl << hex.size << endl << hex.turn << endl;

    // write table as type of char
    for (int i = 0; i < hex.size; i++) {
        for (int j = 0; j < hex.size; j++)
            myOfstream << hex.hexCells[i][j].getState();
        myOfstream << endl;
    }

    myOfstream << hex.moveCount << endl;
    for (int i = 0; i < hex.moveCount; i++){
        myOfstream << hex.moves[i].getRow() <<hex.moves[i].getColumn() << hex.moves[i].getState() << endl; }

    return myOfstream;
}

std::ifstream& operator>>(std::ifstream& myIfstream, Hex& hex)
{
    // read variables from file
	myIfstream >> hex.gameType >> hex.size >> hex.turn;

    hex.createTable();
    for (int i = 0; i < hex.size; i++)
    {
        for (int j = 0; j < hex.size; j++)
        {
            char temp;
            myIfstream >> temp;
            hex.hexCells[i][j].setState(temp);
        }
    }

    myIfstream >> hex.moveCount;
    for (int i = 0; i < hex.moveCount; i++)
    {
        char row_f, column_f, state_f;
        myIfstream >> row_f >> column_f >> state_f;
        hex.moves[i].setRow(row_f - 48);
        hex.moves[i].setColumn(column_f - 48);
        hex.moves[i].setState(state_f);
    }

    return myIfstream;
}

bool Hex::operator==(Hex& rightSide)
{
    int first = countMarked();
    int second = rightSide.countMarked();
    cout << "1st object has " << first << " place" << endl;
    cout << "2nd object has " << second << " place" << endl;

    if (first > second )
    {
        cout << "First one has more marked cells than second one" << endl;
        return true;
    }
    else if (second > first)
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
{}
}
