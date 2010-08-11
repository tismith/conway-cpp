#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <tr1/memory>
#include <stdexcept>
#include <vector>

#include "cell.h"

class Controller {
    public:
        typedef std::tr1::shared_ptr<Controller> Ptr;

        class Exception : public std::runtime_error {
            public: Exception(const char*);
        };
        class BadDimensions : public Exception {
            public: BadDimensions(const char*);
        };

        Controller(const int width, const int height) 
            throw (BadDimensions, exception);
        virtual ~Controller();
        const int get_width(void) const;
        const int get_height(void) const;
        Cell& element(int x, int y);
        const Cell& element(int x, int y) const;

        void const print(void) const;
        void const print_dimensions(void) const;

    private:
        typedef std::vector<Cell> Container;
        typedef auto_ptr<Container> Container_ptr;
        int m_width;
        int m_height;
        int max_element;
        Container_ptr m_elements;
        Controller();
};

#endif //CONTROLLER_H
    
