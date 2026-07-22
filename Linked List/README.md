# C++ Linked List

A lightweight, template-based Linked List Abstract Data Type (ADT) implemented in C++.

## Features:
- **Generic/Templated Design**: Supports storing any data type (`int`, `float`, `std::string`, custom objects) via `template <typename DataType>`.
- **Dynamic Memory Management**: Automatically allocates node memory dynamically on insertion and frees memory on node deletion.
- **Destructor Cleanup**: Includes a custom destructor to prevent memory leaks by freeing all allocated nodes upon list destruction.
- **Bounds Checking & Exception Handling**: Safe element access via `return_node()`, which throws `std::out_of_range` when accessing invalid indices.
- **Zero-Dependency Core**: Standard, lightweight implementation depending only on standard header includes (`<iostream>`, `<stdexcept>`).

## Dependencies: 
- C++ Compiler supporting C++11 or higher (e.g., `g++`, `clang++`)
- Standard Library Headers: `<iostream>`, `<stdexcept>`

## Compilation: 
- Compile and run using `g++`:
    ```bash
    g++ main.cpp -o linked-list-demo
    ./linked-list-demo
    ```

## Class Interface:

| Method                                   | Return Type | Description                                                                       |
| ---------------------------------------- | ----------- | --------------------------------------------------------------------------------- |
| `add_node_bottom(DataType value)`        | `void`      | Appends a new node containing `value` to the end of the list.                     |
| `insert_node(int index, DataType value)` | `void`      | Inserts a node containing `value` at the specified `index`.                       |
| `remove_node(int index)`                 | `void`      | Removes the node at the specified `index` and updates list pointers.              |
| `remove_last_node()`                     | `void`      | Deletes the last node of the list.                                                |
| `return_node(int index)`                 | `DataType`  | Returns the data stored at `index` (throws `std::out_of_range` if out of bounds). |
| `print_list()`                           | `void`      | Displays the formatted list contents (`val1 -> val2 -> nullptr`) to `std::cout`.  |
| `length()`                               | `int`       | Returns the current total count of nodes in the list.                             |
| `empty()`                                | `bool`      | Returns `true` if the list has no nodes (`root == nullptr`), `false` otherwise.   |

## Known Limitations:
- **Sequential $O(N)$ Access**: Operations like `insert_node()`, `remove_node()`, and `return_node()` require traversing nodes sequentially from `root`, resulting in $O(N)$ linear time complexity.
- **Singly Linked Traversal**: Nodes only maintain a `next` pointer (no `prev` pointer), requiring extra traversal to access preceding nodes.
- **Missing Rule of Three**: Currently lacks a custom copy constructor and copy assignment operator (`operator=`); assigning or copying `Linked_List` instances will result in shallow copies and double-free errors.
