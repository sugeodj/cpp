#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    char *input = argv[1];
    FILE *reader = fopen(input, "r");

    if (reader == NULL)
    {
        printf("Unable to open file\n");
        return 1;
    }

    int counter = 0;
    FILE *writer = NULL;
    char filename[8];
    uint8_t buffer[512];

    while (fread(buffer, 512, 1, reader))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (writer != 0 )
            {
                fclose(writer);
            }

            sprintf(filename, "%03i.jpg", counter);
            writer = fopen(filename, "w");
            counter++;
        }

        if (writer != 0)
        {
            fwrite(buffer, 512, 1, writer);
        }
    }

    fclose(reader);
    fclose(writer);
    return 0;
}