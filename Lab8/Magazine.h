#pragma once
#include "Print.h"
class Magazine :
    public Print
{
public:
    Magazine(void);
public:
    ~Magazine(void);
    void show();
    void input();
    Magazine(int);
    Magazine(const Magazine&);
    int get_number_of_pages() { return number_of_pages; };
    void set_number_of_pages(int);
    Magazine& operator=(const Magazine&);
protected:
    int number_of_pages;
};

