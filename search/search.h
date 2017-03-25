#include "algorithms/linear.h"
/*
	Searches for a value in the linked list, using the selected algorithm,
	and returns its position
	@arguments (int value, Node *list)
	@return int
*/
int search (int value, Node *list, int algorithm)
{
  switch (algorithm) {
    case 0:
      return linear(value, list);
    default:
      return linear(value, list);
  }
}
