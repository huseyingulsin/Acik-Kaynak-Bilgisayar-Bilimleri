#include "../include/AbstractHex.h"
#include <iostream>


using namespace std;
using namespace HexOguz;

AbstractHex::AbstractHex(): size(0), totalMove(0), gameType(0), turn(player1), gameState(active)
{
    activeGames++;
    allGames++;
}

AbstractHex::AbstractHex(int a): size(a), totalMove(0), gameType(0), turn(player1), gameState(active)
{
    activeGames++;
    allGames++;
}

bool AbstractHex::isEnd()
{
    if (gameState == winner) return true;
    else                     return false;
}

bool AbstractHex::operator==(const AbstractHex& right) const
{
    if (this->size != right.size)
        return false;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
           if(this->operator()(i,j).getState() != right(i,j).getState())
                return false;
    return true; 
}

Cell AbstractHex::lastMove() // throw (HexErrorHandler)
{
    if (moveLast.getState() == '.')
        throw(HexErrorHandler("Couldn't show last move. (Probably there is not any)\n"));
    return moveLast;
}

void AbstractHex::Welcome()
{
    cout << endl << endl
    << "First Select the game type you want from following." << endl
    << "1- P vs P \n2- P vs CPU"  << endl
    << "Enter your choice:";

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
    }
}

void AbstractHex::allCommands() const
{
    cout << endl << endl <<  "Commands List" << endl
    << "[Coordinate]: your coordinate e.g -> A5" << endl
    << "[SAVE] [filename] " << endl <<  "[LOAD] [filename]" << endl 
    <<  "   Save or Load your game e.g -> SAVE myGame.txt" << endl
    << "[LAST] -> Show last move position and state" << endl
    << "[Q] -> Quit current active game." << endl
    << "[P] -> Print currnet Hex table" << endl
    << "[H] -> See this help massage" << endl << endl;
}

bool AbstractHex::saveOrLoad(string str) // throw (HexErrorHandler)
{
    // look to type of command
    if(str.compare(0, 4, "SAVE", 0 ,4) == 0 && str.size() > 5)
    {
        writeToFile(str.substr(5));
        return 1;
    }
    else if(str.compare(0, 4, "LOAD", 0 ,4) == 0 && str.size() > 5)
    {
        readFromFile(str.substr(5));
        return 0;
    }

    return 0;
}