/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/
#include <stdio.h>

#define MAX 100

int queue[MAX];
int stack[MAX];
int front = 0, rear = -1;
int top = -1;

void enqueue(int value) {
    queue[++rear] = value;
}

int dequeue() {
    return queue[front++];
}

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int main() {

    int n, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    for(int i = front; i <= rear; i++) {
        push(queue[i]);
    }

    front = 0;
    rear = -1;

    while(top != -1) {
        enqueue(pop());
    }

    printf("Reversed queue:\n");

    for(int i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    return 0;
}