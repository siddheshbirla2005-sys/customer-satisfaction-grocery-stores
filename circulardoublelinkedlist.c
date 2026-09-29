#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = newNode; // circular link
    return newNode;
}

// Insert at the end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* last = (*head)->prev;

    newNode->next = *head;
    (*head)->prev = newNode;
    newNode->prev = last;
    last->next = newNode;
}

// Delete a node
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) return;

    struct Node* current = *head, *prevNode = NULL;

    // Search for node with given key
    while (current->data != key) {
        if (current->next == *head) {
            printf("Node %d not found.\n", key);
            return;
        }
        current = current->next;
    }

    // If only one node
    if (current->next == current && current->prev == current) {
        *head = NULL;
        free(current);
        return;
    }

    // Adjust links
    current->prev->next = current->next;
    current->next->prev = current->prev;

    // If deleting head
    if (current == *head) {
        *head = current->next;
    }

    free(current);
}

// Traverse forward
void traverseForward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Forward Traversal: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Traverse backward
void traverseBackward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* last = head->prev;
    struct Node* temp = last;
    printf("Backward Traversal: ");
    do {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != last);
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    traverseForward(head);
    traverseBackward(head);

    deleteNode(&head, 20);
    traverseForward(head);

    return 0;
}
