#ifndef Graph_h
#define Graph_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UnionFindSet.h"

#define Vertex 6
#define Edge 9
typedef char GElemType;

typedef struct MGraph {
    GElemType vertex[Vertex];
    int edge[Vertex][Vertex];
    int visit[Vertex];
    int vertexNum;
    int edgeNum;
} MGraph; // 邻接矩阵存储

typedef struct EdgeNode {
    int adjvex;
    int weight; // 权重可根据需要删去
    struct EdgeNode *next;
} EdgeNode; // 边表结点

typedef struct VertexNode {
    GElemType vertex;
    EdgeNode *first;
    int visit;
    int inNum; // 入度（用于ALGtopSort函数<469>，可根据需要删去）
} VertexNode; // 顶点表结点

typedef struct ALGraph {
    VertexNode adjlist[Vertex];
    int vertexNum;
    int edgeNum;
} ALGraph; // 无向图邻接表存储

typedef struct EdgeArray {
    int from;
    int to;
    int weight;
} EdgeArray; // 边数组

typedef struct EdgeGraph {
    GElemType vertex[Vertex];
    EdgeArray edge[Edge+1]; // 数组长度根据需要修改
    int vertexNum;
    int edgeNum;
} EGraph; // 边集数组存储


void MGundirectedCreate(MGraph *g, int vertexNum, int edgeNum); // 创建无向图(矩阵）

void MGundirectedCreateWithWeight(MGraph *g, int vertexNum, int edgeNum); // 创建无向网图(矩阵）

void MGdirectedCreate(MGraph *g, int vertexNum, int edgeNum); // 创建有向图（矩阵）

void MGdirectedCreateWithWeight(MGraph *g, int vertexNum, int edgeNum); // 创建有向网图(矩阵)

void MGdfTraverse(MGraph *g, int v); // 深度优先遍历（矩阵）

void MGbfTraverse(MGraph *g, int v); // 广度优先遍历（矩阵）

int MGpathExist(MGraph *g, int from, int to); // 判断两顶点之间是否存在路径

ALGraph *ALGtransferFromMGWithWeight(MGraph *MG); // 将邻接矩阵表示的网图转为邻接表表示

void ALGundirectedCreate(ALGraph *g, int vertexNum, int edgeNum); // 创建无向图(表）

void ALGdirectedCreate(ALGraph *g, int vertexNum, int edgeNum); // 创建有向图(表）

void ALGdirectedCreateWithWeight(ALGraph *g, int vertexNum, int edgeNum); // 创建有向网图(表）

void ALGdestroy(ALGraph **g); // 销毁图（表）

void ALGdfTraverse(ALGraph *g, int v); // 深度优先遍历（表）

void ALGbfTraverse(ALGraph *g, int v); // 广度优先遍历（表）

void ALGinNum(ALGraph *g); // 求有向表各顶点的入度

int *ALGtopSort(ALGraph *g); // 有向表拓补排序（也可用于回路判断）

EdgeArray *EGgetEdgeArrayFromMGWithWeight(MGraph *MG); // 得到用邻接矩阵表示的网图的边数组

void EGundirectedCreateWithWeight(EGraph *g, int vertexNum, int edgeNum); // 创建无向网图（边集）

void EGquickSort(EGraph *g, int front, int end); // 对边集数组按照权重排序

void Prim(MGraph *g, int v); // Prim算法建立最小生成树

void Kruskal(EGraph *g, int v); // Kruskal算法建立最小生成树，调用该函数时需包含头文件"UnionFindSet.h"

int *Dijkstra(MGraph *g, int v); // Dijkstra算法求单源点的最短路径

int (*Floyd(MGraph *g))[Vertex]; // Floyd算法求各结点间最短路径

void criticalActivity(MGraph *MG); // 求AOE网的关键活动

int center(MGraph *g); // 求图的中心点，即到其他各顶点往返路径之和最小的顶点



void MGundirectedCreate(MGraph *g, int vertexNum, int edgeNum) {
    int i, j, k;
    g->vertexNum = vertexNum;
    g->edgeNum = edgeNum;
    for (i = 0; i < vertexNum; i++) {
        for (j = 0; j < vertexNum; j++) {
            g->edge[i][j] = 0;
        }
    }
    printf("Input data of vertex:\n");
    for (k = 0; k < vertexNum; k++) {
        scanf("%c",&g->vertex[k]); // 根据需要修改
        g->visit[k] = 0;
    }
    printf("Input number of edge:\n");
    for (k = 0; k < edgeNum; k++) {
        scanf("%i%i",&i,&j);
        g->edge[i][j] = g->edge[j][i] = 1;
    }
    return;
} // 创建无向图(矩阵）

