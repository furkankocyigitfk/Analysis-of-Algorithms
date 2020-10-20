void hanoi(int n, char src, char asst, char dest){
	if(n == 1){
		printf("Move disk from %c to %c\n", src, dest);
		return;
	}
	hanoi(n-1, src, dest, asst);
	printf("Move disk from %c to %c\n", src, dest);
	hanoi(n-1, asst, src, dest);
}
