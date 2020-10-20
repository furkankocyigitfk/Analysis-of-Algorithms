#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TABLESIZE 32
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define NOTFOUND -1

struct node{
	char *data;
	struct node *next;
};

typedef struct node Node;

#include "strToInt.c"
#include "hash1.c"
#include "hash2.c"
#include "createTable.c"
#include "print.c"

#include "Open Addressing/insertOpenAddr.c"
#include "Open Addressing/searchOpenAddr.c"
#include "Open Addressing/deleteOpenAddr.c"

#include "Seperate Chaining/insertSeperate.c"
#include "Seperate Chaining/searchSeperate.c"
#include "Seperate Chaining/deleteSeperate.c"

#include "Open Addressing/Linear Probing/linearProbing.c"
#include "Open Addressing/Quadratic Probing/quadraticProbing.c"
#include "Open Addressing/Double Hashing/doubleHashing.c"
