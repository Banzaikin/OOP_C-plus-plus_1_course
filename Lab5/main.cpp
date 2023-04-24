#include "Object.h" 
#include "Person.h" 
#include "Student.h"
#include "Vector.h"
#include <string> 
#include <iostream>
#include <Windows.h>
using namespace std; 
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Vector v(5);
	Person a;
	cin >> a;
	Student b;
	cin >> b;
	Object* p = &a;
	v.add(p);
	p = &b;
	v.add(p);
	cout << v;
	return 0;
}
