#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

//定义边表结点结构体
typedef struct EdgeNode {
    int adjvex; //邻接点域，存储该顶点对应的下标
    struct EdgeNode *next; //链域，指向下一个邻接点
} EdgeNode;

//定义顶点表结点结构体
typedef struct VertexNode {
    char data; //顶点域，存储顶点信息
    EdgeNode *firstedge; //边表头指针
} VertexNode, AdjList[MAXSIZE]; //AdjList是邻接表类型
//AdjList adjlist相当于VertexNode adjlist[MAXSIZE]; //定义邻接表类型的数组

//图的结构体
typedef struct {
    AdjList adjlist; //邻接表
    int numVertexes, numEdges; //图中当前顶点数和边数
} GraphAdjList;

void createGraph(GraphAdjList *G) {
    G->numVertexes = 4;
    G->numEdges = 5;

    for (int i = 0; i < G->numVertexes; i++) {
        G->adjlist[i].data = '0' + i; //初始化顶点信息
        G->adjlist[i].firstedge = NULL; //初始化边表头指针
    }

    int edges[5][2] = {
        {0, 1}, {0, 2}, {0, 3}, 
        {1, 2}, {2, 3}
    }; //定义边的数组

    for (int i = 0; i < G->numEdges; i++) {
        int from = edges[i][0];
        int to = edges[i][1];

        //创建边表结点
        EdgeNode *e1 = (EdgeNode *)malloc(sizeof(EdgeNode));
        e1->adjvex = to;
        e1->next = G->adjlist[from].firstedge;
        G->adjlist[from].firstedge = e1;

        //因为是无向图，所以还要创建反向边
        EdgeNode *e2 = (EdgeNode *)malloc(sizeof(EdgeNode));
        e2->adjvex = from;
        e2->next = G->adjlist[to].firstedge;
        G->adjlist[to].firstedge = e2;
    }
}

void printGraph(GraphAdjList G) {
    printf("图的邻接表:\n");
    for (int i = 0; i < G.numVertexes; i++) {
        printf("V%c -> ", G.adjlist[i].data);
        EdgeNode *p = G.adjlist[i].firstedge;
        while (p) {
            printf("%d -> ", p->adjvex);
            p = p->next;
        }
        printf("∧\n");
    }
}

int main() {
    GraphAdjList G;
    createGraph(&G);
    printGraph(G);
    return 0;
}
