//
// Created by Win10Pro on 28.02.2020.
//

#include "Functions.h"

U_list<int> Functions::create_new_list() {

    U_list <int> uList;
    return uList;
}

Hashed_tree<int> Functions::create_new_tree() {

    Hashed_tree <int> hashedTree;
    return hashedTree;
}

void Functions::create_N_random_and_push_to_ULL(U_list <int> &uList, int N) {

    for(int i = 0; i < N; i++){

        int t = rand() % N + 1;
        std::cout<<"value is "<<t<<"\n";
        uList.push_back(t);

    }

}

void Functions::create_N_random_and_push_to_HAT(Hashed_tree <int> &hashedTree, int N) {

    for(int i = 0; i < N; i++){

        int t = rand() % N + 1;
        //std::cout<<"value is "<<t<<'\n';
        hashedTree.push_back(t);
        //std::cout<<"Inserted"<<std::endl;
    }



}

void Functions::ull_interactive(U_list <int> uList) {


    char response = 'y';
    while (response == 'y') {
        std::cout << "Please choose, what you want to do with Unrolled linked list:\n"
                     "1 - Push_back new element\n"
                     "2 - Insert new element by index\n"
                     "3 - Create N random elements and push_back them\n"
                     "4 - Pop_back element\n"
                     "5 - Delete element by index\n"
                     "6 - Peek the element by index and print all it values\n"
                     "7 - Print all data from list\n";
        int key;
        std::cin>>key;
        if(key == 1){
            std::cout<<"Please enter the value of your element(int)\n";
            int t;
            std::cin>>t;
            uList.push_back(t);
            std::cout<<"Element was successfully pushed_back\n";

        }
        if(key == 2){
            uList.print_from_list();
            std::cout<<"Please enter the value of your element(int),"
                       " number of node, in which you want to insert new element, and its index\n";
            int node, index, t;
            std::cin>>t>>node>>index;
            uList.insert(t, node, index);
            std::cout<<"Element was successfully inserted\n";


        }
        if(key == 3){
            std::cout<<"Please enter N - number of elements\n";
            int N;
            std::cin>>N;
            this->create_N_random_and_push_to_ULL(uList, N);
            //uList.print_from_list();
            std::cout<<"All "<< N <<" elements was successfully pushed\n";
        }
        if(key == 4){
            uList.pop_back();
            std::cout<<"Element was successfully popped\n";
        }
        if(key == 5){
            uList.print_from_list();
            std::cout<<"Please enter the index of node, in which you want to delete an element, "
                       "and ar_index of your element\n";
            int index, ar_index;
            std::cin>>index>>ar_index;
            uList.delete_by_index(index, ar_index);
            std::cout<<"Element was successfully deleted\n";
        }
        if(key == 6){
            std::cout<<"Please enter the index of node, in which you want to peek an element, "
                       "and ar_index of your element\n";
            int index, ar_index;
            std::cin>>index>>ar_index;
            std::cout<<"The value of element in your position is "<<uList.peek(index, ar_index)<<"\n";
        }
        if(key == 7){
            uList.print_from_list();
        }

        std::cout<<"If you want to continue doing something with this list press 'y', press 'n' if you don`t\n";
        std::cin>>response;



    }

}

void Functions::hat_interactive(Hashed_tree<int> hashedTree) {

    char response = 'y';
    while (response == 'y') {
        std::cout << "Please choose, what oyu want tot do with Hashed array tree:\n"
                     "1 - Push_back new element\n"
                     "2 - Insert new element by index\n"
                     "3 - create N random elements and push_back them\n"
                     "4 - Pop_back element\n"
                     "5 - Delete element by index\n"
                     "6 - Peek the element by index and print all it values\n"
                     "7 - Print all data from tree\n";
        int key;
        std::cin>>key;
        if(key == 1){
            std::cout<<"Please enter the value of your element(int)\n";
            int t;
            std::cin>>t;
            hashedTree.push_back(t);
        }
        if(key == 2){
            hashedTree.print_all_from_tree();
            std::cout<<"Please enter the value of your element(int),"
                       " and number of node, in which you want to insert new element, and its index\n";
            int node, index, t ;
            std::cin>>t>>node>>index;
            hashedTree.insert(t, node,index);
        }
        if(key == 3){
            std::cout<<"Please enter N - number of elements\n";
            int N;
            std::cin>>N;
            this->create_N_random_and_push_to_HAT(hashedTree, N);
            //hashedTree.print_all_from_tree();
            std::cout<<"All "<< N <<" elements was successfully pushed\n";

        }
        if(key == 4){
            hashedTree.pop_back();
            std::cout<<"Element was successfully popped\n";
        }

        if(key == 5){
            hashedTree.print_all_from_tree();
            std::cout<<"Please enter the number node, in which you want to delete an element, "
                       "and index of your element\n";
            int node, index;
            std::cin>>node>>index;
            hashedTree.delete_by_index(node, index);
            std::cout<<"Element was successfully deleted\n";
        }
        if(key == 6){
            std::cout<<"Please enter the number of node, in which you want to peek an element, "
                       "and index of your element\n";
            int node, index;
            std::cin>>node>>index;
            std::cout<<"The value of element in your position is "<<hashedTree.peek(node, index)<<"\n";
        }
        if(key == 7){
            hashedTree.print_all_from_tree();
        }

        std::cout<<"If you want to continue doing something with this list press 'y', press 'n' if you don`t\n";
        std::cin>>response;



    }

}