void MGundirectedCreateWithWeight(MGraph *g, int vertexNum, int edgeNum) {
    int i, j, k;
    int weight;
    g->vertexNum = vertexNum;
    g->edgeNum = edgeNum;
    for (i = 0; i < vertexNum; i++) {
        for (j = 0; j < vertexNum; j++) {
            if (i == j) {
                g->edge[i][j] = 0;
            }
            else g->edge[i][j] = 0xffff;
        }
    }
    printf("Input data of vertex:\n");
    for (k = 0; k < vertexNum; k++) {
        scanf("%c",&g->vertex[k]); // 根据需要修改
        g->visit[k] = 0;
    }
    printf("Input number and weight of edge:\n");
    for (k = 0; k < edgeNum; k++) {
        scanf("%i%i%i",&i,&j,&weight);
        g->edge[i][j] = g->edge[j][i] = weight;
    }
    return;
} // 创建无向网图(矩阵）

void MGdirectedCreate(MGraph *g, int vertexNum, int edgeNum) {
    int i, j, k;
    g->vertexNum = vertexNum;
    g->edgeNum = edgeNum;
    for (i = 0; i < vertexNum; i++) {
        for (j = 0; j < vertexNum; j++) {
            g->edge[i][j] = 0;
        }
    }
    printf("Input data of vertex:\n");
    for (k = 0; k < vertexNum; k++) {
        scanf("%c",&g->vertex[k]); // 根据需要修改
        g->visit[k] = 0;
    }
    printf("Input number of edge:\n");
    for (k = 0; k < edgeNum; k++) {
        scanf("%i%i",&i,&j);
        g->edge[i][j] = 1;
    }
    return;
} // 创建有向图（矩阵）

void MGdirectedCreateWithWeight(MGraph *g, int vertexNum, int edgeNum) {
    int i, j, k;
    int weight;
    g->vertexNum = vertexNum;
    g->edgeNum = edgeNum;
    for (i = 0; i < vertexNum; i++) {
        for (j = 0; j < vertexNum; j++) {
            if (i == j) {
                g->edge[i][j] = 0;
            }
            else g->edge[i][j] = 0xffff;
        }
    }
    printf("Input data of vertex:\n");
    for (k = 0; k < vertexNum; k++) {
        scanf("%c",&g->vertex[k]); // 根据需要修改
        g->visit[k] = 0;
    }
    printf("Input number and weight of edge:\n");
    for (k = 0; k < edgeNum; k++) {
        scanf("%i%i%i",&i,&j,&weight);
        g->edge[i][j] = weight;
    }
    return;
} // 创建有向网图(矩阵)

void MGdfTraverse(MGraph *g, int v) {
    g->visit[v] = 1;
    printf("%c",g->vertex[v]); // 根据需要修改
    for (int i = 0; i < g->vertexNum; i++) {
        if (g->edge[v][i] == 1 && !g->visit[i]) {
            MGdfTraverse(g, i);
        }
    }
    return;
} // 深度优先遍历（矩阵）

void MGbfTraverse(MGraph *g, int v) {
    int queue[Vertex];
    int front = -1, rear = -1;
    queue[++rear] = v;
    g->visit[v] = 1;
    while (front < rear) {
        v = queue[++front];
        printf("%c",g->vertex[v]);
        for (int i = 0; i < g->vertexNum; i++) {
            if (g->edge[v][i] == 1 && !g->visit[i]) {
                queue[++rear] = i;
                g->visit[i] = 1;
            }
        } // for
    } // while
    return;
} // 广度优先遍历（矩阵）

ALGraph *ALGtransferFromMGWithWeight(MGraph *MG) {
    ALGraph *ALG = (ALGraph*)malloc(sizeof(ALGraph));
    EdgeNode *t = NULL;
    ALG->vertexNum = MG->vertexNum;
    ALG->edgeNum = MG->edgeNum;
    for (int i = 0; i < MG->vertexNum; i++) {
        ALG->adjlist[i].vertex = MG->vertex[i];
        ALG->adjlist[i].first = NULL;
        ALG->adjlist[i].visit = 0;
        ALG->adjlist[i].inNum = 0;
        for (int j = 0; j < MG->edgeNum; j++) {
            if (MG->edge[i][j] > 0 && MG->edge[i][j] < 0xffff) {
                t = (EdgeNode*)malloc(sizeof(EdgeNode));
                t->adjvex = j;
                t->weight = MG->edge[i][j];
                t->next = ALG->adjlist[i].first;
                ALG->adjlist[i].first = t;
            }
        } // for j
    } // for i
    return ALG;
} // 将邻接矩阵表示的网图转为邻接表表示

