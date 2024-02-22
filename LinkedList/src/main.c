#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data; // kan gøre generisk med void**
    struct node* next;
} node;

// node constructor
node* create_node(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(node** head, int data) {
    node* newNode = create_node(data);
    newNode->next = *head;
    *head = newNode;
}

void print_list(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    node* head = NULL;
    insert(&head, 5);
    insert(&head, 10);
    insert(&head, 15);

    // Print the linked list
    printf("Linked List: ");
    print_list(head);

    return 0;
}