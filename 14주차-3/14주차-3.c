//학과: 컴퓨터소프트웨어공학과
//학번: 20204024
//이름: 임지윤
//프로그램명: 선형조사법을 이용한 해싱 프로그램 
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#pragma warning(disable:4996)

#define TABLE_SIZE 10
#define MOD 7

typedef struct {
	char key[TABLE_SIZE];
}element;

element hash_table[MOD];

void init_table(element ht[]) // 해싱 테이블을 초기화하는 함수 
{
	int i; // 정수형 변수 i를 선언함. 
	
	for (i = 0; i < MOD; i++) // MOD까지 i를 1씩 증가시키면서, 해싱 테이블의 키값을 NULL값으로 초기화함. 
	{
		ht[i].key[0] = NULL;
	}
}

int transform(char* key) // 키값을 숫자로 변환해주는 함수 
{
	int number = 0; // 정수형 변수 number을 0으로 선언함. 

	while (*key) {
		number = number * 10 + (int)(*key - 48);
		key++;
	}
	return number;
}

int hash_function(char* key)
{
	return transform(key) * MOD;
}

#define empty(item) (strlen(item.key) == 0)
#define equal(item1,item2) (!strcmp(item1.key, item2.key))

void hash_lp_add(element item, element ht[])
{
	int i, hash_value;

	hash_value = i = hash_function(item.key);

	while (!empty(ht[i])) {
		if (equal(item, ht[i])) {
			fprintf(stderr, "탐색키가 중복되었습니다\n");
			exit(1);
		}
		i = (i + 1) & TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "테이블이 가득찼습니다.\n");
			exit(1);
		}
	}
	ht[i] = item;
}

void hash_lp_search(element item, element ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);

	while (!empty(ht[i]))
	{
		if (equal(item, ht[i]))
		{
			fprintf(stderr, "%s 는 HashTable: %d에서 검색되었습니다.\n", item.key,i);
			return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "입력하신 값 %s 은 HashTable에서 검색되지 않았습니다.\n", item.key);
			return;
		}
	}
	fprintf(stderr, "입력하신 값 %s 은 HashTable에서 검색되지 않았습니다\n",item.key);
}

void hash_lp_print(element ht[])
{
	int i;

	for (i = 0; i < MOD; i++)
	{
		printf("data = %s 저장\n",ht[i].key);
	}
}

int main(void)
{
	FILE* fp;
	char* n[TABLE_SIZE][TABLE_SIZE];
	char* m[TABLE_SIZE][TABLE_SIZE];
	int i = 0;
	int j = 0;
	int count = 0;
	int cnt = 0;
	char c = 0;
	element e;

	fp = fopen("data.txt", "r");

	if (fp == NULL)
	{
		printf("FILE NOT FOUND");
		return -1;
	}


	while (!feof(fp))
	{
		fscanf(fp, "%c", &c);

		if (c == 'i')
		{
			fscanf(fp, "%s\n", &n[i]);
			count++;	
		}	

		if (c == 's')
		{
			fscanf(fp, "%s\n", &m[j]);
			cnt++;
		}

	}

	printf("< HashTable Size = [%d] >\n", TABLE_SIZE); // 해싱 테이블의 크기를 출력하는 문장. 
	
	printf("\n< Data Insert Finish >\n"); // 해싱 테이블에 데이터를 삽입하는 구간. 

	for (i = 0; i < count; i++)
	{
		strcpy(e.key, n[i]);
		hash_lp_add(e, hash_table);
		hash_lp_print(hash_table);
		
	}

	printf("< Find Data Location >\n"); // 데이터의 위치를 찾는 함수를 호출하는 구간 

	for (j = 0; j < cnt; j++)
	{
		strcpy(e.key, m[j]);
		hash_lp_search(e, hash_table);
	}

	printf("<finish>\n");

	fclose(fp);
	return 0;
}
  