/*
  Extended Linked List
  --------------------
  This header offers extended functionalities for linked lists
*/

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

int printList (Node *list)
{
	if (!empty(list))
	{
		while (list->next != NULL)
		{
			printf("%i ", list->value);
			list = list->next;
		}

		printf("%i\n", list->value);
	}
	else
	{
		return 2;
	}

	return 0;
}
