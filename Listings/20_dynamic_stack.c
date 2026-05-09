#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;    /* dynamisch allokierter Buffer */
    int size;     /* aktuelle Anzahl Elemente */
    int capacity; /* allokierte Groesse in Elementen */
} intStack;

int stackInit(intStack *stack, const int initialCapacity) {
    stack->data = malloc(initialCapacity * sizeof(int));
    if (stack->data == NULL) {
        return -1;
    }
    stack->size = 0;
    stack->capacity = initialCapacity;
    return 0;
}

int stackPush(intStack *stack, const int value) {
    if (stack->size == stack->capacity) {
        int newCapacity = stack->capacity * 2;
        int *newData = realloc(stack->data, newCapacity * sizeof(int));

        if (newData == NULL) {
            return -1;
        }

        stack->data = newData;
        stack->capacity = newCapacity;
    }

    stack->data[stack->size] = value;
    stack->size++;
    return 0;
}

int stackPop(intStack *stack, int *value) {
    if (stack->size == 0) {
        return -1;
    }

    stack->size--;
    *value = stack->data[stack->size];
    return 0;
}

void stackFree(intStack *stack) {
    free(stack->data);
    stack->data = NULL;
    stack->size = 0;
    stack->capacity = 0;
}

int main(void) {
    intStack stack;
    stackInit(&stack, 2);

    stackPush(&stack, 10);
    stackPush(&stack, 20);
    stackPush(&stack, 30);
    stackPush(&stack, 40);

    printf("Stapel hat %d Elemente, Kapazität: %d\n", stack.size, stack.capacity);

    int value;
    while (stackPop(&stack, &value) == 0) {
        printf("Pop: %d\n", value);
    }

    stackFree(&stack);
}
