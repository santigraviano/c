/*
  Extended Linked List
  --------------------
  This header offers extended functionalities for linked lists
*/

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

/*
	Compares two linked lists with even number of nodes
	@arguments (Node *listA, Node *listB)
	@return (int) number of different node values
*/

int compare (Node *listA, Node *listB)
{
	int diffs = 0;
	for (Node *a = listA, *b = listB; a != NULL && b != NULL; a = a->next, b = b->next)
	{
		if (a->value != b->value)
			diffs++;
	}
	return diffs;
}
