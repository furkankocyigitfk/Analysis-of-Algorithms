int dynFib(int n, int *arr){
	if(arr[n] != -1) return arr[n];
	arr[n] = dynFib(n - 1, arr) + dynFib(n - 2, arr);
	
	return arr[n];
}
