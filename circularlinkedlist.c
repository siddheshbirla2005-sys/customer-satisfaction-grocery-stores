#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at the end of circular linked list
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;  // Point to itself
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

// Traverse and print circular linked list
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Delete a node by value
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) return;

    struct Node *curr = *head, *prev = NULL;

    // Case: deleting head node
    if (curr->data == key) {
        // If only one node
        if (curr->next == *head) {
            free(curr);
            *head = NULL;
            return;
        }

        // Find last node
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }

        last->next = curr->next;
        *head = curr->next;
        free(curr);
        return;
    }

    // Search for node to delete
    do {
        prev = curr;
        curr = curr->next;
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            return;
        }
    } while (curr != *head);
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    printf("Circular Linked List: ");
    traverse(head);

    printf("Deleting 20...\n");
    deleteNode(&head, 20);
    traverse(head);

    printf("Deleting 10...\n");
    deleteNode(&head, 10);
    traverse(head);

    return 0;
}
