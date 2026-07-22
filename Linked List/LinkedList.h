/*
LinkedList.h

Linked List ADT written in C++.
Copyright (C) 2026  Noah Forkenbrock <asr-forkenbrock> 

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <stdexcept>

template <typename DataType>
class Linked_List {
    public: 
        ~Linked_List() {
            Node* current = root;
            while (current != nullptr) {
                Node* next_node = current->next;
                delete current;
                current = next_node;
            }
        }
        
        void print_list(){
            Node* current = root; 
            while(current != nullptr){
                std::cout << current->data << " -> "; 
                current = current->next; 
            }
            std::cout << "nullptr\n";
        }

        void add_node_bottom(DataType value){
            Node* current = root; 
            if(current == nullptr){
                root = new Node(value); 
            }else{
                while(current->next != nullptr){
                    current = current->next; 
                }
                current->next = new Node(value); 
            }
            list_length++; 
        } 
        
        void remove_last_node(){
            if(root == nullptr){ return; }
            Node* current = root; 
            if(current != nullptr && current->next == nullptr){
                delete root; 
                root = nullptr; 
            }else{
                if(current != nullptr){
                    while(current->next->next != nullptr){
                        current = current->next; 
                    }
                    delete current->next; 
                    current->next = nullptr; 
                }
            }
            list_length--; 
        }

        void remove_node(int index){
            if(index < 0 || index >= list_length || root == nullptr){ return; }
            int index_counter = 0; 
            Node* prev_pointer = 0; 
            Node* current = root; 
            if(index == 0){
                Node* temp = root;
                root = root->next;
                delete temp;
                list_length--; 
                return; 
            }
            prev_pointer = root; 
            if(current != nullptr){
                while(current->next != nullptr){
                    if(index_counter == index){
                        prev_pointer->next = current->next; 
                        delete current; 
                        list_length--; 
                        return; 
                    }
                    prev_pointer = current; 
                    current = current->next; 
                    index_counter++; 
                } 
                if(index_counter == index){
                    remove_last_node(); 
                }
            }
        }

        void insert_node(int index, DataType value){
            if(index < 0){ return; } // || index > list_length+1
            int index_counter = 0; 
            Node* prev_pointer = 0; 
            Node* current = root; 
            if(index == 0){ 
                Node* new_node = new Node(value); 
                new_node->next = root; 
                root = new_node; 
                list_length++; 
                return; 
            }
            prev_pointer = root; 
            if(current != nullptr){
                while(current->next != nullptr){
                    if(index_counter == index){
                        Node* new_node = new Node(value); 
                        prev_pointer->next = new_node; new_node->next = current; 
                        list_length++; 
                        return; 
                    }
                    prev_pointer = current; 
                    current = current->next; 
                    index_counter++; 
                } 
                index_counter++; 
            }
            
            
            if(index_counter == index){ 
                Node* new_node = new Node(value);  
                current->next = new_node; 
                list_length++; 
            }
        }

        int length(){
            return list_length; 
        }

        bool empty(){
            return root == nullptr; 
        }

        DataType return_node(int index){ 
            if(index < 0 || index >= list_length || root == nullptr){ throw std::out_of_range("Invalid Index");
            }
            Node* current = root; 
            for(int i=0; i<index; ++i){
                current = current->next;
            }
            return current->data;
        }

    private:
        struct Node { 
            Node(DataType val){ data=val; next=nullptr; }
            ~Node(){ next=nullptr; }
            DataType data; 
            Node* next = nullptr; 
        }; 
        int list_length = 0; 
        Node* root = nullptr; 
}; 

#endif