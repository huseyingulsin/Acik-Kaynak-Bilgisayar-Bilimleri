#include "../include/HexAdapter.h"
#include <iostream>
#include <random>


using namespace HexOguz;
using namespace std;


template<template<typename...> class T>
HexAdapter<T>::HexAdapter(): AbstractHex()
{
    playGame();
}

template<template<typename...> class T>
HexAdapter<T>::HexAdapter(int size):  AbstractHex(size)
{
    playGame();
}

template<template<typename...> class T>
HexAdapter<T>::HexAdapter(bool trash): AbstractHex()
{
    trash = false;
    setSize(6);
}

template<template<typename...> class T>
HexAdapter<T>::HexAdapter(string filename): AbstractHex()
{
    createTable();
    readFromFile(filename);
    setSize(this->size);
    readFromFile(filename);
}

template<template<typename...> class T>
void HexAdapter<T>::print() const
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

template<template<typename...> class T>
void HexAdapter<T>::reset()
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            hexCells[i][j].setState(dot);

    moveLast.setState(dot);
}

template<template<typename...> class T>
void HexAdapter<T>::createTable()
{
    hexCells.resize(size);
    keepUppercase.resize(size);
    for(int i = 0; i < size; i++)
    {       
        hexCells[i].resize(size);
        keepUppercase[i].resize(size);
    }
            
}

template<template<typename...> class T>
void HexAdapter<T>::setSize(int size)
{
    this->size = size;
    createTable();
    reset();
}

template<template<typename...> class T>
void HexAdapter<T>::readFromFile(string filename) // throw (HexErrorHandler)
{
    // rading mode
	ifstream fp(filename);
	if(fp.is_open() == false)
        throw (HexErrorHandler("Couldn't open file.\n"));

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

    char temp;
    fp >> temp >> totalMove;
    moveLast.setState(temp);
	
    fp.close();

    
    if (gameType == 2)
        turn = player1;
    cout << "Game Loaded from -> " + filename << endl;

}

template<template<typename...> class T>
void HexAdapter<T>::writeToFile(string filename) // throw (HexErrorHandler)
{
    // writing mode
	ofstream fp(filename);
	if(fp.is_open() == false)
        throw (HexErrorHandler("Couldn't open file.\n"));

    // write those to file
	fp << gameType << endl << size << endl << turn << endl;

    // write table as type of char
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            fp << hexCells[i][j].getState();
        fp << endl;
    }

    fp << moveLast.getState() << endl;
    fp << totalMove << endl;

	cout << "Game saved as -> " + filename << endl;
	fp.close();  return;
}

template<template<typename...> class T>
Cell HexAdapter<T>::operator()(int column, int row) const 
{
    if (column > size || row > size || column < 0 || row < 0)
        throw HexErrorHandler("Out of border ERROR\n");
    return hexCells[column][row];
}

template<template<typename...> class T>
void HexAdapter<T>::play()
{
    totalMove++;
    // CPU plays random
    setTurn(player2);
    random_device randomCreator;
    mt19937 rand(randomCreator());
    uniform_int_distribution<mt19937::result_type> randRange(0, size -1);
    int row = randRange(randomCreator);
    int column = randRange(randomCreator);
    while (hexCells[column][row].getState() != dot)
    {
        row = randRange(randomCreator);
        column = randRange(randomCreator);
    }
    char row_c = row + 'A';
    cout << "Your Turn " << turn << endl;
    cout << "Computer Entered: " << row_c << column + 1 << endl;
    hexCells[column][row].setState(turn);
    moveLast = Cell(row,column,turn);
    print();
}

template<template<typename...> class T>
void HexAdapter<T>::play(Cell position)
{
    totalMove++;
    turn = position.getState();
    hexCells[position.getColumn()][position.getRow()].setState(position.getState());
    moveLast = position;
    print();
}

template<template<typename...> class T>
void HexAdapter<T>::playGame()
{
    Welcome();
    createTable();

    string coordinate;
    Cell tempCell;
    while(true)
    {

        tempCell.setState(player1);
        while(checkCommand(coordinate, tempCell)); 
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
            while(checkCommand(coordinate, tempCell));
            if (gameState == passive) return;
            // if gameType has changed
            if (gameType == PvCPU){ print(); continue; }
            play(tempCell);
        }
        if (checkWinner()) break;
    }
    
    // it means there is a winner
    if (gameState == winner)
        copyToUpper();
}

template<template<typename...> class T>
bool HexAdapter<T>::checkCommand(string coordinate, Cell& tempCell)
{
    cout << endl << "Your Turn " << tempCell.getState() << endl;
    cout << "Type H for all Commands" << endl << "Command: ";
    cin >> ws;
    getline(cin, coordinate);

    if (coordinate[0] == 'H' && coordinate.length() == 1)
    {
        allCommands();
        return checkCommand(coordinate, tempCell);
    }
    else if (coordinate[0] == 'Q' && coordinate.length() == 1)
    {
        cout << "Quiting... " << endl;

        gameState = passive;
        cout << "This game will be active in background" << endl;
        return false;

    }
    else if (coordinate == "LAST" && coordinate.length() == 4)
    {
        try
        {
            cout << "Last move ->"; 
            lastMove().print();
        }
        catch(const HexErrorHandler& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        return checkCommand(coordinate, tempCell);
    }
    else if (coordinate[0] == 'P' && coordinate.length() == 1)
    {
        print();
        return checkCommand(coordinate, tempCell);
    }
    
    try
    {
        if (saveOrLoad(coordinate))
        {
            return true;
        }
    }
    catch(const HexErrorHandler& e)
    {
        std::cerr << e.what() << '\n';
        return checkCommand(coordinate, tempCell);
    }
        
    // in load circumstance, this func should return false.
    if(coordinate.compare(0, 4, "LOAD", 0 ,4) == 0 && coordinate.size() > 5) 
        return false;
    else
    {
        int row = coordinate[0] - 'A';
        int column = coordinate[1] - '1';
        if (coordinate.length() == 3)
            column = (coordinate[1] - '0') * 10 + (coordinate[2] - '1');
        if ((coordinate.length() != 2 && coordinate.length() != 3) || row > size - 1 || row < 0 || column < 0 || column > size - 1)
        {
            cerr << "Your input is not correct. Be aware this game is case sensitive" << endl;
            return checkCommand(coordinate, tempCell);
        }
        if (hexCells[column][row].getState() != dot)
        {   
            cerr << "this filed is not empty" << endl;
            return checkCommand(coordinate, tempCell);
        }
        tempCell.setRow(row);
        tempCell.setColumn(column);
        return false;
    }
}

template<template<typename...> class T>
bool HexAdapter<T>::checkWinner()
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

template<template<typename...> class T>
bool HexAdapter<T>::check(int x, int y)
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

template<template<typename...> class T>
bool HexAdapter<T>::isValid(int x, int y)
{
    // if this field is valid return true
    if (x >= 0 && x < size && y >= 0 && y < size && hexCells[x][y].getState() == turn)
        return true; 

    return false; 
}

template<template<typename...> class T>
void HexAdapter<T>::copyToUpper()
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (keepUppercase[i][j].getState() != dot)
                hexCells[i][j] = keepUppercase[i][j];

    cout << endl << "You win  ->>>>> " << static_cast<char>(turn - 32) << " <<<<<<<-  " << endl<< "Congrats You are the Pro Hex Player <3<3" << endl << endl;
    print();
    gameState = winner;
    if (isEnd())
        cout << "This game is passive now" << endl;
    activeGames--;
    cout << "There are " << activeGames << " active games now" << endl; 

}