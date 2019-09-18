#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *ptr;
}*front,*rear,*temp,*front1;
 
int frontelement();
void enq(int val);
void deq();
void empty();
void display();
void create();
void size();
 
int count = 0;
 
void main()
{
    int no, ch, e;
 
    printf(" 1 - Enqueue\n");
    printf(" 2 - Dequeue\n");
    printf(" 3 - Show front element of queue\n");
    printf(" 4 - Check if queue is empty\n");
    printf(" 5 - Exit\n");
    printf(" 6 - Display queue\n");
    printf(" 7 - Count number of elements in queue\n");
    create();
    while (1)
    {
        printf("Enter choice : \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data to be enqueued : \n");
            scanf("%d", &no);
            enq(no);
            break;
        case 2:
            deq();
            break;
        case 3:
            e = frontelement();
            if (e != 0)
                printf("Front element = %d\n", e);
            else
                printf("Queue is empty\n");
            break;
        case 4:
            empty();
            break;
        case 5:
            exit(0);
        case 6:
            display();
            break;
        case 7:
            size();
            break;
        default:
            printf("Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}
 
void create(){
    front =  NULL;
    rear = NULL;
}
 
void size(){
    printf("Queue size = %d\n", count);
}
 
void enq(int val)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->data = val;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        temp->data = val;
        temp->ptr = NULL;
 
        rear = temp;
    }
    count++;
}
 
void display()
{
    front1 = front;
 
    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty\n");
        return;
    }
    while (front1 != rear)
    {
        printf("%d ", front1->data);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d\n", front1->data);
}
 
void deq()
{
    front1 = front;
 
    if (front1 == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            printf("Dequed element = %d\n", front->data);
            free(front);
            front = front1;
        }
        else
        {
            printf("Dequed element = %d\n", front->data);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}
 
int frontelement()
{
    if ((front != NULL) && (rear != NULL))
        return(front->data);
    else
        return 0;
}
 
void empty()
{
     if ((front == NULL) && (rear == NULL))
        printf("Queue is empty\n");
    else
       printf("Queue is not empty\n");
}
