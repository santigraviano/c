#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "llist/llist.h"
#include "sort/sort.h"

double calculateTime (clock_t start, clock_t end);

int main (void)
{
  char *algorithm;
  int samples = 30000;

  for (int t = 0; t <= 3; t++)
  {
    Node *list = newLinkedList();

    clock_t appendStart = clock();
    for (int e = samples; e >= 0; e--)
    {
      append(e, list);
    }
    clock_t appendEnd = clock();

    double appendTime = (double)(appendEnd - appendStart) / CLOCKS_PER_SEC;

    printf("Append time: %f seconds\n", appendTime);


    switch (t)
    {
      case 0:
        algorithm = "Bubble";
        break;
      case 1:
        algorithm = "Selection";
        break;
      case 2:
        algorithm = "Insertion";
        break;
      case 3:
        algorithm = "Merge";
        break;
    }

    clock_t sortStart = clock();

    sort(t, list);

    clock_t sortEnd = clock();

    double sortTime = (double)(sortEnd - sortStart) / CLOCKS_PER_SEC;

    printf("%s sort execution time: %f seconds\n", algorithm, sortTime);

    freel(list);
  }

  return 0;
}

double calculateTime (clock_t start, clock_t end)
{
  return (double)(end - start) / CLOCKS_PER_SEC;
}
