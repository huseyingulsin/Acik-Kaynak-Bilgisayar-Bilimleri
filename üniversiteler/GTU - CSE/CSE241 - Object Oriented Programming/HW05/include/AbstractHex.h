/*
* Author: Muhammed Oguz

* This header represents a base class Hex class.

*/

#ifndef ABSTRACTHEX_H
#define ABSTRACTHEX_H

#include "Cell.h"
#include <string>
#include "../include/HexErrorHandler.h"

namespace HexOguz
{

    class AbstractHex
    {
        public:
        AbstractHex();
        AbstractHex(int);

        // Print Function 
        virtual void print() const = 0;

        // Read from file
        virtual void readFromFile(std::string) = 0;
        
        // Write to file
        virtual void writeToFile(std::string) = 0;

        // Resets board from the beginning.
        virtual void reset() = 0;

        // set Size and Reset
        virtual void setSize(int) = 0;

        // play with CPU
        virtual void play() = 0; 
        // play PVP
        virtual void play(Cell) = 0; 

        // Returns true if game is ended.
        bool isEnd();

        // return true if both board equal.
        bool operator==(const AbstractHex&) const;

        // return Cell of given indexes
        virtual Cell operator()(int,int) const = 0;

        // Returns last move, If there is not than throws an exception.
        Cell lastMove(); // throw(HexErrorHandler) 
        // Since "dynamic exception specifications are deprecated in C++11" this line is in comment.

        // returns number of move made so far
        inline int numberOfMoves() const         {return totalMove;}

        // Following functions are not part of Homework Instructions
        void Welcome();
        void allCommands() const;
        bool saveOrLoad(std::string);

        // Oneline setters and getters implemented.
        inline int getSize() const              {return size;}
        inline void setGameType(int gameType)   {this->gameType = gameType;}
        inline int getGameType() const          {return gameType;}
        inline void setTurn(char turn)          {this->turn = turn;}
        inline char getType() const             {return turn;}
        inline void setGameState(int gameState) {this->gameState = gameState;}
        inline int getGameState() const         {return gameState;}
        inline void setTotalMove(int totalMove) {this->totalMove = totalMove;}
        inline static int getActiveGames()      {return activeGames;}
        inline static int getAllGames()         {return allGames;}
        
        
        
        // Params that every derived class will had. So it is protected. 
        protected:
            int size; // represents hex board size. 
            int totalMove = 0; // track number of moves. 
            int gameType = 0; // keep game type
            char turn = player1; // keep player type
            int gameState = active; // keep game status

            Cell moveLast;
            // for track games
            static int activeGames;
            static int allGames;
    };

} // Namespace


#endif // ABSTRACTHEX_H