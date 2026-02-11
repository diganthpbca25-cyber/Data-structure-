#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;


void insert_after_key(int key, int data) {
  

    struct Node* curr = head;

    while (curr != NULL && curr->data != key) {
        curr = curr->next;
    }
    if (head == NULL) {
        printf("List is empty.", key);
        return;
    }
   
    if (curr == NULL) {
        printf("Key  not found in the list.", key);
        return;
    }

 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = curr->next;
    curr->next = new_node;
    
}


void traverse() {
    struct Node* curr = head;
    printf("List: ");
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
  
}


void insert_at_beginning(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

int main() {
   
    insert_at_beginning(1);
    insert_at_beginning(2);
    insert_at_beginning(3);

    printf("Original ");
    traverse();

    insert_after_key(3, 2); 
    insert_after_key(3, 1);

    printf("Final ");
    traverse();

    return 0;
}