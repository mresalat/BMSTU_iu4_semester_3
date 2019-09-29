#include <stdio.h>
#include <stdlib.h>
struct dec_bin{
    int strt;
    int bin[100];
    int dec;
};
int main(){
    struct dec_bin num[100];
	int m,i,j,k;
	do{
		printf("Enter elements number in the Set: ");
	    scanf("%d",&m);
	}
	while (m<=0);
	printf("Enter elements: ");
	int a[100];
	for (int i = 0; i < m; ++i){
		scanf("%d",&a[i]);
	}
   printf("Elements_dec     Elements_binary\n");
	for (i = 0; i < m; ++i){
		num[i].dec=a[i];
		for ( j = 0;a[i]>0; ++j){
			num[i].bin[j]=a[i]&1;
			a[i]=a[i]>>1;
		}
		num[i].strt=j-1;
	}
	for (i = 0; i < m; ++i){
		printf("   %d                  ",num[i].dec);
		for (k = num[i].strt; k >= 0; k--){
			printf("%d",num[i].bin[k] );
		}
		printf("\n");
	}
	return 0;
}
