#include<stdio.h>
#include<stdlib.h>

int main(){

    int array[20],n,i,j;
    printf("Enter number of elements in array.Max 20.\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter number: ");
        scanf("%d",&array[i]);
    }
    printf("Initial array :\n");
    for(i=0;i<n;i++){
    	printf("%d ",array[i]);
    }
    printf("\n");
    for(i=0;i<n;i++){
        for(j=i+2;j<n;j+=2){
            if(i % 2 == 0){
                if(array[i] < array[j]){
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;  
                }
            } 
            else{
                if(array[i] > array[j]){
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;  
                }
            }
        }
    }
    printf("Output Array :\n");
    for(i=0;i<n;i++){
    	printf("%d \n",array[i]);
    }
    printf("\n");
    return 0;
}
