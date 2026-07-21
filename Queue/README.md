# C++ Queue ADT

A lightweight, template-based Queue Abstract Data Type (ADT) implemented in C++ using dynamic arrays.

## Features:
- **Generic/Templated Design**: Supports any data type (`int`, `double`, `std::string`, custom classes) via `template <typename DataType>`.
- **Dynamic Resizing**: Automatically doubles capacity when full to accommodate new elements without explicit reallocation from the user.
- **Rule of Three Compliant**: Includes custom destructor, copy constructor, and exception-safe copy assignment operator to prevent memory leaks and dangling pointers.
- **Bounds & Safety Checking**: Safely handles operations on empty queues by throwing `std::out_of_range` exceptions.
- **Const Correctness**: Implements `const` member functions for `front()`, `back()`, `empty()`, `size()`, and `capacity()`.

## Dependencies: 
- C++ Compiler supporting C++11 or higher (e.g., `g++`, `clang++`)
- Standard Library Headers: `<iostream>`, `<stdexcept>`

## Compilation: 
- Compile and run using `g++`:
    ```bash
    g++ -std=c++11 main.cpp -o queue-demo
    ./queue-demo
    ```

## Class Interface:

| Method                 | Return Type       | Description                                  |
| ---------------------- | ----------------- | -------------------------------------------- |
| `push(DataType value)` | `void`            | Inserts an element at the back of the queue. |
| `pop()`                | `void`            | Removes the front element of the queue.      |
| `front()`              | `const DataType&` | Returns the front element.                   |
| `back()`               | `const DataType&` | Returns the back element.                    |
| `empty()`              | `bool`            | Returns `true` if empty, `false` otherwise.  |
| `size()`               | `size_t`          | Returns current element count.               |
| `capacity()`           | `size_t`          | Returns current allocated array capacity.    |

## Known Limitations:
- **$O(N)$ Dequeue Overhead**: `pop()` shifts all remaining elements left by 1 index, resulting in $O(N)$ linear time complexity instead of $O(1)$ constant time (a circular ring buffer would resolve this).
- **Pass-by-Value in `push()`**: Parameters are passed by value rather than `const DataType&`, which can incur unnecessary copy overhead for large objects.
- **Read-Only Accessors**: `front()` and `back()` only provide `const` references, preventing direct in-place modification of elements.
