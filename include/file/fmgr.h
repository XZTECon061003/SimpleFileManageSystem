#ifndef FMGR_H
#define FMGR_H

#include "list/linked_list.h"

void save_data(
    LinkedList *list,
    const char *path);

void load_data(
    LinkedList *list,
    const char *path);

#endif
