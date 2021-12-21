//컴퓨터소프트웨어공학과
//20204024
//임지윤
//프로그램명: 텍스트파일에 저장된 정보를 학번,이름,총점 순으로 각각 정리하는 프로그램

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable: 4996)

typedef struct Student {
    int num;
    char name[10];
    int kor;
    int math;
    int eng;
    int tot;
    double avg;
}Student;
typedef struct ListNode {
    Student data;
    struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, Student s)
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = s;
    p->link = head;
    head = p;
    return head;
}
void bubble_sort(ListNode* head, int cnt)
{

    int i, j;
    Student temp;
    ListNode* a;
    ListNode* m;


    a = head;
    m = a->link;

    for (i = cnt - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (a->data.num > m->data.num)
            {
                temp = a->data;
                a->data = m->data;
                m->data = temp;

            }
            a = a->link;
            m = m->link;
        }
        a = head;
        m = a->link;
    }
}
void bubble_sort_two(ListNode* head, int cnt)
{
    int i, j;
    Student temp;
    ListNode* a;
    ListNode* m;

    a = head;
    m = a->link;

    for (i = cnt - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (strcmp(a->data.name, m->data.name) > 0)
            {
                temp = a->data;
                a->data = m->data;
                m->data = temp;

            }
            a = a->link;
            m = m->link;
        }
        a = head;
        m = a->link;
    }
}
void bubble_sort_three(ListNode* head, int cnt)
{
    int i, j;
    Student temp;
    ListNode* a;
    ListNode* m;

    a = head;
    m = a->link;

    for (i = cnt - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (a->data.tot < m->data.tot)
            {
                temp = a->data;
                a->data = m->data;
                m->data = temp;

            }
            a = a->link;
            m = m->link;
        }
        a = head;
        m = a->link;
    }
}
void print_list(ListNode* head)
{
    printf("===================================================\n");
    printf("학번\t이름\t수학\t국어\t영어\t총점\t평균\n");
    printf("===================================================\n");


    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%lf\n", p->data.num, p->data.name, p->data.math, p->data.kor, p->data.eng, p->data.tot, p->data.avg);

}
int main()
{
    FILE* fp;
    Student s;
    ListNode* head = NULL;
    int ans;
    int cnt = 0;

    fp = fopen("data.txt", "r");

    if (fp == NULL)
    {
        printf("FILE NOT FOUND");
        return -1;
    }

    while (!feof(fp)) {
        fscanf(fp, "%d %s %d %d %d", &s.num, s.name, &s.kor, &s.math, &s.eng);
        s.tot = s.kor + s.math + s.eng;
        s.avg = s.tot / (float)3;
        head = insert_first(head, s);
        cnt++;
    }

    while (1) {
        printf("숫자 입력: ");
        scanf("%d", &ans);

        if (ans == 1) {

            bubble_sort(head, cnt);
            print_list(head);
        }
        else if (ans == 2) {
            bubble_sort_two(head, cnt);
            print_list(head);
        }
        else if (ans == 3) {
            bubble_sort_three(head, cnt);
            print_list(head);
        }
        else if (ans == 0) {
            break;
        }

        fclose(fp);

    }
}