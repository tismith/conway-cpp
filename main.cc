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
    cout << "Usage: conway [-w <width>] [-h <height>] [-c <steps>]" << endl;
    if (do_exit) exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    int opt = 0;
    int width = 20;
    int height = 10;
    int count = 0;;
    Controller::Ptr controller;

    try {
        while ((opt = getopt(argc, argv, "c:w:h:")) != -1) {
            switch (opt) {
            case 'w':
                istringstream(optarg) >> width;
                break;
            case 'h':
                istringstream(optarg) >> height;
                break;
            case 'c':
                istringstream(optarg) >> count;
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
    
    /* load a basic glider */
    controller->element(1,0) = true;
    controller->element(2,1) = true;
    controller->element(2,2) = true;
    controller->element(1,2) = true;
    controller->element(0,2) = true;

    controller->print();

    if (count < 0) controller->run();
    else {
        for (int i = 0; i < count; i++) {
            controller->tick();
            controller->print();
        }
    }

}

    
