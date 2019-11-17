#include<stdio.h>
#include<stdlib.h>
 
struct node{
        int data;
        struct node* l;
        struct node*r;
}
struct node*  NewNode(int val){
        struct node* new = (struct node*)malloc(sizeof(struct node));
        new->data = val;
        new->l = NULL;
        new->r = NULL;
        return new;
}
int max = 0;
int min = 0;
struct link* root=NULL,curr=NULL;
void add(struct node*,int val);
void delete(struct node*);
int main(){
        int o;
        struct node* root = NULL;
        while(1){
                printf("1.Add new node \n");
                printf("2.Delete a node \n");
                printf("3.Find maximum value \n");
                printf("4.Find minimum value \n");
                printf("5.Exit \n");
                printf("Option :\n");
                scanf("%d", &o);
                switch(o){
                        case 1:
                        add();
                        case 2:
                        delete()
                        case 3:
                        printf("Max = %d\n",&max);
                        case 4:
                        printf("Min = %d\n",&min);
                        case 5:
                        exit(1);
                        default:
                        printf("Invalid choice.Try again\n");
                }
        }
}
void add(struct node* n,int val){
        if(curr==NULL){
                root = NewNode(int val);
                curr = root;
        }
        else if(curr->l==NULL)
                curr->l = NewNode(int val);
        else{
                curr->r=NewNode(int val);
                curr = curr->l;
        }
}
void delete(int val){
        struct node* temp = root;
        if(temp->data==val){
 
        }
}
 
