#include "Student.h"
//конструктор без параметров
Student::Student(void) :Person()
{
	subject = "";
	point = 0;
}
//деструктор
Student::~Student(void)
{
}
//конструктор с параметрами
Student::Student(string N, int A, string S, int P) :Person(N, A)
{
	subject = S;
	point = P;
}
//конструктор копирования
Student::Student(const Student& S)
{
	name = S.name;
	age = S.age;
	subject = S.subject;
	point = S.point;
}
//модификаторы
void Student::set_subject(string S)
{
	subject = S;
}
void Student::set_point(int P)
{
	point = P;
}
//перегрузка операции присваивания
Student& Student::operator=(const Student& s)
{
	if (&s == this)
		return *this;
	name = s.name;
	age = s.age;
	subject = s.subject;
	point = s.point;
	return *this;
}
//операция ввода
istream& operator>>(istream& in, Student& s)
{
	cout << "Введите имя: " << endl;
	in >> s.name;
	cout << "Введите возраст: " << endl;
	in >> s.age;
	cout << "Введите предмет: " << endl;
	in >> s.subject;
	cout << "Введите оценку: " << endl;
	in >> s.point;
	return in;
}
//операция вывода
ostream& operator<<(ostream& out, const Student& s)
{
	out << "Имя: " << s.name << endl;
	out << "Возраст: " << s.age << endl;
	out << "Предмет: " << s.subject << endl;
	out << "Оценка: " << s.point << endl;
	if (s.point == 2)
		out << "Неудовлетворительная оценка!" << endl;
	return out;
}
//функция показа полей класса
void Student::show()
{
	cout << "\nИмя: " << name;
	cout << "\nВозраст " << age;
	cout << "\nПредмет: " << subject;
	cout << "\nОценка: " << point;
	cout << "\n";
}