void ALGundirectedCreate(ALGraph *g, int vertexNum, int edgeNum) {
    int i, j, k;
    EdgeNode *t = NULL;
    g->vertexNum = vertexNum;
    g->edgeNum = edgeNum;
    printf("Input data of vertex:\n");
    for (k = 0; k < vertexNum; k++) {
        scanf("%c",&g->adjlist[k].vertex); // 根据需要修改
        g->adjlist[k].first = NULL;
        g->adjlist[k].visit = 0;
    }
    printf("Input number of edge:\n");
    for (k = 0; k < edgeNum; k++) {
        scanf("%i%i",&i,&j);
        t = (EdgeNode*)malloc(sizeof(EdgeNode));
        t->adjvex = j;
        t->next = g->adjlist[i].first;
        g->adjlist[i].first = t;
        t = (EdgeNode*)malloc(sizeof(EdgeNode));
        t->adjvex = i;
        t->next = g->adjlist[j].first;
        g->adjlist[j].first = t;
    }
    return;
} // 创建无向图(表）

void ALGdirectedCreate(ALGraph *g, int vertexNum, int edgeNum) {
    int i, j, k;
    EdgeNode *t = NULL;
    g->vertexNum = vertexNum;
    g->edgeNum = edgeNum;
    printf("Input data of vertex:\n");
    for (k = 0; k < vertexNum; k++) {
        scanf("%c",&g->adjlist[k].vertex); // 根据需要修改
        g->adjlist[k].first = NULL;
        g->adjlist[k].visit = 0;
        g->adjlist[k].inNum = 0; // 为ALGtopSort函数做准备，可根据需要删去
    }
    printf("Input number of edge:\n");
    for (k = 0; k < edgeNum; k++) {
        scanf("%i%i",&i,&j);
        t = (EdgeNode*)malloc(sizeof(EdgeNode));
        t->adjvex = j;
        t->next = g->adjlist[i].first;
        g->adjlist[i].first = t;
    }
    return;
} // 创建有向图(表）

void ALGdirectedCreateWithWeight(ALGraph *g, int vertexNum, int edgeNum) {
    int i, j, k;
    int weight;
    EdgeNode *t = NULL;
    g->vertexNum = vertexNum;
    g->edgeNum = edgeNum;
    printf("Input data of vertex:\n");
    for (k = 0; k < vertexNum; k++) {
        scanf("%c",&g->adjlist[k].vertex); // 根据需要修改
        g->adjlist[k].first = NULL;
        g->adjlist[k].visit = 0;
        g->adjlist[k].inNum = 0; // 为ALGtopSort函数做准备，可根据需要删去
    }
    printf("Input number and weight of edge:\n");
    for (k = 0; k < edgeNum; k++) {
        scanf("%i%i%i",&i,&j,&weight);
        t = (EdgeNode*)malloc(sizeof(EdgeNode));
        t->adjvex = j;
        t->weight = weight;
        t->next = g->adjlist[i].first;
        g->adjlist[i].first = t;
    }
    return;
} // 创建有向网图(表）

void ALGdestroy(ALGraph **g) {
    int i;
    EdgeNode *p = NULL, *q = NULL;
    for (i = 0; i < (*g)->vertexNum; i++) {
        p = (*g)->adjlist[i].first;
        while (p) {
            q = p->next;
            free(p);
            p = q;
        }
    }
    return;
} // 销毁图（表）

void ALGdfTraverse(ALGraph *g, int v) {
    EdgeNode *p = g->adjlist[v].first;
    printf("%c",g->adjlist[v].vertex);
    g->adjlist[v].visit = 1;
    while (p) {
        v = p->adjvex;
        if (!g->adjlist[v].visit) {
            ALGdfTraverse(g, v);
        }
        else p = p->next;
    }
    return;
} // 深度优先遍历（表）

