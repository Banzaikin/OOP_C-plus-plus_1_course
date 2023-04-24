#pragma once
#include "Magazine.h"


class Tree
{
public:
	Tree();//конструктор с параметрами
public:
	Tree(int);
	~Tree(void);//деструктор
	void add();//добавление элемента в дерево
	void del();
	void show();
	int operator()();//размер вектора
	virtual void HandleEvent(const TEvent& e);
protected:
	Object** beg;//указатель на первый элемент вектора 
	int size;//размер
	int cur;//текущая позиция
};
