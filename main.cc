using namespace std;
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <exception>

extern "C" {
#include <unistd.h>
}

#include "controller.h"

void usage(bool do_exit) {
    cout << "Usage: conway [-w <width>] [-h <height>]" << endl;
    if (do_exit) exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    int opt = 0;
    int width = 20;
    int height = 10;
    Controller::Ptr controller;

    try {
        while ((opt = getopt(argc, argv, "w:h:")) != -1) {
            switch (opt) {
            case 'w':
                istringstream(optarg) >> width;
                break;
            case 'h':
                istringstream(optarg) >> height;
                break;
            default:
                usage(true);
                break;
            }
        }

        controller = Controller::Ptr(new Controller(width, height));

    } catch (exception& e) {
        cout << e.what() << endl;
        usage(true);
    }
    
    controller->print_dimensions();

    controller->print();

}

    
