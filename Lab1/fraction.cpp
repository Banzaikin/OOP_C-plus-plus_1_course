#include <iostream>
#include <cmath>
#include "Header.h"
using namespace std;
//реализаци¤ метода дл¤ инициализации полей структуры
void fraction::init(double F, int S, int num_element)
{
	first = F;
	second = S;
	j = num_element;
}
//реализаци¤ метода дл¤ чтени¤ значений полей структуры
void fraction::read()
{
	cout << "¬ведите первый элемент прогрессии = ";
	cin >> first;
	cout << "\n¬ведите отношение r = ";
	cin >> second;
	cout << "\n¬ведите номер какого элемента нужно вычислить = ";
	cin >> j;
	cout << endl;
}
//реализаци¤ метода дл¤ вывода значений полей структуры
void fraction::show()
{
	cout << "первый элемент прогрессии - " << first << endl;
	cout << "отношение r - " << second << endl;
}
//метод дл¤ нахождени¤ j-ого элемента
double fraction::element()
{		
	return first * pow(second, j);
}