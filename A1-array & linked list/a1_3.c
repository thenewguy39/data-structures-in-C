#include<stdio.h>
void main(){
        int arr[15],copy,i,x,y;
        printf("Enter elements of the array\n");
        for(i=0;i<15;i++){
                scanf("%d",&arr[i]);
        }
        printf("Enter element to be inserted\n");
        scanf("%d",&x);
        for(i=6;i<15;i++){
                copy=arr[i];
                arr[i]=x;
                x=copy;
        }
        for(i=0;i<15;i++){
                printf("%d ",arr[i]);
        }
        printf("\n");
        printf("Enter index of the element to be deleted\n");
        scanf("%d",&y);
        for(i=y;i<15;i++){
                arr[i]=arr[i+1];
        }
        for(i=0;i<14;i++){
                printf("%d ",arr[i]);
        }

}