void Functions::ull_demo(U_list <int> uList) {

    /*
     * insert to show splitting of nodes - delete to show compounding of nodes - peek element
     */
    std::string breakpoint;
    int index = 2, node = 0, t = 25;
    std::cout<<"Firstly we will create and push_back "<<uList.get_max_elements() <<" elements and print all data from list\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    this->create_N_random_and_push_to_ULL(uList, uList.get_max_elements());
    uList.print_from_list();
    std::cout<<"Now we will insert element "<<t<<" in position: node =  "<< node<<" index = "<<index
             <<" to show, that new node will be created, "
               "and print all data from list\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    uList.insert(t, node, index);
    uList.print_from_list();
    std::cout<<"Now we will pop_back element and print all data from list\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    uList.pop_back();
    node = 0;
    index = 0;
    uList.print_from_list();
    std::cout<<"Now we will delete element on position: node = "<<node<<" index = "<<index<<
             " to show that nodes will be compounded and print all data from list\n"
             "cin anything to continue\n";
    std::cin>>breakpoint;
    uList.delete_by_index(node, index);
    uList.print_from_list();
    std::cout<<"Now we will peek the element on position: node = "<< node<<" index = "<< index<<"\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    std::cout<<"The value of element in your position is "<<uList.peek(node, index)<<"\n";
    std::cout<<"This is the end of demo mode\n\n";




}

void Functions::hat_demo(Hashed_tree<int> hashedTree) {

    /*
     * insert to show increasing of array - delete to show decreasing of array - peek element
     */
    std::string breakpoint;
    int t = 25, node = 0, index = 3;
    std::cout<<"Firstly we will create and push_back "<<(4 << 2*hashedTree.get_power())<<" elements and print all data from tree\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    this->create_N_random_and_push_to_HAT(hashedTree, (4 << 2*hashedTree.get_power()));
    hashedTree.print_all_from_tree();
    std::cout<<"Now we will push_back "<< 1 <<" element to show, that capacity of array will be increased "
               "and print all data from tree\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    this->create_N_random_and_push_to_HAT(hashedTree, 1);
    hashedTree.print_all_from_tree();
    std::cout<<"Now we will pop_back "<<(2 << hashedTree.get_power())<<" elements to show that capacity of array will be the same "<<
             " and print all data from tree\n"
             "cin anything to continue\n";
    std::cin>>breakpoint;
    for(int i = 0; i < (2 << hashedTree.get_power()); i++){
        hashedTree.pop_back();
    }
    hashedTree.print_all_from_tree();
    std::cout<<"Now we will delete element on position: node = "<<node<<" index = "<< index<<
             " to show that capacity of array will be decreased and print all data from tree\n"
             "cin anything to continue\n";
    std::cin>>breakpoint;
    hashedTree.delete_by_index(node, index);
    hashedTree.print_all_from_tree();
    std::cout<<"Now we will insert element with value"<< t <<" on position: node = "<<node<<" index = "<< index<<"\n"
             "cin anything to continue\n";
    std::cin>>breakpoint;
    hashedTree.insert(t, node, index);
    hashedTree.print_all_from_tree();
    node = 1;
    index = 2;
    std::cout<<"Now we will peek the element on position: node = "<<node<<" index = "<< index<<"\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    std::cout<<"The value of element in your position is: "<<hashedTree.peek(node, index)<<"\n";
    std::cout<<"This is the end of demo mode\n\n";

}
