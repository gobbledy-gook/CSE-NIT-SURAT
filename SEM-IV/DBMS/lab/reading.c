#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char *s = calloc(1, sizeof(char));
    char t;
    int len;
    while (scanf("%c", &t) == 1)
    {
        if (t == '\n')
            break;
        len = strlen(s);
        s = realloc(s, len + 1);
        *(s + len) = t;
        *(s + len + 1) = '\0';
    }
    printf("%s", s);
}