#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

// чтобы избежать deadlock, можно задать чёткий порядок для lock и unclock

void* thread1_func(void* arg) {
    pthread_mutex_lock(&mutex1);
    printf("Thread 1: Locked mutex 1\n");

    // Искусственная задержка для создания условия deadlock
    sleep(1);

    printf("Thread 1 trying to lock mutex2\n");
    pthread_mutex_lock(&mutex2);
    printf("Thread 1: Locked mutex 2\n");

    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);

    return NULL;
}

void* thread2_func(void* arg) {
    pthread_mutex_lock(&mutex2);
    printf("Thread 2: Locked mutex 2\n");

    sleep(1);

    printf("Thread 2 trying to lock mutex1\n");
    pthread_mutex_lock(&mutex1);
    printf("Thread 2: Locked mutex 1\n");

    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);

    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, thread1_func, NULL);
    pthread_create(&thread2, NULL, thread2_func, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
