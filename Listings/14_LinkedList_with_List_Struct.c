#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} List;

void initList(List *list) {
    list->head = NULL;
    list->size = 0;
}

void addNode(List *list, int data) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Fehler bei der Speicherallokation\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    list->size++;
}

void removeNodesWithValue(List *list, int value) {
    Node *current = list->head;
    Node *prev = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            Node *temp = current;
            current = current->next;
            free(temp);
            list->size--;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void printList(const List *list) {
    Node *current = list->head;
    int i = 1;
    while (current != NULL) {
        printf("Element %d: data = %d\n", i, current->data);
        current = current->next;
        i++;
    }
}

void freeList(List *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    list->size = 0;
}

int main(void) {
    List myList;
    initList(&myList);

    addNode(&myList, 1);
    addNode(&myList, 2);
    addNode(&myList, 3);
    addNode(&myList, 2);

    printf("Original Liste:\n");
    printList(&myList);

    removeNodesWithValue(&myList, 2);
    printf("Liste nach dem Entfernen aller 2er:\n");
    printList(&myList);

    freeList(&myList);
}
