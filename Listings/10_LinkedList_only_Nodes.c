#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Fehler bei der Speicherallokation\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}


void removeNodesWithValue(Node **head, int value) {
    Node *current = *head, *prev = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                *head = current->next;
            }
            Node *temp = current;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
}


void printList(Node *head) {
    Node *current = head;
    int i = 1;
    while (current != NULL) {
        printf("Element %d: data = %d\n", i, current->data);
        current = current->next;
        i++;
    }
}


void freeList(Node **head) {
    Node *current = *head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}


int main(void) {
    Node *head = NULL;

    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 2);

    printf("Original Liste:\n");
    printList(head);

    removeNodesWithValue(&head, 2);
    printf("Liste nach dem Entfernen aller 2en:\n");
    printList(head);

    freeList(&head);
}
