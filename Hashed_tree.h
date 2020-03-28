//
// Created by Win10Pro on 03.03.2020.
//

#ifndef LAB_2B_1_UNROLLED_LINKED_LIST__HASHED_ARRAY_TREE__HASHED_TREE_H
#define LAB_2B_1_UNROLLED_LINKED_LIST__HASHED_ARRAY_TREE__HASHED_TREE_H

#include <iostream>
#include <cmath>
#include <cassert>

template <typename T>
class Hashed_tree {

private:

    int size;
    static int power;
    T** roots;

public:

    Hashed_tree(){
        this->size = 0;
        roots = new T*[2 << power];
        for(int i = 0; i < 2 << power; i++){
            roots[i] = new T[2 << power];
        }

    }

    ~Hashed_tree(){
        delete[] roots;
    }

    //Auxiliary functions

    void array_increase(){

        T** copy_roots = new T*[2 << (power + 1)];
        //std::cout<<"sdsfpower = "<<power<<'\n';
        for(int i = 0; i < 2 << (power + 1); i++){
            copy_roots[i] = new T[2 << (power + 1)];
        }
        //std::cout<<std::endl;
        for(int i = 0; i < size; i++){
            //std::cout<<i<<std::endl;
            copy_roots[i / (2 << (power + 1))][i % (2 << (power + 1))] =
                    roots[i / (2 << power)][i % (2 << power)];

        }
        this->power++;
        delete[] roots;
        this->roots = copy_roots;
    }
    void array_decrease(){

        T** copy_roots = new T*[2 << (power - 1)];
        //std::cout<<"sdsfpower = "<<power<<'\n';
        for(int i = 0; i < 2 << (power - 1); i++){
            copy_roots[i] = new T[2 << (power - 1)];
        }
        //std::cout<<std::endl;
        for(int i = 0; i < size; i++){
            //std::cout<<i<<std::endl;
            copy_roots[i / (2 << (power - 1))][i % (2 << (power - 1))] =
                    roots[i / (2 << power)][i % (2 << power)];

        }
        this->power--;
        delete[] roots;
        this->roots = copy_roots;
    }
    T shift_for_insert(T& t, int& node, int& index){
        T last = roots[(size - 1) / (2 << power)][(size - 1) % (2 << power)];
        for(int i  = size - 1; i > node*(2 << power) + index; i--){
            roots[i / (2 << power)][i % (2 << power)] = roots[(i - 1) / (2 << power)][(i - 1) % (2 << power)];
        }
        roots[node][index] = t;
        return last;
    }
    void shift_for_delete(int& node, int& index){

        for(int i  = node*(2 << power) + index; i < size - 1; i++){
            roots[i / (2 << power)][i % (2 << power)] = roots[(i + 1) / (2 << power)][(i + 1) % (2 << power)];
        }

    }
    int get_power(){
        return power;
    }

    //Functions

    void push_back(T& t){

        if(size == (4 << (2 * power))){

            array_increase();
            push_back(t);
            return;

        }
        if(size % (2 << power) == 0){

            roots[size / (2 << power)][0]  = t ;
            size++;
            return;

        }
        roots[size / (2 << power)][size % (2 << power)] = t;
        size++;

    }
    void pop_back(){
        size--;
        if(size == ((4 << (2 * power)) / 8) && power > 1) {

            array_decrease();
        }

    }
    void insert(T& t, int& node, int& index){
        if(node * (2 << power) + index > size){
            std::cout<<"Can`t insert, index is more than size\n";
            return;
        }
        if(node * (2 << power) + index == size){
            push_back(t);
            return;
        }
        T temp = shift_for_insert(t, node, index);
        //print_all_from_tree();
        push_back(temp);

    }
    void delete_by_index(int& node, int& index){
        if(node * (2 << power) + index > size - 1){
            std::cout<<"Can`t delete, index is more than size\n";
            return;
        }
        if(node * (2 << power) + index == size - 1){
            pop_back();
            return;
        }
        shift_for_delete(node, index);
        pop_back();

    }
    T peek(int& node, int& index){
        return roots[node][index];
    }
    void print_all_from_tree(){
        //std::cout<<"power = "<< power + 1<<"\n";
        std::cout<<"index\t\t";
        for(int i = 0; i < (2 << power); i++){
            std::cout<<i<<"\t";
        }
        std::cout<<"\n"<<std::endl;
        for(int i = 0; i < (2 << power); i++) {

            if( i > size / (2 << power))
                std::cout<<"node "<< i <<" not exist"<< std::endl;
            else {
                std::cout << "node " << i << "\t\t";
                for (int j = 0; j < (2 << power); j++) {

                    if(i == size / (2 << power) && j == size % (2 << power)) {
                        break;
                    }
                    std::cout << roots[i][j] << "\t";

                }
                std::cout << std::endl;
            }

        }
    }

};
template<typename T> int Hashed_tree <T>::power = 1;

#endif //LAB_2B_1_UNROLLED_LINKED_LIST__HASHED_ARRAY_TREE__HASHED_TREE_H
