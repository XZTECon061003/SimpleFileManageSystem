#ifndef MANAGER_MGR_H
#define MANAGER_MGR_H

#include "list/linked_list.h"
#include "tree/btree.h"

typedef struct
{
    LinkedList list;

    BinaryTree tree;
} Manager;

void manager_init(
    Manager *mgr);

void manager_destroy(
    Manager *mgr);

void manager_run(
    Manager *mgr);

void manager_add_object(
    Manager *mgr);

void manager_delete_object(
    Manager *mgr);

void manager_find_object(
    Manager *mgr);

void manager_save_data(
    Manager *mgr);

void manager_load_data(
    Manager *mgr);

#endif
