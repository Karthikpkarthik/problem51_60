#include <stdio.h>
#include <stdlib.h>
#include "ecen/linked_list_lib.h"
int length;
void print_list(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("id: %d\tmath_mark: %d\tscience_mark: %d\n", ptr->id, ptr->math_mark, ptr->science_mark);
        ptr = ptr->link;
    }
}
struct node *append(struct node *ptr, int id, int math, int science)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->id = id;
    temp->math_mark = math;
    temp->science_mark = science;
    temp->link = NULL;
    if (ptr == NULL)
    {
        length++;
        return temp;
    }
    else
    {
        struct node *current = ptr;
        while (current->link != NULL)
        {
            current = current->link;
        }
        current->link = temp;
        length++;
        return ptr;
    }
}
struct node *add(struct node *ptr, int id, int math, int science)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->id = id;
    temp->math_mark = math;
    temp->science_mark = science;
    temp->link = ptr;
    length++;
    return temp;
}
/// @brief
/// @param ptr
struct node *dequeue(struct node *ptr)
{
    if (length == 1)
    {
        printf("id %d is dequeued\n", ptr->id);
        length--;
        return NULL;
    }
    else if (length == 0)
    {
        printf("trying to remove from empty queue\n");
        return NULL;
    }
    else
    {
        struct node *temp = ptr;
        struct node *prev = ptr;
        ptr = ptr->link;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
            prev = prev->link;
        }
        printf("id %d is dequeued\n", ptr->id);

        prev->link = NULL;
        return temp;
    }
}
int main()
{
    struct node *head = NULL;
    printf("To add,press 1\n To dequeue the node, press 2\nTo print the queue,press 3\nTo exit,press 4\n");

    while (1)
    {
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int id, math, science;
            printf("Enter the id to insert: ");
            scanf("%d", &id);
            printf("Enter the math_mark: ");
            scanf("%d", &math);
            printf("Enter the science_mark: ");
            scanf("%d", &science);
            head = add(head, id, math, science);
        }
        else if (choice == 3)
        {
            print_list(head);
        }
        else if (choice == 2)
        {
            head = dequeue(head);
        }
        else if (choice == 4)
        {
            printf("Exiting...\n");
            break;
        }
        else
        {
            printf("Invalid input\n");
        }
    }
}