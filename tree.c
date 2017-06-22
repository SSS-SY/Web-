//
//  main.c
//  tree
//
//  Created by mac on 2016/12/5.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    char element;
    struct node *left;
    struct node *right;
}node;
//由先序遍历和中序遍历构建树
void pre_mid_Creat(node *Root,char pre[],char mid[],int pre_first,int pre_last,int mid_first,int mid_last){
    Root=(node *)malloc(sizeof(node));
    Root->element=pre[pre_first];
    Root->left=NULL;
    Root->right=NULL;
    printf("%c\t",Root->element);
    int position=mid_first;
    printf("\n%d ",position);
    //查找根节点位置
    while (mid[position]!=pre[pre_first]) {
        position++;
    }
    int left_size=position-mid_first;
    if (position>mid_first) {
        pre_mid_Creat(Root->left, pre, mid, pre_first+1, pre_first+left_size,mid_first, position-1);
    }
    if (position<mid_last) {
        pre_mid_Creat(Root->right, pre, mid, pre_first+left_size+1,pre_last,position+1, mid_last);
    }
}
//由中序遍历和后序遍历构建树
void mid_last_Creat(node *Root,char mid[],char last[],int mid_first,int mid_last,int last_first,int last_last){
    Root=(node *)malloc(sizeof(node));
    Root->element=last[last_last];
    Root->left=NULL;
    Root->right=NULL;
    printf("%c\t",Root->element);
    int position=mid_first;
    //查找根节点位置
    while (mid[position]!=last[last_last]) {
        position++;
    }
    int left_size=position-mid_first;
    if (position>mid_first) {
        mid_last_Creat(Root->left, mid, last, mid_first, position-1, last_first, last_first-left_size+1);
    }
    if (position<mid_last) {
        mid_last_Creat(Root->right, mid, last, position+1, mid_last, last_first+left_size, last_last-1);
    }
}
//先序遍历
void pre(node *root){
    if (root!=NULL) {
        printf("%c\t",root->element);
        pre(root->left);
        pre(root->right);
    }
}
//中序遍历
void mid(node *root){
    if (root!=NULL){
        mid(root->left);
        printf("%c\t",root->element);
        mid(root->right);
    }
}
//后序遍历
void last(node *root){
    if (root!=NULL){
        last(root->left);
        last(root->right);
        printf("%c\t",root->element);
    }
}

int main(int argc, const char * argv[]) {
    node *Root;
    char preResult[]={'A','B','D','E','H','C','G','F','I','J','K'};
    char midResult[]={'D','B','H','E','A','G','C','I','F','J','K'};
    char lastResult[]={'D','H','E','B','G','I','K','J','F','C','A'};
    mid_last_Creat(Root, midResult, lastResult, 0, 10, 0, 10);
    pre(Root);
    pre_mid_Creat(Root, preResult, midResult, 0, 10, 0, 10);
    last(Root);
    printf("\n");
    return 0;
}
