# C++ Binary Tree

A lightweight, header-only Binary Search Tree (BST) Abstract Data Type (ADT) implemented in C++.

## Features:
- **Binary Search Tree Property**: Automatically arranges inserted elements following BST property rules (left subtree < root $\le$ right subtree).
- **Multiple Tree Traversals**: Supports standard Depth-First Search (DFS) traversals (**Pre-Order**, **In-Order**, **Post-Order**) and Breadth-First Search (**BFS** / Level-Order).
- **Dynamic Array Construction**: Easily build a binary search tree from a C-style array using `BuildBinaryTree()`.
- **Automatic Memory Cleanup**: Features dynamic node allocation with a destructor (`ClearTree`) to prevent memory leaks.
- **`const` Correctness**: Read-only methods (height calculation, traversals) are marked `const`-safe.

## Dependencies: 
- C++ Compiler supporting C++11 or higher (e.g., `g++`, `clang++`)
- Standard Library Headers: `<iostream>`, `<vector>`, `<algorithm>`

## Compilation: 
- Compile and run using `g++`:
    ```bash
    g++ main.cpp -o binary-tree-demo
    ./binary-tree-demo
    ```

## Class Interface:

| Method                                   | Return Type | Description                                                                   |
| ---------------------------------------- | ----------- | ----------------------------------------------------------------------------- |
| `Insert(int num)`                        | `void`      | Inserts a new value into the binary search tree.                              |
| `BuildBinaryTree(const int* arr, int n)` | `void`      | Inserts `n` elements from an integer array into the tree.                     |
| `PreOrder()`                             | `void`      | Performs Pre-Order traversal (`Root -> Left -> Right`) to `std::cout`.        |
| `InOrder()`                              | `void`      | Performs In-Order traversal (`Left -> Root -> Right`), printing sorted order. |
| `PostOrder()`                            | `void`      | Performs Post-Order traversal (`Left -> Right -> Root`).                      |
| `DFS()`                                  | `void`      | Performs Depth-First Search (alias for Pre-Order).                            |
| `BFS()`                                  | `void`      | Performs Breadth-First Search (Level-Order traversal) level by level.         |
| `Height()`                               | `int`       | Returns the total depth/height of the tree (0 for empty tree).                |
| `Clear()`                                | `void`      | Deletes all nodes and resets `Root` to `nullptr`.                             |

## Known Limitations:
- **Integer Type Bound**: Designed specifically for `int` data types (not templated).
- **Unbalanced Trees**: Does not perform auto-balancing (like AVL or Red-Black trees); worst-case insertion order (sorted input) can result in an $O(N)$ height skewed tree.
- **Missing Rule of Three**: Lacks a custom copy constructor and copy assignment operator (`operator=`); copying a `BinaryTree` instance will create shallow pointer copies resulting in double-free errors.
