int insertion (Node *list)
{
	Node *sorted = list;
	Node *unsorted = list->next;
	int c = 0;

	Node* start = sorted;
	sorted->next = NULL;

	while (unsorted->next != NULL)
	{
		for (int c = 0; sorted->next != NULL; c++)
		{
			if (unsorted->value <= sorted->value)
			{
				if (c == 0)
					start = sorted;

				break;
			}

			sorted = sorted->next;
		}

		if (unsorted->value > sorted->value)
		{
			nodeAppend(unsorted->value, sorted);
		}
		else
		{
			nodePrepend(unsorted->value, sorted);
		}

		sorted = start;
		unsorted = unsorted->next;
	}

	while (sorted->next != NULL)
	{
		if (unsorted->value <= sorted->value)
		{
			break;
		}

		sorted = sorted->next;
	}

	if (unsorted->value > sorted->value)
	{
		nodeAppend(unsorted->value, sorted);
	}
	else
	{
		nodePrepend(unsorted->value, sorted);
	}
}
