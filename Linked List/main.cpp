/*
main.cpp

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

#include <string>
#include "LinkedList.h"

int main(){
    Linked_List<float> l2;
    
    l2.insert_node(0,21); 
    l2.insert_node(1,22); 
    l2.insert_node(2,23); 
    l2.insert_node(1,21.5); 

    l2.insert_node(0,20.5); 

    l2.print_list(); 

    l2.remove_last_node();

    return 0; 


    std::cout << "========================================\n";
    std::cout << "      TESTING LINKED LIST ADT\n";
    std::cout << "========================================\n\n";

    std::cout << "--- 1. Testing add_node_bottom & print_list ---\n";
    Linked_List<int> list;

    std::cout << "Initial length: " << list.length() << "\n";
    std::cout << "Is empty? " << (list.empty() ? "Yes" : "No") << "\n\n";

    std::cout << "Adding 10, 20, 30 to bottom...\n";
    list.add_node_bottom(10);
    list.add_node_bottom(20);
    list.add_node_bottom(30);

    std::cout << "Current List: ";
    list.print_list();
    std::cout << "List Length: " << list.length() << "\n\n";

    std::cout << "--- 2. Testing return_node ---\n";
    std::cout << "Node at index 0: " << list.return_node(0) << "\n";
    std::cout << "Node at index 1: " << list.return_node(1) << "\n";
    std::cout << "Node at index 2: " << list.return_node(2) << "\n\n";

    std::cout << "--- 3. Testing insert_node ---\n";
    std::cout << "Inserting 5 at index 0 (Front)...\n";
    list.insert_node(0, 5);
    list.print_list();

    std::cout << "Inserting 15 at index 2 (Middle)...\n";
    list.insert_node(2, 15);
    list.print_list();

    std::cout << "Inserting 40 at index 5 (Back/Append)...\n";
    list.insert_node(list.length(), 40);
    list.print_list();
    std::cout << "New Length: " << list.length() << "\n\n";

    std::cout << "--- 4. Testing remove_node & remove_last_node ---\n";
    std::cout << "Removing node at index 0 (Front - 5)...\n";
    list.remove_node(0);
    list.print_list();

    std::cout << "Removing node at index 2 (Middle - 20)...\n";
    list.remove_node(2);
    list.print_list();

    std::cout << "Removing last node using remove_last_node()...\n";
    list.remove_last_node();
    list.print_list();
    std::cout << "New Length: " << list.length() << "\n\n";

    std::cout << "--- 5. Testing Templating with std::string ---\n";
    Linked_List<std::string> string_list;
    string_list.add_node_bottom("Apple");
    string_list.add_node_bottom("Banana");
    string_list.add_node_bottom("Cherry");

    std::cout << "String List: ";
    string_list.print_list();
    std::cout << "\n";

    std::cout << "========================================\n";
    std::cout << "        ALL TESTS COMPLETED!\n";
    std::cout << "========================================\n";

    return 0;
}