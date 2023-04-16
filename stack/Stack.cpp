#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <stdio.h> 
#include <Windows.h> 

using namespace std;

struct Point
{
	char data[255]; //поле данных
	Point* next = nullptr; //указатель на следующий элемент стека
};

struct Stack
{
	Point* head = nullptr; //указатель на последний элемент стека
	size_t stack_size = 0;
};

bool stack_is_empty(Stack& stack); //проверка на пустой стек
void output(Point* obj); //рекурсивная функция для обратного вывода 3 2 1 -> 1 2 3 (ввод был 1 2 3)
void show_stack(Stack& stack); //вывод стека
void push(Stack& stack, char* str); //добавить новый элемент сверху
Stack* create_stack(int size); //создание стека из n элементов
void remove_obj(Stack& stack, char* str); //удалить объект с заданным ключом
void push_before(Stack& stack, unsigned index, unsigned k); //вставить перед элементом
void remove_stack(Stack& stack); //удаление списка
void toFile_obj(Point* obj, FILE* file); //рекурсия ф-ия для обратного порядка заноса в файл
void toFile(Stack& stack, char* filename); //загрузить в файл ключи стека
void fromFile(Stack& stack, char* filename); //выгрузить из файла ключи стека

bool stack_is_empty(Stack& stack) //проверка на пустой стек
{
	return stack.head == nullptr; //stack_size = 0;
}
void output(Point* obj) //рекурсивная функция для обратного вывода 3 2 1 -> 1 2 3 (ввод был 1 2 3)
{
	if (obj == nullptr) return;
	output(obj->next);
	cout << obj->data << endl;
}
void show_stack(Stack& stack) //вывод стека
{
	if (stack_is_empty(stack)) cout << "Стек пуст" << endl;
	else output(stack.head);
}
void push(Stack& stack, char* str) //добавить новый элемент сверху
{
	stack.stack_size++;
	Point* obj = new Point;
	strcpy(obj->data, str);
	obj->next = stack.head;
	stack.head = obj;
}
void pop(Stack& stack)
{
	if (stack.head != nullptr)
	{
		Point* temp = stack.head;
		stack.head = stack.head->next;
		delete temp;
		stack.stack_size--;
	}
}
Stack* create_stack(int size) //создание стека из n элементов
{
	Stack* stack = new Stack;
	if (size > 0 && stack_is_empty(*stack))
	{
		char str[255];
		cout << "Введите ключи " << size << " элементов стека: " << endl;
		cin.get();
		for (int i = 1; i <= size; i++)
		{
			cout << i << ". ";
			gets_s(str, 255);
			push(*stack, str);
		}
	}
	return stack;
}
void push_before(Stack& stack, unsigned index, unsigned k)
{
	int new_index = stack.stack_size - index + 1;
	if (new_index < 0 || stack_is_empty(stack)) cout << "Введен неверный индекс/стек пуст" << endl;
	else
	{
		char str[255];
		Stack* stack2 = new Stack;
		for (int i = 1; i <= new_index; i++)
		{
			push(*stack2, stack.head->data);
			pop(stack);
		}
		cout << "Введите " << k << " элементов: " << endl;
		cin.get();
		for (int i = 1; i <= k; i++)
		{
			cin.getline(str, 255);
			push(stack, str);
		}
		for (int i = 0; i < new_index; i++)
		{
			push(stack, stack2->head->data);
			pop(*stack2);
		}

	}
}
void remove_obj(Stack& stack, char* str)
{
	int stack_size = stack.stack_size;
	Stack* stack2 = create_stack(0);
	for (int i = 1; i <= stack_size; i++)
	{
		if (strcmp(stack.head->data, str) != 0)
		{
			push(*stack2, stack.head->data);
		}
		pop(stack);
	}
	cout << endl;
	int stack_size2 = stack2->stack_size;
	for (int i = 1; i <= stack_size2; i++)
	{
		push(stack, stack2->head->data);
		pop(*stack2);
	}
}
void remove_stack(Stack& stack) //удаление списка
{
	Point* temp;
	while (stack.head != nullptr)
	{
		temp = stack.head->next;
		delete stack.head;
		stack.head = temp;
	}
	stack.stack_size = 0;
	cout << "Список удален!" << endl;
}
void toFile_obj(Point* obj, FILE* file)
{
	if (obj == nullptr) return;
	toFile_obj(obj->next, file);
	fputs(obj->data, file);
	fputs("\n", file);
}
void toFile(Stack& stack, char* filename) //загрузить в файл ключи стека
{
	FILE* file;
	if ((file = fopen(filename, "wb")) == NULL) //ошибка открытия файла 
	{
		cout << "Ошибка открытия файла" << endl;
		exit(1);
	}
	cout << "Заносим данные в файл..." << endl;
	toFile_obj(stack.head, file);
	cout << "Данные успешно занесены!" << endl;
	fclose(file);
}
void fromFile(Stack& stack, char* filename) //выгрузить из файла ключи списка
{
	FILE* file;
	char row[255];
	if ((file = fopen(filename, "rb")) == NULL) //ошибка открытия файла 
	{
		cout << "Ошибка открытия файла" << endl;
		exit(2);
	}
	cout << "Считываем данные из файла..." << endl;
	while (!feof(file) && fgets(row, 255, file))
	{
		row[strlen(row) - 1] = '\0'; //заносили с \n, нужно его убрать.
		push(stack, row);
	}
	fclose(file);
	cout << "Данные успешно считаны!" << endl;
}
//меню команд
const char menu[] =
"0.	Выход из программы\n"
"1.	Создание стека\n"
"2.	Добавление элемента в стек.\n"
"3.	Удаление элемента из стека.\n"
"4.	Печать стека.\n"
"5.	Запись стека в файл.\n"
"6.	Уничтожение стека.\n"
"7.	Восстановление стека из файла.\n";

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Stack* stack = new Stack;
	int cmd, k, n;
	int size = 0;
	char keys[255];
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
		case 1: //создание стека
			cout << "Введите кол-во элементов в списке: ";
			cin >> size;
			stack = create_stack(size);
			break;
		case 2: //добавление элементов в стека
			cout << "Введите кол-во объетов и позицию: " << endl;
			cin >> k >> n;
			push_before(*stack, k, n);
			break;
		case 3: //удаление элемента из стека по ключу
			cout << "Введите ключ объекта, который хотите удалить: " << endl;
			cin.get();
			cin.getline(keys, 255);
			remove_obj(*stack, keys);
			break;
		case 4: //печать стека
			if (size <= 0) {
				cout << "Стек пуст!" << endl;
			}
			else {
				cout << "Сейчас стек такой" << endl;
				show_stack(*stack);
			}
			break;
		case 5: //запись в файл
			toFile(*stack, filename);
			break;
		case 6: //удаление стека
			if (size == 0) {
				cout << "Стек пуст, удалять нечего" << endl;
			}
			else {
				remove_stack(*stack); 
				cout << "Стека успешно удален" << endl;
				size = 0;
			}
			break;
		case 7: //считывание с файла
			fromFile(*stack, filename);
			break;
		default:
			cout << "Неправильная команда, попробуйте другую" << endl;
		}
		system("pause");
		system("cls");
	}
}