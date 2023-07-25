#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum
{
    UPPER_CASE,
    LOWER_CASE,
    ORIGINAL
} output_mode_t;

/**
 * @brief Transforms a string to lower case, upper case,
 * or leave unchaged
 * 
 * @param str The target string
 * @param mode The operation mode
 */
void transform_str(char *str, output_mode_t mode)
{
    // leave string unchanged
    if (mode == ORIGINAL)
        return;

    for (size_t i = 0; i < strlen(str); i++)
    {
        if (mode == UPPER_CASE)
            str[i] = toupper(str[i]);
        else
            str[i] = tolower(str[i]);
    }
}

int cat_file(const char *fname, output_mode_t mode)
{
    // auxiliar buffer to read the file in chuncks of 'BUF_SIZE' characters
    #define BUF_SIZE 256
    char buf[BUF_SIZE];

    // try open file in read mode
    FILE *f = fopen(fname, "r");
    if (f == NULL)
        return -1;

    while (!feof(f))
    {   
        // store number of characters read by 'fread'
        // notice the 'BUF_SIZE - 1', leaving one empty byte for the string terminator
        size_t count = fread(buf, sizeof(char), BUF_SIZE - 1, f);
        // add string terminator
        buf[count] = '\0';
        // transform the string, if needed
        transform_str(buf, mode);
        // output the string
        printf("%s", buf);
    }

    printf("\n");

    // close file
    fclose(f);

    return 0;
}

void print_usage(const char *exe) {
    printf("Usage: %s <filename> [-u|-l]\n", exe);
}

int main(int argc, char const *argv[])
{

    if (argc < 2 || argc > 3) {
        print_usage(argv[0]);
        return -1;
    }

    // default operating mode is not changing the string
    output_mode_t m = ORIGINAL;
    
    // handle third optional argument
    if (argc == 3) {
        if (strcmp("-u", argv[2]) == 0) {
            m = UPPER_CASE;
        }
        else if(strcmp("-l", argv[2]) == 0) {
            m = LOWER_CASE;
        }
        else {
            print_usage(argv[0]);
            return -1;
        }
    }

    // cat the file
    cat_file(argv[1], m);

    return 0;
}
