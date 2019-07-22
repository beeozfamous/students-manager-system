#include"HeaderFIRSTtouch.h"
void GetClassList(Node2*&chead)
{
	ifstream fin;
	fin.open("ClassList.csv");
	string aclass;
	chead = new Node2;
	Node2 *cur;
	if (!fin.is_open())
	{
		system("CLS");
		cout << "Crashh: CANNOT OPEN SOURCE";
		system("pause");
		exit(0);
	}
	getline(fin, chead->classname, ',');
	chead->next = NULL;
	cur = chead;
	while (!fin.eof())
	{
		cur->next = new Node2;
		cur = cur->next;
		getline(fin, cur->classname, ',');
		cur->next = NULL;
	}
	fin.close(); 
}
void ViewClassList(Node*AccessedUser, Node*&phead)
{
	View1BoxDraw();
	Node2*chead = NULL, *cur;
	GetClassList(chead);
	cur = chead;
	ClassListScroll(AccessedUser, phead, chead, cur);
}
void ClearViewBox()
{
	setcolor(63);
	for (int i = 3; i <= 76; i++)
		for (int j = 5; j <= 19; j++)
		{
			gotoxy(i, j);
			cout << " ";
		}
}
void View1BoxDraw()
{
	gotoxy(2, 4); cout << char(218);
	for (int i = 1; i <= 74; i++)
	{
		cout << char(196);
	}
	gotoxy(77, 4); cout << char(191);
	for (int i = 5; i <= 19; i++)
	{
		gotoxy(77, i);
		cout << char(179);
	}
	gotoxy(77, 20); cout << char(217);
	gotoxy(2, 20); cout << char(192);
	for (int i = 1; i <= 74; i++)
	{
		cout << char(196);
	}
	for (int i = 5; i <= 19; i++)
	{
		gotoxy(2, i);
		cout << char(179);
	}
	setcolor(58);
	gotoxy(5, 4); cout << "[CLASS VIEW]";
	setcolor(63);
	DrawEnter1Box();
}
void DrawEnter1Box()
{
	gotoxy(10, 23); std::cout << char(218);
	for (int i = 1; i <= 59; i++)
	{
		cout << char(196);
	}
	gotoxy(70, 23); cout << char(191);
	gotoxy(70, 24); cout << char(179);
	gotoxy(70, 25); cout << char(217);
	gotoxy(10, 24); cout << char(179);
	gotoxy(10, 25); cout << char(192);
	for (int i = 1; i <= 59; i++)
	{
		cout << char(196);
	}
	gotoxy(60, 23); cout << char(194);
	gotoxy(60, 24); cout << char(179);
	gotoxy(60, 25); cout << char(193);
	setcolor(58);
	gotoxy(62, 24); cout << "GoClass!";
	gotoxy(20, 20); cout << "[ ENTER CLASS NAME TO GET STUDENT LIST ]!";
	setcolor(63);
	gotoxy(71, 22); cout << char(218);
	for (int i = 1; i <= 5; i++)
		cout << char(196);
	gotoxy(77, 22); cout << char(191);
	gotoxy(77, 23); cout << char(179);
	gotoxy(77, 24); cout << char(179);
	gotoxy(77, 25); cout << char(179);
	gotoxy(77, 26); cout << char(217);
	gotoxy(71, 23); cout << char(179);
	gotoxy(71, 24); cout << char(179);
	gotoxy(71, 25); cout << char(179);
	gotoxy(71, 26); cout << char(192);
	for (int i = 1; i <= 5; i++)
		cout << char(196);
	setcolor(60);
	gotoxy(72,23); cout << " ADD ";
	gotoxy(72,24); cout << "CLASS";
	gotoxy(72, 25); cout << " !!! ";
	setcolor(63);
}
void ClassListScroll(Node*AccessedUser, Node*&phead, Node2*chead, Node2*&cur)
{
	HANDLE ScreenConsole;
	DWORD Num, Mode;
	INPUT_RECORD EventInput;

	ScreenConsole = GetStdHandle(STD_INPUT_HANDLE);
	if (ScreenConsole == INVALID_HANDLE_VALUE)
		return;
	Mode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(ScreenConsole, Mode))
		return;
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(ScreenConsole, Mode)) return;
	setcolor(59);
	gotoxy(55, 10); cout << "| GO  --->>  |";
	gotoxy(55, 11); cout << "|NEXT ---->>>|";
	gotoxy(55, 12); cout << "| !   --->>  |";
	gotoxy(55, 13); cout << "|  [ENTER]   |";
	gotoxy(55, 14); cout << "| TO GET OUT |";
	setcolor(63);
	while (true)
	{
		FlushConsoleInputBuffer(ScreenConsole);
		ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
		if (EventInput.EventType == KEY_EVENT)
		{
			if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT &&EventInput.Event.KeyEvent.bKeyDown==true)
			{
				ClearViewBox();
				for (int i = 5; i <= 19; i++)
				{
					if (cur->next != NULL)
					{
						gotoxy(3, i);
						cout <<"----->"<< cur->classname;
						cur = cur->next;
					}
					else
					{
						cur = chead;
						break;
					}
				}
				ClassListScroll(AccessedUser, phead, chead, cur);
			}
			if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
			{
				ViewAndSearchMouseDetect(AccessedUser, phead);
			}
		}
		if (EventInput.EventType == MOUSE_EVENT)
		{
			if (EventInput.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 11 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 70 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 23 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 25)
				{
					ShowFindedClass(AccessedUser, phead);
				}
			}
		}
	}
}
void ViewAndSearch(Node*AccessedUser, Node*&phead)
{
	View1BoxDraw();
	ViewAndSearchMouseDetect(AccessedUser, phead);
}
void ViewAndSearchMouseDetect(Node*AccessedUser, Node*&phead)
{
	HANDLE ScreenConsole;
	DWORD Num, Mode;
	INPUT_RECORD EventInput;

	ScreenConsole = GetStdHandle(STD_INPUT_HANDLE);
	if (ScreenConsole == INVALID_HANDLE_VALUE)
		return;
	Mode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(ScreenConsole, Mode))
		return;
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(ScreenConsole, Mode)) return;
	while (true)
	{
		FlushConsoleInputBuffer(ScreenConsole);
		ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
		if (EventInput.EventType == MOUSE_EVENT)
		{
			if (EventInput.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{

				if (EventInput.Event.MouseEvent.dwMousePosition.X > 0 &&
					EventInput.Event.MouseEvent.dwMousePosition.X < 20 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 0 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 2)
				{
					system("CLS");
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					FirstBox();
					ProfileBox(AccessedUser, phead);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X > 40 &&
					EventInput.Event.MouseEvent.dwMousePosition.X < 60 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 0 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 2)
				{
					system("CLS");
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					ThirdBox();
					StaffTask(AccessedUser, phead);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X > 60 &&
					EventInput.Event.MouseEvent.dwMousePosition.X < 79 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 0 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 2)
				{
					system("CLS");
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					FourthBox();
					Sleep(500);
					HUBdraw();
					SearchEngineMouseDetect(AccessedUser, phead);

				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X > 20 &&
					EventInput.Event.MouseEvent.dwMousePosition.X < 40 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 0 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 2)
				{
					system("CLS");
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					SecondBox();
					SearchEngine(AccessedUser, phead);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 2 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 77 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 4 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 20)
				{
					system("CLS");
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					ThirdBox();
					ClearViewBox();
					ViewClassList(AccessedUser, phead);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 11 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 70 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 23 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 25)
				{
					ShowFindedClass(AccessedUser, phead);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 71 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 77 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 22 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 26)
				{
					ShowNewClassClass(AccessedUser, phead);
				}
				else
				{
					system("CLS");
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					ThirdBox();
					ViewAndSearch(AccessedUser, phead);
				}
			}
		}
	}
}
//--------------------[pACK]
void GetClassNames(string &CLASSNAME)
{
	char key;
	string asciiValue;
	HANDLE ScreenConsole;
	DWORD Num, Mode;
	INPUT_RECORD EventInput;
	enablePoint();
	ScreenConsole = GetStdHandle(STD_INPUT_HANDLE);
	if (ScreenConsole == INVALID_HANDLE_VALUE)
		return;
	Mode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(ScreenConsole, Mode))
		return;
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(ScreenConsole, Mode)) return;
	while (true)
	{
		FlushConsoleInputBuffer(ScreenConsole);
		ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
		mouseEvent1(EventInput.Event.MouseEvent);
		if (EventInput.EventType == KEY_EVENT && EventInput.Event.KeyEvent.bKeyDown == true)
		{
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 112 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 65) ||
				(EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48) ||
				EventInput.Event.KeyEvent.wVirtualKeyCode == 32)
			{
				asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
				CLASSNAME.append(asciiValue);
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (CLASSNAME == "")
				{
					continue;
				}
				CLASSNAME.pop_back();
				gotoxy(11, 24);
				std::cout << "                 ";
			}
		}
		gotoxy(11, 24);
		std::cout << CLASSNAME;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			break;
		}
		if (EventInput.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			break;
			
		}
	}
	disablePoint();
}
void ShowFindedClass(Node*AccessedUser, Node*&phead)
{
	disablePoint();
	gotoxy(11, 24); cout << "                       ";
	gotoxy(26, 22); cout << "                              ";
	string Classname = "";
	enablePoint();
	setcolor(58);
	DrawEnter1Box();
	GetClassNames(Classname);
	Node2*chead = NULL, *cur;
	GetClassList(chead);
	cur = chead;
	while (cur->next != NULL)
	{
		if (cur->classname == Classname)
		{
			ViewAndSearch2(AccessedUser, phead, Classname);
		}
		cur = cur->next;
	}
	if (cur->next == NULL) {
		DrawEnter1Box();
		setcolor(60);
		gotoxy(26, 22); cout << "[ CANNOT FIND THIS CLASS! ]";
		setcolor(63);
	}
	ViewAndSearch(AccessedUser, phead);
}
//--------------------[2pACK]
void GetNewsClassNames(string &CLASSNAME)
{
	char key;
	string asciiValue;
	HANDLE ScreenConsole;
	DWORD Num, Mode;
	INPUT_RECORD EventInput;
	enablePoint();
	ScreenConsole = GetStdHandle(STD_INPUT_HANDLE);
	if (ScreenConsole == INVALID_HANDLE_VALUE)
		return;
	Mode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(ScreenConsole, Mode))
		return;
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(ScreenConsole, Mode)) return;
	while (true)
	{
		FlushConsoleInputBuffer(ScreenConsole);
		ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
		mouseEvent1(EventInput.Event.MouseEvent);
		if (EventInput.EventType == KEY_EVENT && EventInput.Event.KeyEvent.bKeyDown == true)
		{
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 112 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 65) ||
				(EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48) ||
				EventInput.Event.KeyEvent.wVirtualKeyCode == 32)
			{
				asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
				CLASSNAME.append(asciiValue);
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (CLASSNAME == "")
				{
					continue;
				}
				CLASSNAME.pop_back();
				gotoxy(21, 24);
				std::cout << "                 ";
			}
		}
		gotoxy(21, 24);
		std::cout << CLASSNAME;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			break;
		}
		if (EventInput.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			if (EventInput.Event.MouseEvent.dwMousePosition.X >= 60 &&
				EventInput.Event.MouseEvent.dwMousePosition.X <= 70 &&
				EventInput.Event.MouseEvent.dwMousePosition.Y >= 23 &&
				EventInput.Event.MouseEvent.dwMousePosition.Y <= 25)
			{
				FlushConsoleInputBuffer(ScreenConsole);
				ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
				break;
			}
		}
	}
	disablePoint();
}
void ShowNewClassClass(Node*AccessedUser, Node*&phead)
{
	disablePoint();
	gotoxy(11, 24); cout << "                                         ";
	gotoxy(26, 22); cout << "                                         ";
	string Classname = "";
	enablePoint();
	setcolor(60);
	DrawEnter1Box();
	gotoxy(11, 24); cout << "ADD CLASS:";
	GetNewsClassNames(Classname);
	Node2*chead = NULL, *cur;
	GetClassList(chead);
	cur = chead;
	while (cur->next != NULL)
	{
		if (cur->classname == Classname)
		{
			setcolor(60);
			gotoxy(26, 22); cout << "[ THIS CLASS HAS BEEN EXISTS!!! ]";
			DrawEnter1Box();
			ViewAndSearch(AccessedUser, phead);
		}
		if (CheckRightClassName(Classname) == false)
		{
			setcolor(60);
			gotoxy(26, 22); cout << "[ INPUT WRONG SYNTAX, TRY AGAIN!!! ]";
			DrawEnter1Box();
			ViewAndSearch(AccessedUser, phead);
		}
		cur = cur->next;
	}
	if (cur->next == NULL) {
		setcolor(58);
		DrawEnter1Box();
		SaveAClassToList( Classname,chead);
		ofstream fout;
		string k = "Class/" + Classname;
		k = k + ".csv";
		fout.open(k);
		fout << "EMPTY";
		fout.close();
		gotoxy(26, 22); cout << "[ MAKING SUCCESS!!! ]";
		setcolor(58);
		ViewAndSearch(AccessedUser, phead);
	}
}
//--------------------[aFTERpACK]
void View2BoxDraw(string classname)
{
	gotoxy(2, 4); cout << char(218);
	for (int i = 1; i <= 74; i++)
	{
		cout << char(196);
	}
	gotoxy(77, 4); cout << char(191);
	for (int i = 5; i <= 19; i++)
	{
		gotoxy(77, i);
		cout << char(179);
	}
	gotoxy(77, 20); cout << char(217);
	gotoxy(2, 20); cout << char(192);
	for (int i = 1; i <= 74; i++)
	{
		cout << char(196);
	}
	for (int i = 5; i <= 19; i++)
	{
		gotoxy(2, i);
		cout << char(179);
	}
	setcolor(58);
	gotoxy(5, 4); cout << "[ Class: "<<classname<<" ]";
	setcolor(63);
	DrawEnter2Box();
}
void ViewStudentList(Node*AccessedUser, Node*&phead,string classname)
{
	View2BoxDraw(classname);
	Node3*dhead = NULL, *cur;
	GetStudentList(dhead, classname);
	cur = dhead;
	StudentListScroll(AccessedUser, phead, dhead, cur,classname);
}
void GetStudentList(Node3*&dhead, string inputclass)
{
	ifstream fin;
	string link = inputclass + ".csv";
	link = "Class/" + link;
	fin.open(link);
	dhead = new Node3;
	Node3*cur;
	if (!fin.is_open())
	{
		system("CLS");
		cout << "Crashh: CANNOT OPEN SOURCE";
		system("pause");
		exit(0);
	}
	string tempname, tempmssv, tempnumber, tempphonenumber, tempmail, tempuserid, temppass;
	getline(fin, tempnumber, ',');
	getline(fin, tempmssv, ',');
	getline(fin, tempname, ',');
	getline(fin, tempphonenumber, ',');
	getline(fin, tempmail, ',');
	getline(fin, tempuserid, ',');
	getline(fin, temppass, ',');
	dhead->stuudent.No = tempnumber;
	dhead->stuudent.mssv = tempmssv;
	dhead->stuudent.name = tempname;
	dhead->stuudent.PhoneNumber = tempphonenumber;
	dhead->stuudent.Mail = tempmail;
	dhead->stuudent.userID = tempuserid;
	dhead->stuudent.Password = temppass;
	dhead->next = NULL;
	cur = dhead;
	while (!fin.eof())
	{
		cur->next = new Node3;
		cur = cur->next;
		getline(fin, tempnumber, ',');
		getline(fin, tempmssv, ',');
		getline(fin, tempname, ',');
		getline(fin, tempphonenumber, ',');
		getline(fin, tempmail, ',');
		getline(fin, tempuserid, ',');
		getline(fin, temppass, ',');
		cur->stuudent.No = tempnumber;
		cur->stuudent.mssv = tempmssv;
		cur->stuudent.name = tempname;
		cur->stuudent.PhoneNumber = tempphonenumber;
		cur->stuudent.Mail = tempmail;
		cur->stuudent.userID = tempuserid;
		cur->stuudent.Password = temppass;
		cur->next = NULL;
	}
	fin.close();

}
void DrawEnter2Box()
{
	gotoxy(10, 23); cout << char(218);
	for (int i = 1; i <= 59; i++)
	{
		cout << char(196);
	}
	gotoxy(70, 23); cout << char(191);
	gotoxy(70, 24); cout << char(179);
	gotoxy(70, 25); cout << char(217);
	gotoxy(10, 24); cout << char(179);
	gotoxy(10, 25); cout << char(192);
	for (int i = 1; i <= 59; i++)
	{
		cout << char(196);
	}
	gotoxy(60, 23); cout << char(194);
	gotoxy(60, 24); cout << char(179);
	gotoxy(60, 25); cout << char(193);
	setcolor(58);
	gotoxy(61, 24); cout << "GoStudent";
	gotoxy(20, 20); cout << "[ ENTER STUDENT ID TO GET INFORMATION ]!";
	setcolor(63);
	gotoxy(71, 22); cout << char(218);
	for (int i = 1; i <= 5; i++)
		cout << char(196);
	gotoxy(77, 22); cout << char(191);
	gotoxy(77, 23); cout << char(179);
	gotoxy(77, 24); cout << char(179);
	gotoxy(77, 25); cout << char(179);
	gotoxy(77, 26); cout << char(217);
	gotoxy(71, 23); cout << char(179);
	gotoxy(71, 24); cout << char(179);
	gotoxy(71, 25); cout << char(179);
	gotoxy(71, 26); cout << char(192);
	for (int i = 1; i <= 5; i++)
		cout << char(196);
	setcolor(60);
	gotoxy(72, 23); cout << " ADD ";
	gotoxy(72, 24); cout << " STU-";
	gotoxy(72, 25); cout << "DENT!";
	setcolor(63);

}
void ViewAndSearch2(Node*AccessedUser, Node*&phead,string classname)
{
	View2BoxDraw(classname);
	ViewAndSearchMouseDetect2(AccessedUser, phead,classname);
}
void ViewAndSearchMouseDetect2(Node*AccessedUser, Node*&phead,string classname)
{
	HANDLE ScreenConsole;
	DWORD Num, Mode;
	INPUT_RECORD EventInput;

	ScreenConsole = GetStdHandle(STD_INPUT_HANDLE);
	if (ScreenConsole == INVALID_HANDLE_VALUE)
		return;
	Mode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(ScreenConsole, Mode))
		return;
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(ScreenConsole, Mode)) return;
	while (true)
	{
		FlushConsoleInputBuffer(ScreenConsole);
		ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
		if (EventInput.EventType == MOUSE_EVENT)
		{
			if (EventInput.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{

				if (EventInput.Event.MouseEvent.dwMousePosition.X > 0 &&
					EventInput.Event.MouseEvent.dwMousePosition.X < 20 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 0 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 2)
				{
					system("CLS");
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					FirstBox();
					ProfileBox(AccessedUser, phead);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X > 40 &&
					EventInput.Event.MouseEvent.dwMousePosition.X < 60 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 0 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 2)
				{
					system("CLS");
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					ThirdBox();
					StaffTask(AccessedUser, phead);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X > 60 &&
					EventInput.Event.MouseEvent.dwMousePosition.X < 79 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 0 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 2)
				{
					system("CLS");
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					FourthBox();
					Sleep(500);
					HUBdraw();
					SearchEngineMouseDetect(AccessedUser, phead);

				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X > 20 &&
					EventInput.Event.MouseEvent.dwMousePosition.X < 40 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 0 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 2)
				{
					system("CLS");
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					SecondBox();
					SearchEngine(AccessedUser, phead);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 2 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 77 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 4 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 20)
				{
					system("CLS");
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					ThirdBox();
					ClearViewBox();
					ViewStudentList(AccessedUser, phead,classname);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 11 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 70 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 23 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 25)
				{
					ShowFindedStudent(AccessedUser, phead,classname);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 71 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 77 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 22 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 26)
				{
					Node3*dhead = NULL, *cur;
					GetStudentList(dhead, classname);
					Node3*curstu = new Node3;
					ViewToMakeNew(AccessedUser, phead, classname, dhead,curstu);
				}
				else
				{
					system("CLS");
					setcolor(63);
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					ThirdBox();
					ViewAndSearch2(AccessedUser, phead,classname);
				}
			}
		}
	}
}
void StudentListScroll(Node*AccessedUser, Node*&phead, Node3*dhead, Node3*&cur,string classname)
{
	HANDLE ScreenConsole;
	DWORD Num, Mode;
	INPUT_RECORD EventInput;

	ScreenConsole = GetStdHandle(STD_INPUT_HANDLE);
	if (ScreenConsole == INVALID_HANDLE_VALUE)
		return;
	Mode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(ScreenConsole, Mode))
		return;
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(ScreenConsole, Mode)) return;
	setcolor(59);
	gotoxy(55, 10); cout << "| GO  --->>  |";
	gotoxy(55, 11); cout << "|NEXT ---->>>|";
	gotoxy(55, 12); cout << "| !   --->>  |";
	gotoxy(55, 13); cout << "|  [ENTER]   |";
	gotoxy(55, 14); cout << "| TO GET OUT |";
	setcolor(63);
	while (true)
	{
		FlushConsoleInputBuffer(ScreenConsole);
		ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
		if (EventInput.EventType == KEY_EVENT)
		{
			if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT && EventInput.Event.KeyEvent.bKeyDown == true)
			{
				ClearViewBox();
				for (int i = 5; i <= 18; i++)
				{
					if (cur->next != NULL)
					{
						int k = atoi(cur->stuudent.No.c_str());
						gotoxy(8, i);
						if(k<10)
							cout <<k << "   " << cur->stuudent.mssv << "   " << cur->stuudent.name;
						else
							cout << k << "  " << cur->stuudent.mssv << "   " << cur->stuudent.name;
						cur = cur->next;
					}
					else
					{
						cur = dhead;
						break;
					}
				}
				StudentListScroll(AccessedUser, phead, dhead, cur,classname);
			}
			if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
			{
				ViewAndSearchMouseDetect2(AccessedUser, phead,classname);
			}
		}
		if (EventInput.EventType == MOUSE_EVENT)
		{
			if (EventInput.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 11 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 70 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 23 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 25)
				{
					ShowFindedStudent(AccessedUser, phead,classname);
				}
			}
		}
	}
}
//--------------------[1aFTERpACK]
void GetStudentNames(string &studentname)

