//
// Created by Win10Pro on 28.02.2020.
//

#ifndef LAB_2B_1_UNROLLED_LINKED_LIST__FUNCTIONS_H
#define LAB_2B_1_UNROLLED_LINKED_LIST__FUNCTIONS_H

#include "U_list.h"


class Functions {

public:


    U_list <int> create_new_list();
    void create_N_random_and_insert(U_list <int> &uList, int N);
    void interactive(U_list <int> uList);
    void demo(U_list <int> uList);

};


#endif //LAB_2B_1_UNROLLED_LINKED_LIST__FUNCTIONS_H
