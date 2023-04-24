#pragma once 
#include <string> 
#include <iostream>
using namespace std; 
class Person
{
//конструктор без параметров 
public:
Person(void); 
public:
	//деструктор
	virtual ~Person(void);
	//констрктор с параметрами 
	Person(string, int);
	//конструктор копирования 
	Person(const Person&);

	//селекторы
	string get_name() { return name; } 
	int get_age() { return age; }
	//модификаторы
	void set_name(string); 
	void set_age(int); 
	//перегрузка операции присваивания 
	Person& operator=(const Person&);
	//глобальные операторы-функции ввода-вывода
	friend istream& operator >> (istream& in, Person& p); 
	friend ostream& operator << (ostream& out, const Person& p);
	//атрибуты 
protected:
	string name; 
	int age;
};


