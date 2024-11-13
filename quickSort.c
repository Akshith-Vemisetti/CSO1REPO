#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct Node* partitionLast(struct Node* start, struct Node* end) {
    int pivot = end->data;
    struct Node* p = start;
    struct Node* q = start;
    while (q != end) {
        if (q->data < pivot) {
            swap(&(p->data), &(q->data));
            p = p->next;
        }
        q = q->next;
    }
    swap(&(p->data), &(end->data));
    return p;
}

void quickSortRec(struct Node* start, struct Node* end) {
    if (start != end && start != end->next) {
        struct Node* pivot = partitionLast(start, end);
        quickSortRec(start, pivot);
        quickSortRec(pivot->next, end);
    }
}

void quickSort(struct Node* head) {
    struct Node* end = head;
    while (end->next)
        end = end->next;
    quickSortRec(head, end);
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
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
    push(&head, 10);
    push(&head, 7);
    push(&head, 8);
    push(&head, 5);
    quickSort(head);
    printList(head);
    return 0;
}
