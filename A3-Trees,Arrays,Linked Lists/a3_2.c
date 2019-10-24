#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct link* next;
};
struct node* add_node(struct node*,int);
void display(struct node*);

int main() {
	struct node* head=NULL;
	int n,i,val;
	printf("Enter number of nodes :\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter value at node %d\n",i);
		scanf("%d",&val);
		head = add_node(head,val);
	}
	printf("Initial linked list : \n");
	display(head);
    struct node* temp = head, *head1 = NULL, *head2 = NULL;
    while(temp != NULL){
        if((temp -> data) % 2 == 0) head1 = add_node(head1, temp -> data);
        else head2 = add_node(head2, temp -> data);
        temp = temp -> next;
    }
    printf("Even linked list : \n");
    display(head1);
    printf("Odd linked list : \n");
    display(head2);
	return 0;
}

struct node* add_node(struct node* head,int val){
    struct node* temp = (struct link*) (malloc(sizeof(struct node)));
    temp -> next = NULL;
    temp -> data = val;
    if(head==NULL) head = temp;
    else{
        struct node* p = head;
        while(p -> next != NULL) p = p -> next;
        p -> next = temp;
    }
    return head;
}

void display(struct node* head){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ",temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}


