#include"HeaderFIRSTtouch.h"
void MenuUI(Node*AccessedUser,Node*&phead)
{
	DrawMenuUI(AccessedUser,phead);
	DrawSelectionBox();
	MouseDetectSelection(AccessedUser,phead);
}
void DrawMenuUI(Node*AccessedUser, Node*&phead)
{
	disablePoint();
	system("CLS");
	gotoxy(0, 0);
	cout << char(218);
	gotoxy(0, 27);
	cout << char(192);
	gotoxy(79, 27);
	cout << char(217);
	gotoxy(79, 0);
	cout << char(191);
	gotoxy(1, 0);
	for (int i = 0; i < 78; i++)
		cout << char(196);
	gotoxy(1, 27);
	for (int i = 0; i < 78; i++)
		cout << char(196);
	for (int i = 1; i < 27; i++)
	{
		gotoxy(0, i);
		cout << char(179);
	}
	for (int i = 1; i < 27; i++)
	{
		gotoxy(79, i);
		cout << char(179);
	}
	ShowStatus(AccessedUser->data.Class);
	gotoxy(7, 1); cout << "PROFILE";
	gotoxy(27, 1); cout << "STUDENT";
	gotoxy(44, 1); cout << "CLASS & COURSE";
	gotoxy(67, 1); cout << "LOGOUT";
}
void DrawSelectionBox()
{
	gotoxy(1, 2);
	for (int i = 0; i < 78; i++)
		cout << char(196);
	gotoxy(0, 2); cout << char(195);
	gotoxy(79, 2); cout << char(180);
	gotoxy(20, 1); cout << char(179);
	gotoxy(20, 0); cout << char(194);
	gotoxy(20, 2); cout << char(193);
	gotoxy(40, 1); cout << char(179);
	gotoxy(40, 0); cout << char(194);
	gotoxy(40, 2); cout << char(193);
	gotoxy(60, 1); cout << char(179);
	gotoxy(60, 0); cout << char(194);
	gotoxy(60, 2); cout << char(193);
}
void FirstBox()
{
	gotoxy(0, 2); cout << "                    ";
	gotoxy(0, 2); cout << char(179);
	gotoxy(20, 2); cout <<char(195);
	gotoxy(0, 3); cout << char(195);
	for (int i = 0; i < 20; i++)
		cout << char(196);
	gotoxy(20, 3); cout << char(217);
	setcolor(58);
	gotoxy(7, 1); cout << "PROFILE";
	setcolor(63);
}
void SecondBox()
{
	gotoxy(20, 2); cout << "                    ";
	gotoxy(20, 2); cout << char(180);
	gotoxy(40, 2); cout << char(195);
	gotoxy(20, 3); cout << char(192);
	for (int i = 0; i < 19; i++)
		cout << char(196);
	gotoxy(40, 3); cout << char(217);
	setcolor(58);
	gotoxy(27, 1); cout << "STUDENT";
	setcolor(63);
}
void ThirdBox()
{
	gotoxy(40, 2); cout << "                    ";
	gotoxy(40, 2); cout << char(180);
	gotoxy(60, 2); cout << char(195);
	gotoxy(40, 3); cout << char(192);
	for (int i = 0; i < 19; i++)
		cout << char(196);
	gotoxy(60, 3); cout << char(217);
	setcolor(58);
	gotoxy(44, 1); cout << "CLASS & COURSE";
	setcolor(63);
}
void FourthBox()
{
	gotoxy(60, 2); cout << "                    ";
	gotoxy(79, 2); cout << char(179);
	gotoxy(60, 2); cout << char(180);
	gotoxy(60, 3); cout << char(192);
	for (int i = 0; i < 19; i++)
		cout << char(196);
	gotoxy(79, 3); cout << char(180);
	setcolor(58);
	gotoxy(67, 1); cout << "LOGOUT";
	setcolor(63);
}
void MouseDetectSelection(Node*AccessedUser, Node*&phead)
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
		if (EventInput.EventType==MOUSE_EVENT)
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
					MouseDetectSelection(AccessedUser, phead);

				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X > 0 &&
					EventInput.Event.MouseEvent.dwMousePosition.X < 79 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 3 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 27)
				{
					system("CLS");
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					MouseDetectSelection(AccessedUser, phead);
				}
			}
		}
	}
}
void Skulldraw2(int i,int k,int g)
{
	if (i == 1)
	{
		gotoxy(k, g);
		cout << "                                    ______            \n";
		gotoxy(k, g+1);
		cout << "                                 .-'      '-.         \n";
		gotoxy(k, g+2);
		cout << "                                |            |        \n";
		gotoxy(k, g+3);
		cout << "                               |              |       \n";
		gotoxy(k, g+4);
		cout << "                               |,  .-.  .-.  ,|       \n";
		gotoxy(k, g+5);
		cout << "                               | )(o)|  |(o)( |       \n";
		gotoxy(k, g+6);
		cout << "                               ||     ||     ||       \n";
		gotoxy(k, g+7);
		cout << "                               (_     ^^     _)       \n";
		gotoxy(k, g+8);
		cout << "                                |__|IIIIII|__|        \n";
		gotoxy(k, g+9);
		cout << "                                 |          |         \n";
		gotoxy(k, g+10);
		cout << "                                 | |IIIIII| |         \n";
		gotoxy(k, g + 11);
		cout << "                                  `--------`          \n";
	}
	else if (i == 2)
	{
		setcolor(57);
		gotoxy(k, g);
		cout << "              ______     \n";
		setcolor(58);
		gotoxy(k, g + 1);
		cout << "           .-'      '-.  \n";
		setcolor(59);
		gotoxy(k, g + 2);
		cout << "          |            | \n";
		setcolor(60);
		gotoxy(k, g + 3);
		cout << "         |              |\n";
		setcolor(61);
		gotoxy(k, g + 4);
		cout << "         |,  .-.  .-.  ,|\n";
		setcolor(62);
		gotoxy(k, g + 5);
		cout << "         | )(o)|  |(o)( |\n";
		setcolor(63);
		gotoxy(k, g + 6);
		cout << "         ||     ||     ||\n";
		setcolor(57);
		gotoxy(k, g + 7);
		cout << "         (_     ^^     _)\n";
		setcolor(58);
		gotoxy(k, g + 8);
		cout << "          |__|IIIIII|__| \n";
		setcolor(59);
		gotoxy(k, g + 9);
		cout << "           |          |  \n";
		setcolor(60);
		gotoxy(k, g + 10);
		cout << "           | |IIIIII| |  \n";
		setcolor(61);
		gotoxy(k, g + 11);
		cout << "            `--------`   \n";
		setcolor(63);
	}
	else if (i==3)
	{
		gotoxy(k, g);
		cout << "                                    ______            \n";
		gotoxy(k, g + 1);
		cout << "                                 .-'      '-.         \n";
		gotoxy(k, g + 2);
		cout << "                                |            |        \n";
		gotoxy(k, g + 3);
		cout << "                               |              |       \n";
		gotoxy(k, g + 4);
		cout << "                               |,  .-.  .-.  ,|       \n";
		gotoxy(k, g + 5);
		cout << "                               | )(x)|  |(x)( |       \n";
		gotoxy(k, g + 6);
		cout << "                               ||     ||     ||       \n";
		gotoxy(k, g + 7);
		cout << "                               (_     ^^     _)       \n";
		gotoxy(k, g + 8);
		cout << "                                |__|IIIIII|__|        \n";
		gotoxy(k, g + 9);
		cout << "                                 | |IIIIII| |         \n";
		gotoxy(k, g + 10);
		cout << "                                 |          |         \n";
		gotoxy(k, g + 11);
		cout << "                                  `--------`          \n";
	}
	else if (i == 4)
	{
		setcolor(60);
		gotoxy(k, g + 4);
		cout << "         .-------.\n";
		setcolor(61);
		gotoxy(k, g + 5);
		cout << "         | -----.-----.\n";
		setcolor(62);
		gotoxy(k, g + 6);
		cout << "         | -----| ----|\\\n";
		setcolor(63);
		gotoxy(k, g + 7);
		cout << "         | -----| ----- |\n";
		setcolor(57);
		gotoxy(k, g + 8);
		cout << "         | -----| ----- |\n";
		setcolor(58);
		gotoxy(k, g + 9);
		cout << "         '------| ----- |\n";
		setcolor(59);
		gotoxy(k, g + 10);
		cout << "                '-------'\n";
		
		setcolor(63);
	}
	else if (i == 5)
	{
		setcolor(60);
		gotoxy(k, g + 4);
		cout << " _.........._\n";
		setcolor(61);
		gotoxy(k, g + 5);
		cout << "| |mga     | |\n";
		setcolor(62);
		gotoxy(k, g + 6);
		cout << "| |        | |\n";
		setcolor(63);
		gotoxy(k, g + 7);
		cout << "| |        | |\n";
		setcolor(57);
		gotoxy(k, g + 8);
		cout << "| |________| |\n";
		setcolor(58);
		gotoxy(k, g + 9);
		cout << "|   ______   |\n";
		setcolor(59);
		gotoxy(k, g + 10);
		cout << "|  |    | |  |\n";
		setcolor(60);
		gotoxy(k, g + 11);
		cout << "|__|____|_|__|\n";
		setcolor(63);
	}
}
void ShowStatus(string status)
{
	if (status == "ADMIN")
	{
		setcolor(58);
		gotoxy(37, 27); cout << "/ ADMIN /";
		setcolor(63);
	}
	else if (status == "ACADEMICSTAFF")
	{
		setcolor(58);
		gotoxy(32, 27); cout << "/ ACADEMIC STAFF /";
		setcolor(63);
	}
	else if (status == "LECTURER")
	{
		setcolor(58);
		gotoxy(35, 27); cout << "/ LECTURER /";
		setcolor(63);
	}
	else 
	{
		setcolor(58);
		gotoxy(35, 27); cout << "/ STUDENT /";
		setcolor(63);
	}
}
void MouseDetectSelectionClass(Node*AccessedUser, Node*&phead)
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
					//MouseDetectSelection(AccessedUser, phead);
				}
			}
		}
	}
}

