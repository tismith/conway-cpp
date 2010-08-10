using namespace std;
#include <iostream>
#include "controller.h"

Controller::Controller(const int width, const int height) {
    if (width == 0 || height == 0) {
        throw Controller::BadDimensions();
    }
    m_width = width;
    m_height = height;
}

void const Controller::print(void) {
    cout << "Width is " << m_width << endl;
    cout << "Height is " << m_height << endl;
}

Controller::~Controller() {
       cout << "Destructor called" << endl; 
}
