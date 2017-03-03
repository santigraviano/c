#include "../lib/swap.h"
#include "algorithms/bubble.h"
#include "algorithms/selection.h"
#include "algorithms/insertion.h"
#include "algorithms/merge.h"

int sort (int option, Node* list)
{
	switch (option)
	{
		case 0:
			return bubble(list);
			break;
		case 1:
			return selection(list);
			break;
		case 2:
			return insertion(list);
			break;
		case 3:
			return merge(list);
			break;
		default:
			return bubble(list);
	}
}