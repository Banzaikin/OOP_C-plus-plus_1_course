#include "Header.h"
#include <iostream>
using namespace std;
//перегрузка операции присваивания
Pair& Pair::operator = (const Pair& p)
{
	//Проверка на самоприсваивание
	if (&p == this)
		return *this;
	else 
		first = p.first;
		second = p.second;
		third = p.third;
		c = p.c;
		return *this;
}
//перегрузка бинарной операции вычитания 
Pair Pair::operator -(const Pair& p)
{
	double temp1 = first - second;
	double temp2 = p.first - p.second;
	Pair t;
	t.third = temp1;
	t.second = temp2;
	return t;
}
//перегрузка бинарной операции сложения константы к паре чисел
Pair Pair::operator +(const Pair& p)
{
	int b = (int)c;
	double temp1, temp2;
	if (c - b == 0) {
		temp1 = first + c;
		temp2 = p.first + p.c;
	}
	else {
		temp1 = second + c;
		temp2 = p.second + p.c;
	}
	Pair t;
	t.third = temp1;
	t.second = temp2;
	return t;
}
//перегрузка глобальной функции-операции ввода
istream& operator >> (istream& in, Pair& p)
{
	cout << "Первое число: ";
	in >> p.first;
	cout << "Второе число: ";
	in >> p.second;
	cout << "Константа: ";
	in >> p.c;
	return in;
}
//перегрузка глобальной функции-операции вывода
ostream& operator << (ostream& out, const Pair& p)
{
	return (out << p.third << " : " << p.second);
}