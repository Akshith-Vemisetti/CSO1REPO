#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void selectionSort(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        struct Node* min = temp;
        struct Node* r = temp->next;
        while (r) {
            if (r->data < min->data)
                min = r;
            r = r->next;
        }
        int x = temp->data;
        temp->data = min->data;
        min->data = x;
        temp = temp->next;
    }
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
    push(&head, 64);
    push(&head, 25);
    push(&head, 12);
    push(&head, 22);
    selectionSort(head);
    printList(head);
    return 0;
}
