#include "salary.h"
#include <iostream>
#include <string>
using namespace std;
//конструктор без параметров
Salary::Salary()
{
	name = "";
	salary = 0;
	prize = 0;
	cout << "Конструктор без параметров для объекта " << this << endl;
}
//конструктор с параметрами
Salary::Salary(string N, double S, int P)
{
	name = N;
	salary = S;
	prize = P;
	cout << "Конструктор с параметрами для объекта " << this << endl;
}
//конструктор копирования
Salary::Salary(const Salary& s)
{
	name = s.name;
	salary = s.salary;
	prize = s.prize;
	cout << "Конструктор копирования для объекта " << this << endl;
}
//деструктор
Salary::~Salary()
{
	cout << "Деструктор для объекта " << this << endl;
}
//селекторы
string Salary::get_name()
{
	return name;
}
double Salary::get_salary()
{
	return salary;
}
int Salary::get_prize()
{
	return prize;
}
//модификаторы
void Salary::set_name(string N)
{
	name = N;
}
void Salary::set_salary(double S)
{
	salary = S;
}
void Salary::set_prize(int P)
{
	prize = P;
}
//метод для просмотра атрибутов
void Salary::show()
{
	cout << "ФИО: " << name << endl;
	cout << "Оклад: " << salary << endl;
	cout << "Премия (% от оклада): " << prize << endl;
}