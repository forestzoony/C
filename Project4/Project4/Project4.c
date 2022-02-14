#include <stdio.h>

int main()
{
	int score;

	printf("점수를 입력하시오: ");
	scanf_s("%d", &score);

	switch (score / 10) // 입력된 점수를 10으로 나눈 몫
	{
	case 10:     
	{
		printf("Grade: A");
		break;
	}
	case 9: 
	{
		printf("Grade: A");
		break;
	}
	case 8:
	{
		printf("Grade: B");
		break;
	}
	case 7:
	{
		printf("Grade: C");
		break;
	}
	case 6:
	{
		printf("Grade: D");
		break;
	}
	case 5:
	case 4:
	case 3:
	case 2:
	case 1:
	case 0:
	{
		printf("Grade: E");
		break;
	}
	default:
	{
		break;
	}
	return 0;
	}
}