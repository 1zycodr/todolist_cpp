#ifndef APP_H
#define APP_H

#include "../storage/storage.cpp"

class App {
    public:
        App();
        void init();

        void start_menu();
        void todos_menu();
        
        void done_todo();
        void undone_todo();
        
        void delete_todo();
        void create_todo();

        void create_todo_item();
        void create_toread_item();
        void create_tobuy_item();
        
    private:
        string password = "password";
        Storage* storage;
        const char* CLEAR_COMMAND = "cls"; 
        const string HEADER = "----------------- TODO LIST -----------------";
};

#endif