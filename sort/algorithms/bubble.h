int bubble (Node  list)
{
	int swaps = -1;
	Node *items = list;

	while (swaps != 0)
	{
		swaps = 0;
		items = list;
		while (items->next != NULL)
		{
			int *a = &items->value;
			int *b = &items->next->value;

			if (*a > *b)
			{
				swap(a, b);
				swaps++;
			}

			items =	items->next;
		}
	}

	return 0;
}
