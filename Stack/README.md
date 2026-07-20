# C++ Stack ADT

A lightweight, template-based Stack Abstract Data Type (ADT) implemented in C++ using dynamic arrays.

## Features:
- **Generic Implementation**: Built using C++ templates, allowing it to store any data type (`int`, `double`, custom objects, etc.).
- **Dynamic Memory Management**: Automatically resizes memory allocation on `push()` and `pop()` operations.
- **Rule of Three Compliant**: Fully supports deep copying and proper resource cleanup via a custom destructor, copy constructor, and copy assignment operator (`operator=`).
- **Standard Stack Operations**:
  - `push(value)`: Adds an element to the top of the stack.
  - `pop()`: Removes the top element.
  - `top()`: Accesses the top element (throws `std::out_of_range` if the stack is empty).
  - `empty()`: Returns `true` if the stack is empty.
  - `size()`: Returns the current number of elements.

## Dependencies: 
- C++ Compiler supporting C++11 or higher (e.g., `g++`, `clang++`)
- Standard Library Headers: `<iostream>`, `<stdexcept>`

## Compilation: 
- Compile and run using `g++`:
    ```bash
    g++ main.cpp -o stack-demo
    ./stack-demo
    ```

## Known Limitations:
- **Performance Overhead**: `push()` and `pop()` reallocate and copy the entire dynamic array on every operation ($O(N)$ time complexity). A growth strategy (e.g., doubling capacity when full) would improve performance to $O(1)$ amortized time.
- **Shrinking on Pop**: Memory reallocation on `pop()` requires a copy operation, which is inefficient for large datasets.