//
//  main.c
//  栈
//
//  Created by mac on 2016/12/13.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <mm_malloc.h>
typedef struct node{
    int element;
    struct node *next;
}Node;
//定义一个栈
typedef struct stack{
    Node *top;//栈顶
    Node *bottom;//栈底
}Stack;
//初始化一个栈
void init(Stack *stack){
    stack->bottom=stack->top=NULL;
}
//进栈
int Push(Stack *stack,int num){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode==NULL) {
        return 0;
    }
    newNode->element=num;
    newNode->next=stack->top;
    stack->top=newNode;
    return 1;
}
//判断栈是否为空
int EmptyStack(Stack *stack){
    if (stack->bottom==stack->top) {
        return 0;
    }
    else{
        return 1;
    }
}
//遍历栈元素
void traverse(Stack *stack){
    Node *newNode=stack->top;
    while (newNode!=NULL) {
        printf("%d\t",newNode->element);
        newNode=newNode->next;
    }
}
//出栈
int Pop(Stack *stack){
    Node *freeTop;
    int pop_num;
    if (EmptyStack(stack)==0) {
        exit(-1);
    }
    else {
        freeTop=stack->top;
        pop_num=stack->top->element;
        stack->top=stack->top->next;
        free(freeTop);
        return pop_num;
    }
    
}
//清空栈
void Clear(Stack *stack){
    Node *newNode =NULL;
    while (stack->bottom!=stack->top) {
        newNode=stack->top;
        stack->top=stack->top->next;
        free(newNode);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    Stack *stack;
    stack=(Stack *)malloc(sizeof(Stack));
    init(stack);
    for (int i=0; i<10; i++) {
        Push(stack, 20*i);
    }
    traverse(stack);
    printf("\n出栈：");
    for (int i=0; i<5; i++) {
        printf("%d\t",Pop(stack));
    }
    printf("\n剩余：");
    traverse(stack);
    printf("\n清除");
    Clear(stack);
    traverse(stack);
    printf("\n");
    return 0;
}
