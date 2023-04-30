#include <iostream> 
#include <list> 
#include <cstdlib> 
#include <string>
#include <Windows.h>
#include "Pair.h"
using namespace std;

typedef list<Pair>LinkedList;	//определяем тип для работы со списком
//функция для формирования списка
LinkedList make_list(LinkedList l, int n)
{
	for (int i = 0; i < n; i++)
	{
		Pair a;
		cout << "\nВведите " << i + 1 << " элемент списка : ";
		cin >> a;
		l.push_back(a); //добавление a в конец списка
	}
	return l;
}
//функция для печати списка 
void print_list(LinkedList l)
{
	cout << "\nСейчас список такой: \n";
	copy(l.begin(), l.end(), ostream_iterator<Pair>(cout, "   "));
}
//функция для подсчета среднего арифметического и добавление его в конец списка
LinkedList arithmetic_mean(LinkedList l)
{
	list<Pair>::iterator it = l.begin();
	Pair s;
	//перебор списка
	for (int i = 0; i < l.size(); i++)
	{
		s = s + *it;
		it++;
	}
	int n = l.size();	//количество элементов в векторе 
	l.push_back(s / n);
	return l;
}
//функция удаления элементов из заданного диапазона по ключам
LinkedList delete_elem(LinkedList l, int start, int finish)
{
	list<Pair>::iterator it_start = l.begin();
	list<Pair>::iterator it_finish = l.begin();
	advance(it_start, start);	//смещение итератора до начальной точки отсчета
	advance(it_finish, finish);	//смещение итератор до конечной точки отсчета
	l.erase(it_start, it_finish);
	return l;
}
//функция удаления элементов из заданного диапазона по значениям
//LinkedList delete_elem(LinkedList l, int start, int finish, Pair k)
//{
//	list<Pair>::iterator it_start = l.begin();
//	list<Pair>::iterator it_finish = l.begin();
//	advance(it_start, start);	//смещение итератора от начала до начальной точки отсчета
//	advance(it_finish, finish);	//смещение итератор от конца до конечной точки отсчета
//	for (it_start; it_start != it_finish; ++it_start)
//	{
//		l.remove(k);	//удаление элементов по значению
//	}
//	return l;
//}

//функция добавления суммы минимального и максимального значений
LinkedList sum_min_max(LinkedList l)
{
	list<Pair> copy_l;
	list<Pair>::iterator it = l.begin();
	Pair max = l.front(); //здесь будет максимальное значение в списке
	//цикл нахождения максимального значения
	for (it; it != l.end(); ++it)
	{
		if (max < *it)
			max = *it;
	}
	Pair min = l.front(); //здесь будет минимальное значение в списке
	//цикл нахождения минимального значения
	for (it; it != l.end(); ++it)
	{
		if (min > *it)
			min = *it;
	}
	Pair s = min + max; //сумма минимального и максимального элементов
	//добавление к элементам s
	it = l.begin();
	for (int i = 0; i < l.size(); i++)
	{
		Pair a = *it + s;
		copy_l.push_back(a);
		it++;
	}
	return copy_l;
}

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
		list<Pair> l;		//список
		int n = 0;	//размер списка
		for (;;)
		{
			cout << menu;
			int start, finish;
			/*Pair k;*/
			int cmd;	//команда
			cout << "\nВведите команду: ";
			cin >> cmd;
			switch (cmd)
			{
			case 1:	//создать новый список
				l.clear();
				cout << "\nВведите размер списка: ";
				cin >> n;
				l = make_list(l, n);
				break;
			case 2:	//вывести список
				if (n > 0)
					print_list(l);
				else
					cout << "\nСейчас список пуст";
				break;
			case 3:	//посчитать среднее арифметическое и добавить его в конец списка
				l = arithmetic_mean(l);
				break;
			case 4:	//удалить элементы из заданного диапазона по ключам
				cout << "\nВведите с какого по какой элемент будем удалять: ";
				cin >> start >> finish;
				l = delete_elem(l, start, finish);
				break;
			//case 5:	//удалить элементы из заданного диапазона по значению
			//	cout << "\nВведите с какого по какой элемент будем удалять: ";
			//	cin >> start >> finish;
			//	cout << "\nВведите значение удаляемых элементов: ";
			//	cin >> k;
			//	l = delete_elem(l, start, finish, k);
			//	break;
			case 6:	//добавить ко всем элементам сумму минимального и максимального значений
				l = sum_min_max(l);
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
