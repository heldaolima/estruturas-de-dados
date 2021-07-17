#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct sPerson{
    int age;
    struct sPerson *next;
}sPerson;

void printPerson(sPerson *person, char *comment)
{
    if (person == NULL) printf("%s is NULL\n", comment);
    else
    {
        printf("%s: age: %d adress: %p next: %p\n", comment, person->age, person, person->next);
    }
}

void printList(sPerson *list)
{
    sPerson *t;
    t = list;
    if (t == NULL) printf("List is empty\n");
    else{
        while (t)
        {
            printPerson(t, "t");
            t = t->next;
        }
    }

}

void CleanUp(sPerson *list)
{
    sPerson *next;
    while (list)
    {
        next = list->next;
        printf("Cleaning %d\n", list->age);
        free(list);
        list = next;
    }
}

sPerson* getNewPerson(const int age)
{
    sPerson *NewPerson = NULL;
    NewPerson = malloc(sizeof(sPerson));
    if (NewPerson != NULL)
    {
        NewPerson->age = age;
        NewPerson->next = NULL;
        
        printf("created new person at %p\n", NewPerson);

    }
    else {
        printf("Returned NULL\n");
    }
    
    return NewPerson;
}

int main()
{
    sPerson *first = NULL;
    sPerson *added = NULL;
    
    char com[64];
    int age;

    while (1)
    {
        printf("enter a command or value: ");
        fgets(com, 64, stdin);
        if (strcmp("q\n", com) == 0)
        {
            printf("Quitting...\n");
            break;
        }
        else if (strcmp("print\n", com) == 0)
        {
            printf("Printing..\n");
            printList(first);
        }
        else if(sscanf(com, "%d", &age) != 0)
        {
            printf("Adding %d\n", age);
            if (first == NULL) //cabeça vazia
            {
                first = getNewPerson(age);
                if (first != NULL)
                {
                    added = first;
                }
            }
            else{
                added->next = getNewPerson(age);
                if (added->next != NULL)
                {
                    added = added->next;
                }
            }

        }

    }

    CleanUp(&first);
    //entendi filho da outa
    return 0;
}