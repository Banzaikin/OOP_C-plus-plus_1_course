#include "Person.h" 
#include "Student.h"
#include <iostream> 
#include <Windows.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//класс Person
	Person a; 
	cin >> a; 
	cout << a;
	Person b("≈гор", 21); 
	cout << b;
	a = b; 
	cout << a;
	//класс Student
	Student s;
	cin >> s;
	cout << s;
	return 0;
}
