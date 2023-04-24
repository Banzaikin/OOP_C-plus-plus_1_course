#include "Header.h";
#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	Pair a;
	Pair b;
	Pair c;
	cin >> a;
	cin >> b;
	cout << "Разность чисел: " << a - b << endl;
	cout << "Пара чисел: " << a + b << endl;
	return;
}