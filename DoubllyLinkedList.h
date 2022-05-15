#ifndef DoubllyLinkedList_h
#define DoubllyLinkedList_h

#include <stdio.h>
#include <stdlib.h>

typedef int DLLElemType;

typedef struct dulNode {
    struct dulNode *prior;
    DLLElemType data;
    struct dulNode *next;
} dulNode;


dulNode* DLLalloc(void);// 初始化双链表

int DLLinsert(dulNode **first, int i, DLLElemType x); // 插入元素

int DLLdelete(dulNode **first, int i, DLLElemType *e); // 删除元素



dulNode* DLLalloc() {
    dulNode *first = (dulNode*)malloc(sizeof(dulNode));
    first->prior = NULL;
    first->next = NULL;
    return first;
} // 初始化双链表

int DLLinsert(dulNode **first, int i, DLLElemType x) {
    int count = 1;
    dulNode *p = (*first)->next;
    dulNode *t = NULL;
    while (p && count < i-1) {
        p = p->next;
        count++;
    }
    if (!p) {
        return 0;
    }
    t = (dulNode*)malloc(sizeof(dulNode));
    t->data = x;
    t->prior = p;
    t->next = p->next;
    p->next->prior = t;
    p->next = t;
    return 1;
} // 插入元素

int DLLdelete(dulNode **first, int i, DLLElemType *e) {
    int count = 1;
    dulNode *p = (*first)->next;
    while (p && count < i) {
        p = p->next;
        count++;
    }
    if (!p) {
        return 0;
    }
    *e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return 1;
} // 删除元素

#endif /* DoubllyLinkedList_h */
