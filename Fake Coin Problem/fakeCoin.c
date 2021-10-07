int fakeCoin(int *arr, int x, int y)
{
	if (x == (x + y) / 2)
		return arr[x] > arr[y] ? x : y;
	if (sum(arr, x, (x + y) / 2) > sum(arr, (x + y) / 2 + 1, y))
		return fakeCoin(arr, x, (x + y) / 2);

	return fakeCoin(arr, (x + y) / 2 + 1, y);
}
