//
//  main.c
//  二叉查找树
//
//  Created by SSS on 2016/12/15.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include <mm_malloc.h>
typedef struct node{
    int element;
    struct node *left;
    struct node *right;
}node;
//插入
node *insert(node *Node,int key){
    node *p;
    if (Node==NULL) {
        p=(node *)malloc(sizeof(node));
        p->element=key;
        p->left=NULL;
        p->right=NULL;
    }
    else if(key==Node->element){
        p=Node;
    }
    else if(key>Node->element){
        if (Node->right==NULL) {
            p=(node *)malloc(sizeof(node));
            p->element=key;
            p->left=NULL;
            p->right=NULL;
            Node->right=p;
        }
        else p=insert(Node->right, key);
    }
    else {
        if (Node->left==NULL) {
            p=(node *)malloc(sizeof(node));
            p->element=key;
            p->left=NULL;
            p->right=NULL;
            Node->left=p;
        }
        else {
            p= insert(Node->left, key);
        }
    }
    return p;
}
//查找
node *search(node *node,int key){
    if (node==NULL) {
        return NULL;
    }
    else if (key>node->element){
        return search(node->right, key);
    }
    else if (key<node->element){
        return search(node->left, key);
    }
    return node;
}
//遍历
void mid(node *node){
    if (node!=NULL) {
        mid(node->left);
        printf("\t%d",node->element);
        mid(node->right);
    }
}
//销毁
void Destroy(node *node){
    if (node!=NULL) {
        Destroy(node->left);
        Destroy(node->right);
        free(node);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    node *tree;
    tree=insert(NULL, 23);
    insert(tree, 76);
    insert(tree, 12);
    insert(tree, 31);
    insert(tree, 90);
    insert(tree, 65);
    insert(tree, 49);
    insert(tree, 18);
    insert(tree, 58);
    insert(tree, 86);
    printf("tree:");
    mid(tree);
    printf("\nserch 76:");
    printf("\t%d\n",search(tree, 76)->element);
    Destroy(tree);
    return 0;
}
