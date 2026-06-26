#include "list/linked_list.h"

#include <stdlib.h>

void list_init(
    LinkedList *list) { list->head = NULL; }

void list_destroy(
    LinkedList *list)
{
    Node *cur = list->head;

    while (cur)
    {
        Node *tmp = cur;

        cur = cur->next;

        free(tmp);
    }

    list->head = NULL;
}

void list_push_back(
    LinkedList *list,
    Object obj)
{
    Node *node = malloc(sizeof(Node));

    node->data = obj;

    node->next = NULL;

    if (!list->head)
    {
        list->head = node;
        return;
    }

    Node *cur = list->head;

    while (cur->next)
        cur = cur->next;

    cur->next = node;
}

void list_push_front(
    LinkedList *list,
    Object obj)
{
    Node *node = malloc(sizeof(Node));

    node->data = obj;

    node->next = list->head;

    list->head = node;
}

Object *list_find(
    LinkedList *list,
    int id)
{
    Node *cur = list->head;

    while (cur)
    {
        if (cur->data.id == id)
            return &cur->data;

        cur = cur->next;
    }

    return NULL;
}

void list_remove(
    LinkedList *list,
    int id)
{
    Node *cur = list->head;

    Node *prev = NULL;

    while (cur)
    {
        if (cur->data.id == id)
        {
            if (prev)
                prev->next = cur->next;
            else
                list->head = cur->next;

            free(cur);

            return;
        }

        prev = cur;

        cur = cur->next;
    }
}

void list_traverse(
    LinkedList *list)
{
    Node *cur = list->head;

    while (cur)
    {
        object_print(
            &cur->data);

        cur = cur->next;
    }
}

Node *list_head(
    LinkedList *list) { return list->head; }
