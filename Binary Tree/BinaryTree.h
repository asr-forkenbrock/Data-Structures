/*
BinaryTree.h

Binary Tree ADT written in C++.
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

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <vector>
#include <algorithm>

class BinaryTree{
    private: 
        struct Node {
            Node(int value){ data = value; }
            int data; 
            Node* left = nullptr; 
            Node* right = nullptr;
        }; 
        Node* Root;

        int GetHeight(Node* root) const {
            if (root == nullptr) return 0;
            return 1 + std::max(GetHeight(root->left), GetHeight(root->right));
        }

        void PreOrder_priv(Node* root) const { 
            if(root == nullptr){ return; }
            std::cout << root->data << "\n"; 
            PreOrder_priv(root->left);
            PreOrder_priv(root->right);
        }

        void InOrder_priv(Node* root) const { 
            if(root == nullptr){ return; }
            InOrder_priv(root->left);
            std::cout << root->data << "\n"; 
            InOrder_priv(root->right);
        }

        void PostOrder_priv(Node* root) const { 
            if(root == nullptr){ return; }
            PostOrder_priv(root->left);
            PostOrder_priv(root->right);
            std::cout << root->data << "\n"; 
        }

        void BuildBinarySearchTree(int* arr, int n, Node*& root){
            for(int i=0; i<n; i++){
                Insert_priv(arr[i], root); 
            }
        }

        void CollectLevels(Node* root, int depth, std::vector<std::vector<int>>& levels) const {
            if (root == nullptr) return;
            if (depth >= levels.size()) {
                levels.resize(depth + 1);
            }
            levels[depth].push_back(root->data);
            CollectLevels(root->left, depth + 1, levels);
            CollectLevels(root->right, depth + 1, levels);
        }


        void BFS_priv(Node* root) const { 
            std::vector<std::vector<int>> Levels(GetHeight(root));
            CollectLevels(root,GetHeight(root),Levels); 
            for(int y=0; y<Levels.size(); y++){
                for(int x=0; x<Levels[y].size(); x++){
                    std::cout << Levels[y][x] << "\n"; 
                }
            }
        }

        void Insert_priv(int num, Node*& root){
            if(root == nullptr){
                root = new Node(num); 
            }else if(num >= root->data){         
                Insert_priv(num, root->right); 
            }else if(num < root->data){ 
                Insert_priv(num, root->left); 
            }
        }

        void ClearTree(Node* root){ 
            if(root == nullptr){ return; }
            ClearTree(root->left);
            ClearTree(root->right);
            delete root; 
        }

    public: 
        BinaryTree(){
            Root = nullptr; 
        }

        ~BinaryTree(){
            ClearTree(Root); 
            Root = nullptr;
        }

        void Clear(){ ClearTree(Root); Root = nullptr; }
        int Height() const { return GetHeight(Root); }
        void Insert(int num){ Insert_priv(num, Root); }
        void BuildBinaryTree(int* arr, int n){ BuildBinarySearchTree(arr, n, Root); }
        void PreOrder() const { PreOrder_priv(Root); }
        void InOrder() const { InOrder_priv(Root); }
        void PostOrder() const { PostOrder_priv(Root); }
        void DFS() const { PreOrder_priv(Root); }
        void BFS() const { BFS_priv(Root); }
}; 

#endif