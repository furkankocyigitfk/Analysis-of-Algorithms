#include "header.h"

int main(){
	char *str1 = "BACDB";
	char *str2 = "BDCB";
	printf("Length of longest common subsequence between %s and %s is %d.\n", str1, str2, longestCS(str1, str2));
	
	return 0;
}
