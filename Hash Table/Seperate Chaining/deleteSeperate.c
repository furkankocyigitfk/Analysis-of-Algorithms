void deleteSeperate(Node *table, char *data)
{
	int x = searchSeperate(table, data);
	Node *iter;
	Node *next;
	Node *before = NULL;

	if (x != NOTFOUND)
	{
		iter = &table[x];

		while (iter->next != NULL && strcmp(iter->data, data) != 0)
		{
			before = iter;
			iter = iter->next;
		}

		if (iter == &table[x])
		{
			free(iter->data);
			iter->data = NULL;

			if (iter->next != NULL)
			{
				next = iter->next;
				iter->data = (char *)malloc(sizeof(char) * strlen(next->data));
				strcpy(iter->data, next->data);
				iter->next = next->next;
				free(next->data);
				free(next);
			}
		}
		else
		{
			before->next = iter->next;
			free(iter->data);
			free(iter);
		}
	}
}
