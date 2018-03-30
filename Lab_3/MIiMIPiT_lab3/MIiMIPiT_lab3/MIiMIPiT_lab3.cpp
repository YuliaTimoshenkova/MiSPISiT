// MIiMIPiT_lab3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h" 
#include "stdio.h" 
#include <iostream> 
#include <list> 
#include <vector> 
using namespace std; 


void stairs(int n) 
{ 
struct MyStruct 
{ 
int a[101]; 
}; 

list<MyStruct> A; 
list<MyStruct> fin; 
MyStruct N; 


int *arr; 
arr = new int[n]; 
for (int i = 0; i < n; i++) 
{ 
arr[i] = 0; 
} 
arr[0] = n; 


for (int i = 0; i < n; i++) 
N.a[i] = arr[i]; 
A.push_back(N); 
int j = 1; 
for (int i = 0; i < n ; i++) 
{ 
for (auto c : A) 
{ 

for (int i = 0; i < n; i++) 
arr[i] = c.a[i]; 
if (arr[i] > 2) 
{ 
arr[i] = arr[i] - 1; 
arr[i + 1] = arr[i + 1] + 1; 
for (int i = 0; i < n; i++) 
N.a[i] = arr[i]; 
A.push_back(N); 
} 
} 
} 


for (auto c : A) 
{ 
int flag = 0; 
for (int i = 0; i < n - 1; i++) 
{ 
if (c.a[i] <= c.a[i + 1] && c.a[i]) 
flag = 1; 
} 
if (flag == 0) 
fin.push_back(c); 
} 


for (auto c : fin) 
{ 
for (int i = 0; i < n; i++) 
if (c.a[i] != 0) 
cout << c.a[i] << " "; 
cout << '\n'; 
} 
}; 


int main() 
{ 

int n = 10; 
cout << "Kolichestvo blokov n = " << n << " " << "\n" << "Solutions:" << "\n";
stairs(n); 
system("pause"); 

}

