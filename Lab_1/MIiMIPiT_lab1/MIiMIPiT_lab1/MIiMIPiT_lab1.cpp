// MIiMIPiT_lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;
//Прямой Фибонач
int fibPryamoi(int n, int count)
{
	int *fib;
	fib = new int[n + 1];
	for (int i = 1; i <= n; i++)
	{
		if (i <= count)
		{
			fib[i] = 1;
		}
		else
		{
			fib[i] = 0;
			for (int j = 1; j <= count; j++)
			{
				fib[i] = fib[i] + fib[i - j];
			}
		}

	}
	return fib[n];
}

//Обратный Фибонач

int fibObratniy(int n, int count)
{
	int *fib;
	fib = new int[n + 1 + count];
	for (int i = 1; i <= n; i++)
	{
		fib[i] = 0;
	}
	fib[1] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= count; j++)
		{
			fib[i + j] = fib[i + j] + fib[i];
			if (i + j <= count)
			{
				fib[i + j] = 1;
			}
		}
	}
	return fib[n];
}

//Умножить
int mult(int a, int b)
{
	return a * b;
}
//Сложить
int sum(int a, int b)
{
	return a + b;
}

//Функциональное Боначи

int fibfunc(int n, int count, int(*func)(int, int))
{
	int *fib;
	fib = new int[n + 1];
	for (int i = 1; i <= n; i++)
	{
		if (i <= count)
		{
			fib[i] = 1;
		}
		else
		{
			fib[i] = fib[i - 1];
			for (int j = 1; j < count; j++)
			{
				fib[i] = func(fib[i], fib[i - j - 1]);
			}
		}

	}
	return fib[n];
}

//кабаначи с массивом k
int fibWithKArray(int n, int k)
{
	int value = 0;
	int *fib;
	fib = new int[k];

	if (n <= k)
	{
		return 1;
	}
	else
	{
		for (int j = 1; j <= k; j++)
		{
			fib[j] = 1;
		}

		for (int i = k + 1; i <= n; i++)
		{
			value = 0;

			for (int j = 1; j <= k; j++)
			{
				value = value + fib[j];
				fib[j] = fib[j + 1];
			}

			fib[k] = value;
		}

		return value;
	}
}

//рекурсия
int fibRecursive(int n, int k)
{
	int value = 0;

	if (n <= k)
	{
		return 1;
	}
	else
	{
		for (int i = 1; i <= k; i++)
		{
			value = value + fibRecursive(n - i, k);
		}
		return value;
	}
}

//Мемоизация
int fibMemos(int n, int k)
{
	static int fib[1001];
	static int osn = 0;

	if (osn != k)
	{
		for (int i = 1; i <= 1001; i++)
		{
			fib[i] = 0;
		}
	}

	if (fib[n] == 0)
	{
		fib[n] = fibRecursive(n, k);
	}

	return fib[n];
}



int main()
{

	int n;
	int k;

	cout << "Give me number: \n";
	cin >> n;

	cout << "Give me kabanachi value: \n";
	cin >> k;

	cout << "Results \n Praymoy " << fibPryamoi(n, k) << "\n Obratniy ";
	cout << fibObratniy(n, k) << "\n Functial ";
	cout << fibfunc(n, k, sum) << "\n With k array ";
	cout << fibWithKArray(n, k) << "\n Recursive ";
	cout << fibRecursive(n, k) << "\n Memoiz ";
	cout << fibMemos(n, k) << "\n";


	system("pause");
	return 0;
}

