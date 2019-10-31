#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node{
	int e;
	double c;
	struct node* next;
};
int main(void) {
	int t;
	printf("Enter number of terms in polynomial\n");
	scanf("%d",&t);
	int i,val1,val2;
	struct node *prev,*n,*head;
	for(i=0;i<t;i++){
		n = (struct node*) malloc(sizeof(struct node));
		printf("Enter power and coeff\n");
		scanf("%d %lf",&val1,&val2);
		n->e = val1;
		n->c = val2;
		n->next = NULL;
		if(prev==NULL){
			prev = n;
			head = n;
		}
		else{
			prev->next = n;
			prev = n;
		}
	}	
	double res = 0, x;
	printf("Enter value of x\n");
	scanf("%d",&x);
	n =  head;
	while(n!=NULL){
		res = res + n->c*pow(x,(double) n->e);
		n = n->next;
	}
	printf("Result : %lf",res);
		
	return 0;
}
