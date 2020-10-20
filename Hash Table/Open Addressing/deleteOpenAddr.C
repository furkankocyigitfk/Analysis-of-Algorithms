void deleteOpenAddress(Node *table, char *data, int (*fp)(int, int)){
	int x = searchOpenAddress(table, data, fp);
	
	if(x != NOTFOUND){
		free(table[x].data);
		table[x].data = NULL;
		table[x].next = NULL;
	}
}
