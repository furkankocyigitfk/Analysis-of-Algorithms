#include "header.h"

int main(){
	int values[NumberOfItems] = {12, 10, 20, 15};
	int weights[NumberOfItems] = {2, 1, 3, 2};
	
	printf("%d ", knapsack(values, weights));
	
	return 0;
}
