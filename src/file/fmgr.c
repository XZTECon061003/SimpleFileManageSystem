#include "file/fmgr.h"

#include <stdio.h>

void save_data(
    LinkedList *list,
    const char *path)
{
    FILE *fp = fopen(
        path,
        "w");

    if (!fp)
        return;

    Node *cur = list->head;

    while (cur)
    {
        fprintf(
            fp,
            "%d %s %d\n",
            cur->data.id,
            cur->data.name,
            cur->data.data);

        cur = cur->next;
    }

    fclose(fp);
}

void load_data(
    LinkedList *list,
    const char *path)
{
    FILE *fp = fopen(
        path,
        "r");

    if (!fp)
        return;

    Object obj;

    while (
        fscanf(
            fp,
            "%d %63s %d",
            &obj.id,
            obj.name,
            &obj.data)
        == 3)
    {
        list_push_back(
            list,
            obj);
    }

    fclose(fp);
}
