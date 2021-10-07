int recFib(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return recFib(n - 1) + recFib(n - 2);
}
