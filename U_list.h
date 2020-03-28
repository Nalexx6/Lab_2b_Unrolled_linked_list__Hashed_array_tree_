//
// Created by Win10Pro on 28.02.2020.
//

#ifndef LAB_2B_1_UNROLLED_LINKED_LIST__U_LIST_H
#define LAB_2B_1_UNROLLED_LINKED_LIST__U_LIST_H

#include <vector>
#include <iostream>

template <typename T>
class U_list {

private:

    //Body

    class Listnode{
    public:
        Listnode* next;
        Listnode* prev;
        int num_elements;
        T* array;
        Listnode(){
            this->prev = nullptr;
            this->next = nullptr;
            this->num_elements = 0;
            array = new T[max_elements];
        }
        ~Listnode(){
            delete[] array;
        }

    };

    Listnode* head;
    Listnode* tail;
    static int max_elements;
    int length;
public:

    U_list(){

        head = nullptr;
        tail = nullptr;
        //this->max_elements = 4;
        this->length = 0;

    }
    ~U_list(){}

    //Auxiliary functions

    int get_max_elements(){
        return max_elements;
    }

    //Functions

    void push_back(T& t){

        if(length == 0){

            Listnode* node = new Listnode;
            head = node;
            tail = node;
            node->array[node->num_elements] = t;
            node->num_elements++;
            this->length++;
            //std::cout<<"Element was successfully inserted\n";
            return;

        }

        if(tail->num_elements < this->max_elements) {
            tail->array[tail->num_elements] = t;
            tail->num_elements++;
        }
        else{
            Listnode *for_filled = new Listnode;
//            for_filled->next = tail->next;
//            if(cur != tail)
  //              for_filled->next->prev = for_filled;
            for(int i = 0; i < max_elements/2; i++){
                for_filled->array[for_filled->num_elements] = tail->array[tail->num_elements-1];
                for_filled->num_elements++;
                tail->num_elements--;
            }
            for_filled->array[for_filled->num_elements] = t;
            for_filled->num_elements++;
            for_filled->prev = tail;
            tail->next = for_filled;
            tail = for_filled;
            // std::cout<<for_filled->num_elements<<'\n';
            this->length++;

        }

    }
    void pop_back(){
        tail->num_elements--;
        if(tail->num_elements < max_elements / 2 && tail != head){
            Listnode *to_fill = tail->prev;
            int step = max_elements/2 - tail->num_elements;
            for(int i = 0; i < max_elements / 2 - tail->num_elements; i++) {
                tail->array[tail->num_elements] = to_fill->array[i];
                tail->num_elements++;
            }
            for(int i = 0; i < to_fill->num_elements - step; i++){
                to_fill->array[i] = to_fill->array[i+1];
            }
            to_fill->num_elements -= step;

            if (to_fill->num_elements < max_elements / 2) {
                for(int i = 0; i < to_fill->num_elements; i++){
                    tail->array[tail->num_elements] = to_fill->array[i];
                    tail->num_elements++;
                }
                tail->prev = to_fill->prev;
                to_fill->prev->next = tail;

                length--;
            }
        }
    }
    void insert(T& t, int& node,  int& index){
        if(node > length - 1 && node != 0) {
            std::cout << "Can`t insert, index is more than length" << std::endl;
            return;
        }
        if(node == length - 1 && index == tail->num_elements){
            push_back(t);
            return;
        }

        Listnode* cur = head;

        for(int i = 0; i < node; i++){

            cur = cur->next;

        }
        if(cur->num_elements < this->max_elements) {
            for(int i = cur->num_elements; i > index; i--){
                cur->array[i] = cur->array[i - 1];
            }
            cur->array[index] = t;
            cur->num_elements++;
        }
        else{
            T temp = cur->array[cur->num_elements - 1];
            for(int i = cur->num_elements - 1 ; i > index; i--){
                cur->array[i] = cur->array[i - 1];
            }
            cur->array[index] = t;

            Listnode *for_filled = new Listnode;
            for_filled->next = cur->next;
            if(cur != tail)
                for_filled->next->prev = for_filled;
            for_filled->prev = cur;
            cur->next = for_filled;
            if(cur == tail)
                tail = for_filled;

            for(int i = 0; i < max_elements/2; i++){

                for_filled->array[i] = cur->array[max_elements / 2 + i];
                for_filled->num_elements++;
                cur->num_elements--;

            }
            for_filled->array[for_filled->num_elements] = temp;
            for_filled->num_elements++;
            // std::cout<<for_filled->num_elements<<'\n';

            this->length++;

        }

    }
    void delete_by_index(int& node, int& index){
        if(node > length - 1 || length == 0){
            std::cout<<"There are no node with this index, can`t be deleted\n";
            return;
        }
        if(node == length - 1 && index == tail->num_elements - 1){
            pop_back();
            return;
        }
        Listnode* cur = head;
        for(int i = 0; i < node; i++){
            cur = cur->next;
        }
        if(index > cur->num_elements - 1){
            std::cout<<"There are no element with this index in your node, can`t be deleted\n";
            return;
        }
        for(int i = index; i < cur->num_elements - 1; i++){
            cur->array[i] = cur->array[i+1];
        }
        cur->num_elements--;
        if(cur->num_elements < max_elements / 2) {
            if (cur != tail) {
                Listnode *to_fill = cur->next;
                int step = max_elements/2 - cur->num_elements;
                for(int i = 0; i < max_elements / 2 - cur->num_elements; i++) {
                    cur->array[cur->num_elements] = to_fill->array[i];
                    cur->num_elements++;
                }
                for(int i = 0; i < to_fill->num_elements - step; i++){
                    to_fill->array[i] = to_fill->array[i+1];
                }
                to_fill->num_elements -= step;

                if (to_fill->num_elements < max_elements / 2) {
                    for(int i = 0; i < to_fill->num_elements; i++){
                        cur->array[cur->num_elements] = to_fill->array[i];
                        cur->num_elements++;
                    }
                    cur->next = to_fill->next;
                    if(to_fill != tail)
                        to_fill->next->prev = cur;
                    if(to_fill == tail)
                        tail = cur;
                    length--;
                }
                return;
            }
            if(cur == tail && head != tail){
                Listnode *to_fill = cur->prev;
                int step = max_elements/2 - cur->num_elements;
                for(int i = 0; i < max_elements / 2 - cur->num_elements; i++) {
                    cur->array[cur->num_elements] = to_fill->array[i];
                    to_fill->array[i] = to_fill->array[i+1];
                    cur->num_elements++;
                }
                for(int i = 0; i < to_fill->num_elements - step; i++){
                    to_fill->array[i] = to_fill->array[i+1];
                }
                to_fill->num_elements -= step;

                if (to_fill->num_elements < max_elements / 2) {
                    for(int i = 0; i < to_fill->num_elements; i++){
                        cur->array[cur->num_elements] = to_fill->array[i];
                        cur->num_elements++;
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
        std::cout<<"index\t\t";
        for(int i = 0; i < max_elements; i++){
            std::cout<<i<<"\t";
        }
        std::cout<<"\n"<<std::endl;
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

template<typename T> int U_list <T>::max_elements = 4;

#endif //LAB_2B_1_UNROLLED_LINKED_LIST__U_LIST_H
