// 전처리기

// 컴파일하기에 앞서서 소스 파일 처리하는 컴파일러의 한 부분

// #include 지시자 : 특정한 헤더 파일 포함 시킴
// 단순 매크로 : 숫자 상수를 기호 상수로 만듬 -> #define PI 3.14
// 함수 매크로 : 매크로가 함수처럼 매개변수 가짐 -> #define SUM(x, y) ( (x) + (y) ) 
// ※ 함수 매크로 주의점 : 각각의 매개변수를 전부 괄호로 묶어줘야함
// #ifdef 지시자 : 조건부 컴파일 지시(어떤 조건이 만족되었을 때만 지정된 소스 코드 블록 컴파일)

// #ifdef 지시자 예시
/*
#include <stdio.h>

// #define DEBUG

int average(int x, int y)
{
#ifdef DEBUG // #define DEBUG 이게 켜져있으면 실행됨
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

// 동적 메모리 사용하기

// 동적 메모리 할당 : score = (int*)malloc(100*sizeof(int))
// 동적 메모리 반납 : free(score)
// 메모리 할당 할 수 없는 경우 NULL 반환 

// 포인터 그대로 사용 : *(score+1) = 200
// 배열처럼 사용 : score[0] = 100;

// 메모리 동적 할당 예제 코드
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, * score, sum = 0;
	printf("전체 학생 수 입력 : ");
	scanf("%d", &n);

	score = (int*)malloc(n * sizeof(int));
	if (score == NULL)
	{
		printf("동적 메모리 할당 오류");
		exit(0);
	}

	for (i = 0; i < n; i++)
	{
		printf("점수 입력 : ");
		scnaf("%d", &score[i]);
		sum += score[i];
	}
	printf("평균 : %d\n", sum / n);
	free(score);

	return 0;
}
*/

// 메모리 동적 할당 구조체 예제 코드
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
		printf("동적 메모리 할당 오류");
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

// 동적할당 메모리 크기 변경 : realloc()
// realloc() 예제 코드
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
		printf("파일 열기 오류\n");
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