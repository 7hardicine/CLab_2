#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "Funcs.h"

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int** arr1 = 0;
	int** arr2 = 0;
	double* V = 0;
	double* W = 0;

	int rows_1 = InputInt("Введите количество строк матрицы:");
	int cols_1 = InputInt("Введите количество столбцов матрицы:");
	arr1 = GiveMemoryToMatrix(arr1, rows_1, cols_1);
	arr1 = InputMatrix(arr1, rows_1, cols_1);
	puts("Исходная матрица:");
	OutputMatrix(arr1, rows_1, cols_1);
	V = AvarageInColl(arr1, rows_1, cols_1, V);
	puts("Среднее арифметическое для каждого столбца:");
	OutputArr(V, cols_1);

	int rows_2 = InputInt("Введите количество строк матрицы:");
	int cols_2 = InputInt("Введите количество столбцов матрицы:");
	arr2 = GiveMemoryToMatrix(arr2, rows_2, cols_2);
	arr2 = InputMatrix(arr2, rows_2, cols_2);
	puts("Исходная матрица:");
	OutputMatrix(arr2, rows_2, cols_2);
	W = AvarageInColl(arr2, rows_2, cols_2, W);
	puts("Среднее арифметическое для каждого столбца:");
	OutputArr(W, cols_2);

	free(arr1);
	free(arr2);

	system("pause");
}