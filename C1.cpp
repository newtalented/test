#include <stdio.h>
#include <malloc.h>
#include <curses.h>
#include <stdlib.h>
#include <math.h>
int count;
bool ktra_nguyento(int n);

bool ktra_thuanNghich(int *p, int n);

int* chuyen_cosobky(int n, int coso){
	if(coso<2){
		printf("Co so phai >=2");
		return 0;
	}
	count=1;
	int *x;
	x= (int*) malloc (100* sizeof(int));
	while(n!=0){
		int sodu= n%coso;
		n=n/coso;
		x[count]=sodu;
		count++;
	}
	count--;
	return x;
}

void Result(int *B, int n){
	int i;
	printf("\n ");
	for(i=1;i<=n;i++)
	printf("%3d",B[i]);
	//getchar();
}
void Init(int *B, int n){
	int i;
	for(i=1;i<=n;i++)
	B[i]=0;
}
void Try(int i, int *B, int n){
	int j;
	for(j=0; j<=9;j++){
		if(i==1 && j==0){
			continue;
		}
		B[i]=j;
		if(i==n) {
			//Result(B,n);
			//So nguyen to
			int temp= B[1]*10000 + B[2]*1000+ B[3]*100+ B[4]*10+ B[5];
			//if(ktra_nguyento(temp)){
				//printf("\n%d",temp);
			//}
			
			//So thuan nghich
			//if(ktra_thuanNghich(B,n)){
				//Result(B,n);
			//}

			//chuyen doi co so
			int *p= chuyen_cosobky(temp, 8);
			if(ktra_thuanNghich(p, count))
			{
				Result(p, count);
			}
		}
		else Try(i+1, B, n);
	}
}
bool ktra_nguyento(int n){
	if(n<2){
		return 0;
	}
	double sqr= sqrt(n*1.0);
	for(int i=2; i<= sqr; i++){
		if(n%i == 0)
			return 0;
	}
	return 1;
}

bool ktra_thuanNghich(int *p,int n){
	for(int i=1,j=n; i<j; i++,j--){
		if(p[i] != p[j]){
			return 0;
		}
	}
	return 1;
}
int main(){
	int *B,n;
	printf("\n Nhap n=");
	scanf("%d",&n);
	B=(int *) malloc(n*sizeof(int));
	Init(B,n); 
	Try(1,B,n);
	free(B);
	return 1;
}
