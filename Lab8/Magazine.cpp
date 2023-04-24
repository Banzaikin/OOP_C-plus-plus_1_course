#include "Magazine.h"
Magazine::Magazine(void):Print()
{
	number_of_pages = 0;
}

Magazine::~Magazine(void)
{
}

Magazine::Magazine(int N)
{
	number_of_pages = N;
}

Magazine::Magazine(const Magazine& m)
{
	number_of_pages = m.number_of_pages;
}

void Magazine::set_number_of_pages(int n)
{
	number_of_pages = n;
}

Magazine& Magazine::operator=(const Magazine& m)
{
	if (&m == this)
		return *this;
	number_of_pages = m.number_of_pages;
	return *this;
}

void Magazine::show()
{
	cout << "\nКоличество страниц: " << number_of_pages;
}

void Magazine::input()
{
	cout << "\nВведите кол-во страниц: ";
	cin >> number_of_pages;
}