//학과: 컴퓨터소프트웨어공학과
//학번: 20204024
//이름: 임지윤
//프로그램명: Kruskal의 최소 비용 신장 트리 프로그램

#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)
 
#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 100

int parent[MAX_VERTICES];

void set_init(int n)
{
	for (int i = 0; i < n; i++)
	{
		parent[i] = -1;
	}
}

//curr가 속하는 집합을 반환한다. 
int set_find(int curr)
{
	if (parent[curr] == -1)
	{
		return curr; //루트 
	}
	while (parent[curr] != -1)
	{
		curr = parent[curr];
	}
	return curr;
}

//두개의 원소가 속한 집합을 합친다. 
void set_union(int a, int b)
{
	int root1 = set_find(a);
	int root2 = set_find(b);

	if (root1 != root2)
	{
		parent[root1] = root2;
	}
}

// 간선을 나타내는 구조체 
struct Edge {
	int start, end, weight;
};

typedef struct GraphType {
	int n;  // 간선의 개수 
	struct Edge edges[2 * MAX_VERTICES];
}GraphType;

// 그래프 초기화 
void graph_init(GraphType* g)
{
	g->n = 0;
	for (int i = 0; i < 2 * MAX_VERTICES; i++)
	{
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF;
	}
}

// 간선 삽입 연산
void insert_edge(GraphType* g, int start, int end, int w)
{
	int i = 0;
	g->edges[g->n].start = start;
	g->edges[g->n].end = end;
	g->edges[g->n].weight = w;

	for (i = 0; i < g->n; i++)
	{
		if (g->edges[i].start == end && g->edges[i].end == start) // 정점의 시작과 끝의 값이 같을 경우 
		{
			printf("간선 %d - %d 은 이미 추가된 간선입니다. --제외\n", start, end); // 이미 추가한 간선으로 표시함. 
			return 0;
		}
	}
	g->n++;
}

// qsort()에 사용하는 함수 
int compare(const void* a, const void* b)
{
	struct Edge* x = (struct Edge*)a;
	struct Edge* y = (struct Edge*)b;
	return (x->weight - y->weight);
}

// kruskal의 최소 비용 신장 트리 프로그램
void kruskal(GraphType* g)
{
	int edge_accepted = 0; // 현재까지 선택된 간선의 수
	int uset, vset; // 정점 u와 정점 v의 집합 번호
	struct Edge e;

	set_init(g->n);
	qsort(g->edges, g->n, sizeof(struct Edge), compare);
	

	
	int i = 0;

	while (edge_accepted < (g->n))
	{

		e = g->edges[i];
	
		uset = set_find(e.start);
		vset = set_find(e.end);
		
		if (uset != vset)
		{
			printf("간선 %d-%d : %d\n", e.start, e.end, e.weight);
			edge_accepted++;
			set_union(uset, vset); // 두개의 집합을 합친다. 
		}

		else
		{
			printf("간선 %d-%d : %d - 사이클 생성으로 제외\n", e.start, e.end, e.weight);
			edge_accepted++;
			set_union(uset, vset); // 두개의 집합을 합친다. 
		}
		i++;
	}
}

int main(void)
{
	FILE* fp; 
	GraphType* g; 
	g = (GraphType*)malloc(sizeof(GraphType)); // 메모리 크기를 동적할당한다. 
	int start = 0, end = 0, w = 0; // 정점과 가중치의 값을 초기화한다. 

	graph_init(g); // 그래프를 초기화하는 함수 

	fp = fopen("data.txt", "r"); // 파일을 읽기 모드로 열기 

	if (fp == NULL)
	{
		printf("FILE NOT FOUND\n");
		return -1; // 파일 포인터가 NULL값을 가리킬 경우, 파일을 찾을 수 없음이라고 표시함. 
	}

	printf(">> 데이터 입력\n");

	while (!feof(fp)) // 파일의 끝을 도달할 때까지 반복문을 수행함. 
	{
		fscanf(fp, "%d %d %d", &start, &end, &w);
		insert_edge(g, start, end, w); // 정점 삽입 연산 함수에 정점의 값과 가중치의 값을 추가함. 
		printf("간선 %d - %d 추가 완료\n", start, end);
	}
    
	printf("\n");
	printf(">> 과정\n");
	 
	kruskal(g); // 크루스칼 함수를 실행함. 

	 
	free(g); // 동적할당한 메모리 공간을 해제함. 
	fclose(fp); // 파일을 닫음. 
	return 0;

}


