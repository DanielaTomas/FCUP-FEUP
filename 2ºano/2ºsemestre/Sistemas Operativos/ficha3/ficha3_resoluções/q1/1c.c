#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <substring> <string>\n");
        return EXIT_FAILURE;
    }
    
    // copy argument strings
    char *s = malloc((strlen(argv[1]) + 1) * sizeof(char));
    strcpy(s, argv[1]);

    char *str = malloc((strlen(argv[2]) + 1) * sizeof(char));
    strcpy(str, argv[2]);

    // aux is auxiliar pointer that moves forward through 'str' as substrings are found
    char *aux = str;
    // count number of ocurrences
    unsigned int occur = 0;

    printf("DEBUG: aux = '%s'\n", aux);
    
    // while strstr returns diff. of NULL, a new substring was found
    while ((aux = strstr(aux, s)) != NULL) {
        occur++;
        aux += strlen(s);
        printf("DEBUG: aux = '%s'\n", aux);
    }

    printf("Num of ocurrences: %u\n", occur);

    free(s);
    free(str);

    return 0;
}
