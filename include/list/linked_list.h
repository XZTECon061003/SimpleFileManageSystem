#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "core/object.h"

typedef struct Node
{
    Object data;

    struct Node *next;
} Node;

typedef struct
{
    Node *head;
} LinkedList;

void list_init(
    LinkedList *list);

void list_destroy(
    LinkedList *list);

void list_push_back(
    LinkedList *list,
    Object obj);

void list_push_front(
    LinkedList *list,
    Object obj);

void list_remove(
    LinkedList *list,
    int id);

Object *list_find(
    LinkedList *list,
    int id);

void list_traverse(
    LinkedList *list);

Node *list_head(
    LinkedList *list);

#endif
