/*
* Author: Muhammed Oguz

* This header represents a derived class from AbstractHex Class.

*/

#ifndef HEXADAPTER_H
#define HEXADAPTER_H

#include "AbstractHex.h"
#include <vector>
#include <iostream>
#include <ostream>
#include <fstream>

using std::string;



namespace HexOguz
{
    template<template<typename...> class T>
    class HexAdapter: public AbstractHex
    {
    public:
        HexAdapter();
        HexAdapter(int);
        HexAdapter(bool);
        HexAdapter(string);

        void playGame();
        
        void print() const override;
        void readFromFile(string) override;
        void writeToFile(string) override;
        void reset() override;
        void setSize(int) override;
        void play() override; 
        void play(Cell) override; 
        Cell operator()(int,int) const override;


    private:
        T<T<Cell>> hexCells;
        T<T<Cell>> keepUppercase;
        // Check winner Helper Functions.
        bool checkWinner();
        bool check(int,int);
        bool isValid(int,int);

        // After game is ended. Convert Winning path to UpperCase
        void copyToUpper();

        // check entered command
        bool checkCommand(string, Cell&);

        // create empty table
        void createTable();

    };

} // namespace HexOguz



#endif // HEXADAPTER_H