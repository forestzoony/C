//학과: 컴퓨터소프트웨어공학과
//학번: 20204024
//이름: 임지윤
//프로그램명: 배열로 구현한 노드를 따라가면서 색칠된 노드를 출력하는 완전 이진트리 프로그램 
#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)   

int main()
{
	FILE* fp;
    int c;
    int a[100];  // 배열 a를 선언하는 변수 
    int i = 1;   // 배열 a의 번호를 0이 아닌 1부터 선언 
    int cnt = 0;

    fp = fopen("data.txt", "r");               // data.txt를 읽기 모드로 염. 

    if (fp == NULL)
    {
        printf("FILE NOT FOUND");
        return -1;      
    }                                     // 파일포인터로 지정한 파일이 NULL값이라면 파일을 찾을 수 없음.

    while (!feof(fp))
    {
        fscanf(fp, "%d", &c);
        cnt++;                            // cnt는 배열에 저장되는 텍스트 파일의 숫자들을 세는 개수 
    }

    rewind(fp);

    while (!feof(fp))
    {
        fscanf(fp, "%d", &a[i]);         // 파일이 끝날 때까지 배열 a에 파일포인터에 저장된 정수를 입력받음. 
        i++;
    }

    for (i = 1; i < cnt; i *= 2)       //  배열에 저장된 정수를 출력하는 반복문 
    {
        printf("%d ", a[i]);
    }

}