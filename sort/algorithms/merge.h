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
			next(list->value, left);

			list = list->next;
			
			if (left->next != NULL)
				left = left->next;
		}

		right = list;

		return mergeHalves(mergeSort(left),mergeSort(right));
	}
}

Node* mergeHalves (Node *left, Node *right)
{
	Node *sorted = newLinkedList();
	Node *list = sorted;
	int a, b;

	while (left != NULL || right != NULL)
	{
		if (left == NULL)
		{
			next(right->value, list);
			right = right->next;
		}
		else if (right == NULL)
		{
			next(left->value, list);
			left = left->next;
		}
		else
		{
			a = left->value;
			b = right->value;
			if (a < b)
			{
				next(a, list);
				left = left->next;
			}
			else
			{
				next(b, list);
				right = right->next;
			}
		}

		if (list->next != NULL)
			list = list->next;
	}

	return sorted;
}
