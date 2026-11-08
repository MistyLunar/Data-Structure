#include <stdio.h>

typedef char VertexType;
typedef int EdgeType;

#define MAXSIZE 100

//定义图的邻接矩阵结构体
typedef struct {
    VertexType vertex[MAXSIZE]; //顶点数组
    EdgeType arc[MAXSIZE][MAXSIZE]; //邻接矩阵
    int vexnum_num, edge_num; //图的顶点数和边数
} Mat_Grph;

//创建图的邻接矩阵
void create_graph(Mat_Grph *G) {
    G->vexnum_num = 4;
    G->edge_num = 4;

    G->vertex[0] = '0';
    G->vertex[1] = '1';
    G->vertex[2] = '2';
    G->vertex[3] = '3';

    for (int i = 0; i < G->vexnum_num; i++) 
    {
        for (int j = 0; j < G->vexnum_num; j++) 
        {
            G->arc[i][j] = 0; //初始化邻接矩阵为0
        }
    }

    //添加有向边
    G->arc[0][3] = 1; // 0 -> 3
    G->arc[1][0] = 1; // 1 -> 0
    G->arc[1][2] = 1; // 1 -> 2
    G->arc[2][0] = 1; // 2 -> 0
    G->arc[2][1] = 1; // 2 -> 1
}

void print_matrix(Mat_Grph *G) {
    printf("邻接矩阵表示如下:\n");
    for (int i = 0; i < G->vexnum_num; i++) {
        for (int j = 0; j < G->vexnum_num; j++) {
            printf("%d ", G->arc[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Mat_Grph G;
    create_graph(&G);
    print_matrix(&G);
    return 0;
}