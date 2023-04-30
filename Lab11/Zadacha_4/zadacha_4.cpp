#include <C:\Users\trajt\source\repos\Zadacha_2\Pair.h>
#include <list> 
#include <queue> 
#include <cstdlib> 
#include <Windows.h>

typedef priority_queue<Pair>PQ;		//очередь с приоритетами
typedef list<Pair>LinkedList;		//список

//функция для создания очереди с приоритетами
PQ make_queue(PQ s, int n)
{
	for (int i = 1; i <= n; i++)
	{
		Pair a;
		cout << "\nВведите " << i + 1 << " элемент очереди : ";
		cin >> a;
		s.push(a); //добавление a в конец очереди
	}
	return s;
}
//функция для печати очереди с приоритетами
void print_queue(PQ q)
{
	int j = 0;
	cout << "\nСейчас список такой: \n";
	//priority_queue<Pair> temp(q);
	while (!q.empty())
	{
		cout << j++ << ". " << q.top() << endl;
		q.pop();
	}
}
//функция для подсчета среднего арифметического и добавление его в конец очереди
PQ arithmetic_mean(PQ q)
{
	priority_queue<Pair> temp(q);
	Pair s;
	while (!temp.empty())
	{
		s = s + temp.top();
		temp.pop();
	}
	q.push( s / q.size() );
	return q;
}
//функция удаления элементов из заданного диапазона по ключам
PQ delete_elem(PQ q, int start, int finish)
{
	priority_queue<Pair> temp;
	Pair t;
	int n = 1;
	for(n; n <= start; n++)
	{
		t = q.top();
		q.pop();
		temp.push(t);
	}
	for (n; n <= finish; n++)
	{
		q.pop();
	}
	for (n; n <= q.size(); n++)
	{
		t = q.top();
		q.pop();
		temp.push(t);
	}
	return temp;
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
PQ sum_min_max(PQ q)
{
	priority_queue<Pair> temp;
	Pair t;
	Pair max = q.top(); //здесь будет максимальное значение в списке
	//цикл нахождения максимального значения
	for (int i = 1; i <= q.size(); i++)
	{
		if (max < q.top())
			max = q.top();
	}
	Pair min = q.top(); //здесь будет минимальное значение в очереди
	//цикл нахождения минимального значения
	for (int i = 1; i <= q.size(); i++)
	{
		if (min > q.top())
			min = q.top();
	}
	Pair s = min + max; //сумма минимального и максимального элементов
	//добавление к элементам s
	for (int i = 1; i <= q.size(); i++)
	{
		Pair a = q.top() + s;
		temp.push(a);
	}
	return temp;
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
		priority_queue<Pair> s;		//очередь с приоритетом 
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
				cout << "\nВведите размер очереди с приоритетом: ";
				cin >> n;
				s = make_queue(s, n);
				break;
			case 2:	//вывести список
				if (n > 0)
					print_queue(s);
				else
					cout << "\nСейчас очередь с приоритетом пустая";
				break;
			case 3:	//посчитать среднее арифметическое и добавить его в конец очереди
				s = arithmetic_mean(s);
				break;
			case 4:	//удалить элементы из заданного диапазона по ключам
				cout << "\nВведите с какого по какой элемент будем удалять: ";
				cin >> start >> finish;
				s = delete_elem(s, start, finish);
				break;
				//case 5:	//удалить элементы из заданного диапазона по значению
				//	cout << "\nВведите с какого по какой элемент будем удалять: ";
				//	cin >> start >> finish;
				//	cout << "\nВведите значение удаляемых элементов: ";
				//	cin >> k;
				//	l = delete_elem(l, start, finish, k);
				//	break;
			case 6:	//добавить ко всем элементам сумму минимального и максимального значений
				s = sum_min_max(s);
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