#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *ptr;
}*top,*top1,*temp;
 
int topelement();
void push(int val);
void pop();
void empty();
void display();
void destroy();
void stack_count();
void create();
 
int count = 0;
 
void main()
{
    int no, ch, e;
 
    printf(" 1 - Push element in stack\n");
    printf(" 2 - Pop element from stack\n");
    printf(" 3 - Show top element of stack\n");
    printf(" 4 - Check if stack is empty\n");
    printf(" 5 - Exit\n");
    printf(" 6 - Display stack\n");
    printf(" 7 - Count number of elements in stack\n");
    printf(" 8 - Destroy stack\n");
 
    create();
 
    while (1)
    {
        printf("Enter choice : \n");
        scanf("%d", &ch);
        
        switch (ch)
        {
        case 1:
            printf("Enter data : \n");
            scanf("%d", &no);
            push(no);
            break;
        case 2:
            pop();
            break;
        case 3:
            if (top == NULL)
                printf("No elements in stack\n");
            else
            {
                e = topelement();
                printf(" Top element : %d\n", e);
            }
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
            stack_count();
            break;
        case 8:
            destroy();
            break;
        default :
            printf(" Invalid choice \n");
            break;
        }
    }
}
 
void create()
{
    top = NULL;
}
 
void stack_count()
{
    printf("No. of elements in stack : %d\n", count);
}
 
void push(int val)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->data = val;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->data = val;
        top = temp;
    }
    count++;
}
 
void display()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
 
    while (top1 != NULL)
    {
        printf("%d\n", top1->data);
        top1 = top1->ptr;
    }
}
 
void pop()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("Stack is empty \n");
        return;
    }
    else
        top1 = top1->ptr;
    printf("Popped value : %d\n", top->data);
    free(top);
    top = top1;
    count--;
}
 
int topelement()
{
    return(top->data);
}
 
void empty()
{
    if (top == NULL)
        printf("Stack is empty \n");
    else
        printf("Stack is not empty \n");
}
 
void destroy()
{
    top1 = top;
 
    while (top1 != NULL)
    {
        top1 = top->ptr;
        free(top);
        top = top1;
        top1 = top1->ptr;
    }
    free(top1);
    top = NULL;
 
    printf("Stack destroyed \n");
    count = 0;
}
