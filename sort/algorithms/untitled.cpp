Node* mergeHalves (Node* left, Node* right);
void printList (Node* list);

Node* merge (Node* list)
{
	Node* left = newLinkedList();
	Node* right = NULL;

	// 3 4 2 5 7
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

		return mergeHalves(merge(left),merge(right));
	}
}

Node* mergeHalves (Node* left, Node* right)
{
	printf("Merging: \n");
	printf("Left half ");
	printList(left);
	printf("Right half ");
	printList(right);

	Node* sorted = newLinkedList();
	Node* startLeft, startRight;
	int a, b;

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

	// left = 1 2 3 right = 4 5

		while (left->value > right->value && right->next != NULL)
		{
			append(right->value, sorted);
			right = right->next;
		}

		if (left->value > right->value)
		{
			append(right->value, sorted);
		}

		while (right->value > left->value && left->next != NULL)
		{
			append(left->value, sorted);
			left = left->next;
		}

		if (right->value > left->value)
		{
			append(left->value, sorted);
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
		if (left->next->value < b) {
			a = left->next->value;
		}
		else
		{
			a = b;
			b = left->next->value;
		}
		append(a, sorted);
		append(b, sorted);
	}
	else if (right->next != NULL)
	{
		if (right->next->value < b) {
			a = right->next->value;
		}
		else
		{
			a = b;
			b = right->next->value;
		}
		append(a, sorted);
		append(b, sorted);
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

void printList (Node* list)
{
	while (list->next != NULL)
	{
		printf("%i ", list->value);
		list = list->next;
	}

	printf("%i\n", list->value);
}