//컴퓨터소프트웨어공학과
//20204024
//임지윤
//프로그램명: 파일에 저장된 자료를 읽어와 연결 리스트에 저장하는 파일을 작성한 후, 각 숫자를 버블정렬을 활용하여 오름차순으로 정렬하는 프로그램

#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t) ((t)= (x), (x) = (y), (y) = (t))
#pragma warning (disable: 4996)

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, int value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}
void print_list(ListNode* head)
{
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
}
void bubble_sort(head,cnt)
{
    int i, j, temp;
    ListNode* a;
    ListNode* m;
     
    a = head;
    m = a->link;

    for (i = cnt - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (a->data > m->data)
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
int main()
{
    FILE* fp;
    int num;
    int cnt = 0;
    ListNode* head = NULL;

    fp = fopen("data.txt", "r");

    if (fp == NULL)
    {
        printf("FILE NOT FOUND");
        return -1;
    }
    printf("< 오름차순 정렬 >\n");
    while (!feof(fp)) {
        fscanf(fp, "%d -> ", &num);
        head = insert_first(head, num);
        cnt++;
    }
    bubble_sort(head, cnt);
    print_list(head);
    

    fclose(fp);
}