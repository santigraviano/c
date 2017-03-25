#include "algorithms/linear.h"

int search (int value, Node *list, int algorithm)
{
  switch (algorithm) {
    case 0:
      return linear(value, list);
    default:
      return linear(value, list);
  }
}
