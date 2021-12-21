//학과: 컴퓨터소프트웨어공학과
//학번: 20204024
//이름: 임지윤
//프로그램명: Prim의 최소 비용 신장 트리 프로그램
#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType {
	int n; // 정점의 개수 
	int weight[MAX_VERTICES][MAX_VERTICES]; // 2차원 행렬을 통해 가중치를 받아올 변수 
}GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

int init_graph(GraphType* g, int max) // 그래프 초기화 함수 
{
	int r, c; // 행과 열을 받을 변수를 선언함. 

	for (r = 0; r < max; r++)
	{
		for (c = 0; c < max; c++)
		{
			g->weight[r][c] = INF; // max에 행과 열이 도달할 때까지 반복문을 수행하여 INF값을 대입함. 
		}
	}

}
// 최소 dist[v] 값을 갖는 정점을 반환
int get_min_vertex(int n)
{
	int v, i;

	for (i = 0; i < n; i++)
	{
		if (!selected[i])
		{
			v = i;
			break; // selected[i]이 아닐 경우, i를 대입함. 
		}
	}
	for (i = 0; i < n; i++)
	{
		if (!selected[i] && (distance[i] < distance[v]))
		{
			v = i; 
		}

	}
	return (v); // v를 반환함. 
}


void prim(GraphType* g, int s, int max) // Prim의 최소 신장 비용 알고리즘 함수 
{
	int i, u, v;
	int j;
	int entire = 0; // 가중치 값의 합을 담을 변수를 선언함. 

	int arr[7] = { 0 }; // 7*7 행렬을 선언한 후, 초기화함. 
	g->n = max; // g->n은 끝을 가리킬 때, 끝은 max값과 같음. 
	
	printf("\n");
	printf("과정\n");

	for (u = 0; u < g->n; u++)
	{
		distance[u] = INF; // INF값으로 초기화함. 
	}

	distance[s] = 0; // distance 배열을 0으로 초기화함. 

	for (i = 0; i < g->n; i++)
	{
		u = get_min_vertex(g->n);
		selected[u] = TRUE;

		if (distance[u] == INF)
		{
			return;
		}
		
		
		printf("%d >> ", i+1); // 배열의 인덱스 번호를 하나씩 출력함. 

		arr[i] = u;
		
		for (j = 0; j <= i; j++)
		{
			printf("%d ", arr[j]); // i값까지 반복하면서 arr 배열에 u값을 대입함. 
		}

		for (v = 0; v < g->n; v++)
		{
			if (g->weight[u][v] != INF)
			{
				if (!selected[v] && g->weight[u][v] < distance[v])
				{
					distance[v] = g->weight[u][v]; // 행과 열을 증가시키면서 행렬 내부에 각 가중치를 저장함. 
				}

			}
		}

		entire += distance[u]; // distance[u]에 저장된 값들을 모두 더하여 entire 변수에 저장함. 
		
		printf(": %d\n", entire);

	}
	printf("\n");
	printf("< 필요한 최소 비용 %d >\n", entire); // 모든 가중치의 값을 합함. 
}


int main(void)
{
	FILE* fp;
	GraphType* g;
	int x = 0, y = 0, w = 0;
	int max = 0;
	int temp = 0;


	g = (GraphType*)malloc(sizeof(GraphType)); // 그래프의 메모리 공간을 동적할당 받음. 


	fp = fopen("data1.txt", "r");

	if (fp == NULL)
	{
		printf("FILE NOT FOUND\n");
		return -1;
	}

	while (!feof(fp))
	{
		fscanf(fp,"%d %d %d", &x, &y, &w); // 정점과 가중치를 파일에서 입력받음. 

		if (x > y)
		{
			temp = x; // x값이 y보다 클 경우 

		}
		else
		{
			temp = y; // x보다 y값이 클 경우 
		}

		if (temp > max)
		{
			max = temp; // max 값에 temp값을 대입함. 

		}
	 
	}
	max++; // 행렬에 사용할 크기 값으로 1만큼 증가시킴 

	init_graph(g, max); // 그래프를 초기화함 

	rewind(fp); // 파일을 다시 읽어옴. 

	while (!feof(fp))
	{
		fscanf(fp, "%d %d", &x, &y);
		fscanf(fp, "%d", &g->weight[x][y]); // 가중치를 입력받아옴. 
	}
	
	rewind(fp); // 파일을 처음부터 다시 읽어오기 위함. 

	while (!feof(fp))
	{
		fscanf(fp, "%d %d", &x, &y); // 정점을 입력받아옴. 
		fscanf(fp, "%d", &g->weight[y][x]); // 2차원 행렬에 가중치를 입력받아옴. 
	}

	printf("행렬\n");

	for (x= 0; x < max; x++) // X가 max에 도달할 때까지 (2차원 행렬)
	{
		for (y = 0; y < max; y++) // y가 max값에 도달할 때까지 반복함. 
		{

			if (g->weight[x][y] == INF)
			{
				printf("INF "); // 2차원 행렬에 저장된 가중치의 값이 INF일 경우 
			}
			else
			{
				printf("%d ", g->weight[x][y]);  // 가중치의 값이 INF이 아닐 경우 
			}
		}
		printf("\n");
	}

	printf("\n- Prim의 최소 비용 신장 트리 프로그램 -\n");

	prim(g, 0, max); // prim의 최소 비용 신장 트리 함수를 호출받음. 이 때, max는 이미 지정한 상태임. 




}