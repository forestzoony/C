//학번: 20204024
//이름: 임지윤
//학과: 컴퓨터소프트웨어공학과
//프로그램명: 파일 student.txt에 학생의 학번, 이름, 나이, 키 정보들이 저장되어 있다. 연결 리스트에 이 값들을 저장하고 학생들의 정보를 삽입, 삭제, 출력하는 프로그램
     

#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)  // fscanf , fopen 함수 사용 시, 오류 발생을 해결하기 위함. 

typedef struct Student {
    int num;            // 학생의 학번
    char name[20];      // 학생의 이름
    int age;            // 학생의 나이 
    double height;      // 학생의 키 
}Student;
typedef struct ListNode {
    Student data;
    struct ListNode* link;
}ListNode;
ListNode* insert_first(ListNode* head, Student s)     // 각 정보를 연결 리스트의 첫 노드부분에 저장하는 함수 
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = s;
    p->link = head;
    head = p;
    printf(">> %s(%d)의 학생의 모든 정보가 삽입되었습니다.\n", p->data.name, p->data.num);
    return head;
}
void print_list(ListNode* head)       // 학생의 리스트를 출력하는 함수 
{
    printf("===============학생 리스트 출력================\n");

    int i = 1;

    for (ListNode* p = head; p != NULL; p = p->link) {       
        printf("%d\t%d\t%s\t%d\t%lf\n", i, p->data.num, p->data.name, p->data.age, p->data.height);   // p에 저장된 이름, 학번, 나이, 키를 반복문으로 출력함. 
        i++;

    }

    printf("===============================================\n\n");
}
ListNode* delete_list(ListNode* head, int value)      // 학생의 정보를 삭제하는 함수 
{
    ListNode* removed;
    ListNode* pre = NULL;     // 선행노드를 선언하여 NULL 값으로 선언함. 
    removed = head;      

    if (value == removed->data.num)
    {
        head = removed->link;
        printf(">> %s(%d)의 학생의 모든 정보가 삭제되었습니다.\n", removed->data.name, removed->data.num);
        free(removed);
        return head;               // 입력된 값과 학생의 학번이 일치할 경우 
    }
    else
    {
        for (ListNode* p = head; p != NULL; p = p->link)
        {
            if (p->link->data.num == value)
            {
                removed = p->link;
                p->link = removed->link;
                printf(">> %s(%d)의 학생의 모든 정보가 삭제되었습니다.\n", removed->data.name, removed->data.num);
                free(removed);
                return head;       // p->link에 저장된 학번이 value 값과 같을 경우, 정보가 삭제되는 함수를 구현함. 

            }
        }

    }
}
int main()
{
    FILE* fp;
    Student s;
    ListNode* head = NULL;
    int tmp= 0;
    char c=0;

    fp = fopen("student.txt", "r");     // 학생의 정보가 들어있는 텍스트 파일을 읽기 모드로 열기 

    if (fp == NULL)
    {
        printf("FILE NOT FOUND");
        return -1;
    }

    while (!feof(fp))
    {
        fscanf(fp, "%c", &c);

        if (c == 'i')  // 학생의 학번과 이름, 나이, 키를 저장하는 조건문
        {
            fscanf(fp, "%d %s %d %lf", &s.num, s.name, &s.age, &s.height);
            head = insert_first(head, s);
        }
        else if (c == 'p') // 저장된 학생의 정보를 출력함. 
        {
            print_list(head);
        }
        else if (c=='d') // 특정한 학번을 입력할 시, 해당 학생의 정보가 삭제되는 조건문 
        {
            fscanf(fp, "%d", &tmp);
            head = delete_list(head, tmp); // head에 delete 함수를 대입함. 
        }
    }
}

