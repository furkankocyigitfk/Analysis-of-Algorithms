int searchOpenAddress(Node *table, char *data, int (*fp)(int, int)){
	int key = strToInt(data);
	int i = 0;
	int x = fp(key, i);
	int flag = TRUE;
	
	while((i < TABLESIZE) && (flag == TRUE)){
		if(table[x].data == NULL){
			flag = FALSE;
		}
		else if(strcmp(table[x].data, data) == 0){
			flag = FALSE;
		}
		else{
			i++;
			x = fp(key, i);
		}
	}
	
	if((table[x].data == NULL) || (strcmp(table[x].data, data) != 0))
		return NOTFOUND;
		
	return x;
}
