#ifndef _CELL_H
#define _CELL_H
#include <iostream>

using namespace std;

class Cell {
    public:
        Cell();
        Cell(bool);
        Cell(const Cell& cell);
        ~Cell();
        Cell& operator=(const Cell& cell);
        Cell& operator=(const bool& value);
        bool operator==(const Cell& cell) const;
        bool operator==(const bool& value) const;
        const bool& value() const; 
        bool& value();

    private:
        bool m_value;

        /* these didn't work when there were call members */
        friend istream& operator>>(istream& in, Cell& cell);
        friend ostream& operator<<(ostream& out, const Cell& cell);
};
#endif
