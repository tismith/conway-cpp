using namespace std;
#include <iostream>

#include "cell.h"

Cell::Cell(void) :
    m_value(false) {
}

Cell::Cell(bool value) :
    m_value(value) {
}

Cell::Cell(const Cell& cell) :
    m_value(cell.value()) {
}

Cell::~Cell() {
}

Cell& Cell::operator=(const Cell& cell) {
    this->value() = cell.value();
}

Cell& Cell::operator=(const bool& value) {
    this->value() = value;
}

bool Cell::operator==(const Cell& cell) {
    return this->value() == cell.value();
}

bool Cell::operator==(const bool& value) {
    return this->value() == value;
}

istream& operator>>(istream& in, Cell& cell) {
    in >> cell.value();
    return in;
}

ostream& operator<<(ostream& out, const Cell& cell) {
    out << (cell.value() ? "o" : "-") ;
    return out;
}

const bool& Cell::value(void) const {
    return this->m_value;
}

bool& Cell::value(void) {
    return this->m_value;
}
