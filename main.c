//
//  main.c
//  快速排序
//
//  Created by mac on 2016/12/12.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <mm_malloc.h>

int array[]={1,2,3,4,5,6,7,8,9,10};
typedef struct node{
    int element;
    struct node *privious,*next;
}node;
//创建
node *create(node *head){
    int i=0;
    node *new,*now;
    now=head;
    now->element=array[i];
    i++;
    new=(node *)malloc(sizeof(node));
    for (;i<10; i++) {
        new->element=array[i];
        new->next=NULL;
        if (now==NULL) {
            now=new;
        }
        else{
            now->next=new;
            new->privious=now;
        }
        now=new;
        new=(node *)malloc(sizeof(node));
    }
    head->privious=now;
    now->next=head;
    return head;
}
//遍历
void printList(node *head){
    node *p1=head;
    if (p1 ==NULL) {
        printf("链表为空\n");
    }
    else{
        int i=1;
        while (p1!=NULL) {
            printf("第%d个节点元素值：%d \n",i,p1->element);
            p1=p1->next;
            i++;
        }
        printf("\n");
    }
}
//插入
void insert(node *head,int position,int num){
    node *p1,*p2,*p3;
    p1=(node *)malloc(sizeof(node));
    p1->element=num;
    p2 =head;
    position--;
    while (position!=1) {
        position--;
        p2=p2->next;
    }
    p3=p2->next;
    p2->next=p1;
    p1->next=p3;
}
//删除
void delete(node *head,int num){
    node *p1,*p2;
    p1 = p2 = head;
    while (p1->element!=num) {
        p2=p1;
        p1=p1->next;
    }
    p2->next=p1->next;
    free(p1);
}
int main(int argc, const char * argv[]) {
    node *Head;
    Head = (node *)malloc(sizeof(node));
    printf("初始化：\n");
    create(Head);
    printList(Head);
    printf("插入：\n");
    insert(Head,3,100);
    printList(Head);
    printf("删除：\n");
    delete(Head,9);
    printList(Head);
    return 0;
}
