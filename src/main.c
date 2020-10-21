#include "list.h"
#include <stdio.h>
#include "bubble_sort.h"
int main()
{
	NODE *node_head = new_node(0);
	LIST *new_list_list = new_list(node_head);
	NODE *node_1 = new_node(5);
	NODE *node_2 = new_node(-19);
	NODE *node_3 = new_node(8);
	NODE *node_4 = new_node(4);
	insert_node(new_list_list, node_head, node_1);
	insert_node(new_list_list, node_1, node_2);
	insert_node(new_list_list, node_2, node_3);
	insert_node(new_list_list, node_3, node_4);
	list_display(new_list_list);
	swap_node(new_list_list, node_head, node_1);
	list_display(new_list_list);
	swap_node(new_list_list, node_1, node_head);
	list_display(new_list_list);
	swap_node(new_list_list, node_1, node_2);
	list_display(new_list_list);
	swap_node(new_list_list, node_2, node_1);
	list_display(new_list_list);
	return 0;
}
