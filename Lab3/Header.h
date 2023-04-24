#pragma once
#include <iostream>
using namespace std;
class Pair
{
	int first;
	double third;
	double second;
	double c;
public:
	Pair() { first = 0; second = 0; c = 0; third = 0; };
	Pair(int f, double s, double co, double t) { first = f; second = s; c = co; third = t; }
	Pair(const Pair& p) { first = p.first; second = p.second; c = p.c; third = p.third; }
	~Pair() {};
	int get_first() { return first; }
	int get_second() { return second; }
	double get_c() { return c; }
	double get_third() { return third; }
	void set_first(int f) { first = f; }
	void set_second(double s) { second = s; }
	void set_c(double co) { c = co; }
	void set_third(double t) { third = t; }
	//перегруженные операции
	Pair& operator = (const Pair&);
	Pair operator -(const Pair&);
	Pair operator +(const Pair&);
	//глобальные функции ввода-вывода
	friend istream& operator >> (istream& in, Pair& p);
	friend ostream& operator << (ostream& out, const Pair& p);
};