int hash2(int key)
{
	return 1 + (key % TABLESIZE - 1);
}
