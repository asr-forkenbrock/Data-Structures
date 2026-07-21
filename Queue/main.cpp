/*
main.cpp

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

#include "Stack.h"

template <typename T>
void printStackInfo(const std::string& name, const stack<T>& s){
    std::cout << name << " | Size: " << s.size();
    if(!s.empty()){ std::cout << " | Top: " << s.top(); }else{ std::cout << " | Top: [Empty]"; }
    std::cout << "\n";
}

int main(){
    std::cout << "=========================================\n";
    std::cout << "        C++ STACK ADT DEMONSTRATION      \n";
    std::cout << "=========================================\n\n";

    std::cout << "--- 1. Basic Operations (push, top, pop) ---\n";
    stack<int> numbers;
    
    std::cout << "Pushing: 10, 20, 30\n";
    numbers.push(10);
    numbers.push(20);
    numbers.push(30);

    printStackInfo("numbers", numbers);

    std::cout << "Popping top element...\n";
    numbers.pop();
    printStackInfo("numbers", numbers);
    std::cout << "\n";

    std::cout << "--- 2. Copy Constructor (Deep Copy) ---\n";
    stack<int> copiedStack(numbers); 
    printStackInfo("Original (numbers)", numbers);
    printStackInfo("Copy (copiedStack)", copiedStack);

    std::cout << "Modifying original stack (pushing 99)...\n";
    numbers.push(99);
    printStackInfo("Original (numbers)", numbers);
    printStackInfo("Copy (copiedStack)", copiedStack); 
    std::cout << "\n";

    std::cout << "--- 3. Copy Assignment Operator ---\n";
    stack<int> assignedStack;
    assignedStack.push(5);
    
    std::cout << "Before assignment:\n";
    printStackInfo("assignedStack", assignedStack);

    assignedStack = numbers; 
    std::cout << "After assignment (assignedStack = numbers):\n";
    printStackInfo("assignedStack", assignedStack);
    std::cout << "\n";

    std::cout << "--- 4. Template Support (std::string) ---\n";
    stack<std::string> textStack;
    textStack.push("World");
    textStack.push("Hello");

    printStackInfo("textStack", textStack);
    std::cout << "Popping: " << textStack.top() << "\n";
    textStack.pop();
    printStackInfo("textStack", textStack);
    std::cout << "\n";

    std::cout << "==========================================\n";
    std::cout << "              DEMO COMPLETE               \n";
    std::cout << "==========================================\n";
    return 0;
}