#include "storage.h"
#include "../todo/todo.cpp"
#include "../todo/tobuy.cpp"
#include "../todo/toread.h"
#include <iostream>

using namespace std;

Storage* Storage::instance = nullptr;
BaseToDo* Storage::todos = nullptr;
int Storage::size = 0;

Storage* Storage::getInstance() {
    if (!instance) {
        instance = new Storage();
    }

    return instance;
}

void Storage::addToDoItem(BaseToDo* todo) {
    ToDo* new_todo = dynamic_cast<ToDo*>(todo);

    if (new_todo) {
        cout << "todo!" << endl;
        return;
    }  

    ToBuy* new_tobuy = dynamic_cast<ToBuy*>(todo);

    if (new_tobuy) {
        cout << "tobuy!" << endl;
        return;
    }

    ToRead* new_toread = dynamic_cast<ToRead*>(todo);   

    if (new_toread) {
        cout << "toread!" << endl;
    }

    // TODO
    // add item into todos and increment size.
}

int main() {
    // Testing storage
    Storage* firstStorage = Storage::getInstance();
    Storage* secondStorage = Storage::getInstance();

    // here we can see that firstStorage and secondStorage variables
    // point to the same object
    cout << firstStorage << endl << secondStorage << endl;

    ToDo todo("title", "description");
    ToBuy tobuy("title", "description", 2000);
    secondStorage->addToDoItem(&todo);
    secondStorage->addToDoItem(&tobuy);
    // cout << s->getSize();
    
    return 0;
}