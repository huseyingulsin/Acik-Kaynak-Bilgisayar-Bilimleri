#include "../include/Cell.h"
#include <iostream>

using std::cout;
using std::endl;
using namespace HexOguz;

Cell::Cell()
{
    this->column = 0;
    this->row = 0;
    this->state = dot;
}

Cell::Cell(int row, int column, char state): row(row), column(column), state(state)
{}

void Cell::print() const
{
    char row_c = 'A' + row;
    cout << " Position " << row_c << column + 1 << " State: " << state << endl;   
}