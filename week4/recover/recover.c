#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover File\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");

    // Create a buffer for a block of data
    uint8_t buffer[512];
    bool found_jpg = false;
    int jpg_count = 0;
    char jpg_name[8];
    FILE *outptr = NULL;

    // While there's still data left to read from the memory card
    while (fread(buffer, 512, 1, card) == 1)
    {
        // Create JPEGs from the data
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xff) == 0xe0)
        {
            if (found_jpg)
            {
                fclose(outptr);
            }
            else
            {
                found_jpg = true;
            }
            sprintf(jpg_name, "%03d.jpg", jpg_count);
            outptr = fopen(jpg_name, "w");
            if (outptr == NULL)
            {
                fclose(card);
                printf("could not creat %s. \n", jpg_name);
                return 2;
            }
            jpg_count++;
        }
        // write the current block
        if (found_jpg)
        {
            fwrite(buffer, 512, 1, outptr);
        }
    }

    fclose(card);
    if (found_jpg)
    {
        fclose(outptr);
    }

    return 0;
}
