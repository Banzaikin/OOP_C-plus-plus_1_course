#include "Dialog.h"

//конструктор 
Dialog::Dialog(void):Tree()
{
	EndState = 0;
}
//деструктор 
Dialog::~Dialog(void)
{
}
//получение события
void Dialog::GetEvent(TEvent& event)
{
	string OpInt = "+-?/qam"; //строка содержит коды операций 
	string s;
	string param;

	char code; cout << '>';
	cin >> s; code = s[0];//первый символ команды 
	if(OpInt.find(code)>=0)//является ли символ кодом операции
	{
		event.what = evMessage; 
		switch (code)
		{
		case 'm':	//создать группу
			event.command = cmMake; 
			break;	
		case '+':	//добавить объект в группу 
			event.command = cmAdd; 
			break;
		case '-':	//удалить объект из группы 
			event.command=cmDel;
			break;
		case '?':	//просмотр группы
			event.command=cmShow;
			break; 
		case'q':	//конец работы
			event.command = cmQuit;
			break; 
		case '/':	//handl_event
			event.command = cmGet; 
			break;
		}
		//выделяем параметры команды, если они есть 
		if(s.length()>1)
		{
			param = s.substr(1, s.length() - 1);
			int A = atoi(param.c_str());	//преобразуем парметр в число 
			event.a=A;	//записываем в сообщение
		}
	}
	else 
		event.what = evNothing;	//пустое событие
}

int Dialog::Execute()
{
	TEvent event; 
	do {
		EndState = 0;
		GetEvent(event); //получить событие 
		HandleEvent(event); //обработать событие

	} while (!Valid()); 
	return EndState;
}

int Dialog::Valid()
{
	if (EndState == 0) 
		return 0; 
	else 
		return 1;
}
void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;		//пустое событие
}

void Dialog::EndExec()
{
	EndState = 1;
}
//обработчик событий
void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake:	//создание группы 
			size=event.a; //размер группы
			beg = new Object * [size];//выделяем память под массив указателей 
			cur=0; //текущая позиция
			ClearEvent(event);//очищаем событие 
			break;
		case cmAdd:		//добавление
			add(); 
			ClearEvent(event); 
			break;
		case cmDel:		//удаление 
			del(); 
			ClearEvent( event ); 
			break;
		case cmShow:	//просмотр 
			show(); 
			ClearEvent( event );
			break;
		case cmQuit:	//выход 
			EndExec(); 
			ClearEvent( event );
			break;
		default:
			Tree::HandleEvent(event);
		};
	};
}
