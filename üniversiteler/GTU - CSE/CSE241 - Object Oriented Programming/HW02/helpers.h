#include <iostream>
#include <string>
#include <random>
#include <fstream>

using namespace std;

enum playerFlags 
{
    x = 'x', x_p = 'x' , o = 'o', dat = '.', X = 'X', O = 'O'
};

enum gameFlags
{
    PvP =1, PvCPU, CPUvCPU
};

// write welcome massage and get game type
int getType();

// get size of the table
void setSize(int &size);

// create table
int ** createTable(const int &size = 12);

// delete (free) alocated tables
void deleteTable(int **table, const int &size = 12);

// print whole table
void printTable(int ** table, const int &size);

// plays which players turn
void playTurn(int **table, int &size, char player, int &gameType);

// plays computer itself due to randomize
void playComputer(int **table, const int &size, const char &player);

// copy content of winners for printing uppercase result
void copyUppercaseArray(int **a, int **b, const int &size);

//check if there is a winner
bool checkWinner(int ** table, int x, int y, int ** keepPoints, const int &size, const char &player);

// helpers for CheckWinner
bool check(int **table, int x, int y, int **keepPositions, const int &size, const char &player);
bool isValid(int **table, int x, int y, const int &size, const char &player);

//checks if input is save command or load command
bool saveOrLoad(int **table, string &str, char &player, int &size, int &gameType);

// save game
void saveGame(int **table, const string &filename, char &player, int &size, int &gameType);

// load game
void loadGame(int **table, const string &filename, char &player, int &size, int &gameType);