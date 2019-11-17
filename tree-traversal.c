#include<stdio.h>
#include<stdlib.h>
 
struct node{
        int data;
        struct node* l;
        struct node* r;
};
 
struct node*  NewNode(int val){
        struct node* new = (struct node*)malloc(sizeof(struct node));
        new->data = val;
        new->l = NULL;
        new->r = NULL;
        return new;
}
void inorder(struct node* n){
        if(n==NULL)
                return;
        inorder(n->l);
        printf("%d\n",n->data);
        inorder(n->r);
}
void postorder(struct node* n){
        if(n==NULL)
                return;
        postorder(n->l);
        postorder(n->r);
        printf("%d\n",n->data);
}
 
void preorder(struct node* n){
        if(n==  NULL)
                return;
        printf("%d\n",n->data);
        preorder(n->l);
        preorder(n->r);
}
 
int main(){
        struct node* root;
        root = NewNode(1);
        root->l = NewNode(2);
        root->r = NewNode(3);
        root->l->l = NewNode(4);
        root->r->l = NewNode(5);
        printf("Pre-order:\n");
        preorder(root);
        printf("In-order:\n");
        inorder(root);
        printf("Post-order:\n");
        postorder(root);
        return 0;
}
 
