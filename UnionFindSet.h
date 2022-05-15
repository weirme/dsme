#ifndef UnionFindSet_h
#define UnionFindSet_h

#include <stdio.h>
#include <stdlib.h>

#define UFSMAX 6
typedef char UFSElemType;

typedef struct UFStree {
    UFSElemType data;
    int parent;
} UFStree;


void UFSinit(UFStree tree[], int nodeNum); // 初始化树

int UFSfindRoot(UFStree tree[], int node); // 查找某结点的根结点

void UFSunite(UFStree tree[], int node1, int node2); // 合并两个结点所在的集合



void UFSinit(UFStree tree[], int nodeNum) {
    for (int i = 0; i < nodeNum; i++) {
        tree[i].data = i+'0';
        tree[i].parent = -1;
    }
    return;
} // 初始化树

int UFSfindRoot(UFStree tree[], int node) {
    while (tree[node].parent != -1) {
        node = tree[node].parent;
    }
    return node;
} // 查找某结点的根结点

void UFSunite(UFStree tree[], int node1, int node2) {
    int root1 = UFSfindRoot(tree, node1);
    int root2 = UFSfindRoot(tree, node2);
    tree[root2].parent = root1;
    return;
} // 合并两个结点所在的集合

#endif /* UnionFindSet_h */
