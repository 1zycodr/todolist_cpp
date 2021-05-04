#include "tobuy.h"
using namespace std;

ToBuy::ToBuy(){};

ToBuy::ToBuy(std::string title, std::string description, int price) {
    set_title(title);
    set_description(description);
    set_price(price);
};

void ToBuy::set_price(int price) {
    this->price = price;
};

int ToBuy::get_price() {
    return price;
};


// int main() {
//     // testing ToBuy class
//     ToBuy t("title", "description", 1000);
//     t.done();
    
//     cout << t.get_title() << " " << t.get_description() << " " << t.get_price() << " " << t.get_status() << endl;

//     t.undone();
//     t.set_title("new title");
//     t.set_description("new description");
//     t.set_price(2000);

//     cout << t.get_title() << " " << t.get_description() << " " << t.get_price() << " " << t.get_status() << endl;

//     return 0;
// }