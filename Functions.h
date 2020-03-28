//
// Created by Win10Pro on 28.02.2020.
//

#ifndef LAB_2B_1_UNROLLED_LINKED_LIST__FUNCTIONS_H
#define LAB_2B_1_UNROLLED_LINKED_LIST__FUNCTIONS_H

#include "U_list.h"
#include "Hashed_tree.h"


class Functions {

public:


    U_list <int> create_new_list();
    Hashed_tree <int> create_new_tree();
    void create_N_random_and_push_to_ULL(U_list <int> &uList, int N);
    void create_N_random_and_push_to_HAT(Hashed_tree <int> &hashedTree, int N);
    void ull_interactive(U_list <int> uList);
    void hat_interactive(Hashed_tree <int> hashedTree);
    void ull_demo(U_list <int> uList);
    void hat_demo(Hashed_tree <int> hashedTree);

};


#endif //LAB_2B_1_UNROLLED_LINKED_LIST__FUNCTIONS_H
