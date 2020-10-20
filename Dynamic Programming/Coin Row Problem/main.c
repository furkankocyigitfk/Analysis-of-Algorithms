#include "header.h"

int main(){
	/* Choose non-consecutive maximum sum
		A = {a, b, c}
		if a + c > b then 
			choose a + c
		else 
			choose b
	*/
	int arr[N] = {0, 5, 1, 2, 10, 6, 2};
	int temp[N+1];
	int i;
	
	temp[0] = 0;
	temp[1] = arr[1]; 
	coin(arr, temp);
	
	printf("Non-consecutive maximum sum is %d\n", temp[N-1]);
	
	return 0;
}
