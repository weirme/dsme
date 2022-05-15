#ifndef SinglyLinkedList_h
#define SinglyLinkedList_h

#include <stdio.h>
#include <stdlib.h>

typedef int SLLElemType;

typedef struct node {
    SLLElemType data;
    struct node *next;
} node;


node* SLLalloc(void); // 分配单链表

node* SLLinit(node *first,int n); // 初始化单链表

int SLLempty(node *first); // 判空

int SLLoutput(node *first); // 输出链表

int SLLgetLen(node *first); // 获取链表长度

int SLLlocate(node *first, SLLElemType x); // 按值查找

int SLLget(node *first, int i, SLLElemType *e); // 按位查找

int SLLinsert(node **first, int i, SLLElemType x); // 插入结点

int SLLdelete(node **first, int i, SLLElemType *e); // 删除结点

node* SLLcreate_head(SLLElemType a[], int n); // 头插法建立单链表

node* SLLcreate_tail(SLLElemType a[], int n); // 尾插法建立单链表（较头插法多定义一个tail指针）

node* SLLreserve(node *first); // 逆置链表

node* SLLsort(node *first); // 冒泡法排序链表

node* SLLsameDelete(node *first); // 删除链表中数值相同的结点

void SLLdestory(node *first); // 释放链表



node* SLLalloc(){
    node *first = (node*)malloc(sizeof(node));
    first->next = NULL;
    return first;
} // 分配单链表

node* SLLinit(node *first,int n) {
    first = (node*)malloc(sizeof(node));
    first->next = NULL;
    node *p = first, *t = NULL;
    for (int i = 0; i < n; i++) {
        t = (node*)malloc(sizeof(node));
        printf("输入第%i个数据：\n",i+1);
        scanf("%i",&t->data);
        p->next = t;
        p = p->next;
    }
    p->next = NULL;
    return first;
} // 初始化单链表

int SLLempty(node *first) {
    if (first->next) {
        return 0;
    }
    return 1;
} // 判空

int SLLoutput(node *first) {
    if (!first || !first->next) {
        return 0;
    }
    node *p = first->next;
    printf("输出：\n");
    while (p) {
        printf("%i ",p->data);
        p = p->next;
    }
    return 1;
} // 输出链表

int SLLgetLen(node *first) {
    int count = 0;
    node *p = first->next;
    while (p) {
        p = p->next;
        count++;
    }
    return count;
} // 获取链表长度

int SLLlocate(node *first, SLLElemType x) {
    node *p = first->next;
    int i = 1;
    while (p) {
        if (p->data == x) {
            return i;
        }
        p = p->next;
        i++;
    }
    return 0;
} // 按值查找

int SLLget(node *first, int i, SLLElemType *e) {
    node *p = first->next;
    int count = 1;
    while (p && count < i) {
        p = p->next;
        count++;
    }
    if (!p) {
        return 0;
    }
    *e = p->data;
    return 1;
} // 按位查找

int SLLinsert(node **first, int i, SLLElemType x) {
    node *p = (*first)->next;
    int count = 1;
    while (p && count < i) {
        p = p->next;
        count++;
    }
    if (!p) {
        return 0;
    }
    node *t = (node*)malloc(sizeof(node));
    t->data = x;
    t->next = p->next;
    p->next = t;
    return 1;
} // 插入结点

int SLLdelete(node **first, int i, SLLElemType *e) {
    node *p = *first;
    node *q = NULL;
    int count = 1;
    while (p && count < i) {
        p = p->next;
        count++;
    }
    if (p == NULL || p->next == NULL) {
        return 0;
    }
    q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return 1;
} // 删除结点

node* SLLcreate_head(SLLElemType a[], int n) {
    node *first = (node*)malloc(sizeof(node));
    first->next = NULL;
    node *temp = NULL;
    for (int i = n-1; i >= 0; i--) {
        temp = (node*)malloc(sizeof(node));
        temp->data = a[i];
        temp->next = first->next;
        first->next = temp;
    }
    return first;
} // 头插法建立单链表

node* SLLcreate_tail(SLLElemType a[], int n) {
    node *first = (node*)malloc(sizeof(node));;
    node *tail = NULL, *temp = NULL;
    tail = first;
    for (int i = 0; i < n; i++) {
        temp = (node*)malloc(sizeof(node));
        temp->data = a[i];
        tail->next = temp;
        tail = temp;
    }
    tail->next = NULL;
    return first;
} // 尾插法建立单链表（较头插法多定义一个tail指针）

node* SLLreserve(node *first) {
    node *pre = NULL, *p = first->next, *t = NULL;
    while (p) {
        t = p->next;
        p->next = pre;
        pre = p;
        p = t;
    }
    first->next = pre;
    return first;
} // 逆置链表

node* SLLsort(node *first) {
    if (!first->next) {
        return NULL;
    }
    node *p = first->next, *pre = NULL, *t = NULL;
    int length = SLLgetLen(first);
    int i, j;
    for (i = 0; i < length; i++) {
        pre = first;
        p = pre->next;
        for (j = 0; j < length-i-1; j++) {
            if (p->data > p->next->data) {
                t = p->next;
                p->next = t->next;
                pre->next = t;
                t->next = p;
                pre = t;
            }
            else {
                pre = p;
                p = p->next;
            }
        }
    }
    return first;
} // 冒泡法排序链表

node* SLLsameDelete(node *first) {
    node *q = first->next, *pre = q, *p = q->next;
    while (q) {
        pre = q;
        p = pre->next;
        while (p) {
            if (p->data == q->data) {
                pre->next = p->next;
                free(p);
                p = pre->next;
            }
            else {
                pre = p;
                p = p->next;
            }
        }
        q = q->next;
    }
    return first;
} // 删除链表中数值相同的结点

void SLLdestory(node *first) {
    node *p = first;
    while (first) {
        first = first->next;
        free(p);
        p = first;
    }
    return;
} // 释放链表

#endif /* SinglyLinkedList_h */
