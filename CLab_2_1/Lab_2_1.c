#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define MAXSIZE 20
#define BUFFER 100

/*
В каждом из трех массивов вещественных чисел удалить все элементы, 
принадлежащие интервалу [A, B]. Массивы объявить как динамические.
*/

typedef struct
{
	double* arr;
	int size;
	char name[BUFFER];
} ARRAYS;

int InputInt(char mess[])
{
	printf_s("%s ", mess);
	int num;
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
	double num;
	while (scanf_s("%lf", &num) == 0)
	{
		while (getchar() != '\n');
		puts("Вы ввели что-то не так, повторите ввод:");
	}
	return num;
}
int InputArr(double* arr, char arr_name[])
{
	printf_s("Введите размер массива %s: ", arr_name);
	int arr_size;
	while (scanf_s("%d", &arr_size) == 0 || arr_size > MAXSIZE || arr_size < 1)
	{
		while (getchar() != '\n');
		puts("Вы ввели что-то не так, повторите ввод:");
	}
	for (int i = 0; i < arr_size; i++)
	{
		printf_s("%s[%2d] =", arr_name, i + 1);
		*(arr + i) = InputDouble("");
	}
	return arr_size;
}
void OutputArr(double* arr, int size, char arr_name[])
{
	for (int i = 0; i < size; i++)
	{
		printf_s("%s[%2d] = %.2lf\n", arr_name, i + 1, *(arr + i));
	}
}
double* GiveMemoryToArr(double* arr)
{
	arr = (double*)malloc(MAXSIZE * sizeof(double));
	if (arr == NULL)
	{
		printf_s("Ошибка выделения памяти!\n");
		system("pause");
	}
	return arr;
}
int DeleteElInInterval(double* arr, int size, double A, double B)
{
	for (int i = 0; i < size; i++)
	{
		if ((*(arr + i) >= A) && (*(arr + i) <= B))
		{
			for (int j = i; j < size - 1; j++)
			{
				*(arr + j) = *(arr + j + 1);
			}
			size -= 1;
			i -= 1;
		}
	}
	return size;
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ARRAYS array[MAXSIZE];

	for (int i = 0; i < 3; i++)
	{
		array[i].arr = 0;
		array[i].arr = GiveMemoryToArr(array[i].arr);
		printf_s("Введите название массива #%d: ", i + 1);
		scanf_s(" %s", array[i].name, (unsigned)_countof(array[i].name));
		array[i].size = InputArr(array[i].arr, array[i].name);
		printf_s("Исходный массив %s:\n", array[i].name);
		OutputArr(array[i].arr, array[i].size, array[i].name);
		double A = InputDouble("Введите нижнюю границу A:");
		double B = InputDouble("Введите верхнюю границу B:");
		while (B < A)
		{
			puts("Верхняя граница не может быть меньше нижней");
			B = InputDouble("Введите верхнюю границу B:");
		}
		array[i].size = DeleteElInInterval(array[i].arr, array[i].size, A, B);
		printf_s("Измененный массив %s:\n", array[i].name);
		OutputArr(array[i].arr, array[i].size, array[i].name);
		free(array[i].arr);
	}

	system("pause");
}
