#ifndef CORE_OBJECT_H
#define CORE_OBJECT_H

#include <stdio.h>

typedef struct
{
    int id;

    char name[64];

    int data;
} Object;

void object_init(
    Object *obj,
    int id,
    const char *name,
    int data);

void object_print(
    const Object *obj);

#endif
