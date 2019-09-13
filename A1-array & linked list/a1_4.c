#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
}*stnode;

void InsertionAtEnd(int n);
void Traversal();

int main()
{
    int n=10;
    printf("Linked List Implementation\n");
    InsertionAtEnd(n);
    printf("\n Traversal : \n");
    Traversal();
    return 0;
}
void InsertionAtEnd(int n)
{
    struct node *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));

    if(stnode == NULL)
    {
        printf(" Memory can not be allocated.");
    }
    else
    {


        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        stnode->num = num;
        stnode->next = NULL;
        tmp = stnode;

        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &num);

                fnNode->num = num;
                fnNode->next = NULL;

                tmp->next = fnNode;
                tmp = tmp->next;
            }
        }
    }
}
void Traversal()
{
    struct node *tmp;
    if(stnode == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        tmp = stnode;
        while(tmp != NULL)
        {
            printf(" Data = %d\n", tmp->num);
            tmp = tmp->next;
        }
    }
}
 
