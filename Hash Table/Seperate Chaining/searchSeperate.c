int searchSeperate(Node *table, char *data){
	int x = hash1(strToInt(data));
	Node *iter = &table[x];
	
	while(iter->next != NULL && iter->data != NULL && strcmp(iter->data, data) != 0){
		iter = iter->next;
	}
	
	if(iter->data != NULL && strcmp(iter->data, data) == 0)
		return x;
		
	return NOTFOUND;
}
