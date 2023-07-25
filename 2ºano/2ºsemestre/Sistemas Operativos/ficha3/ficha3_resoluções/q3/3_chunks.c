#include <stdio.h>

#define ERROR_OPEN_FILE -1
#define ERROR_READ_FILE -2
#define OK 0

/**
 * @brief Cats a file text to stdout
 *
 * Reads the file in chunks of a given size and prints the chunk immediately,
 * avoiding memory pressure. As the file is read in chunks, we need to request
 * chunks one or more times. To determine if we reached the end of the file
 * you can use 'feof'.
 *
 * @param filename The filename
 *
 * @retval ERROR_OPEN_FILE - Failed to open the file
 * @retval ERROR_READ_FILE - Error while reading the file
 * @retval OK - Success
 */
int cat_file(const char *filename)
{
#define BUF_SIZE 256
#define CHUNK_SIZE (BUF_SIZE - 1)

    // auxiliar buffer for storing chunks of text from the file
    char buf[BUF_SIZE];

    // open the file in read mode
    FILE *f = fopen(filename, "r");
    if (f == NULL)
        return ERROR_OPEN_FILE;

    // while end of file is not reached
    while (!feof(f))
    {
        // auxiliar for storing the number of items/characters read by fread
        int count;

        // read another chunk of text
        count = fread(buf, sizeof(char), CHUNK_SIZE, f);

        // to check for errors, must use 'ferror'
        if (ferror(f))
            return ERROR_READ_FILE;

        // As chunks are substrings of the file, they will not have the null
        // terminator '\0', unless it is the last chunk
        // It is necessary to add it explicitly before using printf
        // Note that 'count' has the return of 'fread' which is the number of
        // elements/characters read, and we use it to insert the '\0' in the
        // right position. The 'count' is always expected to be CHUNK_SIZE
        // except for the last chunk. We could use that to determine we reached
        // the end of file, but 'feof' is more elegant :)
        buf[count] = '\0';

        // print the chunk to stdout
        printf("%s", buf);
    }

    // close the file
    fclose(f);

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
