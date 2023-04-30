#pragma once
#include <iostream>
using namespace std;
class Pair
{
private:
	int first;
	double second;
public:
	Pair() { first = 0; second = 0; };
	Pair(int f, double s) { first = f; second = s; }
	Pair(const Pair& p) { first = p.first; second = p.second; }
	~Pair() {};
	int get_first() { return first; }
	int get_second() { return second; }
	void set_first(int f) { first = f; }
	void set_second(double s) { second = s; }
	//перегруженные операции
	Pair& operator =(const Pair& p);
	Pair operator +(const Pair& p) const;
	Pair& operator ++();
	Pair operator ++(int);
	Pair operator -(const Pair& p);
	bool operator <(const Pair& p) const;
	bool operator >(const Pair& p);
	friend const Pair operator +(const Pair& left, const int& right);
	friend const Pair operator +(const int& left, const Pair& right);
	friend const Pair operator +(const Pair& left, const double& right);
	friend const Pair operator +(const double& left, const Pair& right);
	Pair operator /(const Pair& p);
	Pair operator /(const int p);
	//глобальные функции ввода-вывода
	friend istream& operator >> (istream& in, Pair& p);
	friend ostream& operator << (ostream& out, const Pair& p);
};