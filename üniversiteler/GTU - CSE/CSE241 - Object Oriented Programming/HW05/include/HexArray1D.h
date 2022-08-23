/*
* Author: Muhammed Oguz

* This header represents a derived class from AbstractHex Class.

*/

#ifndef HEXARRAY1D_H
#define HEXARRAY1D_H

#include "AbstractHex.h"
#include <iostream>
#include <ostream>
#include <fstream>

using std::string;

namespace HexOguz
{

    class HexArray1D : public AbstractHex
    {
        public:
        HexArray1D();
        HexArray1D(int);
        HexArray1D(bool);
        HexArray1D(string);

        // Big Three Provided
        ~HexArray1D();
        const HexArray1D& operator=(const HexArray1D&);
        HexArray1D(const HexArray1D& );


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
        Cell* hexCells = nullptr;
        Cell* keepUppercase = nullptr;


        // Check winner Helper Functions.
        bool checkWinner();
        bool check(int,int);
        bool isValid(int,int);

        // After game is ended. Convert Winning path to UpperCase
        void copyToUpper();

        // check entered command
        bool checkCommand(string, Cell&);

        // create empty table, if first time do calloc, if already exist do realloc
        void createTable();

        // delete table
        void deleteTable();

    };

} // Namespace


#endif // HEXARRAY1D_H