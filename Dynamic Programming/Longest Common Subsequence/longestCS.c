int longestCS(char *str1, char *str2){
	int n = strlen(str1) + 1;
	int m = strlen(str2) + 1;
	int i, j;
	int matrix[n][m];
	
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			if(i == 0 || j == 0){
				matrix[i][j] = 0;
			}
			else if(str1[i-1] == str2[j-1]){
				matrix[i][j] = matrix[i-1][j-1] + 1;
			}
			else{
				matrix[i][j] =MAX(matrix[i][j-1], matrix[i-1][j]);
			}
		}
	}
	
	return matrix[n-1][m-1];
}
