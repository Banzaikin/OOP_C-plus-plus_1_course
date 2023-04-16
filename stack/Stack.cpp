#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <stdio.h> 
#include <Windows.h> 

using namespace std;

struct Point
{
	char data[255]; //���� ������
	Point* next = nullptr; //��������� �� ��������� ������� �����
};

struct Stack
{
	Point* head = nullptr; //��������� �� ��������� ������� �����
	size_t stack_size = 0;
};

bool stack_is_empty(Stack& stack); //�������� �� ������ ����
void output(Point* obj); //����������� ������� ��� ��������� ������ 3 2 1 -> 1 2 3 (���� ��� 1 2 3)
void show_stack(Stack& stack); //����� �����
void push(Stack& stack, char* str); //�������� ����� ������� ������
Stack* create_stack(int size); //�������� ����� �� n ���������
void remove_obj(Stack& stack, char* str); //������� ������ � �������� ������
void push_before(Stack& stack, unsigned index, unsigned k); //�������� ����� ���������
void remove_stack(Stack& stack); //�������� ������
void toFile_obj(Point* obj, FILE* file); //�������� �-�� ��� ��������� ������� ������ � ����
void toFile(Stack& stack, char* filename); //��������� � ���� ����� �����
void fromFile(Stack& stack, char* filename); //��������� �� ����� ����� �����

bool stack_is_empty(Stack& stack) //�������� �� ������ ����
{
	return stack.head == nullptr; //stack_size = 0;
}
void output(Point* obj) //����������� ������� ��� ��������� ������ 3 2 1 -> 1 2 3 (���� ��� 1 2 3)
{
	if (obj == nullptr) return;
	output(obj->next);
	cout << obj->data << endl;
}
void show_stack(Stack& stack) //����� �����
{
	if (stack_is_empty(stack)) cout << "���� ����" << endl;
	else output(stack.head);
}
void push(Stack& stack, char* str) //�������� ����� ������� ������
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
Stack* create_stack(int size) //�������� ����� �� n ���������
{
	Stack* stack = new Stack;
	if (size > 0 && stack_is_empty(*stack))
	{
		char str[255];
		cout << "������� ����� " << size << " ��������� �����: " << endl;
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
	if (new_index < 0 || stack_is_empty(stack)) cout << "������ �������� ������/���� ����" << endl;
	else
	{
		char str[255];
		Stack* stack2 = new Stack;
		for (int i = 1; i <= new_index; i++)
		{
			push(*stack2, stack.head->data);
			pop(stack);
		}
		cout << "������� " << k << " ���������: " << endl;
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
void remove_stack(Stack& stack) //�������� ������
{
	Point* temp;
	while (stack.head != nullptr)
	{
		temp = stack.head->next;
		delete stack.head;
		stack.head = temp;
	}
	stack.stack_size = 0;
	cout << "������ ������!" << endl;
}
void toFile_obj(Point* obj, FILE* file)
{
	if (obj == nullptr) return;
	toFile_obj(obj->next, file);
	fputs(obj->data, file);
	fputs("\n", file);
}
void toFile(Stack& stack, char* filename) //��������� � ���� ����� �����
{
	FILE* file;
	if ((file = fopen(filename, "wb")) == NULL) //������ �������� ����� 
	{
		cout << "������ �������� �����" << endl;
		exit(1);
	}
	cout << "������� ������ � ����..." << endl;
	toFile_obj(stack.head, file);
	cout << "������ ������� ��������!" << endl;
	fclose(file);
}
void fromFile(Stack& stack, char* filename) //��������� �� ����� ����� ������
{
	FILE* file;
	char row[255];
	if ((file = fopen(filename, "rb")) == NULL) //������ �������� ����� 
	{
		cout << "������ �������� �����" << endl;
		exit(2);
	}
	cout << "��������� ������ �� �����..." << endl;
	while (!feof(file) && fgets(row, 255, file))
	{
		row[strlen(row) - 1] = '\0'; //�������� � \n, ����� ��� ������.
		push(stack, row);
	}
	fclose(file);
	cout << "������ ������� �������!" << endl;
}
//���� ������
const char menu[] =
"0.	����� �� ���������\n"
"1.	�������� �����\n"
"2.	���������� �������� � ����.\n"
"3.	�������� �������� �� �����.\n"
"4.	������ �����.\n"
"5.	������ ����� � ����.\n"
"6.	����������� �����.\n"
"7.	�������������� ����� �� �����.\n";

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
		cout << "\n�������� �������: ";
		cin >> cmd;
		cout << endl;
		switch (cmd)
		{
		case 0: //����� �� ���������
			cout << "������� ��� ������� ������ ���������!" << endl;
			return 0;
		case 1: //�������� �����
			cout << "������� ���-�� ��������� � ������: ";
			cin >> size;
			stack = create_stack(size);
			break;
		case 2: //���������� ��������� � �����
			cout << "������� ���-�� ������� � �������: " << endl;
			cin >> k >> n;
			push_before(*stack, k, n);
			break;
		case 3: //�������� �������� �� ����� �� �����
			cout << "������� ���� �������, ������� ������ �������: " << endl;
			cin.get();
			cin.getline(keys, 255);
			remove_obj(*stack, keys);
			break;
		case 4: //������ �����
			if (size <= 0) {
				cout << "���� ����!" << endl;
			}
			else {
				cout << "������ ���� �����" << endl;
				show_stack(*stack);
			}
			break;
		case 5: //������ � ����
			toFile(*stack, filename);
			break;
		case 6: //�������� �����
			if (size == 0) {
				cout << "���� ����, ������� ������" << endl;
			}
			else {
				remove_stack(*stack); 
				cout << "����� ������� ������" << endl;
				size = 0;
			}
			break;
		case 7: //���������� � �����
			fromFile(*stack, filename);
			break;
		default:
			cout << "������������ �������, ���������� ������" << endl;
		}
		system("pause");
		system("cls");
	}
}