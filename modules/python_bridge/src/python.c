#include <_pystring/pystr.h>

// 创建字符串
String string_new(const char *init)
{
    String s;
    if (init)
    {
        s.len = strlen(init);
        s.capacity = s.len + 1;
        s.data = malloc(s.capacity);
        memcpy(s.data, init, s.len + 1);
    } else
    {
        s.len = 0;
        s.capacity = 1;
        s.data = malloc(1);
        s.data[0] = '\0';
    }
    return s;
}

// 释放字符串
void string_free(String *s)
{
    if (s->data) free(s->data);
    s->data = NULL;
    s->len = 0;
    s->capacity = 0;
}

// 获取长度
size_t string_len(const String *s) { return s->len; }

// 转大写
void string_upper(String *s) { for (size_t i = 0; i < s->len; i++) s->data[i] = toupper((unsigned char) s->data[i]); }

// 转小写
void string_lower(String *s) { for (size_t i = 0; i < s->len; i++) s->data[i] = tolower((unsigned char) s->data[i]); }

// input()
String input(const char *prompt)
{
    if (prompt) printf("%s", prompt);
    char buffer[1024];
    if (!fgets(buffer, sizeof(buffer), stdin)) { return string_new(""); }
    // 去掉换行符
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') buffer[len - 1] = '\0';
    return string_new(buffer);
}

// print()
#include <stdarg.h>

void print(int n_args, String args[], const char *sep, const char *end)
{
    if (!sep) sep = " ";
    if (!end) end = "\n";
    for (int i = 0; i < n_args; i++)
    {
        printf("%s", args[i].data);
        if (i != n_args - 1) printf("%s", sep);
    }
    printf("%s", end);
}