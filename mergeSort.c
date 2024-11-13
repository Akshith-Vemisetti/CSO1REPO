#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* merge(struct Node* first, struct Node* second) {
    if (!first) return second;
    if (!second) return first;
    if (first->data < second->data) {
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    } else {
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

struct Node* split(struct Node* head) {
    struct Node* fast = head;
    struct Node* slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct Node* temp = slow->next;
    slow->next = NULL;
    return temp;
}

void mergeSort(struct Node** head_ref) {
    if (!*head_ref || !(*head_ref)->next) return;
    struct Node* second = split(*head_ref);
    mergeSort(head_ref);
    mergeSort(&second);
    *head_ref = merge(*head_ref, second);
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
    push(&head, 10);
    push(&head, 30);
    push(&head, 15);
    push(&head, 5);
    mergeSort(&head);
    printList(head);
    return 0;
}
