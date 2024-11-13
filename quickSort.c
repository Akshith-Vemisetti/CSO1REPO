#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* lastNode(struct Node* head) {
    while (head && head->next)
        head = head->next;
    return head;
}

struct Node* partition(struct Node* low, struct Node* high) {
    int pivot = high->data;
    struct Node* i = low->prev;
    for (struct Node* j = low; j != high; j = j->next) {
        if (j->data <= pivot) {
            i = (i == NULL) ? low : i->next;
            int temp = i->data;
            i->data = j->data;
            j->data = temp;
        }
    }
    i = (i == NULL) ? low : i->next;
    int temp = i->data;
    i->data = high->data;
    high->data = temp;
    return i;
}

void quickSort(struct Node* low, struct Node* high) {
    if (high && low != high && low != high->next) {
        struct Node* p = partition(low, high);
        quickSort(low, p->prev);
        quickSort(p->next, high);
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
    push(&head, 5);
    push(&head, 20);
    push(&head, 4);
    push(&head, 3);
    struct Node* last = lastNode(head);
    quickSort(head, last);
    printList(head);
    return 0;
}
