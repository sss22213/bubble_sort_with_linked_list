#include "bubble_sort.h"


void bubble_sort(LIST* list)
{
	int swap_flag;
	do{
		swap_flag = 0;
		NODE **ptr_inner = &(list->head);
		while( (*ptr_inner)->next != NULL && (*ptr_inner) != NULL)
		{
			if( (*ptr_inner)->val < (*ptr_inner)->next->val )
			{
				swap_node(list, *ptr_inner, (*ptr_inner)->next);
				swap_flag = 1;
			}
			ptr_inner = &(*ptr_inner)->next;
		}
	}while(swap_flag);
}