void ALGbfTraverse(ALGraph *g, int v) {
    int t;
    EdgeNode *p = NULL;
    int queue[Vertex];
    int front = -1, rear = -1;
    queue[++rear] = v;
    g->adjlist[v].visit = 1;
    while (front < rear) {
        t = queue[++front];
        p = g->adjlist[t].first;
        printf("%c",g->adjlist[t].vertex);
        while (p) {
            t = p->adjvex;
            if (!g->adjlist[t].visit) {
                queue[++rear] = t;
                g->adjlist[t].visit = 1;
            }
            p = p->next;
        } // while
    } // while
    return;
} // 广度优先遍历（表）

EdgeArray *EGgetEdgeArrayFromMGWithWeight(MGraph *MG) {
    EdgeArray *EG = (EdgeArray*)malloc(sizeof(EdgeArray)*MG->edgeNum);
    int k = 0;
    for (int i = 0; i < MG->vertexNum; i++) {
        for (int j = 0; j < MG->edgeNum; j++) {
            if (MG->edge[i][j] > 0 && MG->edge[i][j] < 0xffff) {
                EG[k].from = i;
                EG[k].to = j;
                EG[k].weight = MG->edge[i][j];
                k++;
            }
        } // for j
    } // for i
    return EG;
} // 得到用邻接矩阵表示的网图的边数组

void EGundirectedCreateWithWeight(EGraph *g, int vertexNum, int edgeNum) {
    int i, j, k;
    int weight;
    g->vertexNum = vertexNum;
    g->edgeNum = edgeNum;
    printf("Input data of vertex:\n");
    for (k = 0; k < vertexNum; k++) {
        scanf("%c",&g->vertex[k]); // 根据需要修改
    }
    printf("Input number and weight of edge:\n");
    for (k = 0; k < edgeNum; k++) {
        scanf("%i%i%i",&i,&j,&weight);
        g->edge[k].from = i;
        g->edge[k].to = j;
        g->edge[k].weight = weight;
    } // 边集数组的第一个元素可空出，用于后续排序等操作
    return;
} // 创建无向网图（边集）

void EGquickSort(EGraph *g, int front, int end) {
    if (front < end) {
        int i = front, j = end;
        EdgeArray temp = g->edge[i];
        while (i < j) {
            while (i < j && g->edge[j].weight > temp.weight) {
                j--;
            }
            if (i < j) {
                g->edge[i++] = g->edge[j];
            }
            while (i < j && g->edge[i].weight < temp.weight) {
                i++;
            }
            if (i < j) {
                g->edge[j--] = g->edge[i];
            }
        }
        g->edge[i] = temp;
        EGquickSort(g, front, i-1);
        EGquickSort(g, i+1, end);
    }
    return;
} // 对边集数组按照权重排序

void Prim(MGraph *g, int v) {
    int adjvex[Vertex];
    int lowcost[Vertex];
    int i, j;
    int t = 0, temp;
    for (i = 0; i < g->vertexNum; i++) {
        adjvex[i] = v;
        lowcost[i] = g->edge[v][i];
    } // 初始化
    for (i = 1; i < g->vertexNum; i++) {
        temp = 0xffff;
        for (j = 0; j < g->vertexNum; j++) {
            if (lowcost[j] != 0 && lowcost[j] < temp) {
                t = j;
                temp = lowcost[j];
            }
        } // for 选取最短边
        printf("%c->%c (%i)\n",g->vertex[adjvex[t]], g->vertex[t], lowcost[t]);
        for (j = 0; j < g->vertexNum; j++) {
            if (g->edge[t][j] < lowcost[j]) {
                adjvex[j] = t;
                lowcost[j] = g->edge[t][j];
            } // if
        } // for 更新数组
        lowcost[t] = 0;
    } //for
    return;
} // Prim算法建立最小生成树（还可增加一个边集数组作为返回值）

void Kruskal(EGraph *g, int v) {
    EGquickSort(g, 0, g->edgeNum-1);
    UFStree tree[UFSMAX];
    UFSinit(tree, UFSMAX);
    int i;
    int from, to;
    for (i = 0; i < g->edgeNum; i++) {
        from = g->edge[i].from;
        to = g->edge[i].to;
        if (UFSfindRoot(tree, from) != UFSfindRoot(tree, to)) {
            printf("%c->%c (%i)\n",g->vertex[from],g->vertex[to],g->edge[i].weight);
            UFSunite(tree, from, to);
        }
    } // for
    return;
} // Kruskal算法建立最小生成树，调用该函数时需包含头文件"UnionFindSet.h"

void DprintPath(MGraph *g, int path[], int n) {
    if (n == 0) {
        return;
    }
    DprintPath(g, path, path[n]);
    printf("%c->%c ",g->vertex[path[n]], g->vertex[n]);
    return;
} // 用于输出最短路径的函数

