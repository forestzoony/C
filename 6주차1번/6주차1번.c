//학과: 컴퓨터소프트웨어공학과
//학번: 20204024
//이름: 임지윤
//프로그램명: 배열을 이용한 히프를 사용하여 우선순위와 동물 이름을 히프에 추가하는 프로그램
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MAX_ELEMENT 200

typedef struct element {
    int num;
    char name[10];
}element;

typedef struct HeapType {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;


//생성 함수
HeapType* create() {
    return (HeapType*)malloc(sizeof(HeapType));
}

//초기화 함수 
void init(HeapType* h)
{
    h->heap_size = 0; // heap_size를 0으로 초기화하는 함수 
}

//삽입 함수 
void insert_max_heap(HeapType* h, element item)
{
    int i;
    i = ++(h->heap_size);

    while ((i != 1) && (item.num > h->heap[i / 2].num)) // 트리를 올라가면서 부모 노드와 자식노드를 비교하는 while 반복문 
    {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}
void print_heap_list(HeapType* h)
{
    int j;

    for (j = 0; j < 11; j++)
    {
        printf("%d: %s", h->heap[j].num, h->heap[j].name);
    }
}
int main(void)
{
    FILE* fp;
    HeapType* heap;
    element e;
    int i;

    heap = creat();
    init(heap);


    fp = fopen("data.txt", "r");

    if (fp == NULL)
    {
        printf("FILE NOT FOUND\n");
    }

    while (!feof(fp))
    {
        fscanf(fp, "%d %s", &e.num, e.name);
        printf(">> (%d : %s) 입력\n", e.num, e.name);
        insert_max_heap(heap, e);

    }

    printf("===== 동물 하프 출력 =====\n");

    print_heap_list(heap);
  
    free(heap);
    fclose(fp);

    return 0;
}


