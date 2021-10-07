void coin(int *arr, int *temp)
{
	int i;
	for (i = 2; i < N; i++)
	{
		temp[i] = MAX(arr[i] + temp[i - 2], temp[i - 1]);
	}
}
