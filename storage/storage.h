#ifndef STORAGE_H
#define STORAGE_H
#include "../todo/base_todo.h"
#include "../todo/base_todo.cpp"

class Storage {
    private:
        static Storage* instance;
        static BaseToDo* todos;
        static int size;

        Storage() {};

    public:
        static Storage* getInstance();
        
        // adding object to the list
        void addToDoItem(BaseToDo* todo); 

        // returns count of the todos 
        int getSize() {return size;};
};


#endif