#include <stdio.h>
#include <stdlib.h>
struct CLL
{
    int data;
    struct CLL *next;
};
typedef struct CLL node;

void printList(node *head)
{
    if (head == NULL)
        printf("List is empty!");
    else
    {
        int counter = 1;
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
            counter++;
        }
        while (counter)
        {
            printf("%d\t", head->data);
            head = head->next;
            counter--;
        }
    }
}

node *addFront(node *head, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    if (head == NULL)
    {
        temp->next = temp;
        head = temp;
    }
    else
    {
        temp->next = head;
        node *last = head;
        while (last->next != head)
            last = last->next;
        last->next = temp;
        head = temp;
    }
    return head;
}

node *add(node *head)
{
    node *iter = head;
    while (iter->next != head)
        iter = iter->next;
    node *temp = (node *)malloc(sizeof(node));
    temp->data = head->data + iter->data;
    temp->next = head;
    iter->next = temp;
    return head;
}
int main()
{
    node *head = NULL;
    head = addFront(head, 3);
    head = addFront(head, 9);
    head = addFront(head, 1);
    head = addFront(head, 5);
    head = addFront(head, 8);
    printList(head);
    printf("\n after add function\n");
    head = add(head);
    printList(head);
    return 0;
}
