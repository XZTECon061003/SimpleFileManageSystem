//
// Created by 20593 on 2026/6/6.
//

#ifndef PYSTR_H
#define PYSTR_H

#include <_stdC.h>

typedef struct
{
    char *data;
    size_t len;
    size_t capacity;
} String;

/* 字符数组
/* 当前长度
/* 分配容量
*/

/* 构造和析构 */
String string_new(const char *init);

void string_free(String *s);

/* Python风格函数 */
size_t string_len(const String *s);

void string_upper(String *s);

void string_lower(String *s);

/* I/O函数 */
String input(const char *prompt);

void print(int n_args, String args[], const char *sep, const char *end);

#endif //PYSTR_H