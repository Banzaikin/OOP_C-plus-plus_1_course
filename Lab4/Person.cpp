#include "Person.h"
Person::Person(void)
{
	name = "";
	age = 0;
}
//деструктор 
Person::~Person(void)
{
}
//конструктор с параметрами
Person::Person(string N, int A)
{
	name = N;
	age = A;
}
//конструктор копирования
Person::Person(const Person& person)
{
	name = person.name;
	age = person.age;
}
//модификаторы
void Person::set_name(string N)
{
	name = N;
}
void Person::set_age(int A)
{
	age = A;
}
//перегрузка операции присваивания 
Person& Person::operator=(const Person&p)
{
	if (&p == this)
		return *this; 
	name = p.name; 
	age = p.age;
	return *this;
}
//глобальная функция для ввода 
istream& operator>>(istream&in, Person&p)
{
	cout << "\nИмя: "; 
	in >> p.name; 
	cout << "\nВозраст: "; 
	in >> p.age; 
	return in;
}
//глобальная функция для вывода
ostream& operator<<(ostream& out, const Person& p)
{
	out << "\nИмя: " << p.name; 
	out << "\nВозраст: " << p.age;
	out << "\n";
	return out;
}


