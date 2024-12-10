#include<stdio.h>
#include<math.h>

int a[1000][1000],x,y,z;
void nhapMang(){
    printf("Nhap mang 2 chieu\n");
    scanf("%d%d",&x,&y);
    for(int i=1;i<=x;i++){
	    for(int j=1;j<=y;j++){
	    	printf("Moi ban nhap gia tri arr[%d][%d] : ",i ,j);
		    scanf("%d",&a[i][j]);
        }
    }
}
void inMang(){
    printf("\n");
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
		    printf("%d ",a[i][j]);
		}
        printf("\n");
    }
}
void inGoc(){
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if((i==1||i==x)&&(j==1||j==y)){
			    printf("%d ",a[i][j]);
            }else {
			    printf("   ");
			}
        }
        printf("\n");
    }
}
void inBien(){
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if(i==1||i==x||j==1||j==y){
			    printf("%d ",a[i][j]);
            }else {
			    printf("   ");
			}
        }
        printf("\n");
    }
}
void inCheo(){
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if((i==j)||i+j==y+1){
			    printf("%d ",a[i][j]);
            }else {
			    printf("   ");
			}
        }
        printf("\n");
    }
}
int scp(int a){
    if(a<2){
	    return 0;
	}
    for(int i=2;i<=sqrt(a);i++){
	    if(a%i==0){
		    return 0;
		}
	}
    return 1;
}
void insoNT(){
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if(scp(a[i][j])){
			    printf("%d ",a[i][j]);
            }else {
			    printf("   ");
            }
        printf("\n");
    }
}
}
int main(){
    do{
        printf("MENU\n1.Nhap gia tri cac phan tu cua mang\n2.In gia tri cac phan tu cua mang theo ma tran\n3.In ra cac phan tu cua goc theo ma tran\n4.In ra cac phan tu nam tren duong bien theo ma tran\n5.In ra cac phan tu nam tren duong cheo chinh va duong cheo phu tren ma tran\n6.In ra cac phan tu la so nguyen to theo ma tran\n7.Thoat\nLua chon cua ban: ");
        scanf("%d",&z);
        switch(z){
            case 1:
                nhapMang();
                break;
            case 2:
                inMang();
                break;
            case 3:
                inGoc();
                break;
            case 4:
                inBien();
                break;
            case 5:
                inCheo();
                break;
            case 6:
                insoNT();
                break;
            default: 
			continue;
            }
    }while(z!=7);
    return 0;
}
