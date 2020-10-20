#ifndef _LIST_H_
#define _LIST_H_
#include <stdint.h>
#include <stdlib.h>

typedef struct NODE NODE;
typedef struct LIST LIST;
typedef struct LIST
{
	NODE *head;
}LIST;
typedef struct NODE
{
	int32_t val;
	NODE *next;
}NODE;

LIST* new_list(NODE*);
NODE* new_node(int32_t);
void insert_node(LIST*, NODE*, NODE*);
void remove_node(LIST*, NODE*);
int get_node_val(LIST*, int);
void swap_node(LIST*, NODE*, NODE*);
void list_display(LIST*);
void list_node_display(NODE*);
int folyd_cycle_detection(LIST*);

#endif
