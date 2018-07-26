#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <stdexcept>
#include <vector>

#include "cell.h"

class Controller {
    public:
        typedef std::shared_ptr<Controller> Ptr;

        class Exception : public std::runtime_error {
            public: Exception(const char*);
        };
        class BadDimensions : public Exception {
            public: BadDimensions(const char*);
        };

        Controller(const int width, const int height) 
            throw (BadDimensions, exception);
        virtual ~Controller();
        int get_width(void) const;
        int get_height(void) const;
        Cell& element(int x, int y);
        const Cell& element(int x, int y, bool primary_table = true) const;

        void print(void) const;
        void print_dimensions(void) const;

        void tick(void);
        void run(void);

    private:
        int m_width;
        int m_height;
        typedef std::vector<Cell> Container;
        typedef std::shared_ptr<Container> Container_ptr;
        Container_ptr m_elements;
        Container_ptr m_elements_alt;
        int neighbours_alive(int x, int y) const;
        bool apply(const Cell& cell, const int num_alive) const;
        Cell& element_next(int x, int y);
        const Cell& element_next(int x, int y) const;
        
        Controller();
};

#endif //CONTROLLER_H
    
