#include "base_todo.h"
using namespace std;

BaseToDo::BaseToDo() {
    this->status = false;
    this->description = "";
    this->title = "";
};

void BaseToDo::done() {
    status = true;
};

void BaseToDo::undone() {
    status = false;
};

bool BaseToDo::get_status() {
    return status;
};

void BaseToDo::set_status(bool status) {    
    this->status = status;
};

std::string BaseToDo::get_title() {
    return title;
};

void BaseToDo::set_title(std::string title) {
    this->title = title;
};

std::string BaseToDo::get_description() {
    return description;
};

void BaseToDo::set_description(std::string description) {
    this->description = description;
};

// int main() {
//     // testing BaseToDo class
//     BaseToDo t;
//     t.done();
    
//     cout << t.get_title() << " " << t.get_description() << " " << t.get_status() << endl;

//     t.undone();
//     t.set_title("new title");
//     t.set_description("new description");

//     cout << t.get_title() << " " << t.get_description() << " " << t.get_status() << endl;
//     return 0;
// }