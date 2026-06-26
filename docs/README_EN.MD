# DataSystem File Management System Design Documentation

## 1. Project Overview

### 1.1 Project Name

DataSystem — A Data Management System Based on Linked Lists and Binary Trees

### 1.2 Project Objectives

This project implements a simple data management system in pure C language with the following features:

* Create, Read, Update, and Delete (CRUD) operations
* Data storage using linked lists
* Fast searching using a binary search tree
* Quick sort algorithm
* File persistence through file I/O
* Menu-driven interactive interface
* Multi-file project organization
* CMake build management

Each record in the system is represented by an `Object` structure:

```c
typedef struct
{
    int id;
    char name[64];
    int data;
} Object;
```

Where:

| Field | Description       |
| ----- | ----------------- |
| id    | Unique identifier |
| name  | Object name       |
| data  | Data value        |

---

# 2. Overall Project Structure

```text
DataSystem/

include/
├── core/
├── list/
├── tree/
├── sort/
├── file/
├── ui/
└── manager/

src/
├── core/
├── list/
├── tree/
├── sort/
├── file/
├── ui/
└── manager/
```

The project adopts:

```text
Layered Architecture
Modular Development
Separation of Header and Source Files
```

Design architecture:

```text
UI Layer
 ↓
Manager Layer
 ↓
Data Structure Layer
 ├─ LinkedList
 ├─ BinaryTree
 └─ QuickSort
 ↓
File Layer
 ↓
Disk Files
```

---

# 3. Module Design

## 3.1 Core Module

Directory:

```text
include/core/
src/core/
```

Files:

```text
object.h
object.c
config.h
```

Purpose:

### Object

Defines the basic data object used throughout the system.

```c
typedef struct
{
    int id;
    char name[64];
    int data;
} Object;
```

Provides:

```c
object_init()
object_print()
```

Used for:

* Initializing objects
* Printing object information

---

### Config

Stores global configuration settings.

Example:

```c
#define DATA_FILE_PATH "data/users.txt"
```

Used for centralized file path management.

---

# 4. Linked List Module

Directory:

```text
include/list/
src/list/
```

Files:

```text
linked_list.h
linked_list.c
```

---

## 4.1 Data Structures

### Node

```c
typedef struct Node
{
    Object data;
    struct Node* next;
} Node;
```

Represents a linked list node.

---

### LinkedList

```c
typedef struct
{
    Node* head;
} LinkedList;
```

Represents the entire linked list.

---

## 4.2 Functions

### Tail Insertion

```c
list_push_back()
```

Illustration:

```text
head
 ↓
[A]
 ↓
[B]
 ↓
NULL

Insert C

head
 ↓
[A]
 ↓
[B]
 ↓
[C]
 ↓
NULL
```

---

### Head Insertion

```c
list_push_front()
```

---

### Deletion

```c
list_remove()
```

Deletes a node by its ID.

---

### Search

```c
list_find()
```

Traverses the linked list to locate the target node.

Time Complexity:

```text
O(n)
```

---

### Traversal

```c
list_traverse()
```

Outputs all stored data.

---

# 5. Binary Tree Module

Directory:

```text
include/tree/
src/tree/
```

Files:

```text
binary_tree.h
binary_tree.c
```

---

## 5.1 Data Structure

```c
typedef struct TreeNode
{
    Object data;

    struct TreeNode* left;
    struct TreeNode* right;

} TreeNode;
```

---

## 5.2 Binary Search Tree

A BST is constructed based on object IDs:

```text
          50
        /    \
      30      70
     / \      / \
   20   40  60   80
```

Rules:

```text
Left Subtree < Root Node
Right Subtree > Root Node
```

---

## 5.3 Insertion

```c
tree_insert()
```

Recursively finds the correct insertion position.

Complexity:

```text
Average: O(log n)
Worst:   O(n)
```

---

## 5.4 Search

```c
tree_search()
```

Uses BST properties for efficient searching.

Example:

```text
Search for 60

50
 ↓
70
 ↓
60
```

Only three nodes are visited.

---

## 5.5 Inorder Traversal

```c
tree_inorder()
```

Traversal order:

```text
Left Subtree
Root Node
Right Subtree
```

The output is naturally sorted:

```text
20
30
40
50
60
70
80
```

---

# 6. Quick Sort Module

Directory:

```text
include/sort/
src/sort/
```

Files:

```text
quick_sort.h
quick_sort.c
```

