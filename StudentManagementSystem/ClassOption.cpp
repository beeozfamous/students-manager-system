#include"HeaderFIRSTtouch.h"
void Draw3Box()
{
	box333(7);
	box333(13);
	box333(19);
	gotoxy(28, 9);  cout << " -[ STUDENT & CLASSES ]- ";
	gotoxy(28, 15); cout << "      -[ COURSE ]-     ";
	gotoxy(28, 21); cout << "     -[ SCHEDULE ]-    ";
}
void StaffBox(int y)
{
	setcolor(58);
	gotoxy(21, y + 1);
	for (int i = 1; i <= 39; i++)
		cout << char(176);
	gotoxy(21, y + 3);
	for (int i = 1; i <= 39; i++)
		cout << char(176);
	if (y == 7) { 
		gotoxy(28, 9); cout << " -[ STUDENT & CLASSES ]- ";
	}
	if (y == 13) {
		gotoxy(28, 15); cout << "      -[ COURSE ]-     ";
	}
	if (y == 19) {
		gotoxy(28, 21); cout << "     -[ SCHEDULE ]-    ";
	}
	setcolor(63);
}
void box333(int y)
{
	gotoxy(20, y); cout << char(218);
	for (int i = 1; i <= 39; i++)
		cout << char(196);
	gotoxy(60, y); cout << char(191);
	gotoxy(60, y+1); cout << char(179);
	gotoxy(60, y+2); cout << char(179);
	gotoxy(60, y+3); cout << char(179);
	gotoxy(60, y+4); cout << char(217);
	gotoxy(20, y+4); cout << char(192);
	for (int i = 1; i <= 39; i++)
		cout << char(196);
	gotoxy(20, y + 1); cout << char(179);
	gotoxy(20, y + 2); cout << char(179);
	gotoxy(20, y + 3); cout << char(179);
	setcolor(59);
	gotoxy(21, y+1);
	for (int i = 1; i <= 39; i++)
		cout << char(176);
	gotoxy(21, y + 3);
	for (int i = 1; i <= 39; i++)
		cout << char(176);
	setcolor(63);
}
void StaffTaskSelection(Node*AccessedUser, Node*&phead)
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
					StaffTaskSelection(AccessedUser, phead);

				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 20&&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 60 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 7 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 11)
				{
					system("CLS");
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					ThirdBox();
					Draw3Box();
					StaffBox(7);
					system("CLS");
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					ThirdBox();
					ViewAndSearch(AccessedUser, phead);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 20 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 60 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 13 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 17)
				{
					system("CLS");
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					ThirdBox();
					Draw3Box();
					StaffBox(13);
					system("CLS");
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					ThirdBox();
					ViewAndSearchCourse(AccessedUser, phead);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 20 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 60 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 19 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 23)
				{
					system("CLS");
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					ThirdBox();
					Draw3Box();
					StaffBox(19);
					system("CLS");
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					ThirdBox();
					ViewAndSearchSchedule(AccessedUser, phead);
				}
				else
				{
					system("CLS");
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					ThirdBox();
					Draw3Box();
					StaffTaskSelection(AccessedUser, phead);
				}
			}
		}
	}
}
void StaffTask(Node*AccessedUser, Node*&phead)
{
	Draw3Box();
	StaffTaskSelection(AccessedUser, phead);
}
