/*
vector.h

Vector ADT written in C++.
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

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream> 
#include <stdexcept>


template <typename DataType>
class vector {
    private:
        size_t m_size = 0; 
        size_t m_capacity = 0; 
        DataType *m_data; 

    public: 
        ~vector(){
            delete[] m_data; 
            m_size = 0; 
            m_capacity = 0; 
            m_data = nullptr; 
        }

        vector(){
            m_size = 0; 
            m_capacity = 16; 
            m_data = new DataType[m_capacity]; 
        }
        
        vector(int size){
            m_size = 0; 
            m_capacity = size; 
            m_data = new DataType[m_capacity]; 
        }
        
        vector(const vector& other){
            m_capacity = other.m_capacity; 
            m_size = other.m_size; 
            m_data = new DataType[other.m_capacity]; 
            for(size_t i=0; i<m_size; i++){
                m_data[i]=other.m_data[i]; 
            }
        }

        vector& operator=(const vector& other){
            if(this == &other){
                return *this;
            }
            DataType* new_data = new DataType[other.m_capacity];
            for(size_t i = 0; i < other.m_size; i++){
                new_data[i] = other.m_data[i];
            } 
            delete[] m_data;
            m_data = new_data;
            m_size = other.m_size;
            m_capacity = other.m_capacity;
            return *this;
        }

        DataType* data(){
            return m_data;
        }

        void resize(int NewSize){
            if(NewSize < 0){ return; }
            DataType *NewData = new DataType[NewSize];
            m_capacity = NewSize; 
            int CopyCount = (m_capacity < m_size) ? m_capacity : m_size;
            for(int i = 0; i < CopyCount; i++){
                NewData[i] = m_data[i];
            }
            delete[] m_data;
            m_data = NewData;
            m_size = CopyCount;
        }; 

        void insert(int index, DataType value){
            if(index < 0 || index > m_size){
                throw std::out_of_range("Insert index out of bounds");
            }
            if(m_size == m_capacity){
                if(m_capacity == 0){ m_capacity = 8; }
                m_capacity *= 2; 
                DataType *NewData = new DataType[m_capacity]; 
                for(size_t i=0; i<m_size; i++){
                    NewData[i] = m_data[i];
                }
                delete[] m_data; 
                m_data = NewData;
            }
            int subcounter = m_size-1; 
            for(int i=m_size; i>=0; i--){
                if(i == index){ 
                    m_data[i] = value; 
                    continue; 
                }
                m_data[i] = m_data[subcounter]; 
                subcounter--;  
            }
            m_size++;
        }; 
    
        void push_back(DataType NewValue){
            if(m_size == m_capacity){
                if(m_capacity == 0){ m_capacity = 8; }
                m_capacity *= 2; 
                DataType *NewData = new DataType[m_capacity]; 
                for(size_t i=0; i<m_size; i++){
                    NewData[i] = m_data[i];
                }
                delete[] m_data; 
                m_data = NewData;
            }
            m_data[m_size] = NewValue; 
            m_size++; 
        }; 

        void pop_back(){
            if(m_size > 0){
                m_size--; 
            }
        }; 

        void erase(int index){
            if(index >= 0 and index < m_size){ 
                int subcounter=0; 
                for(int i=0; i<m_size; i++){
                    if(i == index){ continue; } 
                    m_data[subcounter] = m_data[i];
                    subcounter++; 
                }
                m_size--; 
            }
        };

        void clear(){ 
            m_size = 0;  
        }; 

        int size() const { return m_size; }; 

        int capacity() const { return m_capacity; }

        DataType& front(){
            if(empty()){ throw std::out_of_range("Vector is empty"); }
            return m_data[0];
        }; 

        const DataType& front() const {
            if(empty()){ throw std::out_of_range("Vector is empty"); }
            return m_data[0];
        }

        DataType& back(){
            if(empty()){ throw std::out_of_range("Vector is empty"); }
            return m_data[m_size-1]; 
        }; 

        const DataType& back() const {
            if(empty()){ throw std::out_of_range("Vector is empty"); }
            return m_data[m_size-1]; 
        }; 

        DataType* begin(){ return m_data; }

        DataType* end(){ return m_data + m_size; }

        bool empty() const { return m_size == 0; }; 

        DataType& operator[](int index){ return m_data[index]; }; 

        DataType& at(size_t index) {
            if(index >= m_size){ throw std::out_of_range("Index out of range"); }
            return m_data[index];
        }

        void ShowData() const {
            std::cout << "Vector Size: " << m_size << "\n"; 
            if(m_size > 0){
                for(int i=0; i<m_size; i++){
                    if(i == m_size-1){
                        std::cout << m_data[i]; 
                    }else{
                        std::cout << m_data[i] << ", "; 
                    }
                }
                std::cout << "\n"; 
            }
        }; 
}; 

#endif