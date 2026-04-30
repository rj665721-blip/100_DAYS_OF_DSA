// A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

#include <stdio.h>
#define MAX 100


int deque[MAX];
int front = -1;

void insertFront(int x)
{
    if(front == -1)
    {
        front = 0;
        deque[front] = x;
    }
    else if(front > 0)
    {
        front--;
        deque[front] = x;
    }
    else
    {
        printf("Deque is full at the front end.\n");
    }
}

void insertRear(int x)
{
    if(front == -1)
    {
        front = 0;
        deque[front] = x;
    }
    else if(front + 1 < MAX)
    {
        front++;
        deque[front] = x;
    }
    else
    {
        printf("Deque is full at the rear end.\n");
    }
}

void deleteFront()
{
    if(front == -1)
    {
        printf("Deque is empty.\n");
    }
    else
    {
        printf("Deleted from front: %d\n", deque[front]);
        if(front == 0)
            front = -1; // Deque becomes empty
        else
            front--;
    }
}

void deleteRear()
{
    if(front == -1)
    {
        printf("Deque is empty.\n");
    }
    else
    {
        printf("Deleted from rear: %d\n", deque[front]);
        if(front == 0)
            front = -1; // Deque becomes empty
        else
            front--;
    }
}

void peekFront()
{
    if(front == -1)
    {
        printf("Deque is empty.\n");
    }
    else
    {
        printf("Front element: %d\n", deque[front]);
    }
}

void peekRear()
{
    if(front == -1)
    {
        printf("Deque is empty.\n");
    }
    else
    {
        printf("Rear element: %d\n", deque[0]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    char op[20];
    int x;
    for(int i = 0; i < n; i++)
    {
        scanf("%s", op);
        if(strcmp(op, "insertFront") == 0)
        {
            scanf("%d", &x);
            insertFront(x);
        }
        else if(strcmp(op, "insertRear") == 0)
        {
            scanf("%d", &x);
            insertRear(x);
        }
        else if(strcmp(op, "deleteFront") == 0)
        {
            deleteFront();
        }
        else if(strcmp(op, "deleteRear") == 0)
        {
            deleteRear();
        }
        else if(strcmp(op, "peekFront") == 0)
        {
            peekFront();
        }
        else if(strcmp(op, "peekRear") == 0)
        {
            peekRear();
        }
    }
    return 0;
}

