#include <stdio.h>

int cp(const char *src_filename, const char *dest_filename)
{
    // open both files
    FILE *fsrc = fopen(src_filename, "r"), *fdest = fopen(dest_filename, "w+");

    // auxiliar buffer to read the file in chuncks of 'BUF_SIZE' characters
    #define BUF_SIZE 256
    char buf[BUF_SIZE];

    size_t count; // store number of characters read by 'fread'
    while ((count = fread(buf, sizeof(char), BUF_SIZE - 1, fsrc)))
    {
        // write to dest file
        fwrite(buf, sizeof(char), count, fdest);
        
        // if number of characters read is inferior to BUF_SIZE - 1, then
        // error or EOF (end of file) was reached
        if (count < BUF_SIZE - 1)
            break;
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    cp(argv[1], argv[2]);
    return 0;
}
