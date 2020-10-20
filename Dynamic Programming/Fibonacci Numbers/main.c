#include "header.h"

int main(){
	/*
	****Recursive Solution****
	fib(n):
		if n == 1 
			return 1
			
		if n == 0 
			return 0
			
		return fib(n-1) + fib(n-2)
	
	****Dynamic Programming Solution****
	arr[0] = 0
	arr[1] = 1
	arr[2..n] = -1
	save fib(n-1) and fib(n-2). Don't try to find it again.
	*/
	int result;
	int arr[N+1];
	int i;
	double time;
	clock_t t;
	
	t = clock();
	
	result = recFib(N);
	
	t = clock() - t;
	time = ((double)t) / CLOCKS_PER_SEC;
	
	printf("result %d took %f seconds\n", result, time);
	
		
	t = clock();
	
	arr[0] = 0;
	arr[1] = 1;
	for(i=2; i<N+1; i++){
		arr[i] = -1;
	}
	result = dynFib(N, arr);
	
	t = clock() - t;
	time = ((double)t) / CLOCKS_PER_SEC;
	printf("result %d took %f seconds", result, time);
	
	return 0;
}
