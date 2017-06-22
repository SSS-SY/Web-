//
//  main.c
//  队列
//
//  Created by mac on 2016/12/13.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include <mm_malloc.h>
typedef struct node{
    int element;
    struct node *next;
}node;
typedef struct queue{
    node *front;
    node *rear;
}queue;
void init(queue *queue){
    queue->front=queue->rear=NULL;
}
int emptyQueue(queue *queue){
    if (queue->front==NULL) {
        return 0;
    }
    else {
        return 1;
    }
}
void Clear(queue *queue){
    node *now;
    node *new;
    now=queue->front;
    init(queue);
    while (now!=NULL) {
        new=now;
        now=now->next;
        free(new);
    }
}
int length(queue *queue){
    int i=0;
    node *now;
    now=queue->front;
    while (now!=NULL) {
        i++;
        now=now->next;
    }
    return i;
}
void insert(queue *queue,int num){
    node *new=(node *)malloc(sizeof(node));
    if (new==NULL) {
        exit(-1);
    }
    new->element=num;
    new->next=NULL;
    if (queue->rear==NULL) {
        queue->front=queue->rear=new;
    }
    else{
        queue->rear->next=new;
        queue->rear=new;
    }
}
void delete(queue *queue){
    node *new;
    if (emptyQueue(queue)==0) {
        printf("\nEmpty，can't delete");
    }
    else {
        new=queue->front;
        queue->front=new->next;
        printf("\t%d",new->element);
        free(new);
    }
}
void traverse(queue *queue){
    node *node;
    node=queue->front;
    while (node!=NULL) {
        printf("\t%d",node->element);
        node=node->next;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    queue *Q;
    Q=(queue *)malloc(sizeof(queue));
    init(Q);
    for (int i=0; i<10; i++) {
        insert(Q, 2*i);
    }
    printf("长度：%d",length(Q));
    printf("\n从队尾遍历：");
    traverse(Q);
    printf("\n出队：");
    for (int i=0; i<5; i++) {
        delete(Q);
    }
    printf("\n遍历：");
    traverse(Q);
    printf("\n清除并检查：");
    Clear(Q);
    traverse(Q);
    printf("\n");
    return 0;
}
