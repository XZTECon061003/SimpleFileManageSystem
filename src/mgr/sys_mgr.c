#include "mgr/sys_mgr.h"

#include "core/config.h"
#include "core/object.h"
#include "file/fmgr.h"
#include "ui/menu.h"

#include <stdio.h>

#include "tree/btree.h"

void manager_init(
    Manager *mgr)
{
    list_init(
        &mgr->list);

    tree_init(
        &mgr->tree);
}

void manager_destroy(
    Manager *mgr)
{
    list_destroy(
        &mgr->list);

    tree_destroy(
        &mgr->tree);
}

void manager_add_object(
    Manager *mgr)
{
    int id;
    int data;

    char name[64];

    printf("Input ID: ");
    scanf("%d", &id);

    printf("Input Name: ");
    scanf("%63s", name);

    printf("Input Data: ");
    scanf("%d", &data);

    Object obj;

    object_init(
        &obj,
        id,
        name,
        data);

    list_push_back(
        &mgr->list,
        obj);

    tree_insert(
        &mgr->tree,
        obj);

    printf("Add success.\n");
}

void manager_delete_object(
    Manager *mgr)
{
    int id;

    printf("Input ID: ");
    scanf("%d", &id);

    list_remove(
        &mgr->list,
        id);

    /* 重建二叉树 */

    tree_destroy(
        &mgr->tree);

    tree_init(
        &mgr->tree);

    Node *cur =
            mgr->list.head;

    while (cur)
    {
        tree_insert(
            &mgr->tree,
            cur->data);

        cur = cur->next;
    }

    printf(
        "Delete success.\n");
}

void manager_find_object(
    Manager *mgr)
{
    int id;

    printf("Input ID: ");

    scanf("%d", &id);

    Object *obj =
            tree_search(
                &mgr->tree,
                id);

    if (obj) { object_print(obj); } else
    {
        printf(
            "Object not found.\n");
    }
}

void manager_save_data(
    Manager *mgr)
{
    save_data(
        &mgr->list,
        DATA_FILE_PATH);

    printf(
        "Data saved.\n");
}

void manager_load_data(
    Manager *mgr)
{
    load_data(
        &mgr->list,
        DATA_FILE_PATH);

    Node *cur =
            list_head(
                &mgr->list);

    while (cur)
    {
        tree_insert(
            &mgr->tree,
            cur->data);

        cur = cur->next;
    }

    printf(
        "Data loaded.\n");
}

void manager_run(
    Manager *mgr)
{
    int choice;

    while (1)
    {
        menu_show();

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                manager_load_data(mgr);
                break;

            case 2:
                manager_add_object(mgr);
                break;

            case 3:
                manager_delete_object(mgr);
                break;

            case 4:
                manager_find_object(mgr);
                break;

            case 5:
                list_traverse(
                    &mgr->list);
                break;

            case 6:
                tree_inorder(
                    &mgr->tree);
                break;

            case 7:
                manager_save_data(mgr);
                break;

            case 0:
                return;

            default:
                printf(
                    "Invalid choice.\n");
        }
    }
}
