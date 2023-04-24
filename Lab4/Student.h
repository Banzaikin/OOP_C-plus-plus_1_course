#pragma once
#include "Person.h"
//наследование
class Student :
    public Person
{
public:
    //конструктор без параметров
    Student(void);
public:
    //деструктор
    ~Student(void);
    //конструктор с параметрами 
    Student(string, int, string, int);
    //конструктор копирования
    Student(const Student& );
    //модификаторы
    string get_subject() { return subject; }
    int get_point() { return point; }
    //селекторы
    void set_subject(string);
    void set_point(int);
    //операция присваивания
    Student& operator=(const Student&);
    //операция ввода
    friend istream& operator>>(istream& in, Student& l);
    //операция вывода 
    friend ostream& operator<<(ostream& out, const Student& l); 
protected:
    string subject;//атрибут предмет
    int point; //атрибут оценка
};

