#include "list.h"
#include <stdio.h>
#include <string.h>
LIST* new_list(NODE* head)
{
	if(head == NULL)
		return NULL;
	LIST* new_list_impl = (LIST*)calloc(1, sizeof(LIST));
	if(new_list_impl == NULL || head == NULL)return NULL;
	new_list_impl->head = head;
	return new_list_impl;
}

NODE* new_node(int32_t val)
{
	NODE* new_node_impl = (NODE*)calloc(1, sizeof(NODE));
	if(new_node_impl == NULL)return NULL;
	new_node_impl->val = val;
	return new_node_impl;
}

void insert_node(LIST* list, NODE* target, NODE *new_node)
{
	if(list==NULL || target==NULL)
		return;
	NODE **ptr_list = &list->head;
	while( *ptr_list != target)
	{
		if(*ptr_list == NULL)return;
		ptr_list = &(*ptr_list)->next;
	}
	new_node->next = (*ptr_list)->next;
	(*ptr_list)->next = new_node;
}

void remove_node(LIST* list, NODE* target)
{
	NODE **ptr_list = &list->head;
	while( *ptr_list != target)
	{
		if(*ptr_list == NULL)return;
		ptr_list = &(*ptr_list)->next;
	}
	*ptr_list = target->next;
}

void swap_node(LIST* list, NODE* node1, NODE* node2)
{
	// NULL
	if( node1 == node2 || node1 == NULL || node2 == NULL)
		return;
	// avoid loop
	if( node2->next == node1 || node2 == list->head)
	{
		NODE *tmp = node1;
		node1 = node2;
		node2 = tmp;
	}
	NODE **ptr_target1 = &list->head;
	NODE **ptr_target2 = &node1;
	while(*ptr_target1 != node1)
	{
		if(*ptr_target1 == NULL)
			return;
		ptr_target1 = &(*ptr_target1)->next;
	}
	while(*ptr_target2 != node2)
	{
		if(*ptr_target2 == NULL)
			return;
		ptr_target2 = &(*ptr_target2)->next;
	}
	// swap
	*ptr_target1 = node2;
	NODE *tmp = node2->next;
	node2->next = node1;
	node1->next = tmp;
}

void list_display(LIST *list)
{
	NODE *ptr_node = list->head;
	while( ptr_node != NULL )
	{
		printf("%d->", ptr_node->val);
		ptr_node = ptr_node->next;
	}
	printf("NULL\n");
}

void list_node_display(NODE *head)
{
	NODE *ptr_node = head;
	while( ptr_node != NULL)
	{
		printf("%d->", ptr_node->val);
		ptr_node = ptr_node->next;
	}
	printf("\n");
}

int folyd_cycle_detection(LIST* list)
{   
    if(list == NULL)
        return 1;
    NODE **ptr_tortoise = &(list->head);
    NODE **ptr_rabbit = &(list->head);
    while(*ptr_tortoise !=NULL && *ptr_rabbit!=NULL && (*ptr_rabbit)->next!=NULL)
    {
        if(*ptr_tortoise == *ptr_rabbit && *ptr_tortoise != list->head)
            return 1;
        ptr_tortoise = &(*ptr_tortoise)->next;
        ptr_rabbit = &(*ptr_rabbit)->next->next;
    }
    return 0;
}

int get_node_val(LIST *list, int idx)
{
	NODE **ptr_list = &list->head;
	while(idx--)
	{
		*ptr_list = (*ptr_list)->next;
	}
	return (*ptr_list)->val;
}
