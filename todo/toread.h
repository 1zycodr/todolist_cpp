#ifndef TOREAD_H
#define TOREAD_H

#ifndef BASE_TODO_H
#include "base_todo.h"
#include "base_todo.cpp"    
#include <iostream>
#endif

class ToRead : public BaseToDo {
    public:
        ToRead();
        ToRead(std::string title, std::string description, std::string link);

        void set_link(std::string link);
        std::string get_link();
    private: 
        std::string link;
};

#endif