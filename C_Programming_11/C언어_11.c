// ��ó����

// �������ϱ⿡ �ռ��� �ҽ� ���� ó���ϴ� �����Ϸ��� �� �κ�

// #include ������ : Ư���� ��� ���� ���� ��Ŵ
// �ܼ� ��ũ�� : ���� ����� ��ȣ ����� ���� -> #define PI 3.14
// �Լ� ��ũ�� : ��ũ�ΰ� �Լ�ó�� �Ű����� ���� -> #define SUM(x, y) ( (x) + (y) ) 
// �� �Լ� ��ũ�� ������ : ������ �Ű������� ���� ��ȣ�� ���������
// #ifdef ������ : ���Ǻ� ������ ����(� ������ �����Ǿ��� ���� ������ �ҽ� �ڵ� ��� ������)

// #ifdef ������ ����
/*
#include <stdio.h>

// #define DEBUG

int average(int x, int y)
{
#ifdef DEBUG // #define DEBUG �̰� ���������� �����
	printf("x = %d, y = %d\n", x, y);
//#else
	...
#endif
	return (x + y) / 2;
}

int main()
{
	printf("%d", average(10, 20));
}
*/

// ���� �޸� ����ϱ�

// ���� �޸� �Ҵ� : score = (int*)malloc(100*sizeof(int))
// ���� �޸� �ݳ� : free(score)
// �޸� �Ҵ� �� �� ���� ��� NULL ��ȯ 

// ������ �״�� ��� : *(score+1) = 200
// �迭ó�� ��� : score[0] = 100;

// �޸� ���� �Ҵ� ���� �ڵ�
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, * score, sum = 0;
	printf("��ü �л� �� �Է� : ");
	scanf("%d", &n);

	score = (int*)malloc(n * sizeof(int));
	if (score == NULL)
	{
		printf("���� �޸� �Ҵ� ����");
		exit(0);
	}

	for (i = 0; i < n; i++)
	{
		printf("���� �Է� : ");
		scnaf("%d", &score[i]);
		sum += score[i];
	}
	printf("��� : %d\n", sum / n);
	free(score);

	return 0;
}
*/

// �޸� ���� �Ҵ� ����ü ���� �ڵ�
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
	int number;
	char title[50];
};

int main()
{
	struct Book* p;
	p = (struct Book*)malloc(2 * sizeof(struct Book));

	if (p == NULL)
	{
		printf("���� �޸� �Ҵ� ����");
		exit(0);
	}

	p[0].number = 1;
	strcpy(p[0].title, "C Programming");

	p[1].number = 2;
	strcpy(p[1].title, "Data Structure");

	free(p);
	return 0;
}
*/

// �����Ҵ� �޸� ũ�� ���� : realloc()
// realloc() ���� �ڵ�
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* infile;
	char line[121];
	char* info = NULL;
	int len;
	int total_size = 0;

	infile = fopen("data.txt", "r");
	if (infile == NULL)
	{
		printf("���� ���� ����\n");
		return 1;
	}

	while (fgets(line, 120, infile))
	{
		len = strlen(line);
		total_size += len;
		info = (char*)realloc(info, sizeof(char) * (total_size + 1));
		strcpy(&info[total_size - len], line);
		info[total_size + 1] = NULL;
	}
	printf("%s\n", info);
	return 0;
}
*/