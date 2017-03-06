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
	int a, b;

	while (left != NULL || right != NULL)
	{
		if (left == NULL)
		{
			append(right->value, sorted);
			right = right->next;
		}
		else if (right == NULL)
		{
			append(left->value, sorted);
			left = left->next;
		}
		else
		{
			a = left->value;
			b = right->value;
			if (a < b)
			{
				append(a, sorted);
				left = left->next;
			}
			else
			{
				append(b, sorted);
				right = right->next;
			}
		}
	}

	return sorted;
}
