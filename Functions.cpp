//
// Created by Win10Pro on 28.02.2020.
//

#include "Functions.h"

U_list<int> Functions::create_new_list() {

    U_list <int> uList;
    return uList;
}

void Functions::create_N_random_and_insert(U_list <int> &uList, int N) {

    for(int i = 0; i < N; i++){

        int t = rand()%20 + 1;
        int index;
        if(uList.length == 0)
            index = 0;
        else
            index = rand() % (uList.length);
        std::cout<<"value is "<<t<<" index is "<<index<<'\n';
        uList.insert(t, index);

    }

}

void Functions::interactive(U_list <int> uList) {


    char response = 'y';
    while (response == 'y') {
        std::cout << "Please choose, what oyu want tot do with Unrolled linked list:\n"
                     "1 - Insert new element by index\n"
                     "2 - create N random elements and insert them randomly\n"
                     "3 - Delete element by index\n"
                     "4 - Peek the element by index and print all it values\n"
                     "5 - Print all data from list\n";
        int key;
        std::cin>>key;
        if(key == 1){
            uList.print_from_list();
            std::cout<<"Please enter the value of your element(int),"
                       " and index of node, in which you want to insert new element\n";
            int index, t;
            std::cin>>t>>index;
            uList.insert(t, index);

        }
        if(key == 2){
            std::cout<<"Please enter N - number of elements\n";
            int N;
            std::cin>>N;
            this->create_N_random_and_insert(uList, N);
            uList.print_from_list();

        }
        if(key == 3){
            uList.print_from_list();
            std::cout<<"Please enter the index of node, in which you want to delete an element, "
                       "and ar_index of your element\n";
            int index, ar_index;
            std::cin>>index>>ar_index;
            uList.delete_by_index(index, ar_index);
        }
        if(key == 4){
            std::cout<<"Please enter the index of node, in which you want to peek an element, "
                       "and ar_index of your element\n";
            int index, ar_index;
            std::cin>>index>>ar_index;
            std::cout<<"The value of element in your position is "<<uList.peek(index, ar_index)<<"\n";
        }
        if(key == 5){
            uList.print_from_list();
        }

        std::cout<<"If you want to continue doing something with this list press 'y', press 'n' if you don`t\n";
        std::cin>>response;



    }

}

void Functions::demo(U_list <int> uList) {

    /*
     * insert to show splitting of nodes - delete to show compounding of nodes - peek element
     */
    std::string breakpoint;
    int index = 1, ar_index = 1;
    std::cout<<"Firstly we will create and insert 4 elements and print all data from list\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    this->create_N_random_and_insert(uList, 4);
    uList.print_from_list();
    std::cout<<"Now we will insert another element to show, that new node will be created, "
               "and print all data from list\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    this->create_N_random_and_insert(uList, 1);
    uList.print_from_list();
    std::cout<<"Now we will delete element on position: index = "<<index<<" ar_index = "<< ar_index<<
               " and print all data from list\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    uList.delete_by_index(index, ar_index);
    index = 0;
    ar_index = 0;
    uList.print_from_list();
    std::cout<<"Now we will delete element on position: index = "<<index<<" ar_index = "<< ar_index<<
             " to show that nodes will be compounded and print all data from list\n"
             "cin anything to continue\n";
    std::cin>>breakpoint;
    uList.delete_by_index(index, ar_index);
    uList.print_from_list();
    std::cout<<"Now we will peek the element on position: index = "<<index<<" ar_index = "<< ar_index<<"\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    std::cout<<"The value of element in your position is "<<uList.peek(index, ar_index)<<"\n";
    std::cout<<"This is the end of demo mode\n\n";




}
