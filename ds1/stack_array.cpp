#include<iostream>
#define STACK_MAX 10

//  Last-In-First-Out (LIFO) principle

/*
Push: Adds an element to the top of the stack.
Pop: Removes the top element from the stack.
Peek: Returns the top element without removing it.
IsEmpty: Checks if the stack is empty.
IsFull: Checks if the stack is full (in case of fixed-size arrays).

*/
int stack_arr[100];

int top = 0;

void push(int x);
void pop();
int peek();
int IsEmpty();
int IsFull();
void printStack();

int main()
{

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    
    printStack();

    printf("Popping one element out ...\n");
    pop();

    printStack();

    return 0;
}

void push(int x)
{
    stack_arr[++top] = x;
}

void pop()
{
    --top;
}

int peek()
{    
    return stack_arr[top];
}

int IsEmpty()
{

    return top<=0;
}
int IsFull(){

    return !(top>=STACK_MAX);
}
void printStack()
{
    printf("Printing the Current Stack:- \n");
    int i =top;
    for(;i>=1;i--)
        printf("%d \n",stack_arr[i]);
}
