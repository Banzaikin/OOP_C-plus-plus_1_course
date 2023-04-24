#pragma once
#include "Object.h" 
#include <string> 
#include <iostream> 
using namespace std; 

class Person:public Object
{
public:
	Person(void); 
public:
	virtual ~Person(void);
	void show();
	Person(string, int);
	Person(const Person&);
	string get_name() 
	{ 
		return name; 
	} 
	int get_age() 
	{ 
		return age; 
	}
	void set_name(string);
	void set_age(int); 
	Person& operator=(const Person&);
	friend istream& operator>>(istream& in, Person& c); 
	friend ostream& operator<<(ostream& out, const Person& c);
protected:
	string name; 
	int age;
};
