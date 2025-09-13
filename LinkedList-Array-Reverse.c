#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createLinkedList(int arr[], int size);
struct Node *reverseLinkedList(struct Node*head);

int main() {
    int a[] = {5, 10, 15};
    struct Node *head = NULL;
    head = createLinkedList(a, 3);
    struct Node *newHead = head;

    printf("Original Linked List: ");
    while (newHead != NULL) {
        printf("%d -> ", newHead->data);
        newHead = newHead->next;
    }
    printf("NULL \n");

    // Reverse a Linked List and update the head pointer
    head = reverseLinkedList(head);

    printf("Reversed Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL \n");

    return 0;
}

// Function to reverse a linked list and return the new head
struct Node *reverseLinkedList(struct Node *head) {
    struct Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        // Store the next node
        next = current->next;
        // reverse the link
        current->next = prev;
        // Propagate
        prev = current;
        current = next;
    }
    head = prev; // Update head to the new head (prev)
    return head; // Return the new head
}

// Function to create a linked list from an array
struct Node *createLinkedList(int arr[], int size) {
    struct Node *head = NULL, *temp = NULL, *current = NULL;
    int i;
    for (i = 0; i < size; i++) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        if (temp == NULL) {
            printf("Memory allocation failed!\n");
            return NULL;
        }
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
