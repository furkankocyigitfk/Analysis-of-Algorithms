int strToInt(char *data)
{
	int i;
	int n = strlen(data);
	int count = 0;

	for (i = 0; i < n; i++)
	{
		count += data[i];
	}

	return count - 'a' * n;
}
