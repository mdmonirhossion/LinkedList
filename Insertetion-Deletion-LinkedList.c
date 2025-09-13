#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to create linked list from array
struct Node *createLinkedList(int arr[], int size) {
    struct Node *head = NULL, *temp = NULL, *current = NULL;
    for (int i = 0; i < size; i++) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            current = head;
        } else {
            current->next = temp;
            current = current->next;
        }
    }
    return head;
}

// Function to print linked list
void printLinkedList(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Insert a new node with value val after node with value key
void insertAfter(struct Node *head, int key, int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    while (head != NULL && head->data != key) {
        head = head->next;
    }
    if (head == NULL) {
        printf("Key %d not found! Insertion failed.\n", key);
        free(newNode);
        return;
    }
    newNode->next = head->next;
    head->next = newNode;
}

// Delete a node by value
struct Node* deleteNode(struct Node *head, int val) {
    struct Node *temp = head, *prev = NULL;
    // If head itself holds the value
    if (temp != NULL && temp->data == val) {
        head = temp->next;
        free(temp);
        return head;
    }
    // Search for the node
    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }
    // If not found
    if (temp == NULL) return head;

    prev->next = temp->next;
    free(temp);
    return head;
}

int main() {
    // ---------- SIMPLE ----------
    printf("=== SIMPLE TASK ===\n");
    int arr1[] = {10, 20, 30};
    struct Node *head1 = createLinkedList(arr1, 3);

    printf("Before Insertion: ");
    printLinkedList(head1);

    insertAfter(head1, 10, 15); // Insert 15 between 10 and 20

    printf("After Insertion: ");
    printLinkedList(head1);

    // ---------- MEDIUM ----------
    printf("\n=== MEDIUM TASK ===\n");
    int arr2[] = {5, 12, 18, 25};
    struct Node *head2 = createLinkedList(arr2, 4);

    printf("Original List: ");
    printLinkedList(head2);

    // Insert 20 after 18
    insertAfter(head2, 18, 20);
    printf("After Inserting 20 after 18: ");
    printLinkedList(head2);

    // Delete node with value 12
    head2 = deleteNode(head2, 12);
    printf("After Deleting 12: ");
    printLinkedList(head2);

    return 0;
}

