#include <stdio.h>
#include <stdlib.h>
#include "ecen/linked_list_lib.h"
int length;
/// @brief
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
/// @brief
/// @param ptr
void print_list(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("id: %d\tmath_mark: %d\tscience_mark: %d\n", ptr->id, ptr->math_mark, ptr->science_mark);
        ptr = ptr->link;
    }
}
struct node *push(struct node *ptr, int id, int math, int science)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->id = id;
    temp->math_mark = math;
    temp->science_mark = science;
    temp->link = ptr;
    length++;
    return temp;
}
struct node *pop(struct node *ptr)
{
    if (length != 0)
    {
        struct node *temp = ptr;
        printf("id: %d is popped from stack\n", temp->id);
        ptr = ptr->link;
        temp->link = NULL;
        free(temp);
        return ptr;
    }
    else
    {
        printf("empty stack!!!!\n");
        return NULL;
    }
}
int main()
{
    printf("To push,press 1\n To pop the node on top of stack, press 2\nTo print the stack,press 3\nTo exit,press 4\n");
    struct node *head = NULL;
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
            head = push(head, id, math, science);
        }
        else if (choice == 3)
        {
            print_list(head);
        }
        else if (choice == 2)
        {
            head = pop(head);
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

    return 0;
}