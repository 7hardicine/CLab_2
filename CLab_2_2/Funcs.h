#pragma once
#include <stdio.h>
#include <Windows.h>

int InputInt(char mess[]);
double InputDouble(char mess[]);
int** GiveMemoryToMatrix(int** arr, int size_i, int size_j);
int** InputMatrix(int** arr, int size_i, int size_j);
void OutputMatrix(int** arr, int size_i, int size_j);
void OutputArr(double* arr, int size);
double* AvarageInColl(int** arr, int size_i, int size_j, double* arr_av);