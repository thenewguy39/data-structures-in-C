#include <stdio.h>
 
#define MAX 50
 
void insert();
void delete();
void display();
void count();
int isunderflow();
int isoverflow();

int queue_array[MAX];
int rear = - 1;
int front = - 1;

main()
{
    int choice;
    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements in queue \n");
        printf("4.Count number of elements in queue \n");
        printf("5.Quit \n");
        printf("Enter your choice : \n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            count();
            case 5:
            exit(1);
            default:
            printf("Invalid choice \n");
        } 
    } 
} 
 
void insert()
{
    int add_item;
    if (isoverflow())
    	printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        	front = 0;
        printf("Enter element to be inserted in queue : \n");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}
 
void delete()
{
    if (isunderflow())
        printf("Queue Underflow \n");
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
} 
 
void display()
{
    int i;
    if (isunderflow())
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}

void count(){
	int res;
	if(isunderflow())
		res = 0;
	else
		res = rear - front + 1;
	printf("Number of elements in queue is = %d\n",res);
}

int isunderflow(){
    if (front == - 1 || front > rear)
    	return 1;
    else
    	return 0;
}

int isoverflow(){
	if (rear == MAX - 1)
		return 1;
	else
		return 0;
}
