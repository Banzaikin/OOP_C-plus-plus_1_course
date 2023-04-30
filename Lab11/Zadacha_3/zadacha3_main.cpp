#include <iostream> 
#include <list> 
#include <cstdlib> 
#include <string>
#include <Windows.h>
#include "LinkedList.h"
using namespace std;

typedef List<double>LinkedList;	//определяем тип для работы со списком

const char menu[] = " 1 - создать список\n"
" 2 - вывести список\n"
" 3 - посчитать среднее арифметическое и добавить его в конец списка\n"
" 4 - удалить элементы из заданного диапазона по ключам\n"
" 6 - добавить ко всем элементам сумму минимального и максимального значений\n"
" 0 - выход из программы\n";
//основная функция 
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try
	{
		List<double> l;		//список
		int n;	//размер списка
		for (;;)
		{
			cout << menu;
			int start, finish;
			int cmd;	//команда
			cout << "\nВведите команду: ";
			cin >> cmd;
			switch (cmd)
			{
			case 1:	//создать новый список
				cout << "\nВведите размер списка: ";
				cin >> n;
				l.make_list(n);
				break;
			case 2:	//вывести список
				if (n > 0)
					l.print_list();
				else
					cout << "\nСейчас список пуст";
				break;
			case 3:	//посчитать среднее арифметическое и добавить его в конец списка
				l.arithmetic_mean();
				break;
			case 4:	//удалить элементы из заданного диапазона по ключам
				cout << "\nВведите с какого по какой элемент будем удалять: ";
				cin >> start >> finish;
				l.delete_elem(start, finish);
				break;
			//case 5:	//удалить элементы из заданного диапазона по значению
			//	cout << "\nВведите с какого по какой элемент будем удалять: ";
			//	cin >> start >> finish;
			//	cout << "\nВведите значение удаляемых элементов: ";
			//	cin >> k;
			//	l = delete_elem(l, start, finish, k);
			//	break;
			case 6:	//добавить ко всем элементам сумму минимального и максимального значений
				l.sum_min_max();
				break;
			case 0:	//выход из программы
				cout << "\nСпасибо что выбрали данную программу!";
				return 0;
			default: //неправильно выбранная команда
				cout << "\nНеправильная команда, попробуйте другую";
			}
			cout << endl;
			system("pause");
			system("cls");
		}
	}
	catch (double)		//блок обработки ошибок
	{
		cout << "Ошибка!";
	}
	return 0;
}
