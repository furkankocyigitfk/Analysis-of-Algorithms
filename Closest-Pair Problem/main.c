#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MIN(a, b) (a) < (b) ? (a) : (b)
#define INF 100000005
#define MAX 50
struct Dot
{
	int x;
	int y;
};
typedef struct Dot Dot;

void qSort(Dot *space, int lo, int hi)
{
	if (lo < hi)
	{
		int q = partition(space, lo, hi);
		qSort(space, lo, q - 1);
		qSort(space, q + 1, hi);
	}
}
int partition(Dot *arr, int lo, int hi)
{
	int i, x, j, temp;
	x = hi;
	i = lo - 1;
	for (j = lo; j <= hi; j++)
	{
		if (arr[j].x < arr[x].x)
		{
			i++;
			temp = arr[i].x;
			arr[i].x = arr[j].x;
			arr[j].x = temp;
			temp = arr[i].y;
			arr[i].y = arr[j].y;
			arr[j].y = temp;
		}
	}
	i++;
	temp = arr[i].x;
	arr[i].x = arr[x].x;
	arr[x].x = temp;
	temp = arr[i].y;
	arr[i].y = arr[x].y;
	arr[x].y = temp;
	return i;
}
float findDist(Dot d1, Dot d2)
{ //noktalar aras�ndaki uzakl�g�n bulunmas�
	return sqrt((d1.x - d2.x) * (d1.x - d2.x) + (d1.y - d2.y) * (d1.y - d2.y));
}
void printSpace(Dot *space, int n)
{ //Noktalar�n x ve y de�erlerini yazd�rma
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d %d\n", space[i].x, space[i].y);
	}
	printf("\n");
}
float BForce(Dot *space, int start, int end)
{								  //3 e esit veya daha az nkta i�in brute force yaklas�m� kullan�larak en k�c�k mesafe dondurulmektedir.
	int i;						  //iterasyon ama�l� kullan�lm��t�r.
	int j;						  //iterasyon ama�l� kullan�lm��t�r.
	float min = INF;			  //minimum uzakl��� bulmak i�in kullan�lm��t�r.
	for (i = start; i < end; i++) //Aral�ktaki t�m d leri kar��la�t�rma
		for (j = i + 1; j <= end; j++)
			if (findDist(space[i], space[j]) < min)
				min = findDist(space[i], space[j]);
	return min;
}
float func(Dot *space, int l, int r)
{ //noktalar aras�ndaki en k���k mesafeyi d�nd�r�r.
	if (r - l < 3)
	{
		return BForce(space, l, r);
	}
	int m = (l + r) / 2;		  //s�ralanm�� d�zlemde medya degeri orta noktad�r.
	float dl = func(space, l, m); //medyan�n solundaki en k���k d de�erini bulma.
	float dr = func(space, m, r); //medyan�n sa��ndaki en k���k d de�erini bulma.
	float dm = MIN(dl, dr);		  //minimum d yi bulmak i�in kullan�lm��t�r.
	int i;						  //space dizisi i�in iterasyon ama�l� kullan�lm��t�r.
	int j = 0;					  //range dizisi i�in iterasyon ama�l� kullan�lm��t�r.
	int lenRange;				  //range dizisinin boyutunu tutmak i�in kullan�lm��t�r.
	Dot *range = (Dot *)malloc(sizeof(Dot) * (r - l + 1));
	for (i = l; i <= r; i++) //medyan degerinden d uzakl�ktaki noktalar�n belirlenmesi
		if ((space[i].x > space[m].x - dm) && (space[i].x < space[m].x + dm))
		{
			range[j++] = space[i];
		}
	lenRange = j;
	for (i = 0; i < lenRange - 1; i++)
	{ //bu aral�kta e�er d degerinden daha k���k bir deger varsa dm guncellenir
		for (j = i + 1; j < lenRange; j++)
		{
			if (abs(range[i].y - range[j].y) < dm && findDist(range[i], range[j]) < dm)
			{
				//eger bak�lan noktalar aras�ndaki y dm degerinden buyukse onlar�n aras�ndaki d > dm olur.
				dm = findDist(range[i], range[j]);
			}
		}
	}
	printf("dl=%.2f dr=%.2f dm=%.2f l=%d r=%d\n", dl, dr, dm, l, r);
	return dm;
}
void printAllDist(Dot *space, int n)
{		   //noktalar�n birbirleriyle olan uzakl�lkar�n�n yazd�r�lmas�
	int i; //iterasyon ama�l�
	int j; //iterasyon ama�l�
	printf("  \t");
	for (i = 0; i < n; i++)
		printf("%d     \t", i);
	printf("\n");

	for (i = 0; i < n; i++)
	{
		printf("%d\t", i);
		for (j = 0; j < n; j++)
		{
			printf("%.2f\t", findDist(space[i], space[j]));
		}
		printf("\n");
	}
}
int main()
{
	FILE *fp; //dosya okuma
	char *filename = "input.txt";
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Not Found File.\n");
		return 0;
	}
	int i;			//space dizisi i�in iterasyon ama�l� kullan�lm��t�r.
	int n;			//kartezyen d�zlemdeki nokta say�s�n� tutmak i�in kullan�lm��t�r.
	Dot space[MAX]; //dosyadaki noktalar�n saklanmas� i�in kullan�lm��t�r.
	while (!feof(fp))
	{ //dosya okuma
		fscanf(fp, "%d %d", &space[i].x, &space[i].y);
		i++;
	}
	n = i - 1;
	fclose(fp);
	qSort(space, 0, n - 1);
	printSpace(space, n);
	printAllDist(space, n);
	printf("%.2f", func(space, 0, n - 1));
	return 0;
}
