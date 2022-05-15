#ifndef Sqlist_h
#define Sqlist_h

#include <stdio.h>
#include <stdlib.h>

#define SLMAX 100
typedef int SLElemType;

typedef struct sqlist {
    SLElemType *data;
    int length;
    int listSize;
} sqlist;


void SLinit(sqlist *L); // 初始化顺序表

int SLempty(sqlist *L); // 判空

int SLoutput(sqlist *L); // 输出顺序表

int SLgetLen(sqlist *L); // 获取表中元素个数

int SLgetElem(sqlist *L, int i, SLElemType *e); // 取第i个元素的值

int SLlocate(sqlist *L, SLElemType x); // 查找第一个与x值相等的元素

int SLsearchWithSentry(sqlist *L, int x);// 查找第一个与x值相等的元素（设置哨兵）

int SLinsert(sqlist *L, int i, SLElemType x); // 在第i个位置上插入一个值为x的元素

int SLdelete(sqlist *L, int i, SLElemType *e); // 删除在第i个位置上的元素

int SLbinSearch(sqlist *L, int x); // 折半查找的非递归算法

int SLbinSearch2(sqlist *L, int x, int first, int end); // 折半查找的递归算法



void SLinit(sqlist *L) {
    L->data = (SLElemType*)malloc(sizeof(SLElemType)*SLMAX);
    L->length = 0;
    L->listSize = SLMAX;
} // 初始化顺序表

int SLempty(sqlist *L) {
    if (L->length) {
        return 0;
    }
    return 1;
} // 判空

int SLoutput(sqlist *L) {
    if (!L->length) {
        return 0;
    }
    for (int i = 0; i < L->length; i++) {
        printf("%5i",L->data[i]); // 根据具体的数据类型更改
    }
    printf("\n");
    return 1;
} // 输出顺序表

int SLgetLen(sqlist *L) {
    return L->length;
} // 获取表中元素个数

int SLgetElem(sqlist *L, int i, SLElemType *e) {
    if (i < 1 || i > L->length) {
        printf("位置错误\n");
        return 0;
    }
    *e = L->data[i-1];
    return 1;
} // 取第i个元素的值

int SLlocate(sqlist *L, SLElemType x) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == x) {
            return i;
        }
    }
    return 0;
} // 查找第一个与x值相等的元素

int SLsearchWithSentry(sqlist *L, int x) {
    L->data[L->length] = x;
    int i = 0;
    while (L->data[i] != x) i++;
    if (i < L->length) {
        return i;
    }
    return 0;
} // 查找第一个与x值相等的元素（设置哨兵）

int SLinsert(sqlist *L, int i, SLElemType x) {
    if (L->length == SLMAX) {
        printf("上溢错误\n");
        return 0;
    }
    if (i < 1 || i > L->length) {
        printf("位置错误\n");
        return 0;
    }
    L->data = (SLElemType*)realloc(L->data, sizeof(SLElemType)*(L->listSize+1));
    for (int j = L->length-1; j >= i-1; j--) {
        L->data[j+1] = L->data[j];
    }
    L->data[i-1] = x;
    L->length ++;
    return 1;
} // 在第i个位置上插入一个值为x的元素

int SLdelete(sqlist *L, int i, SLElemType *e) {
    if (L->length == 0) {
        printf("下溢错误\n");
        return 0;
    }
    if (i < 1 || i > L->length) {
        printf("位置错误\n");
        return 0;
    }
    *e = L->data[i-1];
    for (int j = i; j < L->length; j++) {
        L->data[j-1] = L->data[j];
    }
    L->length --;
    return 1;
} // 删除在第i个位置上的元素

int SLbinSearch(sqlist *L, int x) {
    int first = 0, end = L->length-1;
    while (first <= end) {
        int mid = (first+end)/2;
        if (L->data[mid] == x) return mid;
        if (L->data[mid] < x) end = mid-1;
        if (L->data[mid] > x) first = mid+1;
    }
    return -1;
} // 折半查找的非递归算法

int SLbinSearch2(sqlist *L, int x, int first, int end) {
    if (first > end) {
        return -1;
    }
    int mid = (first+end)/2;
    if (L->data[mid] == x) return mid;
    if (L->data[mid] < x) return SLbinSearch2(L, x, first, mid-1);
    if (L->data[mid] > x) return SLbinSearch2(L, x, mid+1, end);
    return -1;
} // 折半查找的递归算法

#endif /* Sqlist_h */
