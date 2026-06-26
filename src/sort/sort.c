#include "sort/sort.h"

static void swap(
    Object *a,
    Object *b)
{
    Object t = *a;
    *a = *b;
    *b = t;
}

void quick_sort(
    Object arr[],
    int left,
    int right)
{
    if (left >= right)
        return;

    int i = left;
    int j = right;

    int pivot = arr[left].id;

    while (i < j)
    {
        while (i < j &&
               arr[j].id >= pivot)
            j--;

        while (i < j &&
               arr[i].id <= pivot)
            i++;

        if (i < j)
            swap(
                &arr[i],
                &arr[j]);
    }

    swap(
        &arr[left],
        &arr[i]);

    quick_sort(
        arr,
        left,
        i - 1);

    quick_sort(
        arr,
        i + 1,
        right);
}
