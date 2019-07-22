#include"HeaderFIRSTtouch.h"
void DrawSearchBox()
{
	gotoxy(10, 5); cout << char(218);
	for (int i = 1; i <= 59; i++)
	{
		cout << char(196);
	}
	gotoxy(70, 5); cout << char(191);
	gotoxy(70, 6); cout << char(179);
	gotoxy(70, 7); cout << char(217);
	gotoxy(10, 6); cout << char(179);
	gotoxy(10, 7); cout << char(192);
	for (int i = 1; i <= 59; i++)
	{
		cout << char(196);
	}
	gotoxy(60, 5); cout << char(194);
	gotoxy(60, 6); cout << char(179);
	gotoxy(60, 7); cout << char(193);
	setcolor(59);
	gotoxy(62, 6); cout << "Search!";
	gotoxy(31, 4); cout << "SEARCHING STUDENT";
	setcolor(63);
}
void SearchEngineMouseDetect(Node*AccessedUser, Node*&phead)
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
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 10 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 60 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 5 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 20)
				{
					system("CLS");
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					SecondBox();
					ShowTheResult(phead);

				}
				else
				{
					system("CLS");
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					SecondBox();
					SearchEngine(AccessedUser, phead);
				}
			}
		}
	}
}
void SearchEngine(Node*AccessedUser, Node*&phead)
{
	DrawSearchBox();
	SearchEngineMouseDetect(AccessedUser,phead);
}
void GetStudentID(string &MSSV)
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
				MSSV.append(asciiValue);
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (MSSV == "")
				{
					continue;
				}
				MSSV.pop_back();
				gotoxy(11, 6);
				std::cout << "                 ";
			}
		}
		gotoxy(11, 6);
		std::cout << MSSV;
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
				EventInput.Event.MouseEvent.dwMousePosition.Y >= 5 &&
				EventInput.Event.MouseEvent.dwMousePosition.Y <= 7)
			{
				FlushConsoleInputBuffer(ScreenConsole);
				ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
				break;
			}
		}
	}
}
void ShowTheResult(Node*phead)
{
	DrawSearchBox();
	string MSSV="";
	Node*cur=phead;
	GetStudentID(MSSV);
	while (cur->next != NULL)
	{
		if (cur->data.mssv == MSSV)
		{
			ShowingSearchingInfo(cur);
			break;
		}
		cur = cur->next;
	}
	if (cur->next == NULL) {
		gotoxy(30, 9);
		setcolor(60);
		cout << "CANNOT FIND STUDENT!";
		DrawSearchBox();
		setcolor(60);
		Skulldraw2(3, 1, 10);
		setcolor(63);
	}
}
void ShowingSearchingInfo(Node*AccessedUser)
{
	Skulldraw2(2,3,8);
	setcolor(60);
	gotoxy(38, 10); cout << "NAME:";
	setcolor(59);
	cout << AccessedUser->data.name;
	setcolor(60);
	gotoxy(38, 12); cout << "ID:";
	setcolor(59);
	cout << AccessedUser->data.mssv;
	setcolor(60);
	gotoxy(38, 14); cout << "PHONE NUMBER:";
	setcolor(59);
	cout << AccessedUser->data.PhoneNumber;
	setcolor(60);
	gotoxy(38, 16); cout << "EMAIL:";
	setcolor(59);
	cout << AccessedUser->data.Mail;
	setcolor(60);
	gotoxy(38, 18); cout << "CLASS:";
	setcolor(59);
	cout << AccessedUser->data.Class;
	setcolor(63);
}

