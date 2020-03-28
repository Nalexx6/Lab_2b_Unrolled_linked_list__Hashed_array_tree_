//
// Created by Win10Pro on 07.03.2020.
//

#include "Mode.h"

void Mode::interactive() {
    Functions function;
    char response = 'y';
    while(response == 'y') {

        std::cout<<"Hello, please choose the structure\n"
                   "1 - Unrolled linked list\n"
                   "2 -  Hashed array tree\n";
        int key;
        std::cin>>key;
        if(key == 1)
            function.ull_interactive(function.create_new_list());
        if(key == 2)
            function.hat_interactive(function.create_new_tree());

        std::cout<<"If you want to execute interactive for another structure press 'y', press 'n', if you don`t\n";
        std::cin>>response;

    }
}

void Mode::demo() {

    Functions function;
    char response = 'y';
    while(response == 'y') {

        std::cout<<"Hello, please choose the structure\n"
                   "1 - Unrolled linked list\n"
                   "2 -  Hashed array tree\n";
        int key;
        std::cin>>key;
        if(key == 1)
            function.ull_demo(function.create_new_list());
        if(key == 2)
            function.hat_demo(function.create_new_tree());

        std::cout<<"If you want to execute demo for another structure press 'y', press 'n', if you don`t\n";
        std::cin>>response;

    }
}
