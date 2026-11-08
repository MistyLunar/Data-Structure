#include <stdio.h>
#define MAXSIZE 100
#define MAX 0x7fffffff  //用一个极大值表示“无穷”，即无边
typedef char VertexType;
typedef int EdgeType;

typedef struct {
    VertexType vertex[MAXSIZE];  //顶点表
    EdgeType arc[MAXSIZE][MAXSIZE];  //邻接矩阵
    int vertex_num, edge_num;  //图中当前的顶点数和边数
} Mat_Grph;

void create_graph(Mat_Grph* G) {
    G->vertex_num = 4;
    G->edge_num = 5;

    for (int i = 0; i < G->vertex_num; i++) {
        G->vertex[i] = '0' + i;  // 初始化顶点
    }

    for (int i = 0; i < G->vertex_num; i++) {
        for (int j = 0; j < G->vertex_num; j++) {
            G->arc[i][j] = MAX;  // 初始化邻接矩阵为无穷大
            if (i == j) {
                G->arc[i][j] = 0;
            }
        }
    }

    G->arc[0][3] = 3;
    G->arc[1][0] = 5;
    G->arc[1][2] = 2;
    G->arc[2][0] = 6;
    G->arc[2][1] = 4;
}

void print_graph(Mat_Grph G) {
    printf("邻接矩阵:\n");
    for (int i = 0; i < G.vertex_num; i++) {
        for (int j = 0; j < G.vertex_num; j++) {
            if (G.arc[i][j] == MAX) {
                printf("Max ");
            } else {
                printf("%3d ", G.arc[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    Mat_Grph G;
    create_graph(&G);
    print_graph(G);
    return 0;
}