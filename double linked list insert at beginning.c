#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

void insert_at_beginning(int data)
{
    struct Node *new_node;

    new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = head;

    if (head != NULL)
    {
        head->prev = new_node;
    }

    head = new_node;
}

void traverse_forward()
{
    struct Node *curr = head;

    printf("Forward Traversal:\n");

    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

void traverse_backward()
{
    struct Node *curr = head;

    if (curr == NULL)
        return;

    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    printf("\nBackward Traversal:\n");

    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->prev;
    }
}

int main()
{
    insert_at_beginning(3);
    insert_at_beginning(2);
    insert_at_beginning(4);
    insert_at_beginning(7);

    traverse_forward();
    traverse_backward();

    return 0;
}