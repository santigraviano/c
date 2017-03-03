/*
	It swaps two values
	@arguments (int* a, int* b)
*/
void swap (int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}