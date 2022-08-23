#include <iostream>
#include <string>
#include <random>


using namespace std;

// write welcome massage and get game type
int getType();

// get size of the table
int getSize();

// create table
int ** createTable(int size);

// delete (free) alocated tables
void deleteTable(int **table, int size);



// print whole table
void printTable(int ** table, int size);

// plays which players turn
void playTurn(int **table, int size, char player);

// plays computer itself due to randomize
void playComputer(int **table, int size, char player);

// copy content of winners for printing uppercase result
void copyUppercaseArray(int **a, int **b, int size);

//check if there is a winner
bool checkWinner(int ** table, int x, int y, int ** keepPoints, int size, char player);
// helpers for CheckWinner
bool check(int **table, int x, int y, int **keepPositions, int size, char player);
bool isValid(int **table, int x, int y, int size, char player);