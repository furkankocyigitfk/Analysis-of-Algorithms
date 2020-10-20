int sum(int *arr, int x, int y){
	int i;
	int count = 0;
	
	for(i=x; i<=y; i++){
		count += arr[i];
	}
	return count;
}
