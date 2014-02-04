/* input is a file with first digit as the size of input and the rest as numbers*/ 
#include <stdio.h>
#include <stdlib.h>
int main(){
	int *a,n,i;
	scanf("%d",&n);
	a = malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	int key,j;	
	for(i=1;i<n;i++){
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key){
			a[j+1]=a[j];
			j--;				
		}
		a[j+1]=key;
	}
	for(i=0;i<n;i++)
		printf("	%d	\n",a[i]);
	return 0;
}
