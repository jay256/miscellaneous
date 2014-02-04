/* input is a file with first digit as the size of input and the rest as numbers*/ 
#include <stdio.h>
#include <stdlib.h>
int main(){
	int *a,n,i;
	scanf("%d",&n);
	a = malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	int j;	
	for(i=1;i<n;i++){
		for(j=i;j>0;j--){
			if(a[j]<=a[j-1]){
				int temp;
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;	
			}
		}
	}
	for(i=0;i<n;i++)
		printf("	%d	\n",a[i]);
	return 0;
}
