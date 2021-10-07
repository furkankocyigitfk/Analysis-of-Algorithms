int russianMultiplication(int n, int m)
{
	int result = 0;
	while (m > 0)
	{
		if (m & 1 == 1)
		{ //if m is odd
			result += n;
		}
		n = n << 1;
		m = m >> 1;
	}
	return result;
}
