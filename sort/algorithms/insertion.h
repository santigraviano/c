int insertion (Node *list)
{
	Node *sorted = list;
	Node *unsorted = list->next;

	sorted->next = NULL;

	for (Node *currentUnsorted = unsorted; currentUnsorted != NULL; currentUnsorted = currentUnsorted->next)
	{
		Node *currentSorted;

		for (currentSorted = sorted; currentSorted != NULL; currentSorted = currentSorted->next)
		{
			if (currentUnsorted->value <= currentSorted->value)
			{
				break;
			}
		}

		if (currentUnsorted->value > currentSorted->value)
		{
			next(currentUnsorted->value, currentSorted);
		}
		else
		{
			prev(currentUnsorted->value, currentSorted);
		}
	}
}
