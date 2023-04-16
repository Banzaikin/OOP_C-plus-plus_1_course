#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <stdio.h>
using namespace std;

struct Element
{
	char data[255]; //���� ������
	Element* next = nullptr; //��������� �� ��������� �������
	Element* prev = nullptr; //��������� �� ���������� �������
};

Element* head = nullptr;

//������� �������� ������
void createList(Element*& head, int n)
{
	Element* start = nullptr;
	Element* end = nullptr;
	head = new Element;
	cout << "������� head �������: ";
	cin.get();
	cin.getline((*head).data, 255);
	cout << endl;
	start = head;
	end = head;
	for (int i = 1; i <= n - 1; i++)
	{
		cout << "������� " << i + 1 << " �������: ";
		Element* elem = new Element;
		elem->next = nullptr;
		cin.getline((*elem).data, 255);
		cout << endl;
		elem->prev = end;
		end->next = elem;
		end = elem;
	}
}

//������� ������ ������� �� �������
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

//������� ������ ������� �� �����
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

//������� ���������� �������� ����� ��������� ������
void addElementAfter(int index)
{
	Element* end = findObj(index);
	Element* elemIns = new Element;
	cout << "������� ����� �������: ";
	cin.getline((*elemIns).data, 255);
	cout << endl;
	//���������� ����� ������ ���������
	if (index == 1) {
		Element* start = nullptr;
		elemIns->next = end;
		elemIns->prev = start;
		end->prev = elemIns;
		head = elemIns;
	}
	//���������� � �������� ����� �������� ���������
	else {
		Element* start = end->prev;
		elemIns->next = end;
		elemIns->prev = start;
		start->next = elemIns;
		end->prev = elemIns;
	}
}

//������� ���������� �������� ����� �������� �������
void addElementBefore(int index, int size)
{
	Element* start = findObj(index);
	Element* elemIns = new Element;
	cout << "������� ����� �������: ";
	cin.getline((*elemIns).data, 255);
	cout << endl;
	//���������� � ����� ����� ��������� ������
	if (index == size) {
		Element* end = nullptr;
		elemIns->next = end;
		elemIns->prev = start;
		start->next = elemIns;
	}
	//���������� � �������� ����� ��������� ������
	else {
		Element* end = start->next;
		elemIns->next = end;
		elemIns->prev = start;
		start->next = elemIns;
		end->prev = elemIns;
	}
}

//������� �������� �������� 
void removeElementList(char* s)
{
	Element* elemIns = findObj(s);
	if (elemIns == nullptr)
		cout << "������! ������ �������� ���!" << endl;
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

//������� ������ ������
void printList()
{
	Element* elem = head;
	for (int i = 1; elem != nullptr; i++)
	{
		cout << i << ": " << (*elem).data << endl;
		elem = elem->next;
	}
}

//������ ������ � ����
void toFile(char* filename)
{
	FILE* file;
	if ((file = fopen(filename, "wb")) == NULL)
	{
		cout << "������ �������� �����" << endl;
		return;
	}
	Element* temp = head;
	while (temp != nullptr)
	{
		fputs(temp->data, file);
		fputs("\n", file);
		temp = temp->next;
	}
	cout << "������ ������ ������� �������� � ����" << endl;
	fclose(file);
}

//������� �������� ������
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

//������� �������������� ������ �� �����
int fromFile(char* filename)
{
	FILE* file;
	char row[255];
	int i = 0;
	if ((file = fopen(filename, "rb")) == NULL)
	{
		cout << "������ �������� �����" << endl;
		return i;
	}
	Element* start = new Element;
	Element* end;
	start->prev = nullptr;
	head = start;
	//���� ���� �� ������, ��������� ��������
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
		cout << "� ����� ������ ���." << endl;
		head = nullptr;
		delete start;
	}
	else {
		if (start->prev != nullptr)
			start->prev->next = nullptr;
		delete start;
	}
	cout << "������ �� ������ ������� ������� �� �����" << endl;
	return i;
}

//���� ������
const char menu[] =
"0.	����� �� ���������\n"
"1.	�������� ������\n"
"2.	���������� �������� � ������.\n"
"3.	�������� �������� �� ������.\n"
"4.	������ ������.\n"
"5.	������ ������ � ����.\n"
"6.	����������� ������.\n"
"7.	�������������� ������ �� �����.\n";

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
		cout << "\n�������� �������: ";
		cin >> cmd;
		cout << endl;
		switch (cmd)
		{
		case 0: //����� �� ���������
			cout << "������� ��� ������� ������ ���������!" << endl;
			return 0;
		case 1: //�������� ������
			cout << "������� ���-�� ��������� � ������: ";
			cin >> size;
			createList(head, size);
			break;
		case 2: //���������� ��������� � ������
			cout << "������� ���-�� ����������� ���������: ";
			cin >> k;
			cout << "\n������� ����� ��������, ����� � ������� ����� ���������: ";
			cin >> num;
			cout << "\n�� �������� ��� ����� ����� ���������? (��/�����): ";
			cin.get();
			cin.getline(orientation, 255);
			if (num >= 1 && num <= size) {
				if (strcmp(orientation, "��"))
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
				cout << endl << "������! ������� ���������� ����� ��������!" << endl;
			break;
		case 3: //�������� �������� �� ������ �� �����
			cout << "������� ���� ���������� ��������: ";
			cin.get();
			cin.getline(keys, 255);
			removeElementList(keys);
			size--;
			break;
		case 4: //������ ������
			if (size <= 0) {
				cout << "������ ����!" << endl;
			}
			else {
				cout << "������ ������ �����" << endl;
				printList();
			}
			break;
		case 5: //������ � ����
			toFile(filename);
			break;
		case 6: //�������� ������
			if (size == 0) {
				cout << "������ ����, ������� ������" << endl;
			}
			else {
				deleteList();
				cout << "������ ������� ������" << endl;
				size = 0;
			}
			break;
		case 7: //���������� � �����
			size = fromFile(filename);
			break;
		default:
			cout << "������������ �������, ���������� ������" << endl;
		}
		system("pause");
		system("cls");
	}
}
