#include <stdio.h>
#include <stdlib.h>
#include"ecen/linked_list_lib.h"
int main()
{
struct node *head = NULL;
    head = append(head, 1, 23, 34);
    head = append(head, 2, 23, 34);
    head = append(head, 3, 23, 34);
    head = append(head, 4, 23, 34);
    head = append(head, 5, 23, 34);
    printf("To insert, press 1\nTo print the list, press 2\nTo delete node, press 3\n To exit, press 4\n");

    while (1) {
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
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
            if (option == 1) {
                head=insert_before(head, id_tg, id, math, science);
            } else if (option == 2) {
                insert_after(head, id_tg, id, math, science);
            } else {
                printf("Invalid input\n");
            }
        } else if (choice == 2) {
            print_list(head);
        }
        else if(choice==3){
        char id=0;
        printf("enter node id to delete:");
        scanf("%d",&id);
        head=delete(head,id);
        }else if (choice == 4) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid input\n");
        }
    }

    return 0;
}