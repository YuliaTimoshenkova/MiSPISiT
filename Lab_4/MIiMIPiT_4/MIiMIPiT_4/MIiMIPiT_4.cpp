// MIiMIPiT_4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include <stdio.h>
#include <tchar.h>
#include <math.h>
using namespace std;

const int N = 7; // Размер доски и количество ферзей
int X[N]; // Шахматная доска
int Count; // Количество расстановок

// Функция поиска свободных клеток на доске
bool Search_Position(int X[N], int v, int g)
{
	/* 
	v - вертикаль 
	g - горизонталь
	Описание условия  while ((i<k) && (y != X[i]) && (abs(k - i) != abs(y - X[i]))) { i++; }
	(i<k) - проверка предыдущих вертикалей
	(y != X[i]) - проверка горизонтали 
	(abs(k - i) != abs(y - X[i])) - проверка диагонали
	*/
	int i = 0;
	while ((i<v) && (g != X[i]) && (abs(v - i) != abs(g - X[i]))) { i++; }
	if (i == v)
		return true;
	else if (i != v)
		return false;
	else
		return !true && !false;
}
// Функция поиска с возвратом
void Search_Backtracking(int k) 
{
	int i, y;
	for (y = 0; y<N; y++)
		if (Search_Position(X, k, y))
		{
			X[k] = y;
			if (k == N - 1) 
			{
				Count++;
			}
			Search_Backtracking(k + 1);
		}
}
// Функция вывода всех возможных позиций ферзей
void Vivod_Position(int k)
{
	int i, y;
	for (y = 0; y<N; y++)
		if (Search_Position(X, k, y))
		{
			X[k] = y;
			if (k == N - 1) {
				for (i = 0; i<N; i++)
				{
					cout << char('A' + i) << X[i] + 1 << " ";
				}
				cout << endl;
			}
			Vivod_Position(k + 1);
		}
}
int main()
{
	for (int i = 0; i<N; i++)X[i] = 0;
	Count = 0;
	cout << "Zadacha rasstavit " << N << " ferzey:" << endl;
	Search_Backtracking(0);
	cout << "Na doske razmerom " << N << " na " << N << " mojno rasstavit " << Count << " sposobami " << endl;
	cout << "Na doske razmerom " << N << " na " << N << " primer rasstanovki: " << endl;
	Vivod_Position(0);
	cout << endl;
	system("pause");
}