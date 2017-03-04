#include <stdbool.h>
#include <limits.h>
#include "node.h"

/*
ERROR CODES
-1 = Value not found
 0 = Success
 1 = No memory to complete the operation
 2 = Empty list
 3 = Position out of range
*/

/*
	Allocates a new node into memory
	@return Node*
*/
Node* newNode ()
{
	return (Node*) malloc(sizeof(Node));
}

/*
	Creates a pointer to a new Node
	@return Node*
*/
Node* newLinkedList ()
{
	Node *list = newNode();
	list->value = INT_MIN;
	list->next = NULL;
	return list;
}

/*
	Checks if a list is empty
	@arguments (Node *list)
	@return bool
*/
bool empty (Node *list)
{
	if (list->value == INT_MIN && list->next == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
	Counts the number of items in the list
	@arguments (Node *list)
	@return int
*/
int count (Node *list)
{
	int count = 1;

	if (empty(list))
	{
		count = 0;
	}

	while (list->next != NULL)
	{
		count++;
		list = list->next;
	}

	return count;
}

/*
	Checks if a position is available in the list
	@arguments (int position, int listCount)
	@return bool
*/
bool positionAvailableAt (int position, int listCount)
{
	if (position >= 0 && position <= listCount)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
	Push a node at the start of the linked list
	@arguments (int value, Node *list)
	@return int
*/
int prepend (int value, Node *list)
{
	if (empty(list))
	{
		list->value = value;
		list->next = NULL;
		return 0;
	}

	Node *temp = newNode();
	if (temp == NULL)
	{
		return 1;
	}

	temp->value = list->value;
	temp->next = list->next;

	list->value = value;
	list->next = temp;

	return 0;
}

/*
	Push a node at the end of the linked list
	@arguments (int value, Node *list)
	@return int
*/
int append (int value, Node *list)
{
	if (empty(list))
	{
		list->value = value;
		list->next = NULL;
		return 0;
	}

	while (list->next != NULL)
		list = list->next;

	list->next = newNode();
	if (list->next == NULL)
	{
		return 1;
	}

	list->next->value = value;
	list->next->next = NULL;

	return 0;
}

int nodePrepend (int value, Node *list)
{
	Node *temp = newNode();
	if (temp == NULL)
	{
		return 1;
	}

	temp->value = list->value;
	temp->next = list->next;

	list->value = value;
	list->next = temp;

	return 0;
}

int nodeAppend (int value, Node *list)
{
	Node *node = newNode();
	if (node == NULL)
	{
		return 1;
	}

	node->value = value;
	node->next = NULL;

	list->next = node;

	return 0;
}

/*
	Put value at position
	@argument (int position, int value, Node *list)
	@return int (2 = position out of range)
*/
int put (int position, int value, Node *list)
{
	int listCount = count(list);
	int i = 0;

	if (positionAvailableAt(position, listCount))
	{

		if (position == 0)
		{
			return prepend(value, list);
		}
		else if (position == listCount)
		{
			return append(value, list);
		}
		else
		{
			Node *newItem = newNode();
			if (newItem == NULL)
			{
				return 1;
			}

			while (list->next != NULL)
			{
				if (position == i)
				{
					newItem->value = list->value;
					newItem->next = list->next;

					list->value = value;
					list->next = newItem;
					break;
				}

				list = list->next;
				i++;
			}

		}
	}
	else
	{
		return 3;
	}

	return 0;
}

/*
	Searches for a value in the linked list
	and returns its position
	@arguments (int value, Node *list)
	@return int
*/
int search (int value, Node *list)
{
	int position = 0;
	if (list->value == value)
	{
		return position;
	}

	while (list->next != NULL)
	{
		if (list->value == value)
		{
			return position;
		}
		position++;
		list = list->next;
	}

	if (list->value == value)
	{
		return position;
	}

	return -1;
}

/*
	Delete a node from a linked list
	@arguments (int value, Node *list)
	@return int
*/
int delete (int value, Node *list)
{
	Node *tmp = NULL;
	if (!empty(list))
	{
		if (list->value == value)
		{
			if (list->next != NULL)
			{
				list->value = list->next->value;
				list->next = list->next->next;
				return 0;
			}
			else
			{
				list->value = 0;
				list->next = NULL;
				return 0;
			}
		}
		else
		{
			while (list->next != NULL)
			{
				if (list->next->value == value)
				{
					tmp = list->next->next;
					free(list->next);
					list->next = tmp;
					return 0;
				}
				list = list->next;
			}
		}
	}
	else
	{
		return 2;
	}

	return -1;
}

/*
	Free every node in the linked list
	@arguments (Node *int)
*/
void freel (Node *list)
{
	Node *tmp = NULL;
	while (list->next != NULL)
	{
		tmp = list->next->next;
		free(list->next);
		list->next = tmp;
	}
}
