#include "tests.h"
#include "logger/logger.h"

#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

static pthread_mutex_t mutex_sleep = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond_var_sleep = PTHREAD_COND_INITIALIZER;

static void sleep_cond_timedwait(unsigned int time_in_seconds);

static void *func1(void *params);
static void *func2(void *params);

// ====================================================

void test_pthread_cond_timed()
{
    LOGGER_INFO("INICIANDO O PROGRAMA...");

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, func1, NULL);
    pthread_create(&thread2, NULL, func2, NULL);

    while (1)
    {
        sleep(30);
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
}

// ====================================================

static void *func1(void *params)
{
    int cont = 0;
    while (1)
    {
        sleep_cond_timedwait(5);
        LOGGER_INFO("\tContador = %d", cont++);
    }
}

static void *func2(void *params)
{
    sleep(12);
    LOGGER_INFO("CHAMADA DO SIGNAL...");

    pthread_cond_broadcast(&cond_var_sleep);

    while (1)
    {
        sleep(30);
    }
}

static void sleep_cond_timedwait(unsigned int time_in_seconds)
{
    struct timespec ts;
    struct timeval now;
    int rt = 0;

    clock_gettime(CLOCK_REALTIME, &ts);
    ts.tv_sec += time_in_seconds;

    pthread_mutex_lock(&mutex_sleep);
    pthread_cond_timedwait(&cond_var_sleep, &mutex_sleep, &ts);
    LOGGER_INFO("\tReturn: %d || APOS O SLEEP TIMEDWAIT...", rt);
    pthread_mutex_unlock(&mutex_sleep);

    LOGGER_INFO("\tFINALIZADO O SLEEP...");
}
