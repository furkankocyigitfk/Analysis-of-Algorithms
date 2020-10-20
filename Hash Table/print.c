void print(Node *table){
	int i;
	Node *iter;
	
	for(i=0; i<TABLESIZE; i++){
		iter = &table[i];
		printf("%d ", i);
		while(iter->next != NULL){
			printf("%s ", iter->data);
			iter = iter->next;
		}
		printf("%s \n", iter->data);
	}
}