int *Dijkstra(MGraph *g, int v) {
    static int lowcost[Vertex];
    int path[Vertex];
    int i, j;
    int t = 0, temp;
    for (i = 0; i < g->vertexNum; i++) {
        lowcost[i] = g->edge[v][i];
        path[i] = v;
    }
    for (i = 1; i < g->vertexNum; i++) {
        temp = 0xffff;
        for (j = 0; j < g->vertexNum; j++) {
            if (lowcost[j] != 0 && lowcost[j] < temp) {
                t = j;
                temp = lowcost[j];
            }
        } // 寻找最短路径
        DprintPath(g, path, t);
        printf(" (%i)\n",lowcost[t]);
        for (j = 0; j < g->vertexNum; j++) {
            if (lowcost[j] > lowcost[t] + g->edge[t][j] ) {
                lowcost[j] = lowcost[t] + g->edge[t][j];
                path[j] = t;
            }
        } // 更新最短路径数组
        lowcost[t] = 0;
    }
    return lowcost;
} // Dijkstra算法求单源点的最短路径

void FprintPath(MGraph *g, int path[][Vertex], int from, int to) {
    if (path[from][to] == -1) {
        return;
    }
    FprintPath(g, path, from, path[from][to]);
    printf("%c->%c ",g->vertex[path[from][to]],g->vertex[to]);
    return;
} // 用于输出最短路径的函数

int (*Floyd(MGraph *g))[Vertex] {
    static int lowcost[Vertex][Vertex];
    int path[Vertex][Vertex];
    int i, j, k;
    for (i = 0; i < g->vertexNum; i++) {
        for (j = 0; j < g->vertexNum; j++) {
            lowcost[i][j] = g->edge[i][j];
            if (lowcost[i][j] && lowcost[i][j] < 0xffff) {
                path[i][j] = i;
            }
            else path[i][j] = -1;
        } // for j
    } // for i 初始化数组
    for (k = 0; k < g->vertexNum; k++) {
        for (i = 0; i < g->vertexNum; i++) {
            for (j = 0; j < g->vertexNum; j++) {
                if (lowcost[i][j] > lowcost[i][k]+lowcost[k][j]) {
                    lowcost[i][j] = lowcost[i][k]+lowcost[k][j];
                    path[i][j] = k;
                } // if
            } // for k
        } // for j
    } // for i
    for (i = 0; i < g->vertexNum; i++) {
        printf("from %c:\n",g->vertex[i]);
        for (j = 0; j < g->vertexNum; j++) {
            if (i != j && lowcost[i][j] < 0xffff) {
                FprintPath(g, path, i, j);
                printf("(%i)\n",lowcost[i][j]);
            }
        } // for j
    } // for i
    return lowcost;
} // Floyd算法求各结点间最短路径

void ALGinNum(ALGraph *g) {
    EdgeNode *p = NULL;
    for (int i = 0; i < g->vertexNum; i++) {
        p = g->adjlist[i].first;
        while (p) {
            g->adjlist[p->adjvex].inNum++;
            p = p->next;
        }
    } // for
} // 求有向表各顶点的入度

int *ALGtopSort(ALGraph *g) {
    EdgeNode *p = NULL;
    int stack[Vertex];
    int *afterSort = (int*)malloc(sizeof(int)*g->vertexNum);
    int top = -1;
    int count = 0;
    int temp;
    int i;
    ALGinNum(g); // 初始化入度
    for (i = 0; i < g->vertexNum; i++) {
        if (g->adjlist[i].inNum == 0) {
            stack[++top] = i;
        }
    } // 初始化栈
    while (top != -1) {
        temp = stack[top--];
        //        printf("%c ",g->adjlist[temp].vertex);
        afterSort[count] = temp;
        p = g->adjlist[temp].first;
        count++;
        while (p) {
            int j = p->adjvex;
            g->adjlist[j].inNum--;
            if (g->adjlist[j].inNum == 0) {
                stack[++top] = j;
            }
            p = p->next;
        }
    }
    if (count < g->vertexNum) {
        printf("\nCircuit exists!\n");
        return NULL;
    }
    return afterSort;
} // 有向表拓补排序（也可用于回路判断）

