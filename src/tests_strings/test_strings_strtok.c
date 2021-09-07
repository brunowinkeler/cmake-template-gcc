#include "tests.h"
#include "logger/logger.h"

#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

#define LIMITE_HOR_FONT_H2 18
#define LIMITE_HOR_FONT_H3 26
#define LIMITE_HOR_FONT_H4 35

static char **wrap_line(const char *message, char **output_lines, const uint32_t limit_size_per_phrase);
static char **add_string(char **array, const char *string);

void test_strings_strtok()
{
    const char *test_message1 = "Hello World, my name is Bruno Winkeler. I am from Brazil and I am an Embedded Software Engineer.";
    const char *test_message2 = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    const char *test_message3 = "Hello World, my name is Bruno Winkeler. I am from Brazil and I am an Embedded Software Engineer. Would you like to add me on your network?";

    char **output = NULL;

    output = wrap_line(test_message3, output, LIMITE_HOR_FONT_H4);

    int cont = 0;
    while (output[cont] != NULL)
    {
        cont++; //First, count the elements and find NULL element
    }

    printf("SIZE OF lines: %d\n", cont);

    for (int i = 0; i < cont; i++)
    {
        printf("output[%d]: %s\n", i, output[i]);
    }

    free(output);
}

static char **wrap_line(const char *message, char **output_lines, const uint32_t limit_size_per_phrase)
{
    const size_t message_size = strlen(message);
    const char *DELIMITER = " ";

    int diff_ptrs = 0;
    char *result = (char *)message;
    char *prev_result = result;
    char *begin_phrase = result;
    const char *begin_message = message;

    int diff_res_begin = result - begin_message;

    while (diff_res_begin < message_size)
    {
        char *phrase;

        result = strstr(prev_result, DELIMITER);

        if (result != NULL)
        {
            diff_ptrs = result - begin_phrase;

            if (diff_ptrs >= limit_size_per_phrase)
            {
                diff_ptrs = prev_result - begin_phrase;

                phrase = (char *)malloc((sizeof(char) * diff_ptrs) + 1);
                strncpy(phrase, begin_phrase, diff_ptrs);

                begin_phrase = prev_result;
            }

            prev_result = result + 1;
        }
        else
        {
            size_t remain_size = strlen((const char *)begin_phrase);

            if (remain_size >= limit_size_per_phrase)
            {
                diff_ptrs = prev_result - begin_phrase;

                phrase = (char *)malloc((sizeof(char) * diff_ptrs) + 1);
                strncpy(phrase, begin_phrase, sizeof(phrase));
                result = prev_result;
            }
            else
            {
                phrase = (char *)malloc((sizeof(char) * remain_size) + 1);
                strncpy(phrase, begin_phrase, sizeof(phrase));
                result = (char *)begin_message + message_size;
            }
        }

        output_lines = add_string(output_lines, (const char *)phrase);
        free(phrase);

        diff_res_begin = result - begin_message;
    }

    return output_lines;
}

static char **add_string(char **array, const char *string)
{
    if (!array)
    {
        array = (char **)malloc(sizeof(char **) * 1);
    }

    int i = 0;
    while (array[i] != NULL)
    {
        i++;
    }

    array[i] = malloc(strlen(string) + 1);
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
