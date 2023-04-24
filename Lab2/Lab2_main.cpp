#include "salary.h"
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
//функция для возврата объекта как результата
Salary make_salary()
{
	string n;
	cout << "Введите ФИО: ";
	getline(cin, n);
	cout << endl;
	double s;
	cout << "Введите оклад: ";
	cin >> s;
	cout << endl;
	int p;
	cout << "Введите премию(% от оклада): ";
	cin >> p;
	cout << endl;
	Salary t(n, s, p);
	return t;
}
//функция для передачи объекта как параметра
void print_salary(Salary t)
{
	t.show();
}
void main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//конструктор без параметров
	Salary s1;
	s1.show();
	//конструктор с параметрами
	Salary s2("Баяндин Кирилл Семенович", 100000, 10000);
	s2.show();
	//конструктор копирования
	Salary s3 = s2;
	s3.set_name("Бражкин Егор Викторович");
	s3.set_salary(120000);
	s3.set_prize(12000);
	//конструктор копирования
	print_salary(s3);
	//конструктор копирования
	s1 = make_salary();
	s1.show();
}