//학과: 컴퓨터소프트웨어공학과
//학번: 20204024
//이름: 임지윤
//프로그램명: 이진 트리를 사용하여 전위, 중위, 후위 순회순으로 텍스트 파일에 저장된 학생의 정보를 출력하는 프로그램
#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

typedef struct element {
    int num;
    char name[100]; // 학번과 이름 변수를 새로운 구조체 내 변수로 선언함. 
}element;
typedef struct TreeNode {
    element key;
    struct TreeNode* left, * right;
}TreeNode;
TreeNode* new_node(element item) // 새로운 노드를 만드는 함수 
{
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode)); // 동적 메모리 할당의 개념을 사용하여 temp에 메모리를 동적으로 할당해줌. 
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
TreeNode* insert_node(TreeNode* node, element key) // 노드를 추가하는 함수
{
    if (node == NULL)
    {
        return new_node(key);     // 노드의 값이 NULL 값일 경우 
    }

    if (key.num < node->key.num)
    {
        node->left = insert_node(node->left, key);  // 입력한 학번이 노드의 학번보다 작을 경우,
    }
    else if (key.num > node->key.num)
    {
        node->right = insert_node(node->right, key); // 입력한 학번이 노드의 학번보다 클 경우, 
    }
    return node;
}
void preorder(TreeNode* root) {
    if (root != NULL)
    {
        printf(" %d %s →", root->key.num, root->key.name);
        preorder(root->left); // 전위 순회 함수를 재귀 호출하는 함수 ( 자기 자신을 다시 한번 호출하는 함수 )
        preorder(root->right);
    }
} // 전위 순회 함수
void inorder(TreeNode* root) {
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %d %s →", root->key.num, root->key.name);
        inorder(root->right);                  
    }
}  // 중위 순회 함수 
void postorder(TreeNode* root) {
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d %s →", root->key.num, root->key.name);
    }
} // 후위 순회 함수 
int main(void)
{
    FILE* fp;   // 파일 입출력의 개념을 사용하기 위하여 파일 포인터 fp를 선언함. 
    struct element e;
    TreeNode* root = NULL;

    fp = fopen("data.txt", "r");               // data.txt를 읽기 모드로 염. 

    if (fp == NULL)
    {
        printf("FILE NOT FOUND");
        return -1;
    }                                     // 파일포인터로 지정한 파일이 NULL값이라면 파일을 찾을 수 없음.

    while (!feof(fp))
    {
        fscanf(fp, "%d %s", &e.num, e.name);
        root = insert_node(root, e);
    }

    fclose(fp);
    // 순회 함수들을 호출할 때, 마지막 텍스트 파일의 내용을 읽은 후, 화살표가 표시되지 않도록 \b 문자를 사용하였음. 
    printf("전위 순회 :");
    preorder(root);
    printf("\b\b  \n"); // 메인 함수 내부에 전위 순회 함수를 불러오는 함수를 호출함. 

    printf("중위 순회 :");
    inorder(root);
    printf("\b\b  \n");  // 메인 함수 내부에 중위 순회 함수를 불러오는 함수를 호출함. 

    printf("후위 순회 :");
    postorder(root);
    printf("\b\b  \n");  // 메인 함수 내부에 후위 순회 함수를 불러오는 함수를 호출함. 
    return 0;

}