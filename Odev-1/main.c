#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define MIN(a,b) (a)<(b)?(a):(b) 
#define INF 100000005
#define MAX 50
struct Dot{
	int x;
	int y;
};
typedef struct Dot Dot;

void qSort(Dot *space,int lo,int hi){
	if(lo<hi){
		int q=partition(space,lo,hi);
		qSort(space,lo,q-1);
		qSort(space,q+1,hi);
	}
}
int partition(Dot *arr,int lo,int hi){
	int i,x,j,temp;
	x=hi;
	i=lo-1;
	for(j=lo;j<=hi;j++){
		if(arr[j].x<arr[x].x){
			i++;
			temp=arr[i].x;
			arr[i].x=arr[j].x;
			arr[j].x=temp;
			temp=arr[i].y;
			arr[i].y=arr[j].y;
			arr[j].y=temp;
		}
	}
	i++;
	temp=arr[i].x;
	arr[i].x=arr[x].x;
	arr[x].x=temp;
	temp=arr[i].y;
	arr[i].y=arr[x].y;
	arr[x].y=temp;
	return i;
} 
float findDist(Dot d1,Dot d2){//noktalar arasýndaki uzaklýgýn bulunmasý
	return sqrt((d1.x-d2.x)*(d1.x-d2.x)+(d1.y-d2.y)*(d1.y-d2.y));
}
void printSpace(Dot *space,int n){//Noktalarýn x ve y deðerlerini yazdýrma
	int i;
	for(i=0;i<n;i++){
		printf("%d %d\n",space[i].x,space[i].y);
	}
	printf("\n");
}
float BForce(Dot *space,int start,int end){//3 e esit veya daha az nkta için brute force yaklasýmý kullanýlarak en kücük mesafe dondurulmektedir.
	int i;//iterasyon amaçlý kullanýlmýþtýr.
	int j;//iterasyon amaçlý kullanýlmýþtýr.
	float min=INF;//minimum uzaklýðý bulmak için kullanýlmýþtýr.
	for(i=start;i<end;i++)//Aralýktaki tüm d leri karþýlaþtýrma
		for(j=i+1;j<=end;j++)
			if(findDist(space[i],space[j]) < min)
				min=findDist(space[i],space[j]);			
	return min;
}
float func(Dot *space,int l,int r){//noktalar arasýndaki en küçük mesafeyi döndürür.
	if(r-l<3){
		return BForce(space,l,r);
	}
	int m=(l+r)/2;//sýralanmýþ düzlemde medya degeri orta noktadýr.
	float dl=func(space,l,m);//medyanýn solundaki en küçük d deðerini bulma.
	float dr=func(space,m,r);//medyanýn saðýndaki en küçük d deðerini bulma.
	float dm=MIN(dl,dr);//minimum d yi bulmak için kullanýlmýþtýr.
	int i;//space dizisi için iterasyon amaçlý kullanýlmýþtýr.
	int j=0;//range dizisi için iterasyon amaçlý kullanýlmýþtýr.
	int lenRange;//range dizisinin boyutunu tutmak için kullanýlmýþtýr.
	Dot *range=(Dot*)malloc(sizeof(Dot)*(r-l+1));
	for(i=l;i<=r;i++)//medyan degerinden d uzaklýktaki noktalarýn belirlenmesi
		if((space[i].x > space[m].x-dm) && (space[i].x<space[m].x+dm)){
			range[j++]=space[i];
		}
	lenRange=j;
	for(i=0;i<lenRange-1;i++){//bu aralýkta eðer d degerinden daha küçük bir deger varsa dm guncellenir
		for(j=i+1;j<lenRange;j++){
			if(abs(range[i].y - range[j].y) < dm && findDist(range[i],range[j]) < dm){		
			//eger bakýlan noktalar arasýndaki y dm degerinden buyukse onlarýn arasýndaki d > dm olur.		  
				dm=findDist(range[i],range[j]);
			}		
		}
	}
	printf("dl=%.2f dr=%.2f dm=%.2f l=%d r=%d\n",dl,dr,dm,l,r);
	return dm;
}
void printAllDist(Dot *space,int n){//noktalarýn birbirleriyle olan uzaklýlkarýnýn yazdýrýlmasý
	int i;//iterasyon amaçlý
	int j;//iterasyon amaçlý
	printf("  \t");
	for(i=0;i<n;i++)printf("%d     \t",i);
	printf("\n");
	
	for(i=0;i<n;i++){
		printf("%d\t",i);
		for(j=0;j<n;j++){
			printf("%.2f\t",findDist(space[i],space[j]));
		}
		printf("\n");
	}
}
int main(){
	FILE *fp;//dosya okuma
	char *filename="input.txt";
	fp=fopen(filename,"r");
	if(fp == NULL){
		printf("Not Found File.\n");
		return 0;
	}
	int i;//space dizisi için iterasyon amaçlý kullanýlmýþtýr.
	int n;//kartezyen düzlemdeki nokta sayýsýný tutmak için kullanýlmýþtýr.
	Dot space[MAX];//dosyadaki noktalarýn saklanmasý için kullanýlmýþtýr.
	while(!feof(fp)){//dosya okuma
		fscanf(fp,"%d %d",&space[i].x,&space[i].y);
		i++;
	}
	n=i-1;
	fclose(fp);
	qSort(space,0,n-1);
	printSpace(space,n);
	printAllDist(space,n);
	printf("%.2f",func(space,0,n-1));
	return 0;
}
