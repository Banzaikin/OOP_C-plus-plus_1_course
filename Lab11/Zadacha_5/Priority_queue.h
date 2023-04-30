#pragma once
#include <iostream>
#include <list>
#include <queue>
using namespace std;
//класс очереди с приоритетами
template <typename T>
class PriorityQueue
{
private:
	priority_queue<T> q;
	T SearchMidVal();
	int _size;
public:
	PriorityQueue() { _size = 0; };
	~PriorityQueue() {};
	void make_queue(int n);
	void print_queue();
	void arithmetic_mean();
	void delete_elem(int, int);
	int size() { return this->_size; };
	void sum_min_max();
};
//создание очереди
template<class T>
void PriorityQueue<T>::make_queue(int n)
{
	T a;
	for (size_t i = 0; i < n; i++)
	{
		cout << "\nВведите " << i + 1 << " элемент очереди с приоритетами : ";
		cin >> a;
		this->q.push(a);
	}
	_size = n;
}
//вывод очереди
template<class T>
void PriorityQueue<T>::print_queue()
{
	int j = 0;
	priority_queue<double> temp(this->q);
	while (!temp.empty())
	{
		cout << j++ << ". " << temp.top() << endl;
		temp.pop();
	}
}

template<class T>
T PriorityQueue<T>::SearchMidVal()
{
	priority_queue<T> temp(q);
	T mid = 0;
	while (!temp.empty())
	{
		mid = mid + temp.top();
		temp.pop();
	}
	return mid / q.size();
}
//функция для подсчета среднего арифметического и добавление его в конец списка
template<typename T>
void PriorityQueue<T>::arithmetic_mean()
{
	q.push(SearchMidVal());
	this->_size = q.size();
}
//функция удаления элементов из заданного диапазона
template<typename T>
void PriorityQueue<T>::delete_elem(int start, int finish)
{
	priority_queue<T> temp;
	double t;
	int n = 1;
	int z = q.size();
	for (n; n <= start; n++)
	{
		t = q.top();
		q.pop();
		temp.push(t);
	}
	for (n; n <= finish; n++)
	{
		q.pop();
	}
	for (n; n <= z; n++)
	{
		t = q.top();
		q.pop();
		temp.push(t);
	}
	q = temp;
}
//функция добавления суммы минимального и максимального значений
template<typename T>
void PriorityQueue<T>::sum_min_max()
{
	T k;
	T loc_min = q.top(), loc_max = 0;
	priority_queue<T> temp(q);
	while (!temp.empty())
	{
		k = temp.top();
		if (loc_max < k)
		{
			loc_max = k;
			temp.pop();
		}
		else if (loc_min > k)
		{
			loc_min = k;
			temp.pop();
		}
		else temp.pop();
	}
	temp.swap(q);
	while (!temp.empty())
	{
		k = temp.top();
		q.push(k + loc_min + loc_max);
		temp.pop();
	}
}
