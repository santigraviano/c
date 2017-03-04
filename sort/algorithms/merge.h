Node* mergeSort(Node *list);
Node* mergeHalves (Node *left, Node *right);

int merge (Node *list)
{
	Node *sorted = mergeSort(list);

	list->value = sorted->value;
	list->next = sorted->next;

	return 0;
}

Node* mergeSort (Node *list)
{
	Node *left = newLinkedList();
	Node *right = NULL;

	if (list->next == NULL)
	{
		return list;
	}
	else
	{
		for (int i = 0, c = count(list) / 2; i < c; i++)
		{
			append(list->value, left);

			list = list->next;
		}

		right = list;

		return mergeHalves(mergeSort(left),mergeSort(right));
	}
}

Node* mergeHalves (Node *left, Node *right)
{
	Node *sorted = newLinkedList();
	Node *lor = NULL;
	int a, b;

	// If there are more than one value in the halves
	while (left->next != NULL && right->next != NULL)
	{
		// Append one by one smaller values go first
		if (left->value < right->value)
		{
			a = left->value;
			left = left->next;
		}
		else
		{
			a = right->value;
			right = right->next;
		}

		append(a, sorted);
	}

	/*
		If there is one value in one of the halves
		Or if there is a last value to sort
	*/
	if (left->value < right->value)
	{
		a = left->value;
		b = right->value;
	}
	else
	{
		a = right->value;
		b = left->value;
	}

	append(a, sorted);

	/*
		If there is a last value
		Or if an entire half has been appended
	*/
	if (left->next != NULL || right->next != NULL)
	{
		// Decide which half contains that last value
		if (left->next != NULL)
			lor = left;
		else if (right->next != NULL)
			lor = right;

		// If there is more than one value iterate over it
		lor = lor->next;
		while (lor->next != NULL)
		{
			if (b > lor->value)
			{
				append(lor->value, sorted);
				lor = lor->next;
			}
			else
			{
				append(b, sorted);
				b = lor->value;
				lor = lor->next;
			}
		}

		// If there is only one value compare it with the last ordered value
		if (b < lor->value)
		{
			append(b, sorted);
			append(lor->value, sorted);
		}
		else
		{
			append(lor->value, sorted);
			append(b, sorted);
		}
	}
	else
	{
		append(b, sorted);
	}

	return sorted;
}
