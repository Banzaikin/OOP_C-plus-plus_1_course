#pragma once
#include <iostream>
#include <algorithm>		// дл¤ min/max
using namespace std;
// -------------------------------------------------------------------//
//	≈сли ф-и¤ имеет параметр с const, тогда и все св¤занные 
//	с ней ф-ии должны иметь тот же модификатор!
//	110(LinkedList.cpp) - конструктор копировани¤: имеет const list, 
//	работает с индексами через оператор [] => перегрузка
//	оператора [] должна иметь в конце const!! 90(LinkedList.cpp)
//  “оже самое с 65, 71, 77 (77 имеет const)
//-------------------------------------------------------------------//
struct Pair
{
	Pair() {}
	Pair(int a, double b)
	{
		numINT = a;
		numDOUBLE = b;
	}

	int numINT = 0;
	double numDOUBLE = 0;


	Pair& operator =(const Pair& pair)
	{
		this->numINT = pair.numINT;
		this->numDOUBLE = pair.numDOUBLE;
		return *this;
	};
	Pair& operator =(const int& k)
	{
		this->numINT = k;
		this->numDOUBLE = k;
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Pair& pair)
	{
		out << pair.numINT << " : " << pair.numDOUBLE << " |";
		return out;
	}
	friend istream& operator>>(istream& in, Pair& pair)
	{
		in >> pair.numINT >> pair.numDOUBLE;
		return in;
	}
	
	Pair operator * (Pair& pair)
	{
		Pair new_pair;
		new_pair.numINT = this->numINT * pair.numINT;
		new_pair.numDOUBLE = this->numDOUBLE * pair.numDOUBLE;
		return new_pair;
	}
};
//-------------------------//
//	св¤зь списка
//-------------------------//
template<typename T>
struct Point
{
	T num;							// просто число
	Point* next = nullptr;			// указатель на следующий элемент списка
};
//-------------------------//
//	итератор списка
//-------------------------//
template <typename T>
class Iterator
{
private:
	Point<T>* elem = nullptr;		// указатель на св¤зь
public:
	Iterator() { elem = nullptr; }
	Iterator(Point<T>* point) { elem = point; }
	Iterator(const Iterator& it) { elem = it.elem; };
	bool operator == (const Iterator& it) { return elem == it.elem; }
	bool operator != (const Iterator& it) { return elem != it.elem; }
	void operator ++ () { elem = elem->next; };			// ++i - смещение вправо на 1
	void operator ++ (int) { elem = elem->next; };		// i++ - смещение вправо на 1
		//---------// i+n - смещение вправо на n
	Iterator& operator + (int n)
	{
		for (int i = 0; i < n && elem->next != nullptr; i++)
			elem = elem->next;
		return *this;
	}
	T operator * () const { return elem->num; };      // разыменование итератора (вывод)
};

//-------------------------//
//	св¤занный список
//-------------------------//
template <typename T>
class LinkedList
{
private:
	size_t size = 0;								// размер списка
	Point<T>* head = nullptr;						// указатель на первый элемент	
	Point<T>* top = nullptr;						// указатель на ласт элемент
	void output(Point<T>* obj) const;
	void show() const;

public:
	//-------------------------------вывод----------------------------------------//
	friend ostream& operator<<(ostream& out, const LinkedList<T>& list)
	{
		list.show();
		return out;
	}
	//-------------------------------ввод-----------------------------------------//
	friend istream& operator>>(istream& in, LinkedList<T>& list)
	{
		T k;
		in >> k;
		list.push(k);
		return in;
	}
	//---------------------------------------------------------------------------//
	LinkedList();										// конструктор
	LinkedList(size_t s, T k);							// констуктор: s - размер, k - значение по умолчанию
	~LinkedList();										// деструктор
	LinkedList(const LinkedList<T>& list);				// конструктор копировани¤
	T& operator [](int index) const;					// доступ по индексу
	LinkedList& operator =(const LinkedList<T>& list);	// оператор присваивани¤
	LinkedList operator * (LinkedList<T>& list);		// умножение списка на список
	int operator ()() { return size; };					// возвращение длины списка
	void push(T k);										// добавление в конец списка
	T pop();											// удаление первого элемента
	Iterator<T> first() { return Iterator<T>(head); }	// возвращает указатель на первый элемент
	Iterator<T> last() { return Iterator<T>(top); }		// вовзращает указаетль на последний элемент

};



template <typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	top = nullptr;
	size = 0;
}

template <typename T>
LinkedList<T>::LinkedList(size_t s, T k)
{
	size = s;
	if (size != 0) {
		Point<T>* obj = new Point<T>;
		obj->num = k;
		head = obj;
		Point<T>* temp = head;
		for (int i = size - 1; i != 0; i--)
		{
			obj = new Point<T>;
			temp->next = obj;
			obj->num = k;
			temp = obj;
		}
		top = obj;
	}
}

template <typename T>
void LinkedList<T>::push(T k)
{
	if (size == 0)
	{
		head = new Point<T>;
		head->num = k;
		top = head;
	}

	else {
		Point<T>* obj = new Point<T>;
		top->next = obj;
		obj->num = k;
		top = obj;
	}
	size++;
}

template <typename T>
T LinkedList<T>::pop()
{
	T k = head->num;
	Point<T>* temp = head;
	head = head->next;
	size--;
	delete temp;
	return k;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	cout << endl << "¬ызван деструктор!" << endl << endl;
	while (head != nullptr)
	{
		pop();
	}
}

template <typename T>
void LinkedList<T>::output(Point<T>* obj) const
{
	cout << obj->num << " ";
	if (obj == top) return;
	output(obj->next);
}
template <typename T>
void LinkedList<T>::show() const
{
	if (size == 0) cout << "—писок пуст" << endl;
	else output(head);
}

template <typename T>
T& LinkedList<T>::operator[](int index) const
{
	if (index < size && index >= 0)
	{
		Point<T>* temp = head;
		int count = 0;
		while (temp != nullptr)
		{
			if (count == index)
				return temp->num;
			temp = temp->next;
			++count;
		}
	}
	cout << endl << endl;
	perror("ќшибка индексировани¤");
	cout << endl;
	exit(1);
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list)
{
	for (int i = 0; i < list.size; i++)
	{
		this->push(list[i]);
	}
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator =(const LinkedList<T>& list)
{

	int size_temp = size;
	for (int i = 0; i < size_temp; i++)
	{
		this->pop();
	}
	for (int i = 0; i < list.size; i++)
	{
		this->push(list[i]);
	}
	return *this;
}

template <typename T>
LinkedList<T> LinkedList<T>::operator * (LinkedList<T>& list)
{
	T nulik;
	nulik = 0;
	LinkedList<T> new_list;
	for (int i = 0; i < min((int)size, list()); i++)
	{
		new_list.push((*this)[i] * list[i]);
	}
	for (int i = 0; i < max((int)size, list()) - min((int)size, list()); i++)
	{
		new_list.push(nulik);
	}
	return new_list;
}