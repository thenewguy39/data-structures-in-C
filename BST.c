#include<stdio.h>
#include<stdlib.h>
 
struct node{
        int data;
        struct node* r;
        struct node* l;
};
 
struct node* newNode(int val){
        struct node* temp = (struct node*) malloc(sizeof(struct node));
        temp->data = val;
        temp->r = NULL;
        temp->l = NULL;
        return temp;
}
 
struct node* insert(struct node* root, int val){
        if(root == NULL)
                return newNode(val);
        if(root->data > val)
                root->l = insert(root->l, val);
        else if(root->data < val)
                root->r = insert(root->r, val);
        return root;
}
 
struct node* search(struct node* root, int target){
        if(root == NULL || root->data == target)
                return root;
        if(root->data > target)
                return search(root->l, target);
        else if(root->data < target)
                return search(root->r, target);
}
 
void inorder(struct node* n){
        if(n==NULL)
                return;
        inorder(n->l);
        printf("%d\n",n->data);
        inorder(n->r);
}
 
 
int main(){
        int n,i;
        struct node* root = NULL;
 
        printf("Enter number of nodes in BST\n");
        scanf("%d", &n);
        while(n--){
                int val;
                printf("Enter value to be inserted\n");
                scanf("%d", &val);
                root = insert(root, val);
        }
 
        printf("In-order traversal of BST\n");
        inorder(root);
 
        int target;
        printf("Enter target element\n");
        scanf("%d", &target);
 
        struct node* res;
        res = search(root, target);
 
        if(root==NULL)
                printf("Tree is empty\n");
        else if(root != NULL && res == NULL)
                printf("Target element does not occur in BST\n");
        else
                printf("Target element occurs in BST\n");
 
        return 0;
}
 
