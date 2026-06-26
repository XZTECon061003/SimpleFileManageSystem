# SFMSC 文件管理系统设计说明

## 一、项目概述

### 1.1 项目名称

SFMSC ( Simple File Manager System - C Language version ) —— 基于链表与二叉树的数据管理系统

### 1.2 项目目标

本项目使用纯 C 语言实现一个简单的数据管理系统，实现：

* 数据的增删查改（CRUD）
* 链表存储数据
* 二叉搜索树快速查找
* 快速排序
* 文件读写持久化
* 菜单式交互界面
* 多文件工程组织
* CMake 构建管理

系统中的每条数据由一个 Object 结构体表示：

```c
typedef struct
{
    int id;
    char name[64];
    int data;
} Object;
```

其中：

| 字段   | 含义   |
| ---- | ---- |
| id   | 唯一编号 |
| name | 名称   |
| data | 数据值  |

---

# 二、项目整体结构

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

整体采用：

```text
分层设计
模块化开发
头文件与源文件分离
```

设计思想如下：

```text
UI层
 ↓
Manager层
 ↓
数据结构层
 ├─ LinkedList
 ├─ BinaryTree
 └─ QuickSort
 ↓
File层
 ↓
磁盘文件
```

---

# 三、模块设计

## 3.1 Core 模块

目录：

```text
include/core/
src/core/
```

文件：

```text
object.h
object.c
config.h
```

作用：

### Object

定义系统中的基本数据对象。

```c
typedef struct
{
    int id;
    char name[64];
    int data;
} Object;
```

提供：

```c
object_init()
object_print()
```

用于：

* 初始化对象
* 打印对象信息

---

### Config

保存全局配置。

例如：

```c
#define DATA_FILE_PATH "data/users.txt"
```

用于统一管理文件路径。

---

# 四、链表模块

目录：

```text
include/list/
src/list/
```

文件：

```text
linked_list.h
linked_list.c
```

---

## 4.1 数据结构

### Node

```c
typedef struct Node
{
    Object data;
    struct Node* next;
} Node;
```

表示链表节点。

---

### LinkedList

```c
typedef struct
{
    Node* head;
} LinkedList;
```

表示整个链表。

---

## 4.2 功能

### 尾插

```c
list_push_back()
```

示意图：

```text
head
 ↓

[A]
 ↓

[B]
 ↓

NULL

插入C

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

### 头插

```c
list_push_front()
```

---

### 删除

```c
list_remove()
```

按 id 删除节点。

---

### 查找

```c
list_find()
```

遍历链表寻找目标节点。

时间复杂度：

```text
O(n)
```

---

### 遍历

```c
list_traverse()
```

输出所有数据。

---

# 五、二叉树模块

目录：

```text
include/tree/
src/tree/
```

文件：

```text
binary_tree.h
binary_tree.c
```

---

## 5.1 数据结构

```c
typedef struct TreeNode
{
    Object data;

    struct TreeNode* left;
    struct TreeNode* right;

} TreeNode;
```

---

## 5.2 二叉搜索树

根据 id 构建 BST：

```text
          50
        /    \
      30      70
     / \      / \
   20 40    60 80
```

规则：

```text
左子树 < 根节点
右子树 > 根节点
```

---

## 5.3 插入

```c
tree_insert()
```

递归寻找位置。

复杂度：

```text
平均 O(log n)
最坏 O(n)
```

---

## 5.4 查找

```c
tree_search()
```

利用 BST 特性快速查找。

例如：

```text
查找60

50
 ↓
70
 ↓
60
```

只访问 3 个节点。

---

## 5.5 中序遍历

```c
tree_inorder()
```

访问顺序：

```text
左子树
根节点
右子树
```

输出结果天然有序：

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

# 六、快速排序模块

目录：

```text
include/sort/
src/sort/
```

文件：

```text
quick_sort.h
quick_sort.c
```

---

## 排序思想

选择一个基准值 Pivot。

例如：

```text
5 2 8 1 9
```

选：

```text
Pivot = 5
```

划分：

```text
2 1 |5| 8 9
```

递归排序左右两侧。

---

## 时间复杂度

平均：

```text
O(n log n)
```

最坏：

```text
O(n²)
```

---

# 七、文件管理模块

目录：

```text
include/file/
src/file/
```

文件：

```text
fmgr.h
fmgr.c
```

---

## 保存数据

```c
save_data()
```

写入：

```text
1 Alice 100
2 Bob 200
3 Tom 300
```

---

## 加载数据

```c
load_data()
```

读取文件后：

```text
文本文件
 ↓
Object
 ↓
LinkedList
```

实现数据恢复。

---

# 八、菜单模块

目录：

```text
include/ui/
src/ui/
```

文件：

```text
menu.h
menu.c
```

---

## 功能

负责用户界面显示。

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

只负责显示。

不负责业务逻辑。

符合：

```text
UI与逻辑分离
```

原则。

---

# 九、Manager模块

目录：

```text
include/manager/
src/manager/
```

文件：

```text
mgr.h
mgr.c
```

---

## 核心控制器

系统总调度中心。

```text
Manager
 │
 ├── LinkedList
 ├── BinaryTree
 ├── FileManager
 └── Menu
```

---

## 数据成员

```c
typedef struct
{
    LinkedList list;
    BinaryTree tree;
} Manager;
```

---

## 功能

### 初始化

```c
manager_init()
```

---

### 加载数据

```c
manager_load_data()
```

流程：

```text
文件
 ↓
链表
 ↓
二叉树
```

---

### 添加数据

```c
manager_add_object()
```

同步更新：

```text
链表
+
二叉树
```

---

### 删除数据

```c
manager_delete_object()
```

同步删除。

---

### 查找数据

```c
manager_find_object()
```

利用 BST 加速查询。

---

### 保存数据

```c
manager_save_data()
```

写回文件。

---

### 主循环

```c
manager_run()
```

程序入口逻辑。

```text
显示菜单
 ↓
用户输入
 ↓
执行功能
 ↓
返回菜单
```

循环直到退出。

---

# 十、程序运行流程

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
显示菜单
 │
 ▼
用户选择功能
 │
 ├── 加载
 ├── 添加
 ├── 删除
 ├── 查询
 ├── 遍历
 ├── 排序
 └── 保存
 │
 ▼
退出
 │
 ▼
manager_destroy()
```

---

# 十一、项目特点

## 优点

### 多文件工程

符合实际开发规范。

---

### 数据结构结合

链表负责：

```text
存储
插入
删除
```

二叉树负责：

```text
快速查找
有序遍历
```

---

### 文件持久化

实现：

```text
程序关闭
↓
数据保存

程序启动
↓
数据恢复
```

---

### 模块解耦

```text
UI
Manager
LinkedList
BinaryTree
File
```

各模块职责明确。

---

# 12. 待完成事项

## 12.1 适用于C23标准的Python模块接口

## 12.2 适用于C23标准的C++模块接口


