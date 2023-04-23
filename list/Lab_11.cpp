#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <stdio.h>
using namespace std;

struct Element
{
	char data[255]; //поле данных
	Element* next = nullptr; //указатель на следующий элемент
	Element* prev = nullptr; //указатель на предыдущий элемент
};

Element* head = nullptr;

//функция создания списка
void createList(Element*& head, int n)
{
	Element* start = nullptr;
	Element* end = nullptr;
	head = new Element;
	cout << "Введите head элемент: ";
	cin.get();
	cin.getline((*head).data, 255);
	cout << endl;
	start = head;
	end = head;
	for (int i = 1; i <= n - 1; i++)
	{
		cout << "Введите " << i + 1 << " элемент: ";
		Element* elem = new Element;
		elem->next = nullptr;
		cin.getline((*elem).data, 255);
		cout << endl;
		elem->prev = end;
		end->next = elem;
		end = elem;
	}
}

//функция поиска объекта по индексу
Element* findObj(int index)
{
	Element* temp = head;
	int k = 1;
	while (temp != nullptr)
	{
		if (k == index)
			return temp;
		else {
			k++;
			temp = temp->next;
		}
	}
	return nullptr;
}

//функция поиска объекта по ключу
Element* findObj(char* str)
{
	Element* temp = head;
	while (temp != nullptr)
	{
		if (strcmp((*temp).data, str) == 0) {
			return temp;
		}
		else {
			temp = temp->next;
		}
	}
	return nullptr;
}

//функция добавления элемента после заданного номера
void addElementAfter(int index)
{
	Element* end = findObj(index);
	Element* elemIns = new Element;
	cout << "Введите новый элемент: ";
	cin.getline((*elemIns).data, 255);
	cout << endl;
	//Добавление перед первым элементом
	if (index == 1) {
		Element* start = nullptr;
		elemIns->next = end;
		elemIns->prev = start;
		end->prev = elemIns;
		head = elemIns;
	}
	//Добавление в середину перед заданным элементом
	else {
		Element* start = end->prev;
		elemIns->next = end;
		elemIns->prev = start;
		start->next = elemIns;
		end->prev = elemIns;
	}
}

//функция добавления элемента перед заданным номером
void addElementBefore(int index, int size)
{
	Element* start = findObj(index);
	Element* elemIns = new Element;
	cout << "Введите новый элемент: ";
	cin.getline((*elemIns).data, 255);
	cout << endl;
	//добавление в конец после заданного номера
	if (index == size) {
		Element* end = nullptr;
		elemIns->next = end;
		elemIns->prev = start;
		start->next = elemIns;
	}
	//добавление в середину после заданного номера
	else {
		Element* end = start->next;
		elemIns->next = end;
		elemIns->prev = start;
		start->next = elemIns;
		end->prev = elemIns;
	}
}

//функция удаления элемента 
void removeElementList(char* s)
{
	Element* elemIns = findObj(s);
	if (elemIns == nullptr)
		cout << "Ошибка! Такого элемента нет!" << endl;
	else {
		if ((*elemIns).prev != nullptr)
			(*elemIns).prev->next = elemIns->next;
		else
			head = elemIns->next;
		if ((*elemIns).next != nullptr)
			(*elemIns).next->prev = elemIns->prev;
		delete elemIns;
	}
}

//функция печати списка
void printList()
{
	Element* elem = head;
	for (int i = 1; elem != nullptr; i++)
	{
		cout << i << ": " << (*elem).data << endl;
		elem = elem->next;
	}
}

//запись списка в файл
void toFile(char* filename)
{
	FILE* file;
	if ((file = fopen(filename, "wb")) == NULL)
	{
		cout << "Ошибка открытия файла" << endl;
		return;
	}
	Element* temp = head;
	while (temp != nullptr)
	{
		fputs(temp->data, file);
		fputs("\n", file);
		temp = temp->next;
	}
	cout << "Данные списка успешно занесены в файл" << endl;
	fclose(file);
}

