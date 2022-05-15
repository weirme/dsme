#ifndef SqStack_h
#define SqStack_h

#include <stdio.h>
#include <stdlib.h>

#define SSMAX 100
typedef int SSElemType;

typedef struct SqStack {
    SSElemType data[SSMAX];
    int top;
} SqStack;


void SSinit(SqStack *s); // 初始化栈

int SSpush(SqStack *s, SSElemType x); // 入栈

int SSpop(SqStack *s, SSElemType *e); // 出栈

int SSgetTop(SqStack *s, SSElemType *e); // 取栈顶元素

int SSempty(SqStack *s); // 判空



void SSinit(SqStack *s) {
    s->top = -1;
} // 初始化栈

int SSpush(SqStack *s, SSElemType x) {
    if (s->top+1 == SSMAX) {
        printf("上溢错误\n");
        return 0;
    }
    s->data[++s->top] = x;
    return 1;
} // 入栈

int SSpop(SqStack *s, SSElemType *e) {
    if (s->top == -1) {
        printf("下溢错误\n");
        return 0;
    }
    *e = s->data[s->top--];
    return 1;
} // 出栈

int SSgetTop(SqStack *s, SSElemType *e) {
    if (s->top == -1) {
        printf("下溢错误\n");
        return 0;
    }
    *e = s->data[s->top];
    return 1;
} // 取栈顶元素

int SSempty(SqStack *s) {
    if (s->top == -1) {
        return 1;
    }
    return 0;
} // 判空

#endif /* SqStack_h */
