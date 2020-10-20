void insertOpenAddress(Node *table, char *data, int (*fp)(int, int)){
	int i = 0;
	int key = strToInt(data);
	int x = fp(key, i);
	
	while((i < TABLESIZE) && (table[x].data != NULL)){
		i++;
		x = fp(key, i);
	}
	
	if(table[x].data == NULL){
		table[x].data = (char *) malloc (sizeof(char) * strlen(data));
		strcpy(table[x].data, data);
		table[x].next = NULL;
	}	
}
