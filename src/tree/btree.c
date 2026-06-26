#include "tree/btree.h"

#include <stdlib.h>

static TreeNode *create_node(
    Object obj)
{
    TreeNode *node =
            malloc(sizeof(TreeNode));

    node->data = obj;

    node->left = NULL;
    node->right = NULL;

    return node;
}

void tree_init(
    BinaryTree *tree) { tree->root = NULL; }

static TreeNode *insert_node(
    TreeNode *root,
    Object obj)
{
    if (root == NULL)
        return create_node(obj);

    if (obj.id < root->data.id)
    {
        root->left =
                insert_node(
                    root->left,
                    obj);
    } else if (obj.id > root->data.id)
    {
        root->right =
                insert_node(
                    root->right,
                    obj);
    }

    return root;
}

void tree_insert(
    BinaryTree *tree,
    Object obj)
{
    tree->root =
            insert_node(
                tree->root,
                obj);
}

static Object *search_node(
    TreeNode *root,
    int id)
{
    if (!root)
        return NULL;

    if (root->data.id == id)
        return &root->data;

    if (id < root->data.id)
    {
        return search_node(
            root->left,
            id);
    }

    return search_node(
        root->right,
        id);
}

Object *tree_search(
    BinaryTree *tree,
    int id)
{
    return search_node(
        tree->root,
        id);
}

static void inorder_node(
    TreeNode *root)
{
    if (!root)
        return;

    inorder_node(root->left);

    object_print(
        &root->data);

    inorder_node(root->right);
}

void tree_inorder(
    BinaryTree *tree)
{
    inorder_node(
        tree->root);
}

static void destroy_node(
    TreeNode *root)
{
    if (!root)
        return;

    destroy_node(
        root->left);

    destroy_node(
        root->right);

    free(root);
}

void tree_destroy(
    BinaryTree *tree)
{
    destroy_node(
        tree->root);

    tree->root = NULL;
}
