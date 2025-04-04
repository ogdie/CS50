#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc > 2)
    {
        printf("Just pass one argument\n");
        return 1;
    }
    char *inFile = argv[1];
    // open input file
    FILE *inptr = fopen(inFile, "r");
    if (inptr == NULL)
    {
        printf("Cannot open the file\n");
        return 1;
    }
    BYTE buffer[512];
    int imgCount = 0;
    char filename[8];
    FILE *outFile = NULL;
    while (true)
    {
        // read a block of memory
        size_t bytesRead = fread(buffer, sizeof(BYTE), BLOCK_SIZE, inptr);
        if (bytesRead == 0 && feof(inptr))
        {
            break;
        }
        // get a jpeg header
        bool containsJpgHeader = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
        if (containsJpgHeader && outFile != NULL)
        {
            fclose(outFile);
            imgCount++;
        }
        if (containsJpgHeader)
        {
            sprintf(filename, "%03i.jpg", imgCount);
            outFile = fopen(filename, "w");
        }
        if (outFile != NULL)
        {
            fwrite(buffer, sizeof(BYTE), bytesRead, outFile);
        }
    }
    fclose(outFile);
    fclose(inptr);
    return 0;
}
