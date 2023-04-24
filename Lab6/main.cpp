#include "LinkedList.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	LinkedList list;
	int num_elem, elem;
	cout << "Введите кол-во элементов в 1 списке: ";
	cin >> num_elem;
	cout << "\n";
	if (num_elem <= 1)
		cout << "В списке должно быть хотя бы 2 элемента!\n";
	cout << "Заполняем список 1\n\n";
	for (int i = 1; i <= num_elem; i++)
	{
		cout << "Введите " << i << " элемент: ";
		cin >> elem;
		list.push(elem);
		cout << "\n";
	}
	cout << "Вывод элементов списка 1: ";
	cout << list << endl;
	cout << "\nРазмер списка 1: ";
	cout << list() << endl;
	cout << "Первый элемент в списке 1: ";
	cout << list[0] << endl;
	cout << "Создаем итератор, выводим через итератор: ";
	Iterator i = list.first();
	for (; i != list.last(); i++)
		cout << *i << " ";
	cout << endl;
	cout << "Удаляем 1-ый элемент\n";
	list.pop();
	i = list.first();
	cout << "i+=4\n";
	i = i + 4;
	cout << "*i: ";
	cout << *i << endl;
	cout << "Введите кол-во элементов во 2 списке: ";
	cin >> num_elem;
	cout << "\n";
	if (num_elem <= 1)
		cout << "В списке должно быть хотя бы 2 элемента!\n";
	cout << "Заполнение списка 2\n";
	LinkedList list2;
	for (int i = 1; i <= num_elem; i++)
	{
		cout << "Введите " << i << " элемент: ";
		cin >> elem;
		list2.push(elem);
		cout << "\n";
	}
	cout << endl;
	cout << "Вывод 1-ого списка\n";
	cout << list << endl << endl;
	cout << "Вывод 2-ого списка\n";
	cout << list2 << endl << endl;
	cout << "list3 = list * list2\n";
	LinkedList list3 = list * list2;
	cout << list3;
	return 0;
}