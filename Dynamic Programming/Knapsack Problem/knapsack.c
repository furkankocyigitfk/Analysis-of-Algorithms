int knapsack(int *values, int *weights){
	int i, j;
	int matrix[NumberOfItems + 1][CapacityOfWeight + 1];
	
	for(i=0; i<NumberOfItems+1; i++){
		for(j=0; j<CapacityOfWeight+1; j++){
			if(i == 0 || j == 0){
				matrix[i][j] = 0;
			}
			else if(weights[i-1] <= j){
				matrix[i][j] = MAX(matrix[i-1][j-weights[i-1]]+values[i-1], matrix[i-1][j]);
			}
			else{
				matrix[i][j] = matrix[i-1][j];
			}
		}
	}
	
	for(i=0; i<NumberOfItems+1; i++){
		for(j=0; j<CapacityOfWeight+1; j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	
	return matrix[NumberOfItems][CapacityOfWeight];
}
