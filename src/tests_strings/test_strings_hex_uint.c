#include "tests.h"
#include "logger/logger.h"

#include <stdlib.h>

static unsigned int string_to_unsigned_int(char *word);
static unsigned int hex_string_to_unsigned_int(char *word);

void test_strings_hex_uint()
{
    char *lac = "xxxx";
    char *cell_id = "abcdefg";
    char *mcc = "123";
    char *mnc = "05";

    unsigned int u_lac = hex_string_to_unsigned_int(lac);
    unsigned int u_cell_id = hex_string_to_unsigned_int(cell_id);
    unsigned int u_mcc = string_to_unsigned_int(mcc);
    unsigned int u_mnc = string_to_unsigned_int(mnc);

    LOGGER_INFO("LAC HEX: %s || LAC UNSIGNED INT: %u", lac, u_lac);
    LOGGER_INFO("CELL ID HEX: %s || CELL ID UNSIGNED INT: %u", cell_id, u_cell_id);
    LOGGER_INFO("MCC STRING: %s || MCC UNSIGNED INT: %u", mcc, u_mcc);
    LOGGER_INFO("MNC STRING: %s || MNC UNSIGNED INT: %u", mnc, u_mnc);
}

static unsigned int string_to_unsigned_int(char *word)
{
    return strtoul(word, 0, 10);
}

static unsigned int hex_string_to_unsigned_int(char *word)
{
    unsigned int output;
    sscanf(word, "%x", &output);
    return output;
}
