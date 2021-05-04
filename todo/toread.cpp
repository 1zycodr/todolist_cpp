#include "toread.h"
using namespace std;

ToRead::ToRead(){};

ToRead::ToRead(std::string title, std::string description, std::string link) {
    set_title(title);
    set_description(description);
    set_link(link);
};

void ToRead::set_link(std::string link) {
    this->link = link;
};

std::string ToRead::get_link() {
    return link;
};

// int main() {
//     // testing ToRead class
//     ToRead t("title", "description", "link");
//     t.done();
    
//     cout << t.get_title() << " " << t.get_description() << " " << t.get_link() << " " << t.get_status() << endl;

//     t.undone();
//     t.set_title("new title");
//     t.set_description("new description");
//     t.set_link("new link");

//     cout << t.get_title() << " " << t.get_description() << " " << t.get_link() << " " << t.get_status() << endl;

//     return 0;
// }