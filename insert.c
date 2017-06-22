//
//  main.c
//  插入排序
//
//  Created by mac on 2016/12/5.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>

void insert(int *data,int size);
int main(){
    int data[]={0,23,4,13,77,59,38,49};
    int n=sizeof(data)/sizeof(data[0]);
    insert(data,n);
    return 0;
}
void insert(int *data,int size){
    int i,j,k,pass,temp;
    pass=0;
    printf("\n0:");
    for (i=0; i<size;i++) {
        if (i==0) {
            printf(" [%d]",data[i]);
        }else
        printf(" %d",data[i]);
    }
    for (i=1;i<size;i++) {
        temp=data[i];
        for (j=i-1;data[j]>temp;j--) {
            data[j+1]=data[j];
        }
        data[j+1]=temp;
        pass++;
        printf("\n%d:",pass);
        for (k=0;k<size;k++) {
            if (k==0) {
                printf(" [%d",data[k]);
            }
            else if(k==i){
                printf(" %d]",data[k]);
            }
            else printf(" %d",data[k]);
        }
    }
}
