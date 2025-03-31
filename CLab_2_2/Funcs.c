#include <stdio.h>
#include <Windows.h>

int InputInt(char mess[])
{
	printf_s("%s ", mess);
	int num = 0;
	while (scanf_s("%d", &num) == 0)
	{
		while (getchar() != '\n');
		puts("Вы ввели что-то не так, повторите ввод:");
	}
	return num;
}
double InputDouble(char mess[])
{
	printf_s("%s ", mess);
	double num = 0;
	while (scanf_s("%lf", &num) == 0)
	{
		while (getchar() != '\n');
		puts("Вы ввели что-то не так, повторите ввод:");
	}
	return num;
}
int** GiveMemoryToMatrix(int** arr, int size_i, int size_j)
{
	arr = (int**)malloc(size_i * sizeof(int*));
	if (arr == NULL) 
	{
		puts("Ошибка выделения памяти");
		return 1;
	}
	for (int i = 0; i < size_i; i++) 
	{
		*(arr + i) = (int*)malloc(size_j * sizeof(int));
		if (*(arr + i) == NULL)
		{
			puts("Ошибка выделения памяти");
			free(arr);
			return 1;
		}
	}
	return arr;
}
int** InputMatrix(int** arr, int size_i, int size_j)
{
	for (int i = 0; i < size_i; i++) 
	{
		for (int j = 0; j < size_j; j++) 
		{
			printf_s("arr[%2d][%2d] = ", i + 1, j + 1);
			while (scanf_s("%d", (*(arr + i) + j)) == 0)
			{
				while (getchar() != '\n');
				puts("Вы ввели что-то не так, повторите ввод");
				printf_s("arr[%2d][%2d] = ", i + 1, j + 1);
			}
		}
	}
	return arr;
}
void OutputMatrix(int** arr, int size_i, int size_j)
{
	for (int i = 0; i < size_i; i++) 
	{
		for (int j = 0; j < size_j; j++) 
		{
			printf("%2d ", *(*(arr + i) + j));
		}
		puts("");
	}
}
void OutputArr(double* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("arr[%2d] = %.2lf\n", i + 1, *(arr + i));
	}
}
double* AvarageInColl(int** arr, int size_i, int size_j, double* arr_av)
{
	arr_av = (double*)malloc(size_j * sizeof(double));
	if (arr_av == NULL)
	{
		puts("Ошибка выделения памяти\n");
		return 1;
	}
	for (int j = 0; j < size_j; j++)
	{
		*(arr_av + j) = 0;
		for (int i = 0; i < size_i; i++)
		{
			*(arr_av + j) += *(*(arr + i) + j);
		}
		*(arr_av + j) /= size_i;
	}
	return arr_av;
}