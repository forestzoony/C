//�а�: ��ǻ�ͼ���Ʈ������а�
//�й�: 20204024
//�̸�: ������
//���α׷���: Prim�� �ּ� ��� ���� Ʈ�� ���α׷�
#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType {
	int n; // ������ ���� 
	int weight[MAX_VERTICES][MAX_VERTICES]; // 2���� ����� ���� ����ġ�� �޾ƿ� ���� 
}GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

int init_graph(GraphType* g, int max) // �׷��� �ʱ�ȭ �Լ� 
{
	int r, c; // ��� ���� ���� ������ ������. 

	for (r = 0; r < max; r++)
	{
		for (c = 0; c < max; c++)
		{
			g->weight[r][c] = INF; // max�� ��� ���� ������ ������ �ݺ����� �����Ͽ� INF���� ������. 
		}
	}

}
// �ּ� dist[v] ���� ���� ������ ��ȯ
int get_min_vertex(int n)
{
	int v, i;

	for (i = 0; i < n; i++)
	{
		if (!selected[i])
		{
			v = i;
			break; // selected[i]�� �ƴ� ���, i�� ������. 
		}
	}
	for (i = 0; i < n; i++)
	{
		if (!selected[i] && (distance[i] < distance[v]))
		{
			v = i; 
		}

	}
	return (v); // v�� ��ȯ��. 
}


void prim(GraphType* g, int s, int max) // Prim�� �ּ� ���� ��� �˰��� �Լ� 
{
	int i, u, v;
	int j;
	int entire = 0; // ����ġ ���� ���� ���� ������ ������. 

	int arr[7] = { 0 }; // 7*7 ����� ������ ��, �ʱ�ȭ��. 
	g->n = max; // g->n�� ���� ����ų ��, ���� max���� ����. 
	
	printf("\n");
	printf("����\n");

	for (u = 0; u < g->n; u++)
	{
		distance[u] = INF; // INF������ �ʱ�ȭ��. 
	}

	distance[s] = 0; // distance �迭�� 0���� �ʱ�ȭ��. 

	for (i = 0; i < g->n; i++)
	{
		u = get_min_vertex(g->n);
		selected[u] = TRUE;

		if (distance[u] == INF)
		{
			return;
		}
		
		
		printf("%d >> ", i+1); // �迭�� �ε��� ��ȣ�� �ϳ��� �����. 

		arr[i] = u;
		
		for (j = 0; j <= i; j++)
		{
			printf("%d ", arr[j]); // i������ �ݺ��ϸ鼭 arr �迭�� u���� ������. 
		}

		for (v = 0; v < g->n; v++)
		{
			if (g->weight[u][v] != INF)
			{
				if (!selected[v] && g->weight[u][v] < distance[v])
				{
					distance[v] = g->weight[u][v]; // ��� ���� ������Ű�鼭 ��� ���ο� �� ����ġ�� ������. 
				}

			}
		}

		entire += distance[u]; // distance[u]�� ����� ������ ��� ���Ͽ� entire ������ ������. 
		
		printf(": %d\n", entire);

	}
	printf("\n");
	printf("< �ʿ��� �ּ� ��� %d >\n", entire); // ��� ����ġ�� ���� ����. 
}


int main(void)
{
	FILE* fp;
	GraphType* g;
	int x = 0, y = 0, w = 0;
	int max = 0;
	int temp = 0;


	g = (GraphType*)malloc(sizeof(GraphType)); // �׷����� �޸� ������ �����Ҵ� ����. 


	fp = fopen("data1.txt", "r");

	if (fp == NULL)
	{
		printf("FILE NOT FOUND\n");
		return -1;
	}

	while (!feof(fp))
	{
		fscanf(fp,"%d %d %d", &x, &y, &w); // ������ ����ġ�� ���Ͽ��� �Է¹���. 

		if (x > y)
		{
			temp = x; // x���� y���� Ŭ ��� 

		}
		else
		{
			temp = y; // x���� y���� Ŭ ��� 
		}

		if (temp > max)
		{
			max = temp; // max ���� temp���� ������. 

		}
	 
	}
	max++; // ��Ŀ� ����� ũ�� ������ 1��ŭ ������Ŵ 

	init_graph(g, max); // �׷����� �ʱ�ȭ�� 

	rewind(fp); // ������ �ٽ� �о��. 

	while (!feof(fp))
	{
		fscanf(fp, "%d %d", &x, &y);
		fscanf(fp, "%d", &g->weight[x][y]); // ����ġ�� �Է¹޾ƿ�. 
	}
	
	rewind(fp); // ������ ó������ �ٽ� �о���� ����. 

	while (!feof(fp))
	{
		fscanf(fp, "%d %d", &x, &y); // ������ �Է¹޾ƿ�. 
		fscanf(fp, "%d", &g->weight[y][x]); // 2���� ��Ŀ� ����ġ�� �Է¹޾ƿ�. 
	}

	printf("���\n");

	for (x= 0; x < max; x++) // X�� max�� ������ ������ (2���� ���)
	{
		for (y = 0; y < max; y++) // y�� max���� ������ ������ �ݺ���. 
		{

			if (g->weight[x][y] == INF)
			{
				printf("INF "); // 2���� ��Ŀ� ����� ����ġ�� ���� INF�� ��� 
			}
			else
			{
				printf("%d ", g->weight[x][y]);  // ����ġ�� ���� INF�� �ƴ� ��� 
			}
		}
		printf("\n");
	}

	printf("\n- Prim�� �ּ� ��� ���� Ʈ�� ���α׷� -\n");

	prim(g, 0, max); // prim�� �ּ� ��� ���� Ʈ�� �Լ��� ȣ�����. �� ��, max�� �̹� ������ ������. 




}