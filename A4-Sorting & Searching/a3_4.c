#include <stdio.h>
int main(){
	int n,i,j,temp;
	printf("Enter size of list :\n");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}  
	printf("Original array:\n");
	for(i = 0; i < n; i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	for (i = 0; i< n-1; i++){       
    	for (j = 0; j < n-i-1; j++){  
            if (arr[j] > arr[j+1]){ 
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
    	}
	}
	
	printf("Sorted array:\n");
	for(i = 0; i < n; i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	return 0;
}
