Node* mergeSort(Node* list);
Node* mergeHalves (Node* left, Node* right);

int merge (Node* list)
{
	list = mergeSort(list);
}

Node* mergeSort (Node* list)
{
	Node* left = newLinkedList();
	Node* right = NULL;

	printf("Separeting: \n");
	printList(list);

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

		printf("Left half ");
		printList(left);
		printf("Right half ");
		printList(right);
		printf("\n");

		return mergeHalves(mergeSort(left),mergeSort(right));
	}
}

// FIX IT! EXCLUDES ZEROS
Node* mergeHalves (Node* left, Node* right)
{
	printf("Merging: \n");
	printf("Left half ");
	printList(left);
	printf("Right half ");
	printList(right);

	Node* sorted = newLinkedList();
	int a, b;

	// left = 1 right = 2 3

	// sorted = 

	while (left->next != NULL && right->next != NULL)
	{
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

	if (left->next != NULL)
	{
		left = left->next;
		while (left->next != NULL)
		{
			if (b > left->value)
			{
				append(right->value, sorted);
				left = left->next;
			}
			else
			{
				append(b, sorted);
				b = left->value;
				left = left->next;
			}
		}

		if (b < left->value)
		{
			append(b, sorted);
			append(left->value, sorted);
		}
		else
		{
			append(left->value, sorted);
			append(b, sorted);
		}
	}
	else if (right->next != NULL)
	{
		right = right->next;
		while (right->next != NULL)
		{
			if (b > right->value)
			{
				append(right->value, sorted);
				right = right->next;
			}
			else
			{
				append(b, sorted);
				b = right->value;
				right = right->next;
			}
		}
		
		if (b < right->value)
		{
			append(b, sorted);
			append(right->value, sorted);
		}
		else
		{
			append(right->value, sorted);
			append(b, sorted);
		}
	}
	else
	{
		append(b, sorted);
	}

	printf("Merged: ");
	printList(sorted);
	printf("\n");

	return sorted;
}