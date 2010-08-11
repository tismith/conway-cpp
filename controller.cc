using namespace std;
#include <iostream>

#include "controller.h"

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

    element(0,0) = true;
    std::cout << "Element 0,0 is " << element(0,0) << std::endl;
}

const int Controller::get_width(void) const {
    return m_width;
}

const int Controller::get_height(void) const {
    return m_height;
}

void const Controller::print(void) const {
    for (int i = 0; i < m_elements->size(); i++) {
        //cout << "(" << (i % get_width()) << "," << (i / get_height()) << ") ";
        cout << element(i % get_width(), i / get_width()) << " ";
        if ((i+1) % m_width == 0) cout << endl;
    }
}

void const Controller::print_dimensions(void) const {
    cout << "Width is " << get_width() << endl;
    cout << "Height is " << get_height() << endl;
}

const Cell& Controller::element(int x, int y) const {
    int wrapped_x = x % get_width();
    int wrapped_y = y % get_height();
    return m_elements->at(wrapped_x + (wrapped_y * get_width()));
}

Cell& Controller::element(int x, int y) {
    int wrapped_x = x % get_width();
    int wrapped_y = y % get_height();
    return m_elements->at(wrapped_x + (wrapped_y * get_width()));
}

Controller::~Controller() {
}
