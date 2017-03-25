int linear (int value, Node *list)
{
  int position = 0;

  for (Node *current = list; current != NULL; current = current->next)
  {
    if (current->value == value)
      return position;

    position++;
  }
  
  return -1;
}
