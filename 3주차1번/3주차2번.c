//�а�: ��ǻ�ͼ���Ʈ������а�
//�й�: 20204024
//�̸�: ������
//���α׷���: �迭�� ������ ��带 ���󰡸鼭 ��ĥ�� ��带 ����ϴ� ���� ����Ʈ�� ���α׷� 
#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)   

int main()
{
	FILE* fp;
    int c;
    int a[100];  // �迭 a�� �����ϴ� ���� 
    int i = 1;   // �迭 a�� ��ȣ�� 0�� �ƴ� 1���� ���� 
    int cnt = 0;

    fp = fopen("data.txt", "r");               // data.txt�� �б� ���� ��. 

    if (fp == NULL)
    {
        printf("FILE NOT FOUND");
        return -1;      
    }                                     // ���������ͷ� ������ ������ NULL���̶�� ������ ã�� �� ����.

    while (!feof(fp))
    {
        fscanf(fp, "%d", &c);
        cnt++;                            // cnt�� �迭�� ����Ǵ� �ؽ�Ʈ ������ ���ڵ��� ���� ���� 
    }

    rewind(fp);

    while (!feof(fp))
    {
        fscanf(fp, "%d", &a[i]);         // ������ ���� ������ �迭 a�� ���������Ϳ� ����� ������ �Է¹���. 
        i++;
    }

    for (i = 1; i < cnt; i *= 2)       //  �迭�� ����� ������ ����ϴ� �ݺ��� 
    {
        printf("%d ", a[i]);
    }

}