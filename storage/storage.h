#ifndef STORAGE_H
#define STORAGE_H
#include "../todo/base_todo.cpp"

class Storage {
    private:
        static Storage* instance;
        static BaseToDo** todos;
        static int size;

        Storage() {};

    public:
        static Storage* get_instance();
        
        // data format: 
        // todo title status description
        // toread title status description link
        // tobuy title status description price

        // loads data.txt file if storage
        void load();
        // saves the file in data.txt
        void save();

        // adding object to the list
        void add_todo_item(BaseToDo* todo); 
        // removing todo item from todos
        void remove_todo_item(int index);
        // changing the status of item to true (done)
        void done_todo_item(int index);
        // changing the status of item to false (undone)
        void undone_todo_item(int index);

        // printing todo items from todos
        void print_todos();

        // returns count of the todos 
        int get_size() {return size;};
};


#endif