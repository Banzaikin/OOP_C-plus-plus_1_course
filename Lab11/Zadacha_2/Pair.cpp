#include "Pair.h"
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
	return *this;
}
//перегрузка операции сложение
Pair Pair::operator+(const Pair& p) const
{
	Pair temp(this->first + p.first, this->second + p.second);
	return temp;
}
//перегрузка инкремента
Pair& Pair::operator++()
{
	++this->first;
	++this->second;
	return *this;
}

Pair Pair::operator++(int)
{
	Pair temp(*this);
	++this->first;
	++this->second;
	return temp;
}
//перегрузка операции вычитание
Pair Pair::operator-(const Pair& p)
{
	return Pair(this->first - p.first, this->second - p.second);
}

const Pair operator+(const Pair& left, const int& right)
{
	return Pair(left.first + right, left.second);
}

const Pair operator+(const int& left, const Pair& right)
{
	return right + left;
}

const Pair operator+(const Pair& left, const double& right)
{
	return Pair(left.first, left.second + right);
}

const Pair operator+(const double& left, const Pair& right)
{
	return right + left;
}
//перегрузка операции деление
Pair Pair::operator/(const Pair& p)
{
	return Pair(this->first / p.first, this->second / p.second);
}

Pair Pair::operator/(const int p)
{
	return Pair(this->first / p, this->second / p);
}
//перегрузка операции сравнивания
bool Pair::operator<(const Pair& p) const
{
	double thiss = this->first + this->second, otherr = p.first + p.second;
	if (thiss < otherr) return true;
	else return false;
}

bool Pair::operator>(const Pair& p)
{
	return !(*this < p);
}

//перегрузка глобальной функции-операции ввода
istream& operator >> (istream& in, Pair& p)
{
	cout << "\nПервое число: ";
	in >> p.first;
	cout << "\nВторое число: ";
	in >> p.second;
	return in;
}
//перегрузка глобальной функции-операции вывода
ostream& operator << (ostream& out, const Pair& p)
{
	return (out << p.first << " : " << p.second);
}

