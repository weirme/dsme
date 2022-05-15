#ifndef LinkedQueue_h
#define LinkedQueue_h

#include <stdio.h>
#include <stdlib.h>

typedef int LQElemType;

typedef struct node {
    LQElemType data;
    struct node *next;
} node;

typedef struct linkedQueue {
    node *front;
    node *rear;
} LQueue;


void LQinit(LQueue *q); // 初始化链队列

void LQdestory(LQueue *q); // 销毁链队列

void LQenter(LQueue *q, LQElemType x); // 入队

int LQexit(LQueue *q, LQElemType *e); // 出队

int LQgetFront(LQueue *q, LQElemType *e); // 取队头元素

int LQempty(LQueue *q); // 判空



void LQinit(LQueue *q) {
    node *t = (node*)malloc(sizeof(node));
    q->front = q->rear = t;
} // 初始化链队列

void LQdestory(LQueue *q) {
    node *t = q->front;
    while (q->front) {
        q->front = q->front->next;
        free(t);
        t = q->front;
    }
} // 销毁链队列

void LQenter(LQueue *q, LQElemType x) {
    node *t = (node*)malloc(sizeof(node));
    t->data = x;
    t->next = NULL;
    q->rear->next = t;
    q->rear = t;
} // 入队

int LQexit(LQueue *q, LQElemType *e) {
    if (q->front == q->rear) {
        printf("下溢错误\n");
        return 0;
    }
    node *p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if (!p->next) {
        q->rear = q->front;
    } // 判断出队操作前该队列长度是否为1，若为1则操作后形成空队列，尾指针将会丢失
    free(p);
    return 0;
} // 出队

int LQgetFront(LQueue *q, LQElemType *e) {
    if (q->front == q->rear) {
        printf("下溢错误\n");
        return 0;
    }
    *e = q->front->next->data;
    return 1;
} // 取队头元素

int LQempty(LQueue *q) {
    if (q->front == q->rear) {
        return 1;
    }
    return 0;
} // 判空

#endif /* LinkedQueue_h */
