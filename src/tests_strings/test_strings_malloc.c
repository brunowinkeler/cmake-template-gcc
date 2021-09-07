#include "tests.h"
#include "logger/logger.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

char **add_string(char **array, const char *string);

void test_strings_malloc()
{
    char **lines = NULL;

    printf("Printing lines...\n");

    lines = add_string(lines, "Hello World!");
    lines = add_string(lines, "My name is Bruno.");
    lines = add_string(lines, "I am an Electrical Engineer.");
    lines = add_string(lines, "I am an Electrical Engineer.");

    int cont = 0;
    while (lines[cont] != NULL)
    {
        cont++; //First, count the elements and find NULL element
    }
    printf("SIZE OF lines: %d\n", cont);

    for (size_t i = 0; i < cont; i++)
    {
        printf("%s\n", lines[i]);
    }
}

char **add_string(char **array, const char *string)
{
    if (!array)
    {
        array = (char **)malloc(sizeof(char **) * 1);
    }

    int i = 0;
    while (array[i] != NULL)
    {
        i++; //First, count the elements and find NULL element
    }

    LOGGER_DEBUG("size: %d", i);
    LOGGER_DEBUG("string received: %s", string);

    array[i] = malloc(strlen(string) + 1); //or strdup(string);
    strcpy(array[i], string);

    char **temp;
    temp = realloc(array, (i + 1 + 1) * sizeof(char *));

    if (temp == NULL)
    {
        perror("realloc at add_string");
    }
    else
    {
        array = temp;
        array[i + 1] = NULL;
    }

    return array;
}
