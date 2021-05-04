#include "todo.h"

ToDo::ToDo(){};

ToDo::ToDo(std::string title, std::string description) {
    set_title(title);
    set_description(description);
};

// int main() {
//     // testing ToDo class
//     ToDo t("title", "description");
//     t.done();
    
//     cout << t.get_title() << " " << t.get_description() << " " << t.get_status() << endl;

//     t.undone();
//     t.set_title("new title");
//     t.set_description("new description");

//     cout << t.get_title() << " " << t.get_description() << " " << t.get_status() << endl;

//     return 0;
// }