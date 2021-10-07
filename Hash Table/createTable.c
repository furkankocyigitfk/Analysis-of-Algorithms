Node *createTable()
{
	Node *table = (Node *)malloc(sizeof(Node) * TABLESIZE);
	int i;

	for (i = 0; i < TABLESIZE; i++)
	{
		table[i].data = NULL;
		table[i].next = NULL;
	}

	return table;
}
