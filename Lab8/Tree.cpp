#include "Tree.h"
#include "Print.h"
#include "Magazine.h"

//деструктор 
Tree::~Tree(void)
{
if (beg != 0)
	delete[] beg; 
beg = 0;
}
//конструктор с параметрами 
Tree::Tree(int n)
{
	beg = new Object * [n]; 
	cur = 0;
	size = n;
}
//добавление объекта, на который указывает указатель p в вектор 
void Tree::add()
{
	Object* p;
	//выбор из объектов двух возможных классов 
	cout << "1.Print" << endl; 
	cout << "2.Magazine" << endl;
	int y; 
	cin >> y;
	if (y == 1)//добавление объекта класса Print
	{
		Print* a = new (Print);
		a->input();//ввод значений атрибутов 
		p=a;
		if (cur < size)
		{
			beg[cur] = p;//добавление в дерево
			cur++;
		}
	}
	else
	{
		if (y == 2) //добавление объекта класса Magazine
		{
			Magazine* b = new Magazine;
			b->input();
			p = b;
			if (cur < size)
			{
				beg[cur] = p; 
				cur++;
			}
		}
		else
			return;
	}
}

//просмотр дерева
void Tree::show()
{
	if (cur == 0) 
		cout << "Пусто" << endl;
	Object** p = beg;//указатель на указатель типа Object 
	for(int i=0;i<cur;i++)
	{
		(*p)->show();//вызов метода Show() (позднее связывание) 
		p++;//передвигаем указатель на следующий объект
	}
}
//операция, которая возвращает размер вектора 
int Tree::operator ()()
{
	return cur;
}
//удаление элемента из вектора, память не освобождается! 
void Tree::del()
{
	if (cur == 0)
		return;	//пустой 
	cur--;
}

void Tree::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);//вызов метода (позднее связывание) 
			p++;//передвигаем указатель на следующий объект
		}
	}
}
