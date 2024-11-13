#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertionSort(struct Node** head_ref) {
    struct Node* sorted = NULL;
    struct Node* current = *head_ref;
    while (current != NULL) {
        struct Node* next = current->next;
        current->prev = current->next = NULL;
        if (!sorted || sorted->data >= current->data) {
            current->next = sorted;
            if (sorted != NULL)
                sorted->prev = current;
            sorted = current;
        } else {
            struct Node* temp = sorted;
            while (temp->next && temp->next->data < current->data)
                temp = temp->next;
            current->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = current;
            temp->next = current;
            current->prev = temp;
        }
        current = next;
    }
    *head_ref = sorted;
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if (*head_ref != NULL)
        (*head_ref)->prev = new_node;
    *head_ref = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    push(&head, 12);
    push(&head, 11);
    push(&head, 13);
    push(&head, 5);
    insertionSort(&head);
    printList(head);
    return 0;
}
