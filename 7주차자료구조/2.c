//학과: 컴퓨터소프트웨어공학과
//학번: 20204024
//이름: 임지윤
//프로그램명: 인접리스트를 활용하여 텍스트 파일에 저장된 파일의 내용을 그래프의 형태로 표현하는 프로그램
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX_VERTICES 50
typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;
typedef struct GraphNode {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;                      

void init(GraphType* g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;                    // 그래프를 초기화하는 함수 
}

void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++; // 정점을 삽입하는 함수 
}

void insert_edge(GraphType* g, int u, int v)
{
	GraphNode* node;
	if (u >= g->n || v >= g->n)
	{
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;	
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;                  // 간선을 삽입하고, v를 u의 인접 리스트에 삽입하는 함수 
}

void print_adj_list(GraphType* g)
{
	for (int i = 0; i < g->n; i++)
	{
		GraphNode* p = g->adj_list[i];
		printf("정점 %d의 인접 리스트 ", i);
		while (p!= NULL)
		{
			printf("-> %d", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}

int main()
{
	GraphType* g; 
	FILE* fp;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	
	/*fp = fopen("data.txt", "r"); // 파일의 내용을 읽기 모드로 열기

    if (fp == NULL)
     {
	printf("FILE NOT FOUND");
	exit(1);
     }

    while (!feof)
{
	fscanf(fp, "%s", c); // 파일 포인터 fp에 문자열을 입력받아옴
	printf("%s", c); // 입력받아온 문자열을 출력함 .
}*/

	for (int i = 0; i < 4; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 1, 0);
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 0);
	insert_edge(g, 0, 3);
	insert_edge(g, 3, 0);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 3, 2);

	free(g);
	fclose(fp);
	return 0;
}