#include <stdio.h>
#include <stdlib.h>
struct node {
    int id;
    int math_mark;
    int science_mark;
    struct node *link;
};
/// @brief inserts a node before the target node
/// @param ptr 
/// @param id_sc 
/// @param id 
/// @param math 
/// @param science 
struct node*  insert_before(struct node *ptr, int id_sc, int id, int math, int science);
/// @brief inserts a node at the end of list
struct node *append(struct node *ptr, int id, int math, int science);
/// @brief inserts a node after the target node
/// @param ptr 
/// @param id_sc 
/// @param id 
/// @param math 
/// @param science 
void insert_after(struct node *ptr, int id_sc, int id, int math, int science);
/// @brief print linked list start to end
/// @param ptr 
void print_list(struct node *ptr);
/// @brief 
struct node* delete(struct node *ptr, int id_tg);