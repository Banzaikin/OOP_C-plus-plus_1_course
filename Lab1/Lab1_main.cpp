#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	//определение переменных A и B
	fraction A;
	fraction B;
	A.read();
	A.show();
	cout << A.element() << endl;
	B.init(2.0, 2, 4);
	B.show();
	cout << B.element() << endl;
}