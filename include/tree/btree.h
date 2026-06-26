#ifndef TREE_BINARY_TREE_H
#define TREE_BINARY_TREE_H

#include "core/object.h"

typedef struct TreeNode
{
    Object data;

    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct
{
    TreeNode *root;
} BinaryTree;

void tree_init(BinaryTree *tree);

void tree_insert(
    BinaryTree *tree,
    Object obj);

Object *tree_search(
    BinaryTree *tree,
    int id);

void tree_inorder(
    BinaryTree *tree);

void tree_destroy(
    BinaryTree *tree);

#endif
