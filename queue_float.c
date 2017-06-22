//
//  main.c
//  队列。。
//
//  Created by mac on 2016/12/13.
//  Copyright © 2016年 mac. All rights reserved.
//
#include <stdio.h>

#define QUEUE_SIZE 50

typedef struct SeqQueue
{
    int data[QUEUE_SIZE];
    int front;
    int rear;
    
}Queue;

Queue *InitQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if(q == NULL)
    {
        printf("Malloc failed!\n");
        exit(-1);
    }
    q->front = 0;
    q->rear = 0;
    
    return q;
}

int IsFull(Queue *q)
{
    return ((q->rear+1)%QUEUE_SIZE == q->front);
}

int IsEmpty(Queue *q)
{
    return (q->front == q->rear);
}

void Enqueue(Queue *q,int n)
{
    if(IsFull(q))
    {
        return;
    }
    q->data[q->rear] = n;
    q->rear = (q->rear+1)%QUEUE_SIZE;
}

int Dequeue(Queue *q)
{
    if(IsEmpty(q))
    {
        return 0;
    }
    
    int tmp = q->data[q->front];
    q->front = (q->front+1)%QUEUE_SIZE;
    return tmp;
}

void main()
{
    Queue *q = InitQueue();
    int i;
    for(i=0;i<10;i++)
    {
        Enqueue(q,i);
    }
    
    while(!IsEmpty(q))
    {
        int data = Dequeue(q);
        printf("%d->",data);
    }
}
