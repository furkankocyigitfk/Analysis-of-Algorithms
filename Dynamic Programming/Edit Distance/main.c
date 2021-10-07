#include "header.h"

int main()
{
	char *str1 = "arts";
	char *str2 = "maths";
	printf("Distance between %s and %s is %d.\n", str1, str2, editDistance(str1, str2));

	return 0;
}
