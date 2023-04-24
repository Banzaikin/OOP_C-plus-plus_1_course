#include "LinkedList.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	int num_elem;
	Pair elem;
	cout << "Введите кол-во элементов в 1 списке: ";
	cin >> num_elem;
	cout << "\n";
	if (num_elem <= 1)
		cout << "В списке должно быть хотя бы 2 элемента!\n";
	cout << "Заполняем список 1\n\n";
	Pair pair(1, 2);
	LinkedList <Pair> list(num_elem, pair);
	for (int i = 1; i <= num_elem; i++)
	{
		cout << "Введите " << i << " элемент: ";
		cin >> elem;
		list.push(elem);
		cout << "\n";
	}
	cout << list << endl;
	Pair pair2(2, 10);
	LinkedList <Pair> list2(5, pair2);
	cout << list2 << endl;
	LinkedList <Pair> list1 = list * list2;
	cout << list1 << endl;
	Iterator<Pair> it = list1.first();
	for (; it != list1.last(); it++)
	{
		cout << *it << " ";
	}
	cout << *it << endl;
	cout << "\n\n\n\n\n" << endl;
	LinkedList <double> list3(5, 4.5);
	list3.push(6);
	cout << list3 << endl;
	LinkedList <double> list4(5, 10);
	cout << list4 << endl;
	LinkedList <double> list34 = list3 * list4;
	cout << list34 << endl;
	Iterator<double> it2 = list34.first();
	for (; it2 != list34.last(); it2++)
	{
		cout << *it2 << " ";
	}
	cout << *it2;
	return 0;
}
