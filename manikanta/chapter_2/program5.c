#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct arguments {

    char* name;
    int age ;
    char* blood_group;
};

void *say_greeting(void* data)
{
    printf("Name: %s", ((struct arguments*)data)->name);
    printf("Age %d\n", ((struct arguments*)data)->age);
    printf("Blood group: %s\n", ((struct arguments*)data)->blood_group);
    return NULL;
}

int main()
{
    struct arguments *person = (struct arguments*)malloc(sizeof(struct arguments));
    printf("This is a simple data collection apllication\n");
    char blood_group[5],name[50];
    int age;
    printf("Enter the name of the person: ");
    fgets(name,50,stdin);
    printf("Enter the age of ther person: ");
    scanf("%d",&age);
    printf("Enter the person's blood group: ");
    scanf("%s",blood_group);

    person -> name = name;
    person -> age = age;
    person -> blood_group = blood_group;

    pthread_t thread;
    pthread_create(&thread, NULL,say_greeting, (void*)person);
    pthread_join(thread,NULL);
    return 0;
}
