#include<stdio.h>
int a, b;
int number[1005][1005];
void inMang(int size1, int size2){
	printf("Gia tri cua mang la : \n");
	for(int i=0;i<size1;i++){
		for(int j=0;j<size2;j++){
			printf("%d\t",number[i][j]);
		}
		printf("\n");
	}
}

int main(){
	printf("Moi ban nhap so hang : ");
	scanf("%d", &a);
	printf("Moi ban nhap so cot : ");
	scanf("%d", &b);
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			printf("Moi ban nhap gia tri arr[%d][%d] : ",i ,j);
			scanf("%d", &number[i][j]);
		}
	}
	inMang(a,b);
	return 0;
}
