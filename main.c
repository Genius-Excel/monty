#include "monty.h"
/*
* main - an interpreter for Monty ByteCode files
* @argc: argument count
* @argv: argument variable
* Return: always an integer
*/
stack_t *top = NULL;
int main(int argc, const char *argv[]) 
{
    const char *filename;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");

        exit(EXIT_FAILURE);

    } 
    else 
    {
        filename = argv[1];

        if (access(filename, F_OK) != -1) 
	{
            FILE *fp = fopen(filename, "r");

            if (fp == NULL)
	    {
                fprintf(stderr, "Error: Can't open file %s\n", filename);

                exit(EXIT_FAILURE);
            }

            // SCAN THROUGH FILE AND MAKE FUNCTION CALLS=====
            char str[1024];

            while (fgets(str, sizeof(str), fp) != NULL)
	    {
                // Check if the line is equal to "push"
                if (strcmp(str, "push\n") == 0)
		{
                    // Call push function...
                    printf("Found 'push' in the file\n");
                }
                // Add more conditions for other cases if needed
            }

            fclose(fp);
            printf("File is accessible\n");
        } 
	else
	{
            fprintf(stderr, "Error: Can't open file %s\n", filename);

            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

