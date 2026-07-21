# C++ Vector ADT

A lightweight, template-based Vector Abstract Data Type (ADT) implemented in C++ using dynamic arrays.

## Features:
- **Generic/Templated Design**: Supports storing any type (`int`, `double`, `std::string`, custom classes) via `template <typename DataType>`.
- **Dynamic Resizing**: Automatically doubles array capacity when full during `push_back()` or `insert()` operations.
- **Rule of Three Compliant**: Implements custom destructor, copy constructor, and exception-safe copy assignment operator to prevent memory leaks and dangling pointers.
- **Random Access & Iterators**: Provides array indexing via `operator[]`, bounds-checked `at()`, as well as `begin()` and `end()` pointer access for range-based operations.
- **Bounds Checking**: Throws `std::out_of_range` exceptions when accessing or modifying invalid indices.

## Dependencies: 
- C++ Compiler supporting C++11 or higher (e.g., `g++`, `clang++`)
- Standard Library Headers: `<iostream>`, `<stdexcept>`

## Compilation: 
- Compile and run using `g++`:
    ```bash
    g++ main.cpp -o vector-demo
    ./vector-demo
    ```

## Class Interface:

| Method                              | Return Type                     | Description                                                                   |
| ----------------------------------- | ------------------------------- | ----------------------------------------------------------------------------- |
| `push_back(DataType NewValue)`      | `void`                          | Appends an element to the end of the vector.                                  |
| `pop_back()`                        | `void`                          | Removes the last element of the vector.                                       |
| `insert(int index, DataType value)` | `void`                          | Inserts an element at the specified index, shifting existing elements right.  |
| `erase(int index)`                  | `void`                          | Removes the element at the specified index, shifting remaining elements left. |
| `clear()`                           | `void`                          | Resets element count to 0 without freeing allocated memory.                   |
| `resize(int NewSize)`               | `void`                          | Reallocates the internal buffer to a new capacity.                            |
| `front()`                           | `DataType&` / `const DataType&` | Returns a reference to the first element.                                     |
| `back()`                            | `DataType&` / `const DataType&` | Returns a reference to the last element.                                      |
| `at(size_t index)`                  | `DataType&`                     | Returns element reference at index with bounds checking.                      |
| `operator[](int index)`             | `DataType&`                     | Provides direct array indexing.                                               |
| `empty()`                           | `bool`                          | Returns `true` if size is 0, `false` otherwise.                               |
| `size()`                            | `int`                           | Returns current number of elements.                                           |
| `capacity()`                        | `int`                           | Returns current allocated array storage.                                      |
| `data()`                            | `DataType*`                     | Returns raw pointer to internal array buffer.                                 |
| `begin()` / `end()`                 | `DataType*`                     | Returns raw pointers to start and end of active element buffer.               |

## Known Limitations:
- **$O(N)$ Insertion/Deletion Overhead**: `insert()` and `erase()` shift elements sequentially, resulting in $O(N)$ time complexity.
- **Index Type Sign Mismatches**: Methods like `operator[]` and `erase()` take signed `int` indices while member variables `m_size` and `m_capacity` are `size_t`.
- **Missing Upper Bounds Check on `insert()`**: `insert()` checks for negative indices but currently allows inserting past `m_size`, which can lead to uninitialized gaps or buffer overflow if out-of-bounds.
