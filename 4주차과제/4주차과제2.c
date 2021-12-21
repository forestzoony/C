//학과: 컴퓨터소프트웨어공학과 
//학번: 20204024
//이름: 임지윤
//프로그램명: 텍스트 파일에서 정수로 이루어진 정보를 읽어와 이진트리로 구현하고 완전 이진 트리인지 판별하는 프로그램
#include <stdlib.h>
#include <stdio.h>
#include <math.h> // pow 함수를 사용하기 위해 포함한 헤더파일 
#pragma warning (disable: 4996) // fopen, fscanf 함수의 오류를 수정하기 위해 포함한 헤더파일 

typedef int element;
typedef struct TreeNode {
    element key;
    struct TreeNode* left, * right;  // 왼쪽노드와 오른쪽 노드를 구현하기 위함. 
}TreeNode;
TreeNode* new_node(int item) // 동적으로 메모리를 할당하여 새로운 노드를 생성하여 반환하는 함수 
{
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode)); // 포인터 변수에 동적할당으로 메모리를 할당받음. 
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
TreeNode* insert_node(TreeNode* node, element key) // 이진트리 삽입 함수 
{
    if (node == NULL)
        return new_node(key);
    if (key < node->key)
        node->left = insert_node(node->left, key);
    else if (key > node->key)
        node->right = insert_node(node->right, key);

    return node;
}
int get_height(TreeNode* node)
{
    int height = 0; //높이를 0으로 초기화함. 

    if (node != NULL)
    {
        height = 1 + max(get_height(node->left),
            get_height(node->right));     // 왼족 노드와 오른쪽 노드의 최대값에 1을 더한 값이 노드의 높이가 됨. 
    }
    return height; // 높이의 값을 반환함. 
}       // 트리의 높이를 구하는 함수 
int* preorder(TreeNode* root, int* arr, int i) { // 전위순회를 구현하는 함수 

    arr[i] = root->key; // 배열에 노드의 값을 담음.

    if (root->left) { 
        preorder(root->left, arr, 2 * i); // 루트의 왼쪽 노드일 경우, 배열의 인덱스 번호가 2i씩 증가하며 내려감. 
    }
    if (root->right) { 
        preorder(root->right, arr, 2 * i + 1); // 루트의 오른쪽 노드일 경우, 배열의 인덱스 번호가 2i+1씩 증가하며 내려감.
    }
    return arr; // 배열을 반환함.
}
int main(void)
{
    int index = 0;
    TreeNode* root = NULL;
    element e;
    int count = 0; // 노드의 개수를 알기 위해 count 값을 0으로 초기화.
    int* arr; // 메인함수에서 arr 변수를 사용하기 위해 선언함. 
    int height = 0; // 노드의 높이는 0으로 초기화함.
    int i; 
    int boolean = 1;
    int size;

    FILE* fp; // 파일 입출력의 개념을 사용하기 위하여 파일 포인터 fp를 선언함. 
    fp = fopen("data2.txt", "r");  // data.txt를 읽기 모드로 염. 

    if (fp == NULL)
    {
        printf("FILE NOT FOUND");
        return -1;
    }                                     // 파일포인터로 지정한 파일이 NULL값이라면 파일을 찾을 수 없음.

    while (!feof(fp))
    {
        fscanf(fp, "%d", &e); // 파일 포인터 fp에 저장된 텍스트 파일의 내용을 입력받음.
        root = insert_node(root, e);
        printf("Inserted %d\n", e);
        count++; // 노드의 개수 
    }

    height = get_height(root); // 높이 변수에 높이 구하는 함수를 대입함. 
    size = (int)pow(2, height); // 트리의 높이를 size 변수에 저장함.

    arr = (int*)malloc(sizeof(int) * size); // 동적할당으로 배열의 크기를 할당받음. 

    for (i = 0; i < size; i++)
    {
        arr[i] = 0;
                                // i가 증가할 때마다 배열 인덱스에 0을 대입함. 
    }

    arr = preorder(root, arr, 1); // 전위 순회 함수를 이용하여 배열에 값을 대입함. 

    i = size - 1;
    

    while (i > count)
    {
        if (arr[i] != 0)
        {
            boolean = 0;  // 완전 이진트리를 검사하는 조건문
        }
        i--;
    }

    if (boolean == 1)
    {
        printf("완전 이진트리가 맞습니다.");
    }
    else // boolean = 0일 경우,
    {
        printf("완전 이진트리가 아닙니다.");
    }
    return 0;   
}

