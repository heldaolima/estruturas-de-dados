#include <stdio.h>
#include <stdlib.h>

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
    sPerson *second = NULL;

    printPerson(first, "first");
    printPerson(second, "second");

    first = getNewPerson(100);
    second = getNewPerson(24);

    first->next = second;
    
    printPerson(first, "first");
    printPerson(first->next, "first->next");
    printPerson(second, "second");

    free(first);
    free(second);
    
    return 0;
}