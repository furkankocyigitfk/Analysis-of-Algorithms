int quadraticProbing(int key, int i)
{
	return (hash1(key) + i * i) % TABLESIZE;
}
