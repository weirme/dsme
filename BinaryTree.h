#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>
#include <stdlib.h>

#define BTMAX 100
typedef char BTElemType;
typedef int BSTElemType;

typedef struct BiNode {
    BTElemType data;
    struct BiNode *lChild;
    struct BiNode *rChild;
} BiNode;

typedef struct BsNode {
    BSTElemType data;
    struct BsNode *lChild;
    struct BsNode *rChild;
} BsNode;


BiNode *BITcreateBiTree(void); // 建立二叉树

void BITdestroy(BiNode **root); // 销毁二叉树（需传入二级指针）

void BITpreOrder(BiNode *root); // 前序遍历

void BITpreOrder2(BiNode *root); // 先序遍历树的非递归算法

void BITinOrder(BiNode *root); // 中序遍历

void BITinOrder2(BiNode *root); // 中序遍历树的非递归算法

void BITpostOrder(BiNode *root); // 后序遍历

void BITpostOrder2(BiNode *root); // 后序遍历树的非递归算法

void BITlevelOrder(BiNode *root); // 层序遍历

int BITnodeNumber(BiNode *root); // 统计叶子结点个数

int BITheight(BiNode *root); // 求二叉树高度

int BITwidth(BiNode *root); // 求二叉树宽度

int BITdegree1(BiNode *root); // 求度为1的结点个数

void BITfindParent(BiNode *root, BTElemType x); // 查找某结点的父节点

void BITchange(BiNode *root); // 交换左右子树

int BITisEqual(BiNode *root1, BiNode *root2); // 判断两棵树是否相等

int BITcalculate(BiNode *root); // 用树结构实现仅包含二元运算符的简单计算

BsNode *BSTcreate(int n); // 创建二叉排序树

void BSTinsert(BsNode **root, BSTElemType x); // 在二叉排序树中插入结点

void BSTdelete(BsNode **root, int x); // 在二叉排序树中删除值为x的结点

BsNode *BSTsearch(BsNode *root, int x); // 在二叉排序树中查找值为x的结点



BiNode *BITcreateBiTree() {
    char ch;
    BiNode *root = NULL;
    scanf(" %c",&ch);
    if (ch != '#') {
        root = (BiNode*)malloc(sizeof(BiNode));
        root->data = ch;
        root->lChild = BITcreateBiTree();
        root->rChild = BITcreateBiTree();
    }
    return root;
} // 建立二叉树

void BITdestroy(BiNode **root) {
    if (*root == NULL) {
        return;
    }
    BITdestroy(&(*root)->lChild);
    BITdestroy(&(*root)->rChild);
    free(*root);
    *root = NULL;
    return;
} // 销毁二叉树

void BITpreOrder(BiNode *root) {
    if (!root) {
        return;
    }
    printf("%c",root->data);  // 根据需要修改
    BITpreOrder(root->lChild);
    BITpreOrder(root->rChild);
} // 前序遍历

void BITpreOrder2(BiNode *root) {
    BiNode *stack[BTMAX];
    BiNode *p = root;
    int top = -1;
    while (p || top != -1) {
        while (p) {
            printf("%i",p->data); //根据需要修改
            stack[++top] = p;
            p = p->lChild;
        }
        if (top != -1) {
            p = stack[top--];
            p = p->rChild;
        }
    } // while
} // 先序遍历树的非递归算法

void BITinOrder(BiNode *root) {
    if (!root) {
        return;
    }
    BITinOrder(root->lChild);
    printf("%c",root->data); // 根据需要修改
    BITinOrder(root->rChild);
} // 中序遍历

void BITinOrder2(BiNode *root) {
    BiNode *stack[BTMAX];
    BiNode *p = root;
    int top = -1;
    while (p || top != -1) {
        while (p) {
            stack[++top] = p;
            p = p->lChild;
        }
        if (top != -1) {
            p = stack[top--];
            printf("%i",p->data); //根据需要修改
            p = p->rChild;
        }
    } // while
} // 中序遍历树的非递归算法

void BITpostOrder(BiNode *root) {
    if (!root) {
        return;
    }
    BITpostOrder(root->lChild);
    BITpostOrder(root->rChild);
    printf("%c",root->data); // 根据需要修改
} // 后序遍历

void BITpostOrder2(BiNode *root) {
    typedef struct Stack {
        BiNode *p;
        int flag;
    } Stack;
    Stack stack[BTMAX];
    BiNode *p = root;
    int top = -1;
    while (p || top != -1) {
        while (p) {
            stack[++top].p = p;
            stack[top].flag = 1;
            p = p->lChild;
        }
        while (top != -1 && stack[top].flag == 2) {
            printf("%i", stack[top--].p->data); // 根据需要修改
        }
        if (top != -1) {
            stack[top].flag = 2;
            p = stack[top].p->rChild;
        }
    } // while
} // 后序遍历树的非递归算法

void BITlevelOrder(BiNode *root) {
    if (!root) {
        return;
    }
    BiNode *p = NULL, *queue[BTMAX];
    int front = -1, rear = -1;
    queue[++rear] = root;
    while (front != rear) {
        p = queue[++front];
        printf("%c",p->data); // 根据需要修改
        if (p->lChild) {
            queue[++rear] = p->lChild;
        }
        if (p->rChild) {
            queue[++rear] = p->rChild;
        }
    }
    return;
} // 层序遍历

int BITnodeNumber(BiNode *root) {
    if (!root) {
        return 0;
    }
    return BITnodeNumber(root->lChild) + BITnodeNumber(root->rChild) + 1;
} // 统计叶子结点个数

