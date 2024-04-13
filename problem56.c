#include <stdio.h>
#include <stdlib.h>

struct node {
    int id;
    int math_mark;
    int science_mark;
    struct node *link;
};

struct node *append(struct node *ptr, int id, int math, int science) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->id = id;
    temp->math_mark = math;
    temp->science_mark = science;
    temp->link = NULL;
    if (ptr == NULL) {
        ptr = temp;
    } else {
        ptr->link = temp;
    }
    return temp;
}

void print_list(struct node *ptr) {
    while (ptr != NULL) {
        printf("id: %d\tmath_mark: %d\tscience_mark: %d\n", ptr->id, ptr->math_mark, ptr->science_mark);
        ptr = ptr->link;
    }
}

int main() {
    struct node *head = NULL;
    struct node *tail = NULL;
    while(1) {
        int id = 0, math_marks = 0, science_marks = 0;
        printf("enter id:");
        scanf("%d", &id);
        if (id == -1) {
            break;
        }
        printf("enter math_marks:");
        scanf("%d", &math_marks);
        printf("enter science_marks:");
        scanf("%d", &science_marks);
        if (head == NULL) {
            head = append(head, id, math_marks, science_marks);
            tail = head;
        } else {
            tail = append(tail, id, math_marks, science_marks);
        }
    }
    print_list(head);
    return 0;
}
