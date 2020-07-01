#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	char name[10];
	int height;
	int weight;
}Person;
int npcmp(const Person* x, const Person* y)
{
	return strcmp(x->name, y->name);
}

int hpcmp(const Person* x, const Person* y)
{
	return x->height < y->height ? -1 : x->height > y->height ? 1 : 0;
}
int wpcmp(const Person* x, const Person* y)
{
	return x->weight < y->weight ? 1 : x->weight > y->weight ? -1 : 0;
}

void print_person(const Person x[], int no)
{
	for (int i = 0; i < no; i++)
	{
		printf("%-10s %dcm %dkg\n", x[i].name, x[i].height, x[i].weight);
	}
}

int main(void)
{
	Person x[] = {
		{"sunmi", 170, 52},
		{"yoobin", 180, 70},
		{"sohee", 172, 63},
		{"jina", 165, 50},
	};
	int nx = sizeof(x) / sizeof(x[0]);

	puts("정렬 전");
	print_person(x, nx);

	qsort(x, nx, sizeof(Person), (int(*)(const void*, const void*))npcmp);
	puts("\n이름 오름차순으로 정렬 후");
	print_person(x, nx);

	qsort(x, nx, sizeof(Person), (int(*)(const void*, const void*))hpcmp);
	puts("\n키 오름차순으로 정렬 후");
	print_person(x, nx);
	qsort(x, nx, sizeof(Person), (int(*)(const void*, const void*))wpcmp);
	puts("\n몸무게 내림차순으로 정렬 후");
	print_person(x, nx);
}