{
	char key;
	string asciiValue;
	HANDLE ScreenConsole;
	DWORD Num, Mode;
	INPUT_RECORD EventInput;
	enablePoint();
	ScreenConsole = GetStdHandle(STD_INPUT_HANDLE);
	if (ScreenConsole == INVALID_HANDLE_VALUE)
		return;
	Mode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(ScreenConsole, Mode))
		return;
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(ScreenConsole, Mode)) return;
	while (true)
	{
		FlushConsoleInputBuffer(ScreenConsole);
		ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
		mouseEvent1(EventInput.Event.MouseEvent);
		if (EventInput.EventType == KEY_EVENT && EventInput.Event.KeyEvent.bKeyDown == true)
		{
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 112 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 65) ||
				(EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48) ||
				EventInput.Event.KeyEvent.wVirtualKeyCode == 32)
			{
				asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
				studentname.append(asciiValue);
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (studentname == "")
				{
					continue;
				}
				studentname.pop_back();
				gotoxy(11, 24);
				std::cout << "                 ";
			}
		}
		gotoxy(11, 24);
		std::cout << studentname;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			break;
		}
		if (EventInput.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			if (EventInput.Event.MouseEvent.dwMousePosition.X >= 60 &&
				EventInput.Event.MouseEvent.dwMousePosition.X <= 70 &&
				EventInput.Event.MouseEvent.dwMousePosition.Y >= 23 &&
				EventInput.Event.MouseEvent.dwMousePosition.Y <= 25)
			{
				FlushConsoleInputBuffer(ScreenConsole);
				ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
				break;
			}
		}
	}
	disablePoint();
}
void ShowFindedStudent(Node*AccessedUser, Node*&phead,string classname)
{
	disablePoint();
	gotoxy(11, 24); cout << "                          ";
	gotoxy(26, 22); cout << "                              ";
	string Studentid = "";
	enablePoint();
	setcolor(58);
	DrawEnter2Box();
	GetStudentNames(Studentid);
	Node3*dhead = NULL, *cur;
	GetStudentList(dhead,classname);
	cur = dhead;
	while (cur->next != NULL)
	{
		if (cur->stuudent.mssv ==Studentid)
		{
			Node3*curstu = new Node3;
			ViewToEditOrMakeNew(AccessedUser, phead, classname, dhead, Studentid);
		}
		cur = cur->next;
	}
	if (cur->next == NULL) {
		DrawEnter1Box();
		setcolor(60);
		gotoxy(26, 22); cout << "CANNOT FIND [" << Studentid << "] IN THIS CLASS!";
		setcolor(63);
	}
	ViewAndSearch2(AccessedUser, phead,classname);
}
//--------------------[2aFTERpACK]
//--------------------[SpaceForStudentInfomationChanging]
void DrawStudentChangingSpace(string classname,Node3*& student)
{
	ClearView2();
	gotoxy(2, 4); cout << char(218);
	for (int i = 1; i <= 74; i++)
	{
		cout << char(196);
	}
	gotoxy(77, 4); cout << char(191);
	for (int i = 5; i <= 21; i++)
	{
		gotoxy(77, i);
		cout << char(179);
	}
	gotoxy(77, 22); cout << char(217);
	gotoxy(2, 22); cout << char(192);
	for (int i = 1; i <= 74; i++)
	{
		cout << char(196);
	}
	for (int i = 5; i <= 21; i++)
	{
		gotoxy(2, i);
		cout << char(179);
	}
	setcolor(58);
	gotoxy(5, 4); cout << "[ Class: " << classname << " ]";
	setcolor(63);

	gotoxy(25, 23);cout << char(218);
	for (int i = 1; i <= 29; i++)
	{
		cout << char(196);
	}
	gotoxy(55, 23); cout << char(191);
	gotoxy(55, 24); cout << char(179);
	gotoxy(55, 25); cout << char(217);
	gotoxy(25, 24); cout << char(179);
	gotoxy(25, 25); cout << char(192);
	for (int i = 1; i <= 29; i++)
	{
		cout << char(196);
	}
	setcolor(58);
	gotoxy(26, 22); cout << "[  EDIT STUDENT INFOMATION  ]";
	gotoxy(35, 24); cout << "SAVE & EXIT";
	setcolor(63);
	//-----

	DrawSmallBoxSpecial(33, 6);
	DrawSmallBox(40, 10);
	DrawSmallBox(40, 14);
	DrawSmallBox(40, 18);
	DrawSmallBox(9, 14);
	DrawSmallBox(9, 18);
	Skulldraw2(4, 5, 2);
	setcolor(58);
	gotoxy(10, 15); cout << "NAME: ";
	setcolor(63);
	cout<< student->stuudent.name;
	setcolor(58);
	gotoxy(10, 19); cout << "USER ID: ";
	setcolor(63);
	cout<< student->stuudent.mssv;
	setcolor(58);
	gotoxy(34, 7); cout << "EMAIL: ";
	setcolor(63);
	cout<< student->stuudent.Mail;
	setcolor(58);
	gotoxy(41, 11); cout << "USER NAME: ";
	setcolor(63);
	cout<< student->stuudent.userID;
	setcolor(58);
	gotoxy(41, 15); cout << "PASSWORD: ";
	setcolor(63);
	cout<< student->stuudent.Password;
	setcolor(58);
	gotoxy(41, 19); cout << "PHONE NUMBER: ";
	setcolor(63);
	cout<< student->stuudent.PhoneNumber;
}
void ClearView2()
{
	setcolor(63);
	for (int i = 2; i <= 77; i++)
		for (int j = 4; j <= 26; j++)
		{
			gotoxy(i, j);
			cout << " ";
		}
}
void DrawSmallBox(int x, int y)
{
	gotoxy(x, y); std::cout << char(218);
	for (int i = 1; i <= 29; i++)
	{
		cout << char(196);
	}
	gotoxy(x+30, y); cout << char(191);
	gotoxy(x + 30, y+1); cout << char(179);
	gotoxy(x + 30, y+2); cout << char(217);
	gotoxy(x, y+1); cout << char(179);
	gotoxy(x, y+2); cout << char(192);
	for (int i = 1; i <= 29; i++)
	{
		cout << char(196);
	}
}
void DrawSmallBoxSpecial(int x, int y)
{
	gotoxy(x, y); std::cout << char(218);
	for (int i = 1; i <= 36; i++)
	{
		cout << char(196);
	}
	gotoxy(x + 37, y); cout << char(191);
	gotoxy(x + 37, y + 1); cout << char(179);
	gotoxy(x + 37, y + 2); cout << char(217);
	gotoxy(x, y + 1); cout << char(179);
	gotoxy(x, y + 2); cout << char(192);
	for (int i = 1; i <= 36; i++)
	{
		cout << char(196);
	}
}
void ViewToEditOrMakeNew(Node*AccessedUser, Node*&phead, string classname, Node3*dhead,string studentid)
{
	Node3*curstu = GetInfoFromStudentID(studentid, dhead);
	DrawStudentChangingSpace(classname, curstu);
	ViewToEditOrMakeNewMouseDetect(AccessedUser, phead, classname, dhead, studentid, curstu);
}
void ViewToEditOrMakeNewMouseDetect(Node*AccessedUser, Node*&phead, string classname, Node3*dhead, string studentid,Node3*&curstu)
{
	HANDLE ScreenConsole;
	DWORD Num, Mode;
	INPUT_RECORD EventInput;
	string newname="", newid="", password="", email="", newusername="", phonenumber="";

	ScreenConsole = GetStdHandle(STD_INPUT_HANDLE);
	if (ScreenConsole == INVALID_HANDLE_VALUE)
		return;
	Mode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(ScreenConsole, Mode))
		return;
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(ScreenConsole, Mode)) return;
	while (true)
	{
		FlushConsoleInputBuffer(ScreenConsole);
		ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
		if (EventInput.EventType == MOUSE_EVENT)
		{
			if (EventInput.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				//---1
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 40 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 70 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 10 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 12)
				{
					gotoxy(52, 11);
					std::cout << "                 ";
					setcolor(58);
					DrawSmallBox(40, 10);
					setcolor(63);
					ChangeUserUserName(newusername, AccessedUser, phead, classname, dhead, studentid, curstu);
				}
				//---2
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 40 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 70 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 14 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 16)
				{
					gotoxy(51, 15);
					std::cout << "                 ";
					setcolor(58);
					DrawSmallBox(40, 14);
					setcolor(63);
					ChangeUserPassword(password, AccessedUser, phead, classname, dhead, studentid, curstu);
				}
				//---3
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 40 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 70 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 18 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 20)
				{
					gotoxy(55, 19);
					std::cout << "            ";
					setcolor(58);
					DrawSmallBox(40, 18);
					setcolor(63);
					ChangeUserPhoneNumber(phonenumber, AccessedUser, phead, classname, dhead, studentid, curstu);
				}
				//---4
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 33 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 70 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 6 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 8)
				{
					gotoxy(41, 7);
					std::cout << "                            ";
					setcolor(58);
					DrawSmallBoxSpecial(33, 6);
					setcolor(63);
					ChangeUserEmail(email, AccessedUser, phead, classname, dhead, studentid, curstu);
				}
				//---5
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 9 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 39 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 14 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 16)
				{
					gotoxy(16, 15);
					std::cout << "                 ";
					setcolor(58);
					DrawSmallBox(9, 14);
					setcolor(63);
					ChangeUserNameBox(newname, AccessedUser, phead, classname, dhead, studentid, curstu);
				}
				//---6
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 9 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 39 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 18 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 20)
				{
					gotoxy(19, 19);
					std::cout << "                 ";
					setcolor(58);
					DrawSmallBox(9, 18);
					setcolor(63);
					ChangeUserIDBox(newid, AccessedUser, phead, classname, dhead, studentid, curstu);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 25 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 55 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 23 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 25)
				{
					CheckAndSaveStudentInfomation(classname, dhead, curstu, phead);
					system("CLS");
					setcolor(63);
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					ThirdBox();
					ViewAndSearch2(AccessedUser, phead, classname);
				}
				else
				{
					ViewToEditOrMakeNew(AccessedUser, phead, classname, dhead, studentid);

				}
			}
		}
	}
}
//--------------------[SIX-CHANGING-BOX]
void ChangeUserNameBox(string newname, Node*AccessedUser, Node*&phead, string classname, Node3*dhead, string studentid,Node3*&curstu)
{
	char key;
	int minword=0;
	string password ,asciiValue;
	HANDLE ScreenConsole;
	DWORD Num, Mode; 
	INPUT_RECORD EventInput; 
	enablePoint;
	ScreenConsole = GetStdHandle(STD_INPUT_HANDLE);
	if (ScreenConsole == INVALID_HANDLE_VALUE)
		return;
	Mode = ENABLE_EXTENDED_FLAGS; 
	if (!SetConsoleMode(ScreenConsole, Mode)) 
		return;
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;	
	if (!SetConsoleMode(ScreenConsole, Mode)) return;
	while (true)
	{
		FlushConsoleInputBuffer(ScreenConsole);
		ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
		mouseEvent1(EventInput.Event.MouseEvent);
		if (EventInput.EventType == KEY_EVENT && EventInput.Event.KeyEvent.bKeyDown == true)
		{
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 112 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 65) ||
				(EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48) ||
				EventInput.Event.KeyEvent.wVirtualKeyCode == 32)
			{
				asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
				newname.append(asciiValue);
				minword++;
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (newname == "")
				{
					continue;
				}
				newname.pop_back();
				minword--;
				gotoxy(16, 15);
				std::cout << "                 ";
			}
		}
		gotoxy(16, 15);
		std::cout << newname;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (CheckRightNAME(newname) == false)
			{
				setcolor(60);
				DrawSmallBox(9, 14);
				gotoxy(16, 13); cout << "Syntax Error";
				setcolor(63); _getch();
				ViewToEditOrMakeNew(AccessedUser, phead, classname, dhead, studentid); 
			}
			else
			{
				setcolor(58);
				gotoxy(16, 13); cout << "Changed Successful!!";
				setcolor(63);
				curstu->stuudent.name = newname; _getch();
				ViewToEditOrMakeNew(AccessedUser, phead, classname, dhead, studentid);
			}
		}
		disablePoint();
	}
}
void ChangeUserIDBox(string newid, Node*AccessedUser, Node*&phead, string classname, Node3*dhead, string studentid, Node3*&curstu)
{
	char key;
	string password, asciiValue;
	HANDLE ScreenConsole;
	DWORD Num, Mode;
	INPUT_RECORD EventInput;
	enablePoint;
	ScreenConsole = GetStdHandle(STD_INPUT_HANDLE);
	if (ScreenConsole == INVALID_HANDLE_VALUE)
		return;
	Mode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(ScreenConsole, Mode))
		return;
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(ScreenConsole, Mode)) return;
	while (true)
	{
		FlushConsoleInputBuffer(ScreenConsole);
		ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
		mouseEvent1(EventInput.Event.MouseEvent);
		if (EventInput.EventType == KEY_EVENT && EventInput.Event.KeyEvent.bKeyDown == true)
		{
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 112 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 65) ||
				(EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48) ||
				EventInput.Event.KeyEvent.wVirtualKeyCode == 32)
			{
				asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
				newid.append(asciiValue);
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (newid == "")
				{
					continue;
				}
				newid.pop_back();
				gotoxy(19, 19);
				std::cout << "                 ";
			}
		}
		gotoxy(19, 19);
		std::cout << newid;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (CheckRightID(newid)==false)
			{
				setcolor(60);
				DrawSmallBox(9, 18);
				gotoxy(19, 17); cout << "Syntax Error";
				setcolor(63); _getch();
				ViewToEditOrMakeNew(AccessedUser, phead, classname, dhead, studentid); 
			}
			else
			{
				setcolor(58);
				gotoxy(19, 17); cout << "Changed Successful!!";
				setcolor(63);
				curstu->stuudent.userID = newid; _getch();
				ViewToEditOrMakeNew(AccessedUser, phead, classname, dhead, studentid);
			}
			
		}
		disablePoint();
	}
}
void ChangeUserEmail(string email, Node*AccessedUser, Node*&phead, string classname, Node3*dhead, string studentid, Node3*&curstu)
{
	char key;
	string password, asciiValue;
	HANDLE ScreenConsole;
	DWORD Num, Mode;
	INPUT_RECORD EventInput;
	enablePoint;
	ScreenConsole = GetStdHandle(STD_INPUT_HANDLE);
	if (ScreenConsole == INVALID_HANDLE_VALUE)
		return;
	Mode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(ScreenConsole, Mode))
		return;
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(ScreenConsole, Mode)) return;
	while (true)
	{
		FlushConsoleInputBuffer(ScreenConsole);
		ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
		mouseEvent1(EventInput.Event.MouseEvent);
		if (EventInput.EventType == KEY_EVENT && EventInput.Event.KeyEvent.bKeyDown == true)
		{
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 112 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 65) ||
				(EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48) ||
				EventInput.Event.KeyEvent.wVirtualKeyCode == 32 || EventInput.Event.KeyEvent.wVirtualKeyCode == VK_OEM_PERIOD)
			{
				asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
				email.append(asciiValue);
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (email == "")
				{
					continue;
				}
				email.pop_back();
				gotoxy(41, 7);
				std::cout << "                            ";
			}
		}
		gotoxy(41,7);
		std::cout << email;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (CheckRightEmail(email) == false)
			{
				setcolor(60);
				DrawSmallBoxSpecial(33, 6);
				gotoxy(42, 5); cout << "Syntax Error";
				setcolor(63);
				ViewToEditOrMakeNew(AccessedUser, phead, classname, dhead, studentid);
			}
			else
			{
				setcolor(58);
				gotoxy(42, 5); cout << "Changed Successful!!";
				setcolor(63);
				curstu->stuudent.Mail = email;
				ViewToEditOrMakeNew(AccessedUser, phead, classname, dhead, studentid);
			}

		}
		disablePoint();
	}
}
void ChangeUserUserName(string newusername, Node*AccessedUser, Node*&phead, string classname, Node3*dhead, string studentid, Node3*&curstu)
{
	char key;
	string password, asciiValue;
	HANDLE ScreenConsole;
	DWORD Num, Mode;
	INPUT_RECORD EventInput;
	enablePoint;
	ScreenConsole = GetStdHandle(STD_INPUT_HANDLE);
	if (ScreenConsole == INVALID_HANDLE_VALUE)
		return;
	Mode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(ScreenConsole, Mode))
		return;
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(ScreenConsole, Mode)) return;
	while (true)
	{
		FlushConsoleInputBuffer(ScreenConsole);
		ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
		mouseEvent1(EventInput.Event.MouseEvent);
		if (EventInput.EventType == KEY_EVENT && EventInput.Event.KeyEvent.bKeyDown == true)
		{
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 112 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 65) ||
				(EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48) ||
				EventInput.Event.KeyEvent.wVirtualKeyCode == 32)
			{
				asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
				newusername.append(asciiValue);
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (newusername == "")
				{
					continue;
				}
				newusername.pop_back();
				gotoxy(52, 11);
				std::cout << "                 ";
			}
		}
		gotoxy(52, 11);
		std::cout << newusername;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (CheckRightUserName(newusername) == false)
			{
				setcolor(60);
				DrawSmallBox(40, 10);
				gotoxy(52, 9); cout << "Syntax Error";
				setcolor(63); _getch();
				ViewToEditOrMakeNew(AccessedUser, phead, classname, dhead, studentid);
			}
			else
			{
				setcolor(58);
				gotoxy(52, 9); cout << "Changed Successful!!";
				setcolor(63);
				curstu->stuudent.userID = newusername; _getch();
				ViewToEditOrMakeNew(AccessedUser, phead, classname, dhead, studentid);
			}

		}
		disablePoint();
	}
}
void ChangeUserPhoneNumber(string phonenumber, Node*AccessedUser, Node*&phead, string classname, Node3*dhead, string studentid, Node3*&curstu)
{
	char key;
	string password, asciiValue;
	HANDLE ScreenConsole;
	DWORD Num, Mode;
	INPUT_RECORD EventInput;
	enablePoint;
	ScreenConsole = GetStdHandle(STD_INPUT_HANDLE);
	if (ScreenConsole == INVALID_HANDLE_VALUE)
		return;
	Mode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(ScreenConsole, Mode))
		return;
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(ScreenConsole, Mode)) return;
	while (true)
	{
		FlushConsoleInputBuffer(ScreenConsole);
		ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
		mouseEvent1(EventInput.Event.MouseEvent);
		if (EventInput.EventType == KEY_EVENT && EventInput.Event.KeyEvent.bKeyDown == true)
		{
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 112 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 65) ||
				(EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48) ||
				EventInput.Event.KeyEvent.wVirtualKeyCode == 32)
			{
				asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
				phonenumber.append(asciiValue);
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (phonenumber == "")
				{
					continue;
				}
				phonenumber.pop_back();
				gotoxy(55, 19);
				std::cout << "            ";
			}
		}
		gotoxy(55, 19);
		std::cout << phonenumber;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (CheckRightPhoneNumber(phonenumber) == false)
			{
				setcolor(60);
				DrawSmallBox(40, 18);
				gotoxy(55, 17); cout << "Syntax Error";
				setcolor(63); _getch();
				ViewToEditOrMakeNew(AccessedUser, phead, classname, dhead, studentid);
			}
			else
			{
				setcolor(58);
				gotoxy(55, 17); cout << "Changed Successful!!";
				setcolor(63);
				curstu->stuudent.PhoneNumber = phonenumber; _getch();
				ViewToEditOrMakeNew(AccessedUser, phead, classname, dhead, studentid);
			}

		}
		disablePoint();
	}
}
void ChangeUserPassword(string password, Node*AccessedUser, Node*&phead, string classname, Node3*dhead, string studentid, Node3*&curstu)
{
	char key;
	string  asciiValue;
	HANDLE ScreenConsole;
	DWORD Num, Mode;
	INPUT_RECORD EventInput;
	enablePoint;
	ScreenConsole = GetStdHandle(STD_INPUT_HANDLE);
	if (ScreenConsole == INVALID_HANDLE_VALUE)
		return;
	Mode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(ScreenConsole, Mode))
		return;
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(ScreenConsole, Mode)) return;
	while (true)
	{
		FlushConsoleInputBuffer(ScreenConsole);
		ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
		mouseEvent1(EventInput.Event.MouseEvent);
		if (EventInput.EventType == KEY_EVENT && EventInput.Event.KeyEvent.bKeyDown == true)
		{
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 112 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 65) ||
				(EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48) ||
				EventInput.Event.KeyEvent.wVirtualKeyCode == 32)
			{
				asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
				password.append(asciiValue);
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (password == "")
				{
					continue;
				}
				password.pop_back();
				gotoxy(51,15);
				std::cout << "                 ";
			}
		}
		gotoxy(51, 15);
		std::cout << password;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (CheckRightPassword(password) == false)
			{
				setcolor(60);
				DrawSmallBox(40, 14);
				gotoxy(51, 13); cout << "Syntax Error";
				setcolor(63); _getch();
				ViewToEditOrMakeNew(AccessedUser, phead, classname, dhead, studentid);
			}
			else
			{
				setcolor(58);
				gotoxy(51, 13); cout << "Changed Successful!!";
				setcolor(63);
				curstu->stuudent.Password = password; _getch();
				ViewToEditOrMakeNew(AccessedUser, phead, classname, dhead, studentid);
			}

		}
		disablePoint();
	}
}
//---------------------[Make new student pack]
void ViewToMakeNew(Node*AccessedUser, Node*&phead, string classname, Node3*dhead,Node3*&curstu)
{
	
	DrawStudentChangingSpace(classname, curstu);
	ViewToMakeNewMouseDetect(AccessedUser, phead, classname, dhead, curstu);
}
void ViewToMakeNewMouseDetect(Node*AccessedUser, Node*&phead, string classname, Node3*dhead, Node3*&curstu)
{
	HANDLE ScreenConsole;
	DWORD Num, Mode;
	INPUT_RECORD EventInput;
	//string newname = "", newid = "", password = "", email = "", newusername = "", phonenumber = "";

	ScreenConsole = GetStdHandle(STD_INPUT_HANDLE);
	if (ScreenConsole == INVALID_HANDLE_VALUE)
		return;
	Mode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(ScreenConsole, Mode))
		return;
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(ScreenConsole, Mode)) return;
	while (true)
	{
		FlushConsoleInputBuffer(ScreenConsole);
		ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
		if (EventInput.EventType == MOUSE_EVENT)
		{
			if (EventInput.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				//---1
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 40 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 70 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 10 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 12)
				{
					gotoxy(52, 11);
					std::cout << "                 ";
					setcolor(58);
					DrawSmallBox(40, 10);
					setcolor(63);
					MakeNewUserUserName( AccessedUser, phead, classname, dhead, curstu);
				}
				//---2
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 40 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 70 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 14 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 16)
				{
					gotoxy(51, 15);
					std::cout << "                 ";
					setcolor(58);
					DrawSmallBox(40, 14);
					setcolor(63);
					MakeNewUserPassword( AccessedUser, phead, classname, dhead, curstu);
				}
				//---3
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 40 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 70 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 18 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 20)
				{
					gotoxy(55, 19);
					std::cout << "            ";
					setcolor(58);
					DrawSmallBox(40, 18);
					setcolor(63);
					MakeNewUserPhoneNumber(AccessedUser, phead, classname, dhead, curstu);
				}
				//---4
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 33 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 70 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 6 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 8)
				{
					gotoxy(41, 7);
					std::cout << "                            ";
					setcolor(58);
					DrawSmallBoxSpecial(33, 6);
					setcolor(63);
					MakeNewUserEmail( AccessedUser, phead, classname, dhead, curstu);
				}
				//---5
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 9 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 39 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 14 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 16)
				{
					gotoxy(16, 15);
					std::cout << "                 ";
					setcolor(58);
					DrawSmallBox(9, 14);
					setcolor(63);
					MakeNewUserNameBox( AccessedUser, phead, classname, dhead ,curstu);
				}
				//---6
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 9 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 39 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 18 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 20)
				{
					gotoxy(19, 19);
					std::cout << "                 ";
					setcolor(58);
					DrawSmallBox(9, 18);
					setcolor(63);
					MakeNewUserIDBox( AccessedUser, phead, classname, dhead, curstu);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 25 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 55 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 23 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 25)
				{// Big bug- cant write data to curstu
					CheckAndSaveNewStudentToClass(classname,dhead,curstu,phead);
					system("CLS");
					setcolor(63);
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					ThirdBox();
					ViewAndSearch2(AccessedUser, phead, classname);
				}
				else
				{
					ViewToMakeNewMouseDetect(AccessedUser, phead, classname, dhead, curstu);
				}
			}
		}
	}
}
//--------------------[SIX-CHANGING-BOX]
void MakeNewUserNameBox( Node*AccessedUser, Node*&phead, string classname, Node3*dhead, Node3*&curstu)
{
	char key;
	int minword = 0;
	string asciiValue;
	HANDLE ScreenConsole;
	DWORD Num, Mode;
	INPUT_RECORD EventInput;
	string newname;
	enablePoint;
	ScreenConsole = GetStdHandle(STD_INPUT_HANDLE);
	if (ScreenConsole == INVALID_HANDLE_VALUE)
		return;
	Mode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(ScreenConsole, Mode))
		return;
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(ScreenConsole, Mode)) return;
	while (true)
	{
		FlushConsoleInputBuffer(ScreenConsole);
		ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
		mouseEvent1(EventInput.Event.MouseEvent);
		if (EventInput.EventType == KEY_EVENT && EventInput.Event.KeyEvent.bKeyDown == true)
		{
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 112 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 65) ||
				(EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48) ||
				EventInput.Event.KeyEvent.wVirtualKeyCode == 32)
			{
				asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
				newname.append(asciiValue);
				minword++;
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (newname == "")
				{
					continue;
				}
				newname.pop_back();
				minword--;
				gotoxy(16, 15);
				std::cout << "                 ";
			}
		}
		gotoxy(16, 15);
		std::cout << newname;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (CheckRightNAME(newname) == false)
			{
				setcolor(60);
				DrawSmallBox(9, 14);
				gotoxy(16, 13); cout << "Syntax Error";
				setcolor(63); _getch();
				ViewToMakeNew(AccessedUser, phead, classname, dhead, curstu);
			}
			else
			{
				curstu->stuudent.name = newname;
				setcolor(58);
				gotoxy(16, 13); cout << "Make Successful!!";
				setcolor(63); _getch();
				ViewToMakeNew(AccessedUser, phead, classname, dhead, curstu);
			}
		}
		disablePoint();
	}
}
void MakeNewUserIDBox( Node*AccessedUser, Node*&phead, string classname, Node3*dhead, Node3*&curstu)
{
	char key;
	string  asciiValue;
	HANDLE ScreenConsole;
	DWORD Num, Mode;
	INPUT_RECORD EventInput;
	string newid;
	enablePoint;
	ScreenConsole = GetStdHandle(STD_INPUT_HANDLE);
	if (ScreenConsole == INVALID_HANDLE_VALUE)
		return;
	Mode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(ScreenConsole, Mode))
		return;
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(ScreenConsole, Mode)) return;
	while (true)
	{
		FlushConsoleInputBuffer(ScreenConsole);
		ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
		mouseEvent1(EventInput.Event.MouseEvent);
		if (EventInput.EventType == KEY_EVENT && EventInput.Event.KeyEvent.bKeyDown == true)
		{
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 112 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 65) ||
				(EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48) ||
				EventInput.Event.KeyEvent.wVirtualKeyCode == 32)
			{
				asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
				newid.append(asciiValue);
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (newid == "")
				{
					continue;
				}
				newid.pop_back();
				gotoxy(19, 19);
				std::cout << "                 ";
			}
		}
		gotoxy(19, 19);
		std::cout << newid;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (CheckRightID(newid) == false)
			{
				setcolor(60);
				DrawSmallBox(9, 18);
				gotoxy(19, 17); cout << "Syntax Error";
				setcolor(63); _getch();
				ViewToMakeNew(AccessedUser, phead, classname, dhead, curstu);
			}
			else
			{
				curstu->stuudent.mssv = newid;
				setcolor(58);
				gotoxy(19, 17); cout << "Make Successful!!";
				setcolor(63); _getch();
				ViewToMakeNew(AccessedUser, phead, classname, dhead, curstu);
			}

		}
		disablePoint();
	}
}
void MakeNewUserEmail( Node*AccessedUser, Node*&phead, string classname, Node3*dhead, Node3*&curstu)
{
	char key;
	string asciiValue;
	HANDLE ScreenConsole;
	DWORD Num, Mode;
	INPUT_RECORD EventInput;
	string email;
	enablePoint;
	ScreenConsole = GetStdHandle(STD_INPUT_HANDLE);
	if (ScreenConsole == INVALID_HANDLE_VALUE)
		return;
	Mode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(ScreenConsole, Mode))
		return;
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(ScreenConsole, Mode)) return;
	while (true)
	{
		FlushConsoleInputBuffer(ScreenConsole);
		ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
		mouseEvent1(EventInput.Event.MouseEvent);
		if (EventInput.EventType == KEY_EVENT && EventInput.Event.KeyEvent.bKeyDown == true)
		{
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 112 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 65) ||
				(EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48) ||
				EventInput.Event.KeyEvent.wVirtualKeyCode == 32 || EventInput.Event.KeyEvent.wVirtualKeyCode == VK_OEM_PERIOD)
			{
				asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
				email.append(asciiValue);
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (email == "")
				{
					continue;
				}
				email.pop_back();
				gotoxy(41, 7);
				std::cout << "                            ";
			}
		}
		gotoxy(41, 7);
		std::cout << email;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (CheckRightEmail(email) == false)
			{
				setcolor(60);
				DrawSmallBoxSpecial(33, 6);
				gotoxy(42, 5); cout << "Syntax Error";
				setcolor(63); _getch();
				ViewToMakeNew(AccessedUser, phead, classname, dhead, curstu);
			}
			else
			{
				curstu->stuudent.Mail = email;
				setcolor(58);
				gotoxy(42, 5); cout << "Make Successful!!";
				setcolor(63); _getch();
				ViewToMakeNew(AccessedUser, phead, classname, dhead, curstu);
			}

		}
		disablePoint();
	}
}
void MakeNewUserUserName( Node*AccessedUser, Node*&phead, string classname, Node3*dhead, Node3*&curstu)
{
	char key;
	string newusername, asciiValue;
	HANDLE ScreenConsole;
	DWORD Num, Mode;
	INPUT_RECORD EventInput;
	enablePoint;
	ScreenConsole = GetStdHandle(STD_INPUT_HANDLE);
	if (ScreenConsole == INVALID_HANDLE_VALUE)
		return;
	Mode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(ScreenConsole, Mode))
		return;
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(ScreenConsole, Mode)) return;
	while (true)
	{
		FlushConsoleInputBuffer(ScreenConsole);
		ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
		mouseEvent1(EventInput.Event.MouseEvent);
		if (EventInput.EventType == KEY_EVENT && EventInput.Event.KeyEvent.bKeyDown == true)
		{
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 112 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 65) ||
				(EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48) ||
				EventInput.Event.KeyEvent.wVirtualKeyCode == 32)
			{
				asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
				newusername.append(asciiValue);
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (newusername == "")
				{
					continue;
				}
				newusername.pop_back();
				gotoxy(52, 11);
				std::cout << "                 ";
			}
		}
		gotoxy(52, 11);
		std::cout << newusername;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (CheckRightUserName(newusername) == false)
			{
				setcolor(60);
				DrawSmallBox(40, 10);
				gotoxy(52, 9); cout << "Syntax Error";
				setcolor(63); _getch();
				ViewToMakeNew(AccessedUser, phead, classname, dhead, curstu);
			}
			else
			{
				curstu->stuudent.userID = newusername;
				setcolor(58);
				gotoxy(52, 9); cout << "Make Successful!!";
				setcolor(63); _getch();
				ViewToMakeNew(AccessedUser, phead, classname, dhead, curstu);
			}

		}
		disablePoint();
	}
}
void MakeNewUserPhoneNumber( Node*AccessedUser, Node*&phead, string classname, Node3*dhead, Node3*&curstu)
{
	char key;
	string phonenumber, asciiValue;
	HANDLE ScreenConsole;
	DWORD Num, Mode;
	INPUT_RECORD EventInput;
	enablePoint;
	ScreenConsole = GetStdHandle(STD_INPUT_HANDLE);
	if (ScreenConsole == INVALID_HANDLE_VALUE)
		return;
	Mode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(ScreenConsole, Mode))
		return;
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(ScreenConsole, Mode)) return;
	while (true)
	{
		FlushConsoleInputBuffer(ScreenConsole);
		ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
		mouseEvent1(EventInput.Event.MouseEvent);
		if (EventInput.EventType == KEY_EVENT && EventInput.Event.KeyEvent.bKeyDown == true)
		{
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 112 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 65) ||
				(EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48) ||
				EventInput.Event.KeyEvent.wVirtualKeyCode == 32)
			{
				asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
				phonenumber.append(asciiValue);
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (phonenumber == "")
				{
					continue;
				}
				phonenumber.pop_back();
				gotoxy(55, 19);
				std::cout << "            ";
			}
		}
		gotoxy(55, 19);
		std::cout << phonenumber;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (CheckRightPhoneNumber(phonenumber) == false)
			{
				setcolor(60);
				DrawSmallBox(40, 18);
				gotoxy(55, 17); cout << "Syntax Error";
				setcolor(63);
				ViewToMakeNew(AccessedUser, phead, classname, dhead, curstu);
			}
			else
			{
				curstu->stuudent.PhoneNumber = phonenumber;
				setcolor(58); _getch();
				gotoxy(55, 17); cout << "Make Successful!!";
				setcolor(63); _getch();
				ViewToMakeNew(AccessedUser, phead, classname, dhead, curstu);
			}

		}
		disablePoint();
	}
}
void MakeNewUserPassword( Node*AccessedUser, Node*&phead, string classname, Node3*dhead, Node3*&curstu)
{
	char key;
	string password, asciiValue;
	HANDLE ScreenConsole;
	DWORD Num, Mode;
	INPUT_RECORD EventInput;
	enablePoint;
	ScreenConsole = GetStdHandle(STD_INPUT_HANDLE);
	if (ScreenConsole == INVALID_HANDLE_VALUE)
		return;
	Mode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(ScreenConsole, Mode))
		return;
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(ScreenConsole, Mode)) return;
	while (true)
	{
		FlushConsoleInputBuffer(ScreenConsole);
		ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
		mouseEvent1(EventInput.Event.MouseEvent);
		if (EventInput.EventType == KEY_EVENT && EventInput.Event.KeyEvent.bKeyDown == true)
		{
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 112 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 65) ||
				(EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48) ||
				EventInput.Event.KeyEvent.wVirtualKeyCode == 32)
			{
				asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
				password.append(asciiValue);
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (password == "")
				{
					continue;
				}
				password.pop_back();
				gotoxy(51, 15);
				std::cout << "                 ";
			}
		}
		gotoxy(51, 15);
		std::cout << password;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (CheckRightPassword(password) == false)
			{
				setcolor(60);
				DrawSmallBox(40, 14);
				gotoxy(51, 13); cout << "Syntax Error";
				setcolor(63);
				ViewToMakeNew(AccessedUser, phead, classname, dhead, curstu);
			}
			else
			{
				curstu->stuudent.Password = password;
				setcolor(58); _getch();
				gotoxy(51, 13); cout << "Make Successful!!";
				setcolor(63); _getch();
				ViewToMakeNew(AccessedUser, phead, classname, dhead, curstu);
			}

		}
		disablePoint();
	}
}
