#include<stdio.h>
#include<stdlib.h>
 
struct node{
        int data;
        struct node* next;
};
 
struct hash{
        struct node* head[17];
        struct node* tail[17];
};
 
int hash_function(int x){
        return x%17;
}
 
struct hash* initialize(struct hash* hash){
        int i;
        for(i = 0; i < 17; i++){
                hash->head[i] = NULL;
                hash->tail[i] = NULL;
        }
        return hash;
}
 
struct node* newNode(int val){
        struct node* temp;
        temp = (struct node*) malloc(sizeof(struct node));
        temp->data = val;
        temp->next = NULL;
        return temp;
}
 
struct hash* add(struct hash* hash, int val){
        struct node* new = newNode(val);
        int index = hash_function(val);
 
        if(hash->head[index] == NULL){
                hash->head[index] = new;
                hash->tail[index] = new;
        }
        else{
                hash->tail[index]->next = new;
                hash->tail[index] = new;
        }
 
        return hash;
}
 
void print_list(struct node* head){
        struct node* temp = head;
        while(head!=NULL){
                printf("%d ", head->data);
                head = head->next;
        }
}
 
void print_hash(struct hash* hash){
        int i;
        for(i = 0; i < 17; i++){
                printf("key %d: ", i);
                print_list(hash->head[i]);
                printf("\n");
        }
}
 
int main(){
        struct hash* hash;
        hash = initialize(hash);
        int n,i;
        printf("Enter number of elements to be added\n");
        scanf("%d", &n);
        for(i = 0; i < n; i++){
                int val;
                printf("Enter value\n");
                scanf("%d", &val);
                hash = add(hash, val);
        }
        print_hash(hash);
 
        return 0;
}
 
