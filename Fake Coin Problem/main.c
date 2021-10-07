#include "header.h"

int main()
{
	int arr[ARRAYSIZE];
	int i;
	int k;

	for (i = 0; i < ARRAYSIZE; i++)
		arr[i] = 1;

	srand(time(NULL));
	k = rand() % ARRAYSIZE;
	arr[k] = 2;

	printf("Fake coin is found at %d th coin and k = %d\n", fakeCoin(arr, 0, ARRAYSIZE - 1), k);

	return 0;
}
