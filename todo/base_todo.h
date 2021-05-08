#ifndef BASE_TODO_H
#define BASE_TODO_H
#include <iostream>

class BaseToDo {
    public:
        BaseToDo();

        void done();
        void undone();

        bool get_status();
        std::string get_title();
        std::string get_description();

        void set_status(bool status);
        void set_title(std::string title);
        void set_description(std::string description);

        BaseToDo& operator=(const BaseToDo& other);
        virtual ~BaseToDo() {};

    private:
        bool status;
        std::string title;
        std::string description;
};

#endif