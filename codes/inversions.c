/* input is a file with first digit as the size of input and the rest as numbers*/ 
#include <stdio.h>
#include <stdlib.h>

int inv=0;

void merge(int *a, int l, int p, int r){
	int n1=p+1-l;
	int n2=r-p;
	int *b, *c;
	b=malloc(sizeof(int)*n1);
	c=malloc(sizeof(int)*n2);
	int i;	
	for(i=0;i<n1;i++)
		b[i]=a[l+i];
	for(i=0;i<n2;i++)
		c[i]=a[p+i+1];
	b[n1]=2147483647;
	c[n2]=2147483647;
	int k;
	i=0;
	int j=0;
	for(k=l;k<=r;k++){
		if(b[i]<=c[j] && i<n1){
			a[k]=b[i];
			i++;
		}
		else{
			a[k]=c[j];
			inv=inv+n1-i;
			j++;
		}
	}	
}

void mergesort(int *a, int l, int r){
	int p;
	if(l<r){
		p=(l+r)/2;
		mergesort(a,l,p);
		mergesort(a,p+1,r);
		merge(a,l,p,r);
	}	
}

int main(){
	int *a,n,i;
	scanf("%d",&n);
	a = malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	mergesort(a,0,n-1);
	//for(i=0;i<n;i++)
	//	printf("	%d	\n",a[i]);
	printf("no. of inversions: %d\n",inv);	
	return 0;
}
