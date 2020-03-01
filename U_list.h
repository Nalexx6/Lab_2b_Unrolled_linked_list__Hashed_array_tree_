//
// Created by Win10Pro on 28.02.2020.
//

#ifndef LAB_2B_1_UNROLLED_LINKED_LIST__U_LIST_H
#define LAB_2B_1_UNROLLED_LINKED_LIST__U_LIST_H

#include <vector>
#include <iostream>

template <typename T>
class U_list {

public:

    //Body

    class Listnode{
    public:
        Listnode* next;
        Listnode* prev;
        int num_elements;
        std::vector <T> array {};
        Listnode(){
            this->prev = nullptr;
            this->next = nullptr;
            this->num_elements = 0;

        }


    };

    Listnode* head;
    Listnode* tail;
    int max_elements;
    int length;

    U_list(){

        head = nullptr;
        tail = nullptr;
        this->max_elements = 4;
        this->length = 0;

    }

    //Functions

    void insert(T& t, int& index){
        if(index>length - 1 && index != 0) {
            std::cout << "Can`t insert, index is more than length" << std::endl;
            return;
        }

        Listnode* node = new Listnode;

        if(length == 0){

            head = node;
            tail = node;
            node->array.emplace_back(t);
            node->num_elements++;
            this->length++;
            std::cout<<"Element was successfully inserted\n";
            return;

        }

        Listnode* cur = head;

        for(int i = 0; i < index; i++){

            cur = cur->next;

        }
        if(cur->num_elements < this->max_elements) {
            cur->array.emplace_back(t);
            cur->num_elements++;
        }
        else{

            Listnode *for_filled = new Listnode;
            for_filled->next = cur->next;
            if(cur != tail)
                for_filled->next->prev = for_filled;
            for_filled->prev = cur;
            cur->next = for_filled;
            if(cur == tail)
                tail = for_filled;

            for(int i = 0; i < max_elements/2; i++){

                for_filled->array.emplace_back(cur->array[cur->num_elements-1]);
                cur->array.pop_back();
                for_filled->num_elements++;
                cur->num_elements--;


            }
            for_filled->array.emplace_back(t);
            for_filled->num_elements++;
           // std::cout<<for_filled->num_elements<<'\n';

            this->length++;

        }
        std::cout<<"Element was successfully inserted\n";

    }
    void delete_by_index(int& index, int& ar_index){
        if(index > length - 1 || index < 0 ){
            std::cout<<"There are no node with this index, can`t be deleted\n";
            return;
        }
        Listnode* cur = head;
        for(int i = 0; i <  index; i++){
            cur = cur->next;
        }
        if(ar_index > cur->num_elements - 1){
            std::cout<<"There are no element with this index in your node, can`t be deleted\n";
            return;
        }
        cur->array.erase(cur->array.begin()+ar_index);
        cur->num_elements--;
        if(cur->num_elements < max_elements/2) {
            if (cur != tail) {
                Listnode *to_fill = cur->next;
                while (cur->num_elements < max_elements / 2) {
                    cur->array.emplace_back(to_fill->array[to_fill->num_elements - 1]);
                    cur->num_elements++;
                    to_fill->array.pop_back();
                    to_fill->num_elements--;
                }
                if (to_fill->num_elements < max_elements / 2) {
                    while (to_fill->num_elements > 0) {
                        cur->array.emplace_back(to_fill->array[to_fill->num_elements - 1]);
                        cur->num_elements++;
                        to_fill->array.pop_back();
                        to_fill->num_elements--;
                    }
                    cur->next = to_fill->next;
                    if(to_fill != tail)
                        to_fill->next->prev = cur;
                    if(to_fill == tail)
                        cur = tail;
                    length--;
                }
            }
            else    {
                Listnode *to_fill = cur->prev;
                while (cur->num_elements < max_elements / 2) {
                    cur->array.emplace_back(to_fill->array[to_fill->num_elements - 1]);
                    cur->num_elements++;
                    to_fill->array.pop_back();
                    to_fill->num_elements--;
                }
                if (to_fill->num_elements < max_elements / 2) {
                    while (to_fill->num_elements > 0) {
                        cur->array.emplace_back(to_fill->array[to_fill->num_elements - 1]);
                        cur->num_elements++;
                        to_fill->array.pop_back();
                        to_fill->num_elements--;
                    }
                    cur->prev = to_fill->prev;
                    to_fill->prev->next = cur;

                    length--;
                }

            }

        }
        std::cout<<"Element was successfully deleted\n";

    }
    T peek(int& index, int ar_index){
//        if(index > length - 1 || index < 0 ){
//            std::cout<<"There are no node with this index, can`t be returned\n";
//            return;
//        }
        Listnode* cur = head;
        for(int i = 0; i <  index; i++) {
            cur = cur->next;
        }
//        if(ar_index > cur->num_elements - 1){
//            std::cout<<"There are no element with this index in your node, can`t be returned\n";
//            return;

        return cur->array[ar_index];
    }
    void print_from_list() {
        Listnode* cur = head;
        std::cout<<"This is data from list\n"
                   "ar_index\t0\t1\t2\t3\n\n";
        for(int i = 0; i < length; i++){
            std::cout<<"node "<<i<<"\t\t";
            for(int j = 0; j < cur->num_elements; j++){
                std::cout<<cur->array[j]<<"\t";
            }

            std::cout<<'\n';
            cur = cur->next;
        }

    }


};


#endif //LAB_2B_1_UNROLLED_LINKED_LIST__U_LIST_H
