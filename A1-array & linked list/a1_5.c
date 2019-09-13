#include<stdio.h>
#include<stdlib.h>

struct linked_list
{
    int number;
    struct linked_list *next;
};

typedef struct linked_list node;
node *head=NULL, *last=NULL;

void create();
void traverse();
void insert_at_last(int value);
void insert_at_first(int value);
void insert_after(int key, int value);
void delete_item(int value);
void show_count();
void reverse_list();

int count;

int main()
{
    int key, value;


    printf("Create Linked List\n");
    create();
    traverse();


    printf("\nInsert new node at end\n");
    scanf("%d", &value);
    insert_at_last(value);
    traverse();



    printf("\nInsert new node at first\n");
    scanf("%d", &value);
    insert_at_first(value);
    traverse();



    printf("\nEnter value at node after which new node is to be inserted\n");
    scanf("%d", &key);
    printf("\nEnter value at new node\n");
    scanf("%d", &value);
    insert_after(key, value);
    traverse();


    printf("\nEnter value to be deleted from list\n");
    scanf("%d", &value);
    delete_item(value);
    traverse();

    reverse_list();

    return 0;
}


void create()
{
    int val;
    count=0;

    while(1)
    {
        printf("Input a number. (Enter -1 to exit)\n");

        scanf("%d", &val);

        if(val==-1)
            break;

        insert_at_last(val);
    }

}


void insert_at_last(int value)
{
    node *temp_node;
    temp_node = (node *) malloc(sizeof(node));

    temp_node->number=value;
    temp_node->next=NULL;


    if(head==NULL)
    {
        head=temp_node;
        last=temp_node;
    }
    else
    {
        last->next=temp_node;
        last=temp_node;
    }
    count++;

}


void insert_at_first(int value)
{
    node *temp_node = (node *) malloc(sizeof(node));

    temp_node->number=value;
    temp_node->next = head;

    head = temp_node;
    count++;

}

void insert_after(int key, int value)
{
    node *myNode = head;
    int flag = 0;

    while(myNode!=NULL)
    {
        if(myNode->number==key)
        {
            node *newNode = (node *) malloc(sizeof(node));
            newNode->number = value;
            newNode->next = myNode->next;
            myNode->next = newNode;

            printf("%d is inserted after %d\n", value, key);

            flag = 1;


            break;
        }
        else
            myNode = myNode->next;
    }

    if(flag==0)
        printf("Key not found!\n");
    else
        count++;

}


void delete_item(int value)
{
    node *myNode = head, *previous=NULL;
    int flag = 0;

    while(myNode!=NULL)
    {
        if(myNode->number==value)
        {
            if(previous==NULL)
                head = myNode->next;
            else
                previous->next = myNode->next;

            printf("%d is deleted from list\n", value);

            flag = 1;
            free(myNode);
            break;
        }

        previous = myNode;
        myNode = myNode->next;
    }

    if(flag==0)
        printf("Key not found!\n");
    else
        count--;

}

void traverse()
{
    printf("\nYour full linked list is\n");

    node *myList;
    myList = head;

    while(myList!=NULL)
    {
        printf("%d ", myList->number);

        myList = myList->next;
    }
    puts("");
    show_count();

}

void reverse_list()
{
    printf("\nReversed linked list is : \n");

    node *myList;
    myList = head;
    int arr[count];
    int j,i=0;

    while(myList!=NULL)
    {
        arr[i++]=myList->number;

        myList = myList->next;
    }
    for(j=count-1;j>=0;j--)
    {
        printf("%d ",arr[j]);
    }
    printf("\n");
}


void show_count()
{
    printf("\nNumber of nodes in linked list : %d", count);
}
                                                                   
