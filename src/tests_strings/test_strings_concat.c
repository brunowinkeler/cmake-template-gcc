#include "tests.h"
#include "logger/logger.h"

#include <string.h>

static void concat_list(const char **list_words, size_t list_size, char *output_phrase);

void test_strings_concat()
{
    const char *list_words_custom[] = {"Hello, ", "my ", "name ", "is ", "Bruno!"};
    size_t list_size = sizeof(list_words_custom) / sizeof(list_words_custom[0]);

    LOGGER_INFO("list_size: %lu", list_size);

    char result_phrase[200] = {0};
    concat_list(list_words_custom, list_size, result_phrase);

    LOGGER_INFO("Result Phrase: %s", result_phrase);

    char hello[50] = {0};
    strcpy(hello, "Hello ");
    strcat(hello, "World!");
    LOGGER_INFO("hello: %s", hello);

    const char *hello_world = hello;
    LOGGER_INFO("hello_world: %s", hello_world);
}

static void concat_list(const char **list_words, size_t list_size, char *output_phrase)
{
    strcpy(output_phrase, list_words[0]);

    for (size_t i = 1; i < list_size; i++)
    {
        strcat(output_phrase, list_words[i]);
    }
}
