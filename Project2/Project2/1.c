#include <stdio.h>
#include <string.h>
#include <malloc.h>
#pragma warning(disable: 4996)

typedef struct Student {
	char name[20]; // 이름
	int num; // 학번
	int kor; // 국어성적
	int math; // 수학성적 
	int eng; // 영어성적 
	int average; // 평균
	int sum; // 총점 
}Student;

int main(void)
{
    FILE* fp;
    struct Student* s;
    int cnt = 0;
    int i = 0, temp;
    double avg;
    int sum;

    s = (struct Student*) malloc(sizeof(struct Student) * 10); // 동적메모리 할당

    fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("FILE NOT FOUND");
        return -1;
    }                                   // 파일을 열기모드로 열기 

    while (!feof(fp)) {
        fscanf(fp, "%d %s %d %d %d", &s[i].num, &s[i].name, &s[i].kor, &s[i].math, &s[i].eng);
        //printf("%d %s %d %d %d \n", s[i].num, s[i].name, s[i].kor, s[i].math, s[i].eng);
        cnt++;
        i++;
    }          // 파일이 끝날때까지 파일 내부의 저장된 내용을 구조체 변수에 각각 저장

    fclose(fp);

    printf("===================================================\n");
    printf("학번\t이름\t국어\t영어\t수학\t총점\t평균\t\n");
    printf("===================================================\n");


    for (i = 0; i < cnt; i++)
    {
        sum = s[i].kor + s[i].math + s[i].eng;
        avg = sum / 3;
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%f \n", s[i].num, s[i].name, s[i].kor, s[i].math, s[i].eng, sum, avg);
    }        // 구조체 변수에 저장된 파일의 내용을 출력함. 

    free(s);

    printf("==========================================\n");

}