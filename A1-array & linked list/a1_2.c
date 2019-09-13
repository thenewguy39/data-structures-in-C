#include<stdio.h>
struct student{
        int roll;
        char name[20];
        float marks;
};

struct student s[100];
int size=0;

void create(){
        printf("Enter name of student \n");
        scanf("%s",&s[size].name);
        printf("Enter roll number of student \n");
        scanf("%d",&s[size].roll);
        printf("Enter percentage marks of student \n"); 
        scanf("%f",&s[size].marks);
        size++; 
}        
        
void display(){
        int i;
        for(i=0;i<size;i++){
                printf(" Name : %s \n Roll No. : %d \n Percentage Marks : %f \n",s[i].name,s[i].roll,s[i].marks);
        }       
}   
    
void search(){
        int r,i,flag=0; 
        printf("Enter roll number of student\n");
        scanf("%d",&r);
        for(i=0;i<size;i++){ 
                if(s[i].roll==r){
                        printf(" Name : %s \n Roll No. : %d \n Percentage Marks : %f \n",s[i].name,s[i].roll,s[i].marks);
                        flag=1;
                }
        }
        if(flag==0)
                printf("Record not found\n");
}
void modify(){
        int r,i,flag=0;
        float m;
        printf("Enter roll number of student\n");
        scanf("%d",&r);
        printf("Enter modified percentage\n");
        scanf("%f",&m);

        for(i=0;i<size;i++){
                if(s[i].roll==r){
                        s[i].marks=m;
                        flag=1;
                }
        }
        if(flag==0)
                printf("Record not found\n");
}

void main(){
        while(1){
                int x;
                printf("1:add 2:display 3:search 4:modify 5:exit\n");
                scanf("%d",&x);
                if(x==5)
                        break;
                switch(x){
                        case 1: create(); break;
                        case 2: display(); break;
                        case 3: search(); break;
                        case 4: modify(); break;
                }
        }
}

