#ifndef Heap_h
#define Heap_h

#include <stdio.h>
#include <stdlib.h>

#define HEMAX 8
typedef int HEElemType;

typedef struct priQueue {
    HEElemType data[HEMAX];
    int rear;
} priQueue;


void HEenter(priQueue *q, HEElemType x); // 优先队列的入队

void HEexit(priQueue *q, HEElemType *e); // 优先队列的出队

void HEsift(HEElemType heap[], int n, int root); // 大根堆筛选

void HEsort(HEElemType heap[], int n); // 堆排序



void HEenter(priQueue *q, HEElemType x) {
    if (q->rear == HEMAX-1) {
        printf("上溢错误\n");
        return;
    }
    int i;
    int t;
    i = q->rear++;
    q->data[i] = x;
    while (i/2 > 0 && q->data[i/2] < x) {
        t = q->data[i];
        q->data[i] = q->data[i/2];
        q->data[i/2] = t;
        i /= 2;
    }
} // 优先队列的入队

void HEexit(priQueue *q, HEElemType *e) {
    if (q->rear == 1) {
        printf("下溢错误\n");
        return;
    }
    int i, j;
    int t;
    *e = q->data[1];
    q->data[1] = q->data[q->rear--];
    i = 1;
    j = 2*i;
    while (j <= q->rear) {
        if (j < q->rear && q->data[j] < q->data[j+1]) {
            j++;
        }
        if (q->data[i] < q->data[j]) {
            t = q->data[i];
            q->data[i] = q->data[j];
            q->data[j] = t;
            i = j;
            j *= 2;
        }
        else break;
    }
    return;
} // 优先队列的出队

void HEsift(HEElemType heap[], int n, int root) {
    int i = root, j = 2*i;
    n--; // 堆中最后一个元素的下标为输入数组长度n-1
    while (j <= n) {
        if (j < n && heap[j] < heap[j+1]) {
            j++;
        }
        if (heap[j] < heap[i]) {
            break;
        }
        heap[0] = heap[j];
        heap[j] = heap[i];
        heap[i] = heap[0];
        i = j;
        j = 2*i;
    }
    return;
} // 大根堆筛选

void HEsort(HEElemType heap[], int n) {
    int i;
    for (i = n/2; i >= 1; i--) {
        HEsift(heap, n, i);
    } // 建堆
    for (i = 1; i < n; i++) {
        heap[0] = heap[1];
        heap[1] = heap[n-i];
        heap[n-i] = heap[0];
        HEsift(heap, n-i, 1);
    }
    return;
} // 堆排序

#endif /* Heap_h */
