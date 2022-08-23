/*
* Author: Muhammed Oguz

* This header represents a derived class from AbstractHex Class.

*/

#ifndef HEXVECTOR_H
#define HEXVECTOR_H

#include "AbstractHex.h"
#include <vector>
#include <iostream>
#include <ostream>
#include <fstream>

using std::vector;
using std::string;

namespace HexOguz
{

    class HexVector : public AbstractHex
    {
        public:
        HexVector();
        HexVector(int);
        HexVector(bool);
        HexVector(string);

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
        vector<vector<Cell>> hexCells;
        vector<vector<Cell>> keepUppercase;


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

} // Namespace


#endif // HEXVECTOR_H