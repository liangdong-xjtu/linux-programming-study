#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

#define handle_error_en(en, msg) \
    do {errno = en; perror(msg); exit(EXIT_FAILURE);} while(0)

pthread_mutex_t mutex;
int num;

static void * thread_func(void *arg)
{
    int s;
    while(1) {
        do {
            s = pthread_mutex_trylock(&mutex);
            if (s != 0)
                printf("sub thread wait for mutex\n");
            usleep(100*1000); //us
        } while (s);
        printf("sub thread lock\n");
        num--;
        num--;
        printf("num = %d\n", num);
        pthread_mutex_unlock(&mutex);
        printf("sub thread unlock\n");
        usleep(100*1000); //us
    }
}

int main()
{
    pthread_t thread;
    int s;

    s = pthread_mutex_init(&mutex, NULL);
    if (s != 0)
        handle_error_en(s, "pthread_mutex_init failed");

    s = pthread_create(&thread, NULL, &thread_func, NULL);
    if (s != 0)
        handle_error_en(s, "pthread_create failed");

    while(1) {
        do {
            s = pthread_mutex_trylock(&mutex);
            if (s != 0)
                printf("main thread wait for mutex\n");
            usleep(100*1000); //us
        } while (s);
        printf("main thread lock\n");
        num = num + 2;
        printf("num = %d\n", num);
        pthread_mutex_unlock(&mutex);
        printf("main thread unlock\n");
        usleep(100*1000); //us
    }

    return 0;
}
