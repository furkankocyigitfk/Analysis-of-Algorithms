int doubleHashing(int key, int i){
	return (hash1(key) + i * hash2(key)) % TABLESIZE;
}
