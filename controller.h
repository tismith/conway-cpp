#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <tr1/memory>


class Controller {
    public:
        Controller(const int width, const int height);
        virtual ~Controller();
        void const print(void);
        typedef std::tr1::shared_ptr<Controller> Ptr;
        class BadDimensions {};

    private:
        Controller();
        int m_width;
        int m_height;
};

#endif //CONTROLLER_H
    
