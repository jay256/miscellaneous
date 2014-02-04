#include <stdio.h>
#include <stdlib.h>

int *maxCrossingSubarray(int *a, int low, int mid, int high){
	int *result;
	int leftsum=-999999;
	int sum=0;
	int i,maxleft;
	for(i=mid;i>=low;i--){
		sum=sum+a[i];
		if(sum>leftsum){
			leftsum=sum;
			maxleft=i;
		}			
	}
	int rightsum=-999999;
	sum=0;
	int maxright;
	for(i=(mid+1);i<high;i++){
		sum=sum+a[i];
		if(sum>rightsum){
			rightsum=sum;
			maxright=i;
		}			
	}
	result=malloc(sizeof(int)*3);
	result[0]=maxleft;
	result[1]=maxright;
	result[2]=leftsum+rightsum;
	return result;
}

int *maxSubarray(int *a, int low, int high){
	int *result;
	result=malloc(sizeof(int)*3);	
	if(high==low){
		result[0]=low;
		result[1]=high;
		result[2]=a[low];
		return result;		
	}		
	else{
		int mid=(low+high)/2;
		int *return_left;
		return_left=malloc(sizeof(int)*3);
		int *return_right;
		return_right=malloc(sizeof(int)*3);
		int *return_cross;
		return_cross=malloc(sizeof(int)*3);
		return_left=maxSubarray(a,low,mid);
		return_right=maxSubarray(a,mid+1,high);
		return_cross=maxCrossingSubarray(a,low,mid,high);
		if((return_left[2]>=return_right[2]) && (return_left[2]>=return_cross[2]))
			return return_left;
		else if((return_right[2]>=return_left[2]) && (return_right[2]>=return_cross[2]))
			return return_right;
		else
			return return_cross;
	}
}

int main(){
	int size;
	scanf("%d",&size);
	int *sp,*diff;
	sp=malloc(sizeof(int)*size);
	diff=malloc(sizeof(int)*(size-1));
	int i;
	for(i=0;i<size;i++)
		scanf("%d",(sp+i));
	for(i=0;i<size-1;i++)
		diff[i]=sp[i+1]-sp[i];
	int *result;
	result=malloc(sizeof(int)*3);
	result=maxSubarray(diff,0,size-1);
	printf("Purchase date index: %d\n",result[0]+1);
	printf("Selling date index: %d\n",result[1]+1);
	printf("Net profit: %d\n",result[2]);
}	
