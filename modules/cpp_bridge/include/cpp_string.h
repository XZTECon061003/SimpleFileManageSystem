#ifndef CPP_STRING
#define CPP_STRING

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// typedef char* string;
typedef struct
{
    char *str;
    size_t len;
    size_t capacity;
} String;

void String_Init(String *str);

void String_Clear(String *str);


#endif