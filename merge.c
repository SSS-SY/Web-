//
//  main.c
//  归并排序
//
//  Created by mac on 2016/12/12.
//  Copyright © 2016年 mac. All rights reserved.
//
#include <stdio.h>
void mergeArray(int a[],int first,int mid,int last,int c[]){
    int i=first;
    int j=mid+1;
    int k=0;
    while (i<=mid&&j<=last) {
        if (a[i]<=a[j]) {
            c[k++]=a[i++];
        }
        else {
            c[k++]=a[j++];
        }
    }
    while (i<=mid) {
        c[k++]=a[i++];
    }
    while (j<=last) {
        c[k++]=a[j++];
    }
    for (int i=first; i<=last; i++) {
        a[i]=c[i-first];
    }
}
void mergeSort(int a[],int first,int last,int c[]){
    if (first<last) {
        int mid;
        mid=(first+last)/2;
        mergeSort(a,first,mid,c);
        mergeSort(a,mid+1,last,c);
        mergeArray(a,first,mid,last,c);
    }
}
int main(int argc, const char * argv[]){
    int a[]={10,32,4,65,78,2,54,18,34,57,20};
    int p[11];
    for (int i=0;i<11;i++) {
        printf(" a[%d]：%2d",i,a[i]);
    }
    printf("\n");
    mergeSort(a,0,10,p);
    for (int i=0;i<11;i++) {
        printf(" a[%d]：%2d",i,a[i]);
    }
    printf("\n");
    return 0;
}
