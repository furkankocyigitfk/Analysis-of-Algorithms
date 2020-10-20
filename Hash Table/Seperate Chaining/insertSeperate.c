void insertSeperate(Node *table, char *data){
	Node *iter = &table[hash1(strToInt(data))];
	if(iter->data == NULL){
		iter->data = (char *) malloc (sizeof(char) * strlen(data));
		strcpy(iter->data, data);
		iter->next = NULL;
		return;
	}
	
	while(iter->next != NULL){
		iter = iter->next;
	}	
	iter->next = (Node *) malloc (sizeof(Node));
	iter->next->data = (char *) malloc (sizeof(char) * strlen(data));
	strcpy(iter->next->data, data);
	iter->next->next = NULL;
}
