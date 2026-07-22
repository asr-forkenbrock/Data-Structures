/*
main.cpp

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

#include "BinaryTree.h"

int main() {
    std::cout << "========================================\n";
    std::cout << "        Binary Tree ADT Demo            \n";
    std::cout << "========================================\n\n";

    BinaryTree tree;

    int initial_data[] = {15, 10, 20, 8, 12, 17, 25};
    int n = sizeof(initial_data) / sizeof(initial_data[0]);

    std::cout << "Building tree from array: {15, 10, 20, 8, 12, 17, 25}...\n";
    tree.BuildBinaryTree(initial_data, n);

    std::cout << "Inserting additional values: 6 and 19...\n\n";
    tree.Insert(6);
    tree.Insert(19);

    std::cout << "Tree Height: " << tree.Height() << "\n\n";

    std::cout << "--- In-Order Traversal (Sorted Order) ---\n";
    tree.InOrder();
    std::cout << "\n";

    std::cout << "--- Pre-Order Traversal (Root -> Left -> Right) ---\n";
    tree.PreOrder();
    std::cout << "\n";

    std::cout << "--- Post-Order Traversal (Left -> Right -> Root) ---\n";
    tree.PostOrder();
    std::cout << "\n";

    std::cout << "--- DFS Alias (Pre-Order) ---\n";
    tree.DFS();
    std::cout << "\n";

    std::cout << "--- BFS Traversal (Level-Order) ---\n";
    tree.BFS();
    std::cout << "\n";

    std::cout << "Clearing tree memory...\n";
    tree.Clear();
    std::cout << "Tree Height after Clear(): " << tree.Height() << "\n";

    std::cout << "\n========================================\n";
    std::cout << "            Demo Finished               \n";
    std::cout << "========================================\n";

    return 0;
}