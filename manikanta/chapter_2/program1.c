#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *custom_thread_function()
{
    for(int i=0;i<15;i++){
        printf("I am custom thread function created by programmer\n");
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t thread;
    int status;

    status = pthread_create(&thread, NULL, custom_thread_function, NULL);

    if(!status){
        printf("Custom created succeffully.\n");
    }
    else {
        printf("Unable to create the custom thread.\n");
        return 0;
    }

    for(int i=0;i<15;i++){
        printf("I am the process thread created by compiler by default.\n");
        sleep(1);
    }

    return 0;
}