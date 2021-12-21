//학과 : 컴퓨터소프트웨어공학과
//학번: 20204024 
//이름: 임지윤
//프로그램명 : 텍스트 파일에서 정점과 엣지 정보를 입력받아 인접 행렬을 생성하여 그래프를 생성하는 프로그램
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50 
typedef struct GraphType {
	int n; // 정점의 개수 
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

// 그래프 초기화
void init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}

// 정점 삽입 연산
void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
	fprintf(stderr, "그래프: 정점의 개수 초과");
	return;
	}
}

// 간선 삽입 연산
void insert_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}

	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

// 인접 행렬 출력 함수
void print_adj_mat(GraphType* g)
{
	for (int i = 0; i < g->n; i++)
	{
		for (int j = 0; j < g->n; j++)
		{
			printf("%2d", g->adj_mat[i][j]);
	    }
	printf("\n");
    }
}

void main()
{
	FILE* fp; // 파일 포인터 선언 
	char c;
	int* arr; // 배열 포인터 
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType)); // 그래프의 메모리 공간을 동적할당 받음. 


	
	init(g); // 그래프 초기화 

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
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);

	
	free(g);
	fclose(fp);
}