---

## Sorting Principle

Select a pivot value.

Example:

```text
5 2 8 1 9
```

Choose:

```text
Pivot = 5
```

Partition:

```text
2 1 |5| 8 9
```

Then recursively sort both partitions.

---

## Time Complexity

Average:

```text
O(n log n)
```

Worst Case:

```text
O(n²)
```

---

# 7. File Management Module

Directory:

```text
include/file/
src/file/
```

Files:

```text
fmgr.h
fmgr.c
```

---

## Save Data

```c
save_data()
```

Writes data in the following format:

```text
1 Alice 100
2 Bob 200
3 Tom 300
```

---

## Load Data

```c
load_data()
```

After reading the file:

```text
Text File
 ↓
Object
 ↓
LinkedList
```

This enables data recovery.

---

# 8. Menu Module

Directory:

```text
include/ui/
src/ui/
```

Files:

```text
menu.h
menu.c
```

---

## Functionality

Responsible for displaying the user interface.

```text
=====================
Data Manage System
=====================

1.Load Data
2.Add Object
3.Delete Object
4.Find Object
5.Show List
6.Show Tree
7.Save Data
0.Exit
```

Only handles display logic.

Does not handle business logic.

Follows the principle of:

```text
Separation of UI and Business Logic
```

---

# 9. Manager Module

Directory:

```text
include/manager/
src/manager/
```

Files:

```text
mgr.h
mgr.c
```

---

## Core Controller

The central coordinator of the system.

```text
Manager
 │
 ├── LinkedList
 ├── BinaryTree
 ├── FileManager
 └── Menu
```

---

## Data Members

```c
typedef struct
{
    LinkedList list;
    BinaryTree tree;
} Manager;
```

---

## Functions

### Initialization

```c
manager_init()
```

---

### Load Data

```c
manager_load_data()
```

Workflow:

```text
File
 ↓
LinkedList
 ↓
BinaryTree
```

---

### Add Data

```c
manager_add_object()
```

Updates both structures simultaneously:

```text
LinkedList
+
BinaryTree
```

---

### Delete Data

```c
manager_delete_object()
```

Removes data from both structures.

---

### Search Data

```c
manager_find_object()
```

Uses the BST to accelerate searching.

---

### Save Data

```c
manager_save_data()
```

Writes data back to the file.

---

### Main Loop

```c
manager_run()
```

Main program workflow.

```text
Display Menu
 ↓
User Input
 ↓
Execute Function
 ↓
Return to Menu
```

Repeats until the user exits.

---

# 10. Program Execution Flow

```text
main()
 │
 ▼
manager_init()
 │
 ▼
manager_run()
 │
 ▼
Display Menu
 │
 ▼
User Selects Function
 │
 ├── Load
 ├── Add
 ├── Delete
 ├── Search
 ├── Traverse
 ├── Sort
 └── Save
 │
 ▼
Exit
 │
 ▼
manager_destroy()
```

---

# 11. Project Features

## Advantages

### Multi-File Project Structure

Follows real-world software development practices.

---

### Combined Data Structures

Linked List handles:

```text
Storage
Insertion
Deletion
```

Binary Tree handles:

```text
Fast Search
Ordered Traversal
```

---

### File Persistence

Supports:

```text
Program Exit
↓
Data Saved

Program Start
↓
Data Restored
```

---

### Modular Decoupling

```text
UI
Manager
LinkedList
BinaryTree
File
```

Each module has clearly defined responsibilities.

---

# 12. To do List

## 12.1 Python module addons

### Built-in functions of Python 3.10

```
abs()
aiter()
all()
anext()
any()
ascii()

bin()
bool()
breakpoint()
bytearray()
bytes()

callable()
chr()
classmethod()
compile()
complex()

delattr()
dict()
dir()
divmod()

enumerate()
eval()
exec()

filter()
float()
format()
frozenset()

getattr()
globals()

hasattr()
hash()
help()
hex()

id()
input()
int()
isinstance()
issubclass()
iter()

len()
list()
locals()

map()
max()
memoryview()
min()

next()

object()
oct()
open()
ord()

pow()
print()
property()

range()
repr()
reversed()
round()

set()
setattr()
slice()
sorted()
staticmethod()
str()
sum()
super()

tuple()
type()

vars()

zip()

__import__()

```

### Built-in modules of Python 3.10

## 12.2 C++ module addons

### 
