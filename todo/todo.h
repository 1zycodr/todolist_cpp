#ifndef TODO_H
#define TODO_H
#include "base_todo.h"
#include <iostream>

class ToDo : public BaseToDo {
    public:
        ToDo();
        ToDo(std::string title, std::string description);
};

#endif