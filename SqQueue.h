#ifndef SqQueue_h
#define SqQueue_h

#include <stdio.h>
#include <stdlib.h>

#define SQMAX 100
typedef int SQElemType;

typedef struct queue {
    SQElemType data[SQMAX];
    int front;
    int rear;
} queue;

void SQinit(queue *q); // 初始化队列

int SQenter(queue *q, SQElemType x); // 入队

int SQexit(queue *q, SQElemType *e); // 出队

int SQgetFront(queue *q, SQElemType *e); // 取队头元素

int SQempty(queue *q); // 判空



void SQinit(queue *q) {
    q->front = q->rear = SQMAX-1;
} // 初始化队列

int SQenter(queue *q, SQElemType x) {
    if ((q->rear+1)%SQMAX == q->front) {
        printf("上溢错误\n");
        return 0;
    }
    q->rear = (q->rear+1)%SQMAX;
    q->data[q->rear] = x;
    return 1;
} // 入队

int SQexit(queue *q, SQElemType *e) {
    if (q->rear == q->front) {
        printf("下溢错误\n");
        return 0;
    }
    *e = q->data[q->front];
    q->front = (q->front+1)%SQMAX;
    return 1;
} // 出队

int SQgetFront(queue *q, SQElemType *e) {
    if (q->rear == q->front) {
        printf("下溢错误\n");
        return 0;
    }
    *e = q->data[q->front];
    return 1;
} // 取队头元素

int SQempty(queue *q) {
    if (q->rear == q->front) {
        return 1;
    }
    return 0;
} // 判空

#endif /* SqQueue_h */
