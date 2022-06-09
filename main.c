#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void *routine(void *arg)
{
    int index = *(int *)arg;
    printf("-->%d", tab[index]);
    free(arg);
    return NULL;
}

int main()
{
    pthread_t th[10];
    int i = 0;
    while (i < 10)
    {
        int *a = malloc(sizeof(int));
        *a = i;
        pthread_create(&th[i], NULL, &routine, a);
        i++;
    }
    i = 0;
    while (i < 10)
    {
        pthread_join(th[i], NULL);
        i++;
    }

    return 0;
}