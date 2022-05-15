#ifndef LinkedStack_h
#define LinkedStack_h

#include <stdio.h>
#include <stdlib.h>

typedef int LSElemType;

typedef struct node {
    LSElemType data;
    struct node *next;
} node;


void LSinit(node *top); // 初始化链栈

void LSdestory(node *top); // 销毁链栈

void LSpush(node **top, LSElemType x); // 入栈

int LSpop(node **top, LSElemType *e); // 出栈

int LSgetTop(node *top, LSElemType *e); // 取栈顶元素

int LSempty(node *top); // 判空



void LSinit(node *top) {
    top = NULL;
} // 初始化链栈

void LSdestory(node *top) {
    node *p = top;
    while (top) {
        top = top->next;
        free(p);
        p = top;
    }
} // 销毁链栈

void LSpush(node **top, LSElemType x) {
    node *t = (node*)malloc(sizeof(node));
    t->data = x;
    t->next = *top;
    *top = t;
} // 入栈

int LSpop(node **top, LSElemType *e) {
    if (!*top) {
        printf("下溢错误\n");
        return 0;
    }
    node *t = *top;
    *e = t->data;
    *top = (*top)->next;
    free(t);
    return 1;
} // 出栈

int LSgetTop(node *top, LSElemType *e) {
    if (!top) {
        printf("下溢错误\n");
        return 0;
    }
    *e = top->data;
    return 1;
} // 取栈顶元素

int LSempty(node *top) {
    if (top) {
        return 0;
    }
    return 1;
} // 判空

#endif /* LinkedStack_h */
