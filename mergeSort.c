#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* sortedMerge(struct Node* a, struct Node* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->data <= b->data) {
        a->next = sortedMerge(a->next, b);
        return a;
    } else {
        b->next = sortedMerge(a, b->next);
        return b;
    }
}

void splitList(struct Node* source, struct Node** front, struct Node** back) {
    struct Node* fast = source->next;
    struct Node* slow = source;
    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

void mergeSort(struct Node** head_ref) {
    struct Node* head = *head_ref;
    struct Node* a;
    struct Node* b;
    if (!head || !head->next) return;
    splitList(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *head_ref = sortedMerge(a, b);
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
    push(&head, 15);
    push(&head, 10);
    push(&head, 5);
    push(&head, 20);
    mergeSort(&head);
    printList(head);
    return 0;
}
