//
//  main.c
//  heap
//
//  Created by SSS on 2016/12/15.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
//调整
void Adjust(int a[],int father,int size){
    int left=2*father;
    int right=left+1;
    int max=father;
    if (father<=size/2) {
        if (left<size&&a[max]>a[left]) {
            max=left;
        }
        if (right<size&&a[max]>a[right]) {
            max=right;
        }
        if (max!=father) {
            int j=a[father];
            a[father]=a[max];
            a[max]=j;
            Adjust(a, max, size);//避免以max为父节点的不是堆
        }
    }
}
//排序
void sort(int a[],int size){
    int i;
    //建最小堆
    for (i=size/2; i>0; i--) {
        Adjust(a,i,size);
    }
    //排序
    for (i=size-1;i>0;i--) {
        int j=a[0];
        a[0]=a[i];
        a[i]=j;
        Adjust(a,0,i-1);
    }
}
int main(int argc, const char * argv[]) {
    int a[]={18,35,54,63,76,29,47};
    printf("Before:");
    for (int i=0; i<7; i++) {
        printf("%d\t",a[i]);
    }
    sort(a, 7);
    printf("\nAfter:");
    for (int i=0; i<7; i++) {
        printf("%d\t",a[i]);
    }
    printf("\n");
    return 0;
}
