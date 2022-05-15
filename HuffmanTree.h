#ifndef HuffmanTree_h
#define HuffmanTree_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HTMAX 5

typedef struct huffman {
    int weight;
    int parent;
    int lChild;
    int rChild;
} huffman;

typedef struct prefixCode {
    char c;
    int weight;
    char code[HTMAX];
} code;


void HTcreate(huffman *huff, int *weight, int n); // 创建哈夫曼树

void HTpreOrder(huffman *huff, int rootNumber); // 先序遍历哈夫曼树

void HTcode(code *code, int n); // 前缀编码



void HTselect(huffman *huff, int n, int *first, int *second) {
    int first_small = 0xffff, second_small = 0xffff;
    for (int i = 0; i < n; i++) {
        if (huff[i].parent == -1) {
            if (huff[i].weight < first_small) {
                second_small = first_small;
                first_small = huff[i].weight;
                *second = *first;
                *first = i;
            }
            else if (huff[i].weight < second_small) {
                second_small = huff[i].weight;
                *second = i;
            }
        } // if
    } // for
    return;
} // 查找权值最小的两个元素

void HTcreate(huffman *huff, int *weight, int n) {
    int i;
    int first, second;
    for (i = 0; i < 2*n-1; i++) {
        huff[i].parent = -1;
        huff[i].lChild = -1;
        huff[i].rChild = -1;
    }
    for (i = 0; i < n; i++) {
        huff[i].weight = weight[i];
    }
    for (i = n; i < 2*n-1; i++) {
        HTselect(huff, i, &first, &second);
        huff[i].weight = huff[first].weight + huff[second].weight;
        huff[i].lChild = first;
        huff[i].rChild = second;
        huff[first].parent = i;
        huff[second].parent = i;
    }
    return;
} // 创建哈夫曼树

void reserve(char *s) {
    char *p = s, *q = s+strlen(s)-1;
    char t;
    while (p < q) {
        t = *p;
        *p++ = *q;
        *q-- = t;
    }
} // 为前缀编码做准备的字符串逆置函数

void HTpreOrder(huffman *huff, int rootNumber) {
    if (rootNumber == -1) {
        return;
    }
    printf("%i\n",huff[rootNumber].weight); // 根据需要修改
    HTpreOrder(huff, huff[rootNumber].lChild);
    HTpreOrder(huff, huff[rootNumber].rChild);
} // 先序遍历哈夫曼树

void HTcode(code *code, int n) {
    int i, j;
    int weight[HTMAX]; // 根据n的实际大小修改N的值
    char t;
    huffman huff[2*HTMAX-1];
    for (i = 0; i < n; i++) {
        weight[i] = code[i].weight;
    }
    HTcreate(huff, weight, n);
    for (i = 0; i < n; i++) {
        j = i;
        int k = 0;
        while (huff[j].parent != -1) {
            t = huff[huff[j].parent].lChild == j?'0':'1';
            code[i].code[k++] = t;
            j = huff[j].parent;
        }
        code[i].code[k] = '\0';
        reserve(code[i].code);
    }
} // 前缀编码

#endif /* HuffmanTree_h */
