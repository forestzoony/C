//�а�: ��ǻ�ͼ���Ʈ������а� 
//�й�: 20204024
//�̸�: ������
//���α׷���: �ؽ�Ʈ ���Ͽ��� ������ �̷���� ������ �о�� ����Ʈ���� �����ϰ� ���� ���� Ʈ������ �Ǻ��ϴ� ���α׷�
#include <stdlib.h>
#include <stdio.h>
#include <math.h> // pow �Լ��� ����ϱ� ���� ������ ������� 
#pragma warning (disable: 4996) // fopen, fscanf �Լ��� ������ �����ϱ� ���� ������ ������� 

typedef int element;
typedef struct TreeNode {
    element key;
    struct TreeNode* left, * right;  // ���ʳ��� ������ ��带 �����ϱ� ����. 
}TreeNode;
TreeNode* new_node(int item) // �������� �޸𸮸� �Ҵ��Ͽ� ���ο� ��带 �����Ͽ� ��ȯ�ϴ� �Լ� 
{
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode)); // ������ ������ �����Ҵ����� �޸𸮸� �Ҵ����. 
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
TreeNode* insert_node(TreeNode* node, element key) // ����Ʈ�� ���� �Լ� 
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
    int height = 0; //���̸� 0���� �ʱ�ȭ��. 

    if (node != NULL)
    {
        height = 1 + max(get_height(node->left),
            get_height(node->right));     // ���� ���� ������ ����� �ִ밪�� 1�� ���� ���� ����� ���̰� ��. 
    }
    return height; // ������ ���� ��ȯ��. 
}       // Ʈ���� ���̸� ���ϴ� �Լ� 
int* preorder(TreeNode* root, int* arr, int i) { // ������ȸ�� �����ϴ� �Լ� 

    arr[i] = root->key; // �迭�� ����� ���� ����.

    if (root->left) { 
        preorder(root->left, arr, 2 * i); // ��Ʈ�� ���� ����� ���, �迭�� �ε��� ��ȣ�� 2i�� �����ϸ� ������. 
    }
    if (root->right) { 
        preorder(root->right, arr, 2 * i + 1); // ��Ʈ�� ������ ����� ���, �迭�� �ε��� ��ȣ�� 2i+1�� �����ϸ� ������.
    }
    return arr; // �迭�� ��ȯ��.
}
int main(void)
{
    int index = 0;
    TreeNode* root = NULL;
    element e;
    int count = 0; // ����� ������ �˱� ���� count ���� 0���� �ʱ�ȭ.
    int* arr; // �����Լ����� arr ������ ����ϱ� ���� ������. 
    int height = 0; // ����� ���̴� 0���� �ʱ�ȭ��.
    int i; 
    int boolean = 1;
    int size;

    FILE* fp; // ���� ������� ������ ����ϱ� ���Ͽ� ���� ������ fp�� ������. 
    fp = fopen("data2.txt", "r");  // data.txt�� �б� ���� ��. 

    if (fp == NULL)
    {
        printf("FILE NOT FOUND");
        return -1;
    }                                     // ���������ͷ� ������ ������ NULL���̶�� ������ ã�� �� ����.

    while (!feof(fp))
    {
        fscanf(fp, "%d", &e); // ���� ������ fp�� ����� �ؽ�Ʈ ������ ������ �Է¹���.
        root = insert_node(root, e);
        printf("Inserted %d\n", e);
        count++; // ����� ���� 
    }

    height = get_height(root); // ���� ������ ���� ���ϴ� �Լ��� ������. 
    size = (int)pow(2, height); // Ʈ���� ���̸� size ������ ������.

    arr = (int*)malloc(sizeof(int) * size); // �����Ҵ����� �迭�� ũ�⸦ �Ҵ����. 

    for (i = 0; i < size; i++)
    {
        arr[i] = 0;
                                // i�� ������ ������ �迭 �ε����� 0�� ������. 
    }

    arr = preorder(root, arr, 1); // ���� ��ȸ �Լ��� �̿��Ͽ� �迭�� ���� ������. 

    i = size - 1;
    

    while (i > count)
    {
        if (arr[i] != 0)
        {
            boolean = 0;  // ���� ����Ʈ���� �˻��ϴ� ���ǹ�
        }
        i--;
    }

    if (boolean == 1)
    {
        printf("���� ����Ʈ���� �½��ϴ�.");
    }
    else // boolean = 0�� ���,
    {
        printf("���� ����Ʈ���� �ƴմϴ�.");
    }
    return 0;   
}

