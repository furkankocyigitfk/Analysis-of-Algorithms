#include "header.h"

int main()
{
	Node *table = createTable();

	//insertOpenAddress(table, "furkan", &linearProbing);
	//print(table);
	//deleteOpenAddress(table, "furkan", &linearProbing);
	//print(table);

	insertSeperate(table, "fuonan");
	insertSeperate(table, "furkan");
	insertSeperate(table, "fupman");
	//printf("%d ",searchSeperate(table, "fupman"));

	print(table);
	printf("\n");
	deleteSeperate(table, "furkan");
	deleteSeperate(table, "fuonan");
	deleteSeperate(table, "fupman");
	print(table);

	return 0;
}
