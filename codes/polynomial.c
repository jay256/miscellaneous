#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	scanf("%d",&n);
	int *a;
	a=malloc(sizeof(int)*n);
	int i;	
	for(i=0;i<n;i++)
		scanf("%d",(a+i));
	int x;
	scanf("%d",&x);
	int value=0;	
	for(i=n-1;i>=1;i--){
		value = x*(value + a[i]); 
	}	
	printf("%d\n",value+a[0]);
}
