#include "core/object.h"

#include <string.h>

void object_init(
    Object *obj,
    int id,
    const char *name,
    int data)
{
    obj->id = id;

    strcpy(obj->name, name);

    obj->data = data;
}

void object_print(
    const Object *obj)
{
    printf(
        "ID:%d Name:%s Data:%d\n",
        obj->id,
        obj->name,
        obj->data
    );
}
