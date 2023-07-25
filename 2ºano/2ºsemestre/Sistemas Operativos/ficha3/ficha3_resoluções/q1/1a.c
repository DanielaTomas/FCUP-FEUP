#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    // 
    // printf("locale: %s\n", setlocale(LC_ALL, "pt_PT.iso88591"));
    
    if (argc != 2)
    {
        printf("Usage: %s <string>\n", argv[0]);
        return -1;
    }

    char *str = argv[1];

    printf("DEBUG: string length = %d\n", strlen(str));

    for (size_t i = 0; i < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }

    printf("%s\n", str);
    
    return 0;
}
