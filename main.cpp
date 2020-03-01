
#include "Functions.h"

int main() {

    Functions function;
    char response = 'y';
    while(response == 'y') {

        std::cout<<"Hello, please choose the mode\n"
                   "1 - interactive\n"
                   "2 - demo\n";
        int key;
        std::cin>>key;
        if(key == 1)
            function.interactive(function.create_new_list());
        if(key == 2)
            function.demo(function.create_new_list());

        std::cout<<"If you want to execute another mode press 'y', press 'n', if you don`t\n";
        std::cin>>response;

    }
}