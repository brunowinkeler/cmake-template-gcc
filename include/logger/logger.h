/**
 * \file logger.h
 * \version 1.0.0
 * \date 29/06/2021
 */

#ifndef LOGGER_H
#define LOGGER_H

/**************************************************************************************************
 * Includes
 **************************************************************************************************/

#include <stdio.h>

// Habilitar LOGGER
#define ENABLE_LOGGER_DEBUG    1
#define ENABLE_LOGGER_INFO     1
#define ENABLE_LOGGER_WARN     1
#define ENABLE_LOGGER_ERROR    1

#define APP_NAME               "GCC-TEMPLATE"

/**************************************************************************************************
 * Preprocessor Macros and Defines
 **************************************************************************************************/

#if ENABLE_LOGGER_DEBUG == 1
#define LOGGER_DEBUG(...)                                           \
    {                                                               \
        get_actual_date_time(logger_date_time);                     \
        printf("[%s][DEBUG][%s]", logger_date_time, APP_NAME);      \
        printf("[%s][L#%d] ", __func__, __LINE__);                  \
        printf(__VA_ARGS__);                                        \
        printf("\n");                                               \
    }
#else
#define LOGGER_DEBUG(...)
#endif

#if ENABLE_LOGGER_INFO == 1
#define LOGGER_INFO(...)                                            \
    {                                                               \
        get_actual_date_time(logger_date_time);                     \
        printf("[%s][INFO][%s] ", logger_date_time, APP_NAME);      \
        printf(__VA_ARGS__);                                        \
        printf("\n");                                               \
    }
#else
#define LOGGER_INFO(...)
#endif

#if ENABLE_LOGGER_WARN == 1
#define LOGGER_WARN(...)                                            \
    {                                                               \
        get_actual_date_time(logger_date_time);                     \
        printf("[%s][WARN][%s]", logger_date_time, APP_NAME);       \
        printf("[%s][L#%d] ", __func__, __LINE__);                  \
        printf(__VA_ARGS__);                                        \
        printf("\n");                                               \
    }
#else
#define LOGGER_WARN(...)
#endif

#if ENABLE_LOGGER_ERROR == 1
#define LOGGER_ERROR(...)                                           \
    {                                                               \
        get_actual_date_time(logger_date_time);                     \
        printf("[%s][ERROR][%s]", logger_date_time, APP_NAME);      \
        printf("[%s][L#%d] ", __func__, __LINE__);                  \
        printf(__VA_ARGS__);                                        \
        printf("\n");                                               \
    }
#else
#define LOGGER_ERROR(...)
#endif

/**************************************************************************************************
 * Typedefs and Variable Definitions
 **************************************************************************************************/

extern char logger_date_time[200];

/**************************************************************************************************
 * Public Function Prototypes
 **************************************************************************************************/

void get_actual_date_time(char *date_time);

#endif // LOGGER_H
