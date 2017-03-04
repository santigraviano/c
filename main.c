#include <stdio.h>
#include <stdlib.h>
#include "llist/llist.h"
#include "sort/sort.h"

// Linked List
int printList (Node* list);

int main (void)
{
	int value = 0;
	int input = 1;
	int sortOpt = 0;
	int pushOpt = 0;
	int pushPos = 0;
	int listCount = 0;
	char* operation;
	int operationResult = 0;
	int searchResult = -1;
	Node* list = newLinkedList();

	while (input != 0)
	{
		printf("====> MENU <====\n");
		printf("0) Quit\n");
		printf("1) Add a value to the list\n");
		printf("2) Search a value in the list\n");
		printf("3) Delete a value in the list\n");
		printf("4) Sort the list\n");
		printf("5) Print the list\n");
		printf("6) Count the items on the list\n");
		scanf("%i", &input);

		switch (input)
		{
			case 0:
				printf("Bye\n");
				freel(list);
				free(list);
				break;

			case 1:
				operation = "push";
				printf("Where your value will be added?\n");
				printf("0) At the start of the list\n");
				printf("1) At the end of the list\n");
				printf("2) At some position\n");
				scanf("%i", &pushOpt);

				switch(pushOpt)
				{
					case 0:
						printf("Enter a value to add at the start of the list:\n");
						scanf("%i", &value);
						operationResult = prepend(value, list);
						break;
					case 1:
						printf("Enter a value to add at the end of the list:\n");
						scanf("%i", &value);
						operationResult = append(value, list);
						break;
					case 2:
						listCount = count(list);
						printf("There is positions available from 0 to %i\n", listCount);
						printf("Enter the position to put the value\n");
						scanf("%i", &pushPos);

						while (!positionAvailableAt(pushPos, listCount))
						{
							printf("Entered position was out of range\n");
							printf("Enter a different position to put the value\n");
							scanf("%i", &pushPos);
						}

						printf("Enter a value to add at position %i of the list:\n", pushPos);
						scanf("%i", &value);
						operationResult = put(pushPos, value, list);
						break;
					default:
						operationResult = append(value, list);
				}
				break;

			case 2:
				operation = "search";
				printf("Enter a value to search in the list:\n");
				scanf("%i", &value);

				operationResult = search(value, list);

				if (operationResult != -1)
				{
					searchResult = operationResult;
					operationResult = 0;
				}
				break;

			case 3:
				operation = "delete";
				printf("Enter a value to delete in the list:\n");
				scanf("%i", &value);

				operationResult = delete(value, list);
				break;

			case 4:
				operation = "sort";
				printf("Choose one sorting algorithm\n");
				printf("0) Bubble sort\n");
				printf("1) Selection sort\n");
				printf("2) Insertion sort\n");
				printf("3) Merge sort\n");
				scanf("%i", &sortOpt);

				operationResult = sort(sortOpt, list);
				break;

			case 5:
				operation = "print list";
				operationResult = printList(list);
				break;

			case 6:
				operation = "count items";
			 	listCount = count(list);
				printf("There are %i items in the list.\n", listCount);
				operationResult = 0;
		}

		if (input != 0)
		{
			switch (operationResult)
			{
				case 0:
					printf("| Operation %s completed |", operation);
					if (operation == "search")
						printf(" Value %i founded at position %i\n", value, searchResult);
					break;
				case 1:
					printf("| Operation: %s not completed. Error: No memory to complete the operation |\n", operation);
					break;
				case 2:
					printf("| Operation: %s not completed. Error: empty list |\n", operation);
					break;
				case 3:
					printf("| Operation: %s not completed. Error: Position out of range |\n", operation);
					break;
				case -1:
					printf("| Info: Value not found. |\n");
					break;
			}
			printf("\n");
		}

	}

	return 0;
}

int printList (Node* list)
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
