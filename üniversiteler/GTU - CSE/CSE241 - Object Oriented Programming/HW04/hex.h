/*
* This header file contains hex class

* Muhamemd Oguz 1801042634

*/
#ifndef HEX 
#define HEX

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>

using namespace std;

namespace HexOguz // my namespace
{

enum playerFlags {player1 = 'x', player2 = 'o', dot = '.'};
enum gameFlags {PvP =1, PvCPU, CPUvCPU};
enum gameStatus {active, passive, winner};


class Hex
{
public:
    // default cosnturctor
    Hex(); 
    // take a file, load game and play
    Hex(string filename); 
    // take a file, load game. do not play.
    Hex(string filename, bool test);

    // -----------------------------------------------------
    //  ---- HW4 IMPLEMENTIONS ---- 
    class Cell;

    // explicit because it should not interfere with Hex(string)
    explicit Hex(int size);
    
    // ! Big Three Provided
    // Destructor
    ~Hex(); 
    // Copy Constructor
    Hex(const Hex& copyHex); 
    // assignment operator
    const Hex& operator=(const Hex& rightSide); 

    // conversion constructor
    Hex(string file, char y); 

    // USED FOR UNDO, returns VOID because not necessary
    void operator--(int garbage);
    void operator--();
    void undo_helper();

    bool operator==(Hex& rightSide); 

    friend std::ostream& operator<<(std::ostream& myOstream, const Hex& hex);
    friend std::ofstream& operator<<(std::ofstream& myOfstream, const Hex& hex);
    friend std::ifstream& operator>>(std::ifstream& myIfstream, Hex& hex);
    

    // play with CPU
    Cell play(); 
    // play PVP
    Cell play(Cell position); 

    // END OF HW4 IMPLEMENTIONS -------------------------
    // -------------------------------------------------------------------------

    // print welcome massage
    void Welcome();
    // print all commands massage
    void allCommands() const;

    // create table
    void createTable();
    // copy lowercase table to uppercase after winner
    void coppyToUpper();

    // checks valid move or not
    bool checkTurn(string coordinate, Cell &tempCell);
    // check command is save load or not
    bool saveOrLoad(string str);
    // save game
    void saveGame(string filename);
    // load game
    void loadGame(string filename);
    
    // return 1 if there is a winner
    bool checkWinner(); 
    // start with taking size from user and play game
    void playGame(); 
    
    // count all marked cells for selected game
    int countMarked(); 

    // count all marked cells for all games
    // Games value is not a class data, so it could be vector due to instructions.
    static int countMarked(vector<Hex*> Games);



    // setters and getters
    // all of those inline
    static int getActiveGames();
    static int getAllGames();
    int getSize() const;
    char getPlayer() const;
    int getStatus() const;
    void setSize(int valSize);
    void setPlayer(char valPlayer);
    void setActive(int state);
private:
    // main data keeps table
    Cell** hexCells = nullptr;
    // for converting uppercase letter
    Cell** keepUppercase = nullptr;

    // keeps move and move count
    Cell* moves = nullptr;
    int moveCount = 0;

    // PARAMS
    int size = 0;
    int gameType = 0;
    char turn = player1;
    int gameState = active;

    // Score Params
    int score_x = 0;
    int score_o = 0;

    // static member for keeping active games
    static int activeGames;
    static int allGames;

    // helper functions to checkWinner
    bool check(int x, int y);
    bool isValid(int x, int y);

    // helps destructor and assignment operator
    void deleteHelper(); 

    // for testing game quickly
    bool test;
};

class Hex::Cell
{
public:
    Cell(); // default consturcotr
    Cell(char valState);
    Cell(int setRow, int setColumn, char setState);
    
    // Big three does not needed, only assigment is enough for this class


    // setters and getters
    // all of them are inline
    void setRow(int setRow);
    void setColumn(int setColumn);
    void setState(char setState);
    int getColumn() const; 
    int getRow() const;
    char getState() const;
private:
    int row = 0, column = 0;
    char state = dot;
};

// Inline functions -> What is inline? Very short functions can write inline, it is more efficient,
// Sadly inline functions had to be in header file, otherwise it gives an error
// From Hex Class
inline void Hex::setSize(int set) {size = set;}
inline void Hex::setPlayer(char player) {turn = player;}
inline void Hex::setActive(int state) {gameState = state;}
inline int Hex::getSize() const {return size;}
inline char Hex::getPlayer() const {return turn;}
inline int Hex::getStatus() const {return gameState;}
inline int Hex::getActiveGames() {return activeGames;}
inline int Hex::getAllGames() {return allGames;}
// From Cell Class
inline void Hex::Cell::setRow(int setRow) {row = setRow;}
inline void Hex::Cell::setColumn(int setColumn) {column = setColumn;}
inline void Hex::Cell::setState(char setState) {state = setState;}
inline int Hex::Cell::getRow() const {return row;}
inline int Hex::Cell::getColumn() const {return column;}
inline char Hex::Cell::getState() const {return state;}

}

#endif