int *vfirst(MGraph *g, int *sort) {
    int *vfirst = (int*)malloc(sizeof(int)*g->vertexNum);
    int max;
    int i, j;
    vfirst[sort[0]] = 0;
    for (i = 1; i < g->vertexNum; i++) {
        max = 0;
        for (j = 0; j < i; j++) {
            if (g->edge[sort[j]][sort[i]] < 0xffff && vfirst[sort[j]] + g->edge[sort[j]][sort[i]] > max) {
                max = vfirst[sort[j]] + g->edge[sort[j]][sort[i]];
            }
        }
        vfirst[sort[i]] = max;
    }
    return vfirst;
} // 求事件的最早发生时间

int *vlast(MGraph *g, int *sort, int vfirstOfEnd) {
    int *vlast = (int*)malloc(sizeof(int)*g->vertexNum);
    int min;
    int i, j;
    vlast[sort[g->vertexNum-1]] = vfirstOfEnd;
    for (i = g->vertexNum-2; i >= 0; i--) {
        min = 0xffff;
        for (j = g->vertexNum-1; j > i; j--) {
            if (g->edge[sort[i]][sort[j]] < 0xffff && vlast[sort[j]] - g->edge[sort[i]][sort[j]] < min ) {
                min = vlast[sort[j]] - g->edge[sort[i]][sort[j]];
            }
        }
        vlast[sort[i]] = min;
    }
    return vlast;
} // 求时间的最迟发生时间

int *efirst(EdgeArray *g, int edgeNum, int *vfirst) {
    int *efirst = (int*)malloc(sizeof(int)*edgeNum);
    for (int i = 0; i < edgeNum; i++) {
        efirst[i] = vfirst[g[i].from];
    }
    return efirst;
} // 求活动的最早发生时间

int *elast(EdgeArray *g, int edgeNum, int *vlast) {
    int *elast = (int*)malloc(sizeof(int)*edgeNum);
    for (int i = 0; i < edgeNum; i++) {
        elast[i] = vlast[g[i].to] - g[i].weight;
    }
    return elast;
} // 求活动的最迟发生时间

void criticalActivity(MGraph *MG) {
    ALGraph *ALG = ALGtransferFromMGWithWeight(MG);
    EdgeArray *EA = EGgetEdgeArrayFromMGWithWeight(MG);
    int *afterSort = ALGtopSort(ALG);
    int *vF = vfirst(MG, afterSort);
    int *vL = vlast(MG, afterSort, vF[afterSort[MG->vertexNum-1]]);
    int *eF = efirst(EA, MG->edgeNum, vF);
    int *eL = elast(EA, MG->edgeNum, vL);
    printf("Critical Activity:\n");
    for (int i = 0; i < MG->edgeNum; i++) {
        if (eF[i] == eL[i]) {
            printf("%i->%i\n",EA[i].from,EA[i].to);
        }
    }
    return;
} // 求AOE网的关键活动

int center(MGraph *g) {
    int i, j, k;
    int distance[Vertex][Vertex];
    int sum[Vertex];
    int center = 0;
    for (i = 0; i < g->vertexNum; i++) {
        for (j = 0; j < g->vertexNum; j++) {
            distance[i][j] = g->edge[i][j];
        } // for j
    } // for i 初始化数组
    for (k = 0; k < g->vertexNum; k++) {
        for (i = 0; i < g->vertexNum; i++) {
            for (j = 0; j < g->vertexNum; j++) {
                if (distance[i][j] > distance[i][k]+distance[k][j]) {
                    distance[i][j] = distance[i][k]+distance[k][j];
                } // if
            } // for k
        } // for j
    } // for i
    // 无路径记录和输出的Floyd算法用于求各结点间的最短距离
    for (i = 0; i < g->vertexNum; i++) {
        sum[i] = 0;
        for (j = 0; j < g->vertexNum; j++) {
            sum[i] += distance[i][j];
            sum[i] += distance[j][i];
        }
        if (sum[i] < sum[center]) {
            center = i;
        }
    }
    return center;
} // 求图的中心点，即到其他各顶点往返路径之和最小的顶点

int MGpathExist(MGraph *g, int from, int to) {
    if (g->edge[from][to] && g->edge[from][to] < 0xffff) {
        return 1;
    }
    int flag = 0;
    for (int i = 0; i < g->vertexNum; i++) {
        if (!g->visit[i] && g->edge[from][i] && g->edge[from][i] < 0xffff) {
            g->visit[i] = 1;
            flag = MGpathExist(g, from, i);
        }
    }
    return flag;
} // 判断两顶点之间是否存在路径

#endif /* Graph_h */
