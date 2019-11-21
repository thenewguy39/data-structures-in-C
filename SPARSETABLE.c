#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
int mat[SIZE][SIZE];

int arr[SIZE][3];
int curr = 0;

struct node{
	int r, c, data;
	struct node* next;
};
struct node* head = NULL;

void add(int i, int j, int val){
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->r = i;
	new_node->c = j;
	new_node->data = val;
	
	if(head == NULL)
		head = new_node;
	else{
		struct node* temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}

void SparseTable(int r, int c){
	int i, j;
	for(i = 0; i < r; i++){
		for(j = 0; j < c; j++){
			if(mat[i][j] != 0){
				add(i+1, j+1, mat[i][j]);
				
				arr[curr][0] = i+1;
				arr[curr][1] = j+1;
				arr[curr][2] = mat[i][j];
				curr++;
			}
		}
	}
}

void print2(){
	printf("Sparse Table stored using array\n");
	int i;
	for(i = 0; i < curr; i++){
		printf("(Row,Col) = (%d,%d) ", arr[i][0], arr[i][1]);
		printf("Value = %d\n", arr[i][2]);
	}
}

void print1(){
	printf("Sparse Table stored using linked list\n");
	struct node* temp = head;
	while(temp != NULL){
		printf("(Row,Col) = (%d,%d) ", temp->r, temp->c);
		printf("Value = %d\n", temp->data);
		temp = temp->next;
	}
}

void create(int r, int c){
	printf("Enter original matrix\n");
	int i, j;
	for(i = 0; i < r; i++){
		for(j = 0; j < c; j++)
			scanf("%d", &mat[i][j]);
	}
	SparseTable(r, c);
	print1();
	print2();
}

int main(void) {
	int r,c;
	printf("Enter number of rows in original matrix\n");
	scanf("%d", &r);
	printf("Enter number of columns in original matrix\n");
	scanf("%d", &c);
	create(r, c);
	return 0;
}
