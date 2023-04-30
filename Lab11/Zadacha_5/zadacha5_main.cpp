#include <C:\Users\trajt\source\repos\Zadacha_2\Pair.h>
#include <iostream> 
#include <list> 
#include <cstdlib> 
#include <string>
#include <Windows.h>
#include "Priority_queue.h"
using namespace std;

typedef PriorityQueue<double>PQ;	//определяем тип для работы со списком

const char menu[] = " 1 - создать очередь с приоритетами\n"
" 2 - вывести очередь с приоритетами\n"
" 3 - посчитать среднее арифметическое и добавить его в конец очереди с приоритетами\n"
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
		PriorityQueue<double> q;		//список
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
			case 1:	//создать новую очередь с приоритетами
				cout << "\nВведите размер очереди с приоритетами: ";
				cin >> n;
				q.make_queue(n);
				break;
			case 2:	//вывести очередь с приоритетами
				if (n > 0)
					q.print_queue();
				else
					cout << "\nСейчас очередь с приоритетами пустая";
				break;
			case 3:	//посчитать среднее арифметическое и добавить его в конец очереди с приоритетами
				q.arithmetic_mean();
				break;
			case 4:	//удалить элементы из заданного диапазона по ключам
				cout << "\nВведите с какого по какой элемент будем удалять: ";
				cin >> start >> finish;
				q.delete_elem(start, finish);
				break;
				//case 5:	//удалить элементы из заданного диапазона по значению
				//	cout << "\nВведите с какого по какой элемент будем удалять: ";
				//	cin >> start >> finish;
				//	cout << "\nВведите значение удаляемых элементов: ";
				//	cin >> k;
				//	l = delete_elem(l, start, finish, k);
				//	break;
			case 6:	//добавить ко всем элементам сумму минимального и максимального значений
				q.sum_min_max();
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
