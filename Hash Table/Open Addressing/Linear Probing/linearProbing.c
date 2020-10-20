int linearProbing(int key, int i){
	return (hash1(key) + i ) % TABLESIZE;
}