int BITheight(BiNode *root) {
    if (!root) {
        return 0;
    }
    int lheight = BITheight(root->lChild);
    int rheight = BITheight(root->rChild);
    return lheight>rheight?lheight+1:rheight+1;
} // 求二叉树高度

int BITwidth(BiNode *root) {
    if (!root) {
        return 0;
    }
    BiNode *queue[BTMAX];
    BiNode *p = NULL;
    int front = -1, rear = -1;
    int last = -1; // 同层最右结点在队列的位置
    int temp = 0, maxWidth = 0;
    queue[++rear] = root;
    while (front < rear) {
        p = queue[++front];
        temp++;
        if (p->lChild) {
            queue[++rear] = p->lChild;
        }
        if (p->rChild) {
            queue[++rear] = p->rChild;
        }
        if (front >= last) {
            last = rear;
            if (temp > maxWidth) {
                maxWidth = temp;
            }
            temp = 0;
        } // if
    } // while
    return maxWidth;
} // 求二叉树宽度

int BITdegree1(BiNode *root) {
    if (!root) {
        return 0;
    }
    BiNode *queue[BTMAX];
    BiNode *p = root;
    int number = 0;
    int front = -1, rear = -1;
    queue[++rear] = p;
    while (front < rear) {
        p = queue[++front];
        if ((p->lChild && !p->rChild) || (!p->lChild && p->rChild)) {
            number++;
        } // 此处修改可改为求度为0或2的节点个数
        if (p->lChild) {
            queue[++rear] = p->lChild;
        }
        if (p->rChild) {
            queue[++rear] = p->rChild;
        }
    } // while
    return number;
} // 求度为1的结点个数

void BITfindParent(BiNode *root, BTElemType x) {
    if (!root) {
        return;
    }
    if (root->lChild && root->lChild->data == x) {
        printf("%c",root->data);
        return;
    }
    if (root->rChild && root->rChild->data == x) {
        printf("%c",root->data); // 根据需要修改
        return;
    }
    BITfindParent(root->lChild, x);
    BITfindParent(root->rChild, x);
} // 查找某结点的父节点

void BITchange(BiNode *root) {
    if (!root) {
        return;
    }
    BiNode *p = root->lChild;
    root->lChild = root->rChild;
    root->rChild = p;
    BITchange(root->lChild);
    BITchange(root->rChild);
} // 交换左右子树

int BITisEqual(BiNode *root1, BiNode *root2) {
    if (!root1 && !root2) {
        return 1;
    }
    else if (root1 && root2) {
        if (root1->data == root2->data)  {
            return (BITisEqual(root1->lChild, root2->lChild) && BITisEqual(root1->rChild, root2->rChild));
        }
        else return 0;
    }
    else return 0;
} // 判断两棵树是否相等

int BITcalculate(BiNode *root) {
    if (root->data >= '0' && root->data <= '9') {
        return root->data - '0';
    }
    else {
        switch (root->data) {
            case '+':
                return BITcalculate(root->lChild) + BITcalculate(root->rChild);
            case '-':
                return BITcalculate(root->lChild) - BITcalculate(root->rChild);
            case '*':
                return BITcalculate(root->lChild) * BITcalculate(root->rChild);
            case '/':
                return BITcalculate(root->lChild) / BITcalculate(root->rChild);
            default:return 0;
        } // switch
    } // else
} // 用树结构实现仅包含二元运算符的简单计算

void BSTinsert(BsNode **root, BSTElemType x) {
    if (!*root) {
        BsNode *t = (BsNode*)malloc(sizeof(BsNode));
        t->data = x;
        t->lChild = t->rChild = NULL;
        *root = t;
        return;
    }
    if (x < (*root)->data) {
        BSTinsert(&(*root)->lChild, x);
    }
    else BSTinsert(&(*root)->rChild, x);
} // 在二叉排序树中插入结点

BsNode *BSTcreate(int n) {
    int x;
    BsNode *root = NULL;
    printf("Input the data:\n");
    for (int i = 0; i < n; i++) {
        scanf("%i",&x);
        BSTinsert(&root, x);
    }
    return root;
} // 创建二叉排序树

void BSTdelete(BsNode **root, int x) {
    BsNode *pre = *root, *p = pre, *q = NULL;
    while (p->data != x) {
        pre = p;
        if (x < p->data) {
            p = p->lChild;
        }
        else p = p->rChild;
    }
    if (pre->lChild == p) {
        pre->lChild = p->rChild;
    }
    else pre->rChild = p->rChild;
    q = p->rChild;
    pre = p->lChild;
    if (p == *root) {
        *root = q;
    }
    free(p);
    p = pre;
    if (!p) {
        return; // 左子树为空，结束
    }
    while (q) {
        pre = q;
        if (p->data < q->data) {
            q = q->lChild;
        }
        else q = q->rChild;
    }
    if (pre->lChild == q) {
        pre->lChild = p;
    }
    else pre->rChild = p;
    return;
} // 在二叉排序树中删除值为x的结点

BsNode *BSTsearch(BsNode *root, int x) {
    if (!root) {
        return NULL;
    }
    if (root->data == x) {
        return root;
    }
    if (root->data > x) {
        return BSTsearch(root->lChild, x);
    }
    if (root->data < x) {
        return BSTsearch(root->rChild, x);
    }
    return NULL;
} // 在二叉排序树中查找值为x的结点

#endif /* BinaryTree_h */
