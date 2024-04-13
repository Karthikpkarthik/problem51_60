#include"linked_list_lib.h"
void print_list(struct node *ptr);
struct node *append(struct node *ptr, int id, int math, int science);
/// @brief 
/// @param ptr 
void print_list(struct node *ptr) {
    while (ptr != NULL) {
        printf("id: %d\tmath_mark: %d\tscience_mark: %d\n", ptr->id, ptr->math_mark, ptr->science_mark);
        ptr = ptr->link;
    }
}
/// @brief 
struct node *append(struct node *ptr, int id, int math, int science) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->id = id;
    temp->math_mark = math;
    temp->science_mark = science;
    temp->link = NULL;
    if (ptr == NULL) {
        return temp;
    } else {
        struct node *current = ptr;
        while (current->link != NULL) {
            current = current->link;
        }
        current->link = temp;
        return ptr;
    }
}
/// @brief 
/// @param ptr 
/// @param id_sc 
/// @param id 
/// @param math 
/// @param science 
void insert_after(struct node *ptr, int id_sc, int id, int math, int science) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    while (ptr->id != id_sc) {
        ptr = ptr->link;
        if (ptr == NULL) {
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
/// @brief 
/// @param ptr 
/// @param id_sc 
/// @param id 
/// @param math 
/// @param science 
struct node*  insert_before(struct node *ptr, int id_sc, int id, int math, int science) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (ptr->id == id_sc) {
        new_node->id = id;
        new_node->math_mark = math;
        new_node->science_mark = science;
        new_node->link = ptr;

    }
    struct node *prev = ptr;
    ptr = ptr->link;
    while (ptr != NULL) {
        if (ptr->id == id_sc) {
            new_node->id = id;
            new_node->math_mark = math;
            new_node->science_mark = science;
            new_node->link = ptr;
            prev->link = new_node;
            return;
        }
        prev = ptr;
        ptr = ptr->link;
    }
    printf("Node with id %d not found.\n", id_sc);
    free(new_node);
}

struct node* delete(struct node *ptr, int id_tg) {
    struct node *prev = ptr;
    struct node *temp= ptr;
    int temp_len=0;
    ptr = ptr->link;
    while (prev != NULL) {
        printf("%d  %d  %d\n",prev->id,ptr->id,temp_len);
        temp_len++;
         if(temp_len==1&&prev->id == id_tg)
            {
                prev->link=NULL;
                return ptr;
            }
          else if(ptr->id == id_tg) {
            if (ptr->link==NULL)
            {
                prev->link=NULL;
                free(ptr);
                return temp;
            }
            else if(ptr->link!=NULL){
            printf("%d %d %d\n",ptr->id,prev->id,temp_len);
            prev->link = ptr->link;
            ptr->link = NULL;
            free(ptr);
            return temp;
            }
            }
        prev=prev->link;
        ptr=ptr->link;
        }

    printf("Node with id %d not found.\n", id_tg);
    }