#pragma once
#include "Object.h"

class Print :
    public Object
{
public:
    Print(void);                //конструктор без параметров 
public:
    virtual ~Print(void);       //деструктор
    void show();                //функция для просмотра атрибутов класса с помощью указателя 
    void input();               //функция для ввода значений атрибутов 
    Print(string, string);      //конструктор с параметрами
    Print(const Print&);        //конструктор копирования
    //селекторы
    string get_name() { return name; } 
    string get_author() { return author; }
    //модификаторы
    void set_name(string); 
    void set_author(string); 
    Print& operator=(const Print&); //перегрузка операции присваивания 
    void HandleEvent(const TEvent& e);
protected:
    string name; 
    string author;
};

