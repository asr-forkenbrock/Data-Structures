/*
main.cpp

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

#include <string>
#include "vector.h"

int main() {
    std::cout << "========================================\n";
    std::cout << "        TESTING CUSTOM VECTOR ADT\n";
    std::cout << "========================================\n\n";

    std::cout << "--- 1. Testing push_back & Size/Capacity ---\n";
    vector<int> numbers;
    
    std::cout << "Initial size: " << numbers.size() << ", capacity: " << numbers.capacity() << "\n";
    std::cout << "Is empty? " << (numbers.empty() ? "Yes" : "No") << "\n\n";

    std::cout << "Pushing 10, 20, 30, 40...\n";
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);

    numbers.ShowData();
    std::cout << "Front: " << numbers.front() << "\n";
    std::cout << "Back:  " << numbers.back() << "\n\n";

    std::cout << "--- 2. Element Access & Modification ---\n";
    std::cout << "Element at index 2 (using operator[]): " << numbers[2] << "\n";
    std::cout << "Element at index 1 (using at()):         " << numbers.at(1) << "\n";

    std::cout << "Modifying numbers[0] to 99...\n";
    numbers[0] = 99;
    numbers.ShowData();
    std::cout << "\n";

    std::cout << "--- 3. Testing Insert & Erase ---\n";
    std::cout << "Inserting 15 at index 1...\n";
    numbers.insert(1, 15);
    numbers.ShowData();

    std::cout << "Erasing element at index 2...\n";
    numbers.erase(2);
    numbers.ShowData();
    std::cout << "\n";

    std::cout << "--- 4. Testing Iterators (begin/end) ---\n";
    std::cout << "Iterating through vector: [ ";
    for (int* it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "]\n\n";

    std::cout << "--- 5. Testing Deep Copy (Rule of Three) ---\n";
    vector<int> copy_constructed = numbers; 
    
    vector<int> assigned_vector;
    assigned_vector = numbers;

    std::cout << "Modifying original vector (pushing 500)...\n";
    numbers.push_back(500);

    std::cout << "Original vector back: " << numbers.back() << "\n";
    std::cout << "Copied vector back:   " << copy_constructed.back() << " (Should remain unchanged)\n";
    std::cout << "Assigned vector back: " << assigned_vector.back() << " (Should remain unchanged)\n\n";

    std::cout << "--- 6. Testing Template Support (std::string) ---\n";
    vector<std::string> words;
    words.push_back("Hello");
    words.push_back("Vector");
    words.push_back("ADT");

    words.ShowData();
    std::cout << "\n";

    std::cout << "========================================\n";
    std::cout << "        ALL TESTS COMPLETED!\n";
    std::cout << "========================================\n";

    return 0;
}