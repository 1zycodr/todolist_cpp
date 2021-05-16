#include "app.h"
#include <iostream>
using namespace std;


App::App() {
    system(CLEAR_COMMAND);
};


void App::init() {
    storage = Storage::get_instance();

    try {
        storage->load();
    } catch (string err) {
        cout << err << endl;
        cout << "Creating data.txt file..." << endl;
        storage->load();
    }

    while(true) {
        start_menu();
    }
};


void App::start_menu() {
    string user_password;
    int attempts = 3;
    
    system(CLEAR_COMMAND);  
    cout << HEADER << endl;
    cout << "Hello! Welcome to ToDo List application!" << endl;
    cout << "Enter password: ";
    
    cin >> user_password;
    
    while (--attempts != 0 && user_password != password) {
        cout << "Wrong password! Try again (" << attempts << " attempts): ";
        cin >> user_password;
    }

    if (attempts == 0) {
        cout << "Attempts are over! Access is denied." << endl;
        exit(0);       
    }

    while (true) {
        todos_menu();
    }
};


void App::todos_menu() {
    system(CLEAR_COMMAND);
    cout << HEADER << endl;
    cout << "Your todos:" << endl;
    storage->print_todos();
    cout << "\nOptions:\n[1] - Create new todo\n[2] - Delete todo\n";
    cout << "[3] - Done todo\n[4] - Undone todo\n[5] - exit\n";
    cout << "Choose option (1 - 5): ";
    
    string user_option;
    cin >> user_option;

    while (
        user_option != "1" && user_option != "2" &&
        user_option != "3" && user_option != "4" &&
        user_option != "5"
    ) {
        cout << "Invalid option! Enter from 1 to 5: ";
        cin >> user_option;
    }

    if (user_option == "1") {
        create_todo();
    } else if (user_option == "2") {
        delete_todo();
    } else if (user_option == "3") {
        done_todo();
    } else if (user_option == "4") {
        undone_todo();
    } else if (user_option == "5") {
        cout << "Goodbye!" << endl;
        exit(0);
    }
};


void App::create_todo() {
    system(CLEAR_COMMAND);
    cout << HEADER << endl;
    cout << "Choose type: \n[1] - ToDo\n[2] - ToRead\n[3] - ToBuy\n";
    cout << "Enter number (1 - 3): ";
    string user_input;
    cin >> user_input;

    while (
        user_input != "1" &&
        user_input != "2" && 
        user_input != "3" 
    ) {
        cout << "Invalid number! Enter from 1 to 3: ";
        cin >> user_input;
    }
    
    if (user_input == "1") {
        create_todo_item();
    } else if (user_input == "2") {
        create_toread_item();
    } else {
        create_tobuy_item();
    }

    try {
        storage->save();
    } catch (string err) {
        cout << err << endl;
        cout << "Creating data.txt file..." << endl;
        storage->save();
    }
};


void App::create_todo_item() {
    string title, description;
    cout << "Enter title: ";
    cin >> title;
    cout << "Enter description: ";
    cin >> description;

    ToDo* todo = new ToDo(title, description);
    storage->add_todo_item(todo);
};


void App::create_toread_item() {
    string title, description, link;
    cout << "Enter title: ";
    cin >> title;
    cout << "Enter description: ";
    cin >> description;
    cout << "Enter link: ";
    cin >> link;

    ToRead* toread = new ToRead(title, description, link);
    storage->add_todo_item(toread);
};


void App::create_tobuy_item() {
    string title, description;
    int price;
    cout << "Enter title: ";
    cin >> title;
    cout << "Enter description: ";
    cin >> description;
    cout << "Enter price: ";
    cin >> price;

    ToBuy* tobuy = new ToBuy(title, description, price);
    storage->add_todo_item(tobuy);
};


void App::delete_todo() {
    int id;
    cout << "Enter todo id (-1 - cancel): ";
    cin >> id; 

    while (id >= storage->get_size() && id != -1) {
        cout << "Error! No such id, please, reenter: ";
        cin >> id;
    }

    if (id == -1) {
        return;
    }

    storage->remove_todo_item(id);

    try {
        storage->save();
    } catch (string err) {
        cout << err << endl;
        cout << "Creating data.txt file..." << endl;
        storage->save();
    }
};


void App::done_todo() {
    int id;
    cout << "Enter todo id (-1 - cancel): ";
    cin >> id; 

    while (id >= storage->get_size() && id != -1) {
        cout << "Error! No such id, please, reenter: ";
        cin >> id;
    }

    if (id == -1) {
        return;
    }
    
    storage->done_todo_item(id);
    try {
        storage->save();
    } catch (string err) {
        cout << err << endl;
        cout << "Creating data.txt file..." << endl;
        storage->save();
    }
};


void App::undone_todo() {
    int id;
    cout << "Enter todo id (-1 - cancel): ";
    cin >> id; 

    while (id >= storage->get_size() && id != -1) {
        cout << "Error! No such id, please, reenter: ";
        cin >> id;
    }

    if (id == -1) {
        return;
    }
    
    storage->undone_todo_item(id);

    try {
        storage->save();
    } catch (string err) {
        cout << err << endl;
        cout << "Creating data.txt file..." << endl;
        storage->save();
    }
};