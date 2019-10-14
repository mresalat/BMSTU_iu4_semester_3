#include <stdio.h>
#include <stdlib.h>
struct dec_bin{
    int strt;
    int bin[100];
    int dec;
};
int main(){
    system("color f0");
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
		int hh=abs(a[i]);
		for ( j = 0;hh>0; ++j){
			num[i].bin[j]=hh&1;
			hh=hh>>1;
		}
		num[i].strt=j;
		if(a[i]<0){
            for(int k=0;k<=j;k++){
                if(num[i].bin[k]==1)num[i].bin[k]=0;
                else if(num[i].bin[k]==0)num[i].bin[k]=1;
            }
            int carry=0;
            for(int k=0;k<=j;k++){
                int s=carry;
                if(k==0)s++;
                s+=num[i].bin[k];
                if(s==1)num[i].bin[k]=1;
                else num[i].bin[k]=0;
                if(s==2)carry=1;
                else carry=0;
            }
		}
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