//функция удаления списка
void deleteList()
{
	Element* elem = head;
	while (head != nullptr)
	{
		elem = head->next;
		delete head;
		head = elem;
	}
}

//функция восстановления списка из файла
int fromFile(char* filename)
{
	FILE* file;
	char row[255];
	int i = 0;
	if ((file = fopen(filename, "rb")) == NULL)
	{
		cout << "Ошибка открытия файла" << endl;
		return i;
	}
	Element* start = new Element;
	Element* end;
	start->prev = nullptr;
	head = start;
	//пока файл не пустой, считываем элементы
	while (!feof(file) && fgets(row, 255, file))
	{
		row[strlen(row) - 1] = '\0';
		strcpy(start->data, row);
		end = new Element;
		start->next = end;
		end->prev = start;
		start = end;
		++i;
	}
	fclose(file);
	if (i == 0) {
		cout << "В файле ничего нет." << endl;
		head = nullptr;
		delete start;
	}
	else {
		if (start->prev != nullptr)
			start->prev->next = nullptr;
		delete start;
	}
	cout << "Данные из списка успешно считаны из файла" << endl;
	return i;
}

//меню команд
const char menu[] =
"0.	Выход из программы\n"
"1.	Создание списка\n"
"2.	Добавление элемента в список.\n"
"3.	Удаление элемента из списка.\n"
"4.	Печать списка.\n"
"5.	Запись списка в файл.\n"
"6.	Уничтожение списка.\n"
"7.	Восстановление списка из файла.\n";

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int cmd, k, num;
	int size = 0;
	char keys[255];
	char orientation[255];
	char filename[] = "list.txt";
	for (;;)
	{
		cout << menu << endl;
		cout << "\nВыберите команду: ";
		cin >> cmd;
		cout << endl;
		switch (cmd)
		{
		case 0: //выход из программы
			cout << "Спасибо что выбрали данную программу!" << endl;
			return 0;
		case 1: //создание списка
			cout << "Введите кол-во элементов в списке: ";
			cin >> size;
			createList(head, size);
			break;
		case 2: //добавление элементов в список
			cout << "Введите кол-во добавляемых элементов: ";
			cin >> k;
			cout << "\nВведите номер элемента, рядом с которым будем вставлять: ";
			cin >> num;
			cout << "\nДо элемента или после будем вставлять? (до/после): ";
			cin.get();
			cin.getline(orientation, 255);
			if (num >= 1 && num <= size) {
				if (strcmp(orientation, "до"))
				{
					cin.get();
					for (int i = 1; i <= k; i++)
					{
						addElementBefore(num, size);
						size++;
						num++;
					}
				}
				else
				{
					cin.get();
					for (int i = 1; i <= k; i++)
					{
						addElementAfter(num);
						size++;
						num++;
					}
				}
			}
			else
				cout << endl << "Ошибка! Введите корректный номер элемента!" << endl;
			break;
		case 3: //удаление элемента из списка по ключу
			cout << "Введите ключ удаляемого элемента: ";
			cin.get();
			cin.getline(keys, 255);
			removeElementList(keys);
			size--;
			break;
		case 4: //печать списка
			if (size <= 0) {
				cout << "Список пуст!" << endl;
			}
			else {
				cout << "Сейчас список такой" << endl;
				printList();
			}
			break;
		case 5: //запись в файл
			toFile(filename);
			break;
		case 6: //удаление списка
			if (size == 0) {
				cout << "Список пуст, удалять нечего" << endl;
			}
			else {
				deleteList();
				cout << "Список успешно удален" << endl;
				size = 0;
			}
			break;
		case 7: //считывание с файла
			size = fromFile(filename);
			break;
		default:
			cout << "Неправильная команда, попробуйте другую" << endl;
		}
		system("pause");
		system("cls");
	}
}
