#include "Print.h"
Print::Print(void)
{
	name = ""; 
	author = "";
}
//деструктор 
Print::~Print(void)
{
}
//констрктор с параметрами 
Print::Print(string N, string A)
{
	name = N;
	author = A;
}
//конструктор копирования 
Print::Print(const Print& p)
{
	name = p.name;
	author = p.author;
}

//селекторы
void Print::set_name(string n)
{
	name = n;
}
void Print::set_author(string a)
{
	author = a;
}

//оператор присваивания
Print& Print::operator=(const Print& p)
{
	if (&p == this)
		return *this; 
	name = p.name;
	author = p.author;
	return *this;
}
//метод для просмотра атрибутов 
void Print::show()
{
	cout << "\nПечатное издание: ";
	cout << "\nНазвание: " << name; 
	cout << "\nАвтор: " << author;
}
//метод для ввода значений атрибутов 
void Print::input()
{
	cout << "\nВведите название печатного издания: "; 
	cin >> name; 
	cout << "\nВведите автора печатного издания:"; 
	cin >> author; 
}

void Print::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)//событие-сообщение
	{
		switch (e.command)
		{
		case cmGet:
			cout << "Название = " << get_name() << endl; 
			break;
		}
	}
}

