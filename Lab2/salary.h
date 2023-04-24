#pragma once
#include <iostream>
#include <string>
using namespace std;

class Salary
{
	//атрибуты
	string name;
	double salary;
	int prize;
public:
	Salary(); //конструктор без параметров
	Salary(string, double, int); //конструктор с параметрами
	Salary(const Salary&); //конструктор копирования
	~Salary(); //деструктор
	string get_name(); //селектор
	void set_name(string); //модификатор
	double get_salary(); //селектор
	void set_salary(double); //модификатор
	int get_prize(); //селектор
	void set_prize(int); //модификатор
	void show(); //просмотр атрибутов
};