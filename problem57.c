#include <stdio.h>
#include <stdlib.h>

struct node
{
    int id;
    int math_mark;
    int science_mark;
    struct node *link;
};

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
        return ptr;
    }
}

void insert_after(struct node *ptr, int id_sc, int id, int math, int science)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    while (ptr->id != id_sc)
    {
        ptr = ptr->link;
        if (ptr == NULL)
        {
            printf("Node with id %d not found.\n", id_sc);
            free(new_node);
            return;
        }
    }
    new_node->id = id;
    new_node->math_mark = math;
    new_node->science_mark = science;
    new_node->link = ptr->link;
    ptr->link = new_node;
}

struct node *insert_before(struct node *ptr, int id_sc, int id, int math, int science)
{    struct node *temp=ptr;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (ptr->id == id_sc)
    {
        new_node->id = id;
        new_node->math_mark = math;
        new_node->science_mark = science;
        new_node->link = ptr;
        return new_node;
    }
    struct node *prev = ptr;
    ptr = ptr->link;
    while (ptr != NULL)
    {
        if (ptr->id == id_sc)
        {
            new_node->id = id;
            new_node->math_mark = math;
            new_node->science_mark = science;
            new_node->link = ptr;
            prev->link = new_node;
            return temp;
        }
        prev = ptr;
        ptr = ptr->link;
    }
    printf("Node with id %d not found.\n", id_sc);
    free(new_node);
}

int main()
{
    struct node *head = NULL;
    head = append(head, 1, 23, 34);
    head = append(head, 2, 23, 34);
    head = append(head, 3, 23, 34);
    head = append(head, 4, 23, 34);
    head = append(head, 5, 23, 34);
    printf("To insert, press 1\nTo print the list, press 2\nTo exit, press 3\n");

    while (1)
    {
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int id_tg, id, math, science, option;
            printf("Enter the id of target followed by id to insert and its data\n");
            printf("Enter the target id: ");
            scanf("%d", &id_tg);
            printf("Enter the id to insert: ");
            scanf("%d", &id);
            printf("Enter the math_mark: ");
            scanf("%d", &math);
            printf("Enter the science_mark: ");
            scanf("%d", &science);
            printf("To insert before id, press 1\nTo insert after id, press 2: ");
            scanf("%d", &option);
            if (option == 1)
            {
               head= insert_before(head, id_tg, id, math, science);
            }
            else if (option == 2)
            {
                insert_after(head, id_tg, id, math, science);
            }
            else
            {
                printf("Invalid input\n");
            }
        }
        else if (choice == 2)
        {
            print_list(head);
        }
        else if (choice == 3)
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
