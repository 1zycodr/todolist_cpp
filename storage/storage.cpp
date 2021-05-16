#include "storage.h"
#include "../todo/todo.cpp"
#include "../todo/tobuy.cpp"
#include "../todo/toread.cpp"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

Storage* Storage::instance = nullptr;
BaseToDo** Storage::todos = nullptr;
int Storage::size = 0;

Storage* Storage::get_instance() {
    if (!instance) {
        instance = new Storage();
    }

    return instance;
}

void Storage::add_todo_item(BaseToDo* todo) {
    if (todos == nullptr) {
        todos = new BaseToDo*[1];
        todos[0] = todo;
        size++;
    } else {
        size++;
        BaseToDo** new_todos = new BaseToDo*[size];
        for (int i = 0; i < size - 1; i++) {
            new_todos[i] = todos[i];
        }
        delete[] todos;
        todos = new_todos;
        todos[size - 1] = todo;
    }
}

void Storage::remove_todo_item(int index) {
    if (index == 0 && size == 1) {
            size = 0;
            todos = nullptr;
    } else if (index >= 0 && index < size) {
        for (int i = 0; i < size; i++) {
            if (i == index) {
                BaseToDo** new_todos = new BaseToDo*[size - 1];
                std::copy(todos, todos + i, new_todos);
                std::copy(todos + i + 1, todos + size, new_todos + i);
                delete[] todos;
                todos = new_todos;
                --size;
            }
        } 
    }
}

void Storage::print_todos() {
    for (int i = 0; i < size; i++) {
        cout << "\n[id: " << i << "] Name: " << todos[i]->get_title();
        cout << " " << (todos[i]->get_status() ? "(done)" : "(undone)") << endl;
        cout << "\tDescription: " << todos[i]->get_description() << endl;

        ToDo* todo = dynamic_cast<ToDo*>(todos[i]);

        if (todo) continue;

        ToBuy* tobuy = dynamic_cast<ToBuy*>(todos[i]);

        if (tobuy) {
            cout << "\tPrice: " << tobuy->get_price() << endl;
            continue;
        }

        ToRead* toread = dynamic_cast<ToRead*>(todos[i]);

        if (toread) {
            cout << "\tLink: " << toread->get_link() << endl;
        }
    }
};

void Storage::done_todo_item(int index) {
    if (index >= 0 && index < size) {
        todos[index]->set_status(true);
    }
};

void Storage::undone_todo_item(int index) {
    if (index >= 0 && index < size) {
        todos[index]->set_status(false);
    }  
};


void Storage::save() {
    ofstream datafile;
    datafile.open("data.txt");

    if (datafile.fail()) {
        throw "Error! data.txt file does not exists.";
    }

    for (int i = 0; i < size; i++) {
        ToDo* todo = dynamic_cast<ToDo*>(todos[i]);

        if (todo) {
            datafile << "todo " << todo->get_title() << " ";
            datafile << todo->get_status() << " " << todo->get_description() << "\n";
            continue;
        }

        ToBuy* tobuy = dynamic_cast<ToBuy*>(todos[i]);

        if (tobuy) {
            datafile << "tobuy " << tobuy->get_title() << " ";
            datafile << tobuy->get_status() << " " << tobuy->get_description() << " ";
            datafile << tobuy->get_price() << "\n";
            continue;
        }

        ToRead* toread = dynamic_cast<ToRead*>(todos[i]);

        if (toread) {
            datafile << "toread " << toread->get_title() << " ";
            datafile << toread->get_status() << " " << toread->get_description() << " ";
            datafile << toread->get_link() << "\n";
            continue;
        }
    }
};

void Storage::load() {
    cout << "Reading datafile..." << endl; 
    
    ifstream datafile;
    string type, title, description, link;
    bool status;
    int price;

    datafile.open("data.txt");

    if (datafile.fail()) {
        throw "Error! data.txt file does not exist!";
    }

    while(datafile >> type) {
        if (type == "todo") {
            datafile >> title >> status >> description;
            ToDo* todo = new ToDo(title, description);
            todo->set_status(status);
            add_todo_item(todo);
        } else if (type == "toread") {
            datafile >> title >> status >> description >> link;
            ToRead* toread = new ToRead(title, description, link);
            toread->set_status(status);
            add_todo_item(toread);
        } else if (type == "tobuy") {
            datafile >> title >> status >> description >> price;
            ToBuy* tobuy = new ToBuy(title, description, price);
            tobuy->set_status(status);
            add_todo_item(tobuy);
        }
    }
};


// int main() {
//     // Testing storage
//     Storage* first_storage = Storage::get_instance();
//     Storage* second_storage = Storage::get_instance();

//     // here we can see that first_storage and second_storage variables
//     // point to the same object
//     cout << first_storage << endl << second_storage << endl;

//     first_storage->load();

//     ToDo todo("title", "description1");
//     ToBuy tobuy("title", "description2", 2000);
//     ToRead toread("title", "description3", "link");

//     second_storage->add_todo_item(&todo);
//     first_storage->add_todo_item(&tobuy);
//     second_storage->add_todo_item(&toread);
    
//     cout << first_storage->get_size() << " " << second_storage->get_size() << endl;
    
//     first_storage->print_todos();
    
//     first_storage->remove_todo_item(2);

//     cout << endl;
//     second_storage->print_todos();

//     first_storage->add_todo_item(&toread);

//     cout << endl;
//     second_storage->print_todos();

//     first_storage->done_todo_item(1);
//     second_storage->done_todo_item(0);

//     cout << endl;
//     second_storage->print_todos();

//     first_storage->undone_todo_item(1);
//     second_storage->undone_todo_item(0);
//     first_storage->remove_todo_item(5);

//     cout << endl;
//     second_storage->print_todos();

//     // first_storage->remove_todo_item(0);
//     // first_storage->remove_todo_item(0);
//     // first_storage->remove_todo_item(0);
//     // first_storage->remove_todo_item(0);

//     // cout << endl;
//     // second_storage->print_todos();
//     first_storage->save();

//     return 0;
// }