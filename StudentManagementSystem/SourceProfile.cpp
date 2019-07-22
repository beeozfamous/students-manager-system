#include"HeaderFIRSTtouch.h"
void ProfileBox(Node*AccessedUser, Node*&phead)
{
	//enablePoint();
	Draw2Box();
	ShowingInfo(AccessedUser);
	ProfileMouseDetect(AccessedUser, phead);
}
void ProfileMouseDetect(Node*AccessedUser, Node*&phead)
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
					ProfileMouseDetect(AccessedUser, phead);

				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 30 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 50 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 20 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 22)
				{
					system("CLS");
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					FirstBox();
					OldNewConfirm(AccessedUser, phead);
				}
				else
				{
					system("CLS");
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					FirstBox();
					ProfileBox(AccessedUser, phead);
				}
			}
		}
	}
}
void ShowingInfo(Node*AccessedUser)
{
	Skulldraw2(2, 7, 5);
	setcolor(60);
	gotoxy(38, 7); cout << "NAME:";
	setcolor(59);
	cout << AccessedUser->data.name;
	setcolor(60);
	gotoxy(38, 9); cout << "ID:";
	setcolor(59);
	cout << AccessedUser->data.mssv;
	setcolor(60);
	gotoxy(38, 11); cout << "PHONE NUMBER:";
	setcolor(59);
	cout << AccessedUser->data.PhoneNumber;
	setcolor(60);
	gotoxy(38, 13); cout << "EMAIL:";
	setcolor(59);
	cout << AccessedUser->data.Mail;
	setcolor(60);
	gotoxy(38, 15); cout << "CLASS:";
	setcolor(59);
	cout << AccessedUser->data.Class;
	setcolor(63);
}
void Draw2Box()
{
	setcolor(59);
	gotoxy(30, 20); cout << char(218);
	for (int i = 1; i <= 19; i++) cout << char(196);
	gotoxy(30, 22); cout << char(192);
	for (int i = 1; i <= 19; i++) cout << char(196);
	gotoxy(50, 20); cout << char(191);
	gotoxy(50, 21); cout << char(179);
	gotoxy(50, 22); cout << char(217);
	gotoxy(30, 21); cout << char(179);
	gotoxy(33, 21); cout << "CHANGE PASSWORD";
	setcolor(63);
}
void ChangePasswordDraw()
{
	gotoxy(10, 5); cout << char(218);
	for (int i = 1; i <= 59; i++)
		cout << char(196);
	gotoxy(70, 5); cout << char(191);
	for (int i = 6; i <= 24; i++)
	{
		gotoxy(70, i);
		cout << char(179);
	}
	for (int i = 6; i <= 24; i++)
	{
		gotoxy(10, i);
		cout << char(179);
	}
	gotoxy(70, 25); cout << char(217);
	gotoxy(10, 25); cout << char(192);
	for (int i = 1; i <= 59; i++)
		cout << char(196);
	//-------
	gotoxy(20, 17); cout << char(218);
	for (int i = 1; i <= 39; i++)
		cout << char(196);
	gotoxy(60, 17); cout << char(191);
	gotoxy(60, 18); cout << char(179);
	gotoxy(60, 19); cout << char(217);
	gotoxy(20, 18); cout << char(179);
	gotoxy(20, 19); cout << char(192);
	for (int i = 1; i <= 39; i++)
		cout << char(196);
	//=====
	gotoxy(20, 12); cout << char(218);
	for (int i = 1; i <= 39; i++)
		cout << char(196);
	gotoxy(60, 12); cout << char(191);
	gotoxy(60, 13); cout << char(179);
	gotoxy(60, 14); cout << char(217);
	gotoxy(20, 13); cout << char(179);
	gotoxy(20, 14); cout << char(192);
	for (int i = 1; i <= 39; i++)
		cout << char(196);
	//=====
	gotoxy(20, 22); cout << char(218);
	for (int i = 1; i <= 39; i++)
		cout << char(196);
	gotoxy(60, 22); cout << char(191);
	gotoxy(60, 23); cout << char(179);
	gotoxy(60, 24); cout << char(217);
	gotoxy(20, 23); cout << char(179);
	gotoxy(20, 24); cout << char(192);
	for (int i = 1; i <= 39; i++)
		cout << char(196);
	//=====
	setcolor(58);
	gotoxy(11, 7);
	for (int i = 1; i <= 59; i++)
		cout << char(177);
	gotoxy(29, 7); cout << "[-/ CHANGING PASSWORD /-]";
	setcolor(60);
	gotoxy(22, 13); cout << "OLD PASSWORD:";
	gotoxy(22, 18); cout << "NEW PASSWORD:";
	gotoxy(22, 23); cout << "CONFIRM PASSWORD:";
	setcolor(63);
}
void ChangePasswordOldBox(string &oldpassword)
{
	char key;
	string  asciiValue,asterisk;
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
		if (EventInput.EventType == KEY_EVENT && EventInput.Event.KeyEvent.bKeyDown == true)
		{
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 112 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 65) ||
				(EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48) ||
				EventInput.Event.KeyEvent.wVirtualKeyCode == 32)
			{
				asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
				oldpassword.append(asciiValue);
				asterisk.append("*");
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (oldpassword == "")
				{
					continue;
				}
				oldpassword.pop_back();
				asterisk.pop_back();
				gotoxy(36, 13);
				std::cout << "                 ";
			}
		}
		gotoxy(36, 13);
		std::cout << asterisk;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			break;
		}

	}
}
void ChangePasswordNewBox(string &newpassword)
{
	char key;
	string  asciiValue="",asterisk="";
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
	gotoxy(36, 18);
	while (true)
	{
		FlushConsoleInputBuffer(ScreenConsole);
		ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
		if (EventInput.EventType == KEY_EVENT && EventInput.Event.KeyEvent.bKeyDown == true)
		{
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 112 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 65) ||
				(EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48) ||
				EventInput.Event.KeyEvent.wVirtualKeyCode == 32)
			{
				asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
				newpassword.append(asciiValue);
				asterisk.append("*");
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (newpassword == "")
				{
					continue;
				}
				newpassword.pop_back();
				asterisk.pop_back();
				gotoxy(36, 18);
				std::cout << "                 ";
			}
		}
		gotoxy(36, 18);
		std::cout << asterisk;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			break;
		}
	}
}
void ChangePasswordConfirmBox(string &newconfirmpassword)
{
	char key;
	string  asciiValue,asterisk;
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
		if (EventInput.EventType == KEY_EVENT && EventInput.Event.KeyEvent.bKeyDown == true)
		{
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 112 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 65) ||
				(EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48) ||
				EventInput.Event.KeyEvent.wVirtualKeyCode == 32)
			{
				asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
				newconfirmpassword.append(asciiValue);
				asterisk.append("*");
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (newconfirmpassword == "")
				{
					continue;
				}
				newconfirmpassword.pop_back();
				asterisk.pop_back();
				gotoxy(40, 23);
				std::cout << "                 ";
			}
		}
		gotoxy(40, 23);
		std::cout << asterisk;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			break;
		}
		enablePoint;
	}
}
void OldNewConfirm(Node*AccessedUser, Node*&phead)
{
	string oldpassword = "", newpassword = "", newconfirmpassword = "";
	ChangePasswordDraw();
	while (true)
	{
		ChangePasswordOldBox(oldpassword);
		ChangePasswordNewBox(newpassword);
		ChangePasswordConfirmBox(newconfirmpassword);
		if (oldpassword != AccessedUser->data.Password)
		{
			setcolor(60);
			gotoxy(11, 9);
			for (int i = 1; i <= 59; i++)
				cout << char(177);
			gotoxy(36, 13);
			std::cout << "                 ";
			gotoxy(36, 18);
			std::cout << "                 ";
			gotoxy(40, 23);
			std::cout << "                 ";
			gotoxy(27, 9); cout << "[-/ ENTER WRONG PASSWORD! /-]";
			setcolor(63);
			OldNewConfirm(AccessedUser, phead);
		}
		else if (newconfirmpassword != newpassword)
		{
			setcolor(60);
			gotoxy(11, 9);
			for (int i = 1; i <= 59; i++)
				cout << char(177);
			gotoxy(36, 13);
			std::cout << "                 ";
			gotoxy(36, 18);
			std::cout << "                 ";
			gotoxy(40, 23);
			std::cout << "                 ";
			gotoxy(25, 9); cout << "[-/ CONFIRM WRONG PASSWORD /-]";
			setcolor(63);
			OldNewConfirm(AccessedUser, phead);
		}
		else if (newpassword == oldpassword)
		{
			setcolor(60);
			gotoxy(11, 9);
			for (int i = 1; i <= 59; i++)
				cout << char(177);
			gotoxy(36, 13);
			std::cout << "                 ";
			gotoxy(36, 18);
			std::cout << "                 ";
			gotoxy(40, 23);
			std::cout << "                 ";
			gotoxy(28, 9); cout << "[-/ PASSWORD IS THE SAME /-]";
			setcolor(63);
			OldNewConfirm(AccessedUser, phead);
		}
		else if (oldpassword == AccessedUser->data.Password )
		{
			AccessedUser->data.Password = newpassword;
			saveInfoStudent("UserData.csv", phead);
			setcolor(58);
			gotoxy(11, 9);
			for (int i = 1; i <= 59; i++)
				cout << char(177);
			gotoxy(28, 9); cout << "[-/ CHANGING SUCCESSFUL /-]";
			setcolor(63);
			MoveToUserUI(AccessedUser, phead);
		}
	}
}
