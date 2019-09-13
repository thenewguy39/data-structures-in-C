#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 20
int stack[SIZE];

int top = -1;

void push(int element);
int  pop();
int isEmpty();
int isFull();


int main()
{
    int choice, data;


    while(1)
    {
        printf("STACK IMPLEMENTATION USING ARRAYS \n");
        printf("Options: \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Is Full\n");
        printf("4. Is Empty\n");
        printf("5. Exit\n");
        printf("Choose an option:\n ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to push into stack : ");
                scanf("%d", &data);

                push(data);
                break;

            case 2:
                data = pop();

                if (data != INT_MIN)
                    printf("Value popped : %d\n", data);
                break;

            case 3:
                if(isFull())
                    printf("Stack is full.\n");
                else
                    printf("Stack is not full.\n");
                break;

            case 4:
                if(isEmpty())
                    printf("Stack is empty.\n");
                else
                    printf("Stack is not empty.\n");
                break;

            case 5:
                printf("Program closed.\n");
                exit(0);

            default:
                printf("Invalid option.Please try again.\n");
        }

        printf("\n\n");
    }


    return 0;
}



void push(int element)
{
    if (top >= SIZE)
    {
        printf("Stack Overflow.\n");
        return;
    }

    top++;

    stack[top] = element;

    printf("Data pushed to stack.\n");
}



int pop()
{
    if (top < 0)
    {
        printf("Stack is empty.\n");

        return INT_MIN;
    }


    return stack[top--];
}


int isFull()
{
    if(top >= SIZE)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}
 
