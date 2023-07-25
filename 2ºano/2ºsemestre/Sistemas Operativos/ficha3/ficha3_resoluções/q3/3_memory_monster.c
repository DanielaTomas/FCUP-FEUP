#include <stdio.h>
#include <stdlib.h>

#define ERROR_OPEN_FILE -1
#define ERROR_READ_FILE -2
#define ERROR_MEM_ALLOC -3
#define OK 0

/**
 * @brief Cats a file text to stdout
 *
 * In this approach, we read the entire file into a buffer and then print it
 * to stdout.
 * (1) determine the size of the file, i.e., how many characters it has.
 * (2) allocate the memory for the file's text/context with malloc
 * (3) read the entire file and print it
 *
 * Note: For large files it consumes a lot of memory (unnecessarily).
 * Reading entire files is not efficient anyway.
 *
 * @param filename The filename
 *
 * @retval ERROR_OPEN_FILE - Failed to open the file
 * @retval ERROR_READ_FILE - Error while reading the file
 * @retval OK - Success
 */
int cat_file(const char *filename)
{
    // Open the file in read mode
    FILE *f = fopen(filename, "r");
    if (f == NULL)
        return ERROR_OPEN_FILE;

    // Determine the file size (bytes)
    // the portable way is using 'fseek' to move the file pointer to the end of
    // the file, then using 'ftell' to get the position for the last position,
    // then setting the pointer to the beggining of the file
    // NOTE: There are better APIs for UNIX (stat, fstat) and Windows
    fseek(f, 0, SEEK_END);
    long filesize = ftell(f);
    fseek(f, 0, SEEK_SET);

    // Allocate the buffer to read the entire file
    // One extra byte is needed for the '\0'
    char *buf = (char *)malloc((filesize + 1) * sizeof(char));
    if (buf == NULL)
        return ERROR_MEM_ALLOC;

    // Read the entire file
    fread(buf, sizeof(char), filesize, f);

    // Check for errors
    if (ferror(f))
    {
        free(buf);
        return ERROR_READ_FILE;
    }

    // Set the '\0' and print the file content
    buf[filesize] = '\0';
    printf("%s", buf);

    // close the file and release memory
    fclose(f);
    free(buf);

    return OK;
}

int main(int argc, char const *argv[])
{
    for (size_t i = 1; i < argc; i++)
    {
        const char *filename = argv[i];
        printf("***** BEGIN '%s' *****\n", filename);
        int ret = cat_file(filename);
        if (ret == ERROR_OPEN_FILE)
            printf("ERROR: Failed to open file");
        else if (ret == ERROR_READ_FILE)
            printf("ERROR: Error while reading file");
        printf("\n***** END '%s' *****\n", filename);
    }

    return 0;
}
