//
//  main.c
//  1
//
//  Created by mac on 2016/12/14.
//  Copyright © 2016年 mac. All rights reserved.
//
#define Succeed 1
#define Fail 0
#include <mm_malloc.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
typedef struct Bucket{
    char *key;
    void *value;
    struct Bucket *next;
}Bucket;
typedef struct HashTable{
    int size;
    int ele_num;
    Bucket **buckets;
}HashTable;
//初始化
int init(HashTable *ht){
    ht->size=7;
    ht->ele_num=0;
    ht->buckets=(Bucket **)malloc(sizeof(Bucket));
    if (ht->buckets==NULL) {
        return Fail;
    }
    else {
        return Succeed;
    }
}
//确定索引
int Index(HashTable *ht,char *key){
    int hash=0;
    while (*key!='\0') {
        hash=hash+(int)*key;
        key++;
    }
    return hash%(ht->size);
}
//插入
int Insert(HashTable *ht,char *key,void *value){
    int index = Index(ht, key);
    Bucket *p1,*p2;
    p1=p2=ht->buckets[index];
    while (p1) {
        if (strcmp(p1->key, key)==0) {
            p1->value=value;
            return  Succeed;
        }
        p1=p1->next;
    }
    Bucket *new =(Bucket *)malloc(sizeof(Bucket));
    if (new==NULL) {
        return Fail;
    }
    new->key=key;
    new->value=value;
    new->next=NULL;
    ht->ele_num++;
    if (p2) {
        new->next=p2;
    }
    ht->buckets[index]=new;
    return Succeed;
}
//查找
int Lookup(HashTable *ht,char *key,void **result){
    int index=Index(ht, key);
    Bucket *bucket=ht->buckets[index];
    while (bucket) {
        if (strcmp(bucket->key, key)==0) {
            *result=bucket->value;
            return Succeed;
        }
        bucket = bucket->next;
    }
    return Fail;
}
//删除
int Remove(HashTable *ht, char *key){
    int index = Index(ht,key);
    Bucket *front,*rear,*curent;
    front=NULL;
    curent=ht->buckets[index];
    while (curent) {
        if (strcmp(curent->key, key)) {
            rear =curent->next;
            if (front==NULL) {
                ht->buckets[index]=rear;
            } else {
                front->next=rear;
            }
            free(curent);
            return Succeed;
        }
        front=curent;
        curent=curent->next;
    }
    return Fail;
}
//销毁
int Destroy(HashTable *ht){
    Bucket *temp,*current;
    current=temp=NULL;
    for (int i=0; i< ht->size; i++) {
        current=ht->buckets[i];
        while (current) {
            temp=current->next;
            free(current);
            current=temp;
        }
    }
    free(ht->buckets);
    return Succeed;
}
int main(int argc, char **argv)
{
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    int result = init(ht);
    assert(result == Succeed);
    int int1 = 10;
    int int2 = 20;
    char str1[] = "Hello World!";
    char str2[] = "Value";
    char str3[] = "Hello New World!";
    int *j = NULL;
    char *find_str = NULL;
    printf("insert Key1:FirstInt\n");
    Insert(ht, "FirstInt", &int1);
    printf("insert Key2:SecendInt\n");
    Insert(ht, "SecendInt", &int2);
    printf("insert Key3:FirstStr\n");
    Insert(ht, "FirstStr", str1);
    printf("insert Key4:SecendStr\n");
    Insert(ht, "SecnedStr", str2);
    printf("Key Lookup FirStr:\n");
    result = Lookup(ht, "FirstStr", &find_str);
    assert(result == Succeed);
    printf("the value is %s\n", find_str);
    printf("Key Update:change %s to %s\n",str1,str3);
    Insert(ht, "FirstStr", str3);
    result = Lookup(ht, "FirstStr", &find_str);
    assert(result == Succeed);
    printf("After Update,the value of FirstStr is %s\n", find_str);
    printf("delete FirstInt\n");
    Remove(ht, "FrstInt");
    printf("Destroy HashTable\n");
    Destroy(ht);
    return 0; 
}
