#include <stdio.h>

typedef struct {
    char firstName[50];
    char lastName[50];
    int age;
} Person;

Person *findYoungestPerson(Person *persons[], int size) {
    if (size <= 0) {
        return NULL;
    }

    Person *youngest = persons[0];
    for (int i = 0; i < size; i++) {
        if (persons[i]->age < youngest->age) {
            youngest = persons[i];
        }
    }

    return youngest;
}

int main(void) {
    Person person1 = {"Max", "Mustermann", 30};
    Person person2 = {"Anna", "Schmidt", 25};
    Person person3 = {"John", "Doe", 40};

    Person *persons[] = {&person1, &person2, &person3};

    int size = sizeof(persons) / sizeof(persons[0]);

    Person *youngest = findYoungestPerson(persons, size);

    printf("Name: %s %s, Age: %d\n", youngest->firstName, youngest->lastName, youngest->age);

    return 0;
}
