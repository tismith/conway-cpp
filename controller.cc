#include <iostream>

#include "controller.h"

using namespace std;

Controller::Exception::Exception(const char* desc) : 
    runtime_error(desc) {
}

Controller::BadDimensions::BadDimensions(const char* desc) : 
    Exception(desc) {
}

Controller::Controller(const int width, const int height) 
    throw (Controller::BadDimensions, exception) {
    if (width == 0 || height == 0) {
        throw BadDimensions("Incorrectly Dimensioned");
    }
    m_width = width;
    m_height = height;
    m_elements = Container_ptr(new Container(width*height, false));
    m_elements_alt = Container_ptr(new Container(width*height, false));
}

const int Controller::get_width(void) const {
    return m_width;
}

const int Controller::get_height(void) const {
    return m_height;
}

void const Controller::print(void) const {
    for (int y = 0; y < get_height(); y++) {
        for (int x = 0; x < get_width(); x++) {
            cout << element(x,y) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void const Controller::print_dimensions(void) const {
    cout << "Width is " << get_width() << endl;
    cout << "Height is " << get_height() << endl;
}

/* reader */
/* primary_table is an optional argument that defaults to true */
const Cell& Controller::element(int x, int y, bool primary_table) const {
    /* to get the modulus wrapping from -ve to +ve correctly
     * x%m is in [-m+1, m-1], so adding m to it won't change it's 
     * modulo, but will make it guaranteed +ve */
    int wrapped_x = (x % get_width() + get_width()) % get_width();
    int wrapped_y = (y % get_height() + get_height()) % get_height();
    if (primary_table) {
        return m_elements->at(wrapped_x + (wrapped_y * get_width()));
    } else {
        return m_elements_alt->at(wrapped_x + (wrapped_y * get_width()));
    }
}

/* writer */
Cell& Controller::element(int x, int y) {
    return const_cast<Cell&>(static_cast<const Controller*>(this)->element(x, y));
}

const Cell& Controller::element_next(int x, int y) const {
    return element(x, y, false);
}

Cell& Controller::element_next(int x, int y) {
    return const_cast<Cell&>(static_cast<const Controller*>(this)->element_next(x, y));
}

void Controller::tick(void) {
    for (int x = 0; x < get_width(); x++) {
        for (int y = 0; y < get_height(); y++) {
            element_next(x,y) = apply(element(x,y), neighbours_alive(x,y));
        }
    }
    swap(m_elements_alt, m_elements);
}

void Controller::run(void) {
    while (true) {
        tick();
        print();
    }
}

const bool Controller::apply(const Cell& cell, const int num_alive) const {
    if (num_alive < 2) return false;
    if (num_alive == 2) return cell.value();
    if (num_alive == 3) return true;
    if (num_alive > 3) return false;
    return false;
}

int const Controller::neighbours_alive(int x, int y) const {
    int count = 0;
    bool debug = false;

    for (int j = y-1; j <= y+1; j++) {
        for (int i = x-1; i <= x+1; i++) {
            if (debug) cout << "(" << i << "," << j << ") = " << element(i, j).value() << endl ; 
            if (!(i == x && j == y)) {
                if (element(i, j) == true) count++;
            }
        }
    }
    return count;
}

Controller::~Controller() {
}
