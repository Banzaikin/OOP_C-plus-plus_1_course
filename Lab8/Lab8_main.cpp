#include "Dialog.h"
#include <iostream>
#include "windows.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "¬ведите что-нибудь: " << endl << endl;
	cout << "-----------------------------------" << endl;
	cout << endl << "1.\n2.\n3.\n4.\n5. z\n6.n\n";
	cout << "-----------------------------------" << endl;
	cout << endl;
	Dialog D;
	D.Execute();
	return 0;
}