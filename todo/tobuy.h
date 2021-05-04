#ifndef TOBUY_H
#define TOBUY_H

#ifndef BASE_TODO_H
#include "base_todo.h"
#include "base_todo.cpp"    
#endif

#include <iostream>

class ToBuy : public BaseToDo {
    public:
        ToBuy();
        ToBuy(std::string title, std::string description, int price);

        void set_price(int price);
        int get_price();
    private:
        int price;
};

#endif