#include <stdio.h>
int main(){
	int n,i,j,key;
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
	
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
	
	printf("Sorted array:\n");
	for(i = 0; i < n; i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	return 0;
}
