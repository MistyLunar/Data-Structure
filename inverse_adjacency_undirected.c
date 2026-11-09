#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100

typedef struct EdgeNode {
    int from; //前驱
    struct EdgeNode *next;
} EdgeNode;

typedef struct VertexNode {
    char data; //顶点信息
    EdgeNode *firstin; //指向前驱链表头
} VertexNode, InAdjList[MAXVEX];

typedef struct {
    InAdjList inlist; //前驱邻接表
    int numVertexes, numEdges; //顶点数和边数
} InverseGraph;

void createGraph(InverseGraph *G) {
    G->numVertexes = 4;
    G->numEdges = 5;

    // 初始化顶点名称（V0 ~ V3）
    for (int i = 0; i < G->numVertexes; i++) {
        G->inlist[i].data = '0' + i;
        G->inlist[i].firstin = NULL;
    }

    // 有向边集合（只添加一个方向）
    int edges[5][2] = {
        {0, 3}, {1, 0}, {1, 2},
        {2, 0}, {2, 1}
    };

    // 添加每条边
    for (int i = 0; i < G->numEdges; i++) {
        int from = edges[i][0];
        int to = edges[i][1];

        EdgeNode *e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->from = from;
        e->next = G->inlist[to].firstin;
        G->inlist[to].firstin = e;
    }
}

void printInverseGraph(InverseGraph *G) {
    printf("图的前驱邻接表如下：\n");
    for (int i = 0; i < G->numVertexes; i++) {
        printf("V%c -> ", G->inlist[i].data);
        EdgeNode *p = G->inlist[i].firstin;
        while (p) {
            printf("%d -> ", p->from);
            p = p->next;
        }
        printf("∧\n");
    }
}

int main() {
    InverseGraph G;
    createGraph(&G);
    printInverseGraph(&G);
    return 0;
}