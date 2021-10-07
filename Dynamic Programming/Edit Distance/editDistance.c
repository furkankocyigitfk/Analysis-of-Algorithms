int editDistance(char *str1, char *str2)
{
	int n = strlen(str1) + 1;
	int m = strlen(str2) + 1;
	int i, j;
	int matrix[n][m];

	for (i = 0; i < n; i++)
	{
		matrix[i][0] = i;
	}
	for (i = 0; i < m; i++)
	{
		matrix[0][i] = i;
	}

	for (i = 1; i < n; i++)
	{
		for (j = 1; j < m; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				matrix[i][j] = matrix[i - 1][j - 1];
			}
			else
			{
				matrix[i][j] = MIN(MIN(matrix[i - 1][j - 1], matrix[i - 1][j]), matrix[i][j - 1]) + 1;
			}
		}
	}

	return matrix[n - 1][m - 1];
}
