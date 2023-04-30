#include <iostream> 
#include <set> 
#include <cstdlib> 
#include <Windows.h>
#include "Pair.h"
using namespace std;

typedef multiset<Pair>MS;	//определяем тип для работы с контейнером множество дубликатами
//функция для формирования контейнера множество дубликатами
MS make_multiset(MS ms, int n)
{
	for (int i = 0; i < n; i++)
	{
		Pair a;
		cout << "\nВведите " << i + 1 << " элемент: ";
		cin >> a;
		ms.insert(a); //добавление a в конец контейнера множество дубликатами
	}
	return ms;
}
//функция для печати контейнера множество дубликатами
void print_multiset(MS ms)
{
	cout << "\nСейчас контейнер множество дубликатами такой: \n";
	int k = 1;
	for (auto& i : ms)
	{
		cout << k << ". " << i << endl;
		k++;
	}
}
//функция для подсчета среднего арифметического и добавление его в конец контейнера множество дубликатами
MS arithmetic_mean(MS ms)
{
	Pair a;
	for (auto& i : ms)
		a = a + i;
	ms.insert(a / ms.size());
	return ms;
}

//функция удаления элементов из заданного диапазона по ключам
MS delete_elem(MS ms, Pair start, Pair finish)
{
	auto left = ms.lower_bound(start);
	auto right = ms.upper_bound(finish);
	ms.erase(left, right);
	return ms;
}

//функция добавления суммы минимального и максимального значений
MS sum_min_max(MS ms)
{
	multiset<Pair> temp; //создание промежуточного пустого контейнера
	Pair max;//здесь будет максимальное значение в контейнере множество дубликатами
	//цикл нахождения максимального значения
	for (auto& i : ms)
	{
		if (max < i)
			max = i;
	}
	Pair min; //здесь будет минимальное значение в контейнере множество дубликатами
	//цикл нахождения минимального значения
	for (auto& i : ms)
	{
		if (min > i)
			min = i;
	}
	Pair s = min + max; //сумма минимального и максимального элементов
	//добавление к элементам s
	for (auto& i : ms)
		temp.insert(i + min + max);
	ms.swap(temp);
	return ms;
}

const char menu[] = " 1 - создать контейнер множество дубликатами\n"
" 2 - вывести контейнер множество дубликатами\n"
" 3 - посчитать среднее арифметическое и добавить его в конец контейнера множество дубликатами\n"
" 4 - удалить элементы из заданного диапазона по ключам\n"
" 5 - добавить ко всем элементам сумму минимального и максимального значений\n"
" 0 - выход из программы\n";
//основная функция 
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try
	{
		multiset<Pair> ms;		//контейнер множество дубликатами
		Pair p;
		int n = 0;	//размер контейнера множество дубликатами
		for (;;)
		{
			cout << menu;
			Pair start, finish;
			int cmd;	//команда
			cout << "\nВведите команду: ";
			cin >> cmd;
			switch (cmd)
			{
			case 1:	//создать новый контейнер множество дубликатами
				ms.clear();
				cout << "\nВведите размер контейнера множество дубликатами: ";
				cin >> n;
				ms = make_multiset(ms, n);
				break;
			case 2:	//вывести контейнер множество дубликатами
				if (n > 0)
					print_multiset(ms);
				else
					cout << "\nСейчас список пуст";
				break;
			case 3:	//посчитать среднее арифметическое и добавить его в конец контейнера множество дубликатами
				ms = arithmetic_mean(ms);
				break;
			case 4:	//удалить элементы из заданного диапазона по ключам
				cout << "\nВведите с какого по какой элемент будем удалять: ";
				cin >> start >> finish;
				ms = delete_elem(ms, start, finish);
				break;
			case 5:	//добавить ко всем элементам сумму минимального и максимального значений
				ms = sum_min_max(ms);
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
