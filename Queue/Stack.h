/*
Stack.h

Stack ADT written in C++.
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

#ifndef STACK_H
#define STACK_H

#include <iostream>

template <typename DataType>
class stack {
    public:
        ~stack(){
            delete[] data; 
            data_size = 0; 
            data = nullptr; 
        }
        
        stack(){
            data_size = 0; 
            data = nullptr; 
        }
        
        stack(int size){
            data_size = size; 
            data = new DataType[size]; 
        }
        
        stack(const stack& other){
            data_size = other.data_size; 
            data = new DataType[other.data_size]; 
            for(int i=0; i<data_size; i++){
                data[i]=other.data[i]; 
            }
        }
        
        stack& operator=(const stack& other){
            if (this == &other){
                return *this;
            }
            delete[] data;
            data_size = other.data_size;
            data = new DataType[data_size];
            for(size_t i = 0; i < data_size; i++){
                data[i] = other.data[i];
            }
            return *this;
        }
        
        void push(DataType value){
            DataType* NewData = new DataType[data_size+1]; 
            if(data_size > 0){
            	for(int i=0; i<data_size; i++){
            	    NewData[i] = data[i]; 
            	}
            }
            NewData[data_size] = value; 
            data_size++; 
            delete[] data; 
            data = NewData; 
        }
        
        void pop(){
            if(data_size > 0){
                DataType* NewData = new DataType[data_size-1]; 
                if(data_size > 0){
                    for(int i=0; i<data_size-1; i++){
                	NewData[i] = data[i]; 
                    }
                }
                data_size--; 
                delete[] data; 
                data = NewData; 
            }
        }
        
        const DataType& top() const {
            if(empty()){
               throw std::out_of_range("Stack is empty");
            }
            return data[data_size-1]; 
        }
        
        bool empty() const {
            return data_size == 0; 
        }
        
        int size() const {
            return data_size; 
        }
        
    private:
        DataType* data = nullptr; 
        size_t data_size = 0; 
}; 


#endif