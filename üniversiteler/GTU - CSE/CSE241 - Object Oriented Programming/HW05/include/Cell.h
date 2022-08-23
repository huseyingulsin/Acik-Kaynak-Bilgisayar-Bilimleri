/*
* Author: Muhammed Oguz

* This header represents a Cell Class.

*/

#ifndef CELL_H
#define CELL_H



namespace HexOguz
{
    enum playerFlags {player1 = 'x', player2 = 'o', dot = '.'};
    enum gameFlags {PvP =1, PvCPU, CPUvCPU};
    enum gameStatus {active, passive, winner};

    class Cell
    {
        public:
        Cell();
        Cell(int,int,char);
        void print() const;

        // implemented as inline. 
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

    inline void Cell::setRow(int row) {this->row = row;}
    inline void Cell::setColumn(int column) {this->column = column;}
    inline void Cell::setState(char state) {this->state = state;}
    inline int Cell::getRow() const {return row;}
    inline int Cell::getColumn() const {return column;}
    inline char Cell::getState() const {return state;}

} // Namespace


#endif // CELL_H