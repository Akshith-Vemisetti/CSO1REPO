#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void bubbleSort(struct Node* head) {
    struct Node* current;
    struct Node* last = NULL;
    int swapped;
    if (!head) return;
    do {
        swapped = 0;
        current = head;
        while (current->next != last) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
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
    push(&head, 64);
    push(&head, 34);
    push(&head, 25);
    push(&head, 12);
    bubbleSort(head);
    printList(head);
    return 0;
}
