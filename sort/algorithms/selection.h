int selection (Node* list)
{
	Node* unsorted = list;
	Node* smallest = list;

	while (list->next != NULL)
	{
		smallest = list;
		
		while (unsorted->next != NULL)
		{
			if (unsorted->value < smallest->value)
			{
				smallest = unsorted;
			}

			unsorted = unsorted->next;
		}

		if (unsorted->value < smallest->value)
		{
			smallest = unsorted;
		}
		
		swap(&list->value, &smallest->value);

		list = list->next;
		unsorted = list->next;
	}

	return 0;
}