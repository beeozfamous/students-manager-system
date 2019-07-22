#include"HeaderFIRSTtouch.h"
void DrawSchedule()
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
	gotoxy(61, 24); cout << "Schedule";
	gotoxy(20, 20); cout << "[ ENTER CLASS TO VIEW CLASS SCHEDULE ]!";
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
	gotoxy(72, 24); cout << "SCHE-";
	gotoxy(72, 25); cout << "DULE!";
	setcolor(63);
}
void ViewsScheduleBoxDraw()
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
	DrawSchedule();
}
void ViewScheduleList(Node*AccessedUser, Node*&phead)
{
	ViewsScheduleBoxDraw();
	Node5*schedulelist = NULL, *cur;
	GetSchedule(schedulelist);
	cur = schedulelist;
	ScheduleListScroll(AccessedUser, phead, schedulelist, cur);
}
void GetScheduleNames(string &Schedule)

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
				Schedule.append(asciiValue);
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (Schedule == "")
				{
					continue;
				}
				Schedule.pop_back();
				gotoxy(11, 24);
				std::cout << "                 ";
			}
		}
		gotoxy(11, 24);
		std::cout << Schedule;
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
void ShowFindedSchedule(Node*AccessedUser, Node*&phead)
{
	disablePoint();
	gotoxy(11, 24); cout << "                          ";
	gotoxy(26, 22); cout << "                              ";
	string Classname = "";
	enablePoint();
	setcolor(58);
	DrawSchedule();
	GetScheduleNames(Classname);
	Node5*Schedulelist = NULL, *cur;
	GetSchedule(Schedulelist);
	cur = Schedulelist;
	while (cur->next != NULL)
	{
		if (cur->Scheduledata.classcode == Classname)
		{
			Node5*curstu = new Node5;
			ViewToEditOrMakeNewSchedule(AccessedUser, phead, Schedulelist, Classname);
		}
		cur = cur->next;
	}
	if (cur->next == NULL) {
		DrawEnter1Box();
		setcolor(60);
		gotoxy(26, 22); cout << "CANNOT FIND [" << Classname << "] IN DATABASE!";
		setcolor(63);
	}
	ViewAndSearchSchedule(AccessedUser, phead);
}
void ScheduleListScroll(Node*AccessedUser, Node*&phead, Node5*schedulelist, Node5*&cur)
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
						gotoxy(8, i);
						if (atoi(cur->Scheduledata.No.c_str())<10)
							cout <<"------->"<< atoi(cur->Scheduledata.No.c_str()) << "    " << cur->Scheduledata.classcode ;
						else
							cout << atoi(cur->Scheduledata.No.c_str()) << "   " << cur->Scheduledata.classcode ;
						cur = cur->next;
					}
					else
					{
						cur = schedulelist;
						break;
					}
				}
				ScheduleListScroll(AccessedUser, phead, schedulelist, cur);
			}
			if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
			{
				ViewAndSearchMouseDetectForSchedule(AccessedUser, phead);
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
					ShowFindedSchedule(AccessedUser, phead);
				}
			}
		}
	}
}
void ViewAndSearchMouseDetectForSchedule(Node*AccessedUser, Node*&phead)
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
					ViewScheduleList(AccessedUser, phead);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 11 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 70 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 23 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 25)
				{
					ShowFindedSchedule(AccessedUser, phead);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 71 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 77 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 22 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 26)
				{
					Node5*Schedulelist = NULL, *cur;
					GetSchedule(Schedulelist);
					ShowNewScheduleClass(AccessedUser, phead, Schedulelist);
				}
				else
				{
					system("CLS");
					setcolor(63);
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					ThirdBox();
					ViewAndSearchSchedule(AccessedUser, phead);
				}
			}
		}
	}
}
void ViewAndSearchSchedule(Node*AccessedUser, Node*&phead)
{
	ViewsScheduleBoxDraw();
	ViewAndSearchMouseDetectForSchedule(AccessedUser, phead);
}
void DrawMakeOrEditSchedule(Node5*curschedule,string classname)
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
	gotoxy(5, 4); cout << "[CLASS "<< classname <<" SCHEDULE]";
	setcolor(63);

	gotoxy(25, 23); cout << char(218);
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
	gotoxy(26, 22); cout << "[  EDIT SCHEDULE INFOMATION  ]";
	gotoxy(35, 24); cout << "SAVE & EXIT";
	setcolor(63);
	for (int i = 6; i <= 20; i++)
	{
		gotoxy(7, i); cout << char(179);
		gotoxy(17, i); cout << char(179);
		gotoxy(27, i); cout << char(179);
		gotoxy(37, i); cout << char(179);
		gotoxy(47, i); cout << char(179);
		gotoxy(57, i); cout << char(179);
		gotoxy(67, i); cout << char(179);
	}
	for (int i = 3; i <= 76; i++)
	{
		gotoxy(i, 5); cout << char(196);
		gotoxy(i, 7); cout << char(196);
		gotoxy(i, 10); cout << char(196);
		gotoxy(i, 14); cout << char(196);
		gotoxy(i, 18); cout << char(196);
		gotoxy(i, 21); cout << char(196);
	}
	gotoxy(7, 5); cout << char(194);
	gotoxy(17, 5); cout << char(194);
	gotoxy(27, 5); cout << char(194);
	gotoxy(37, 5); cout << char(194);
	gotoxy(47, 5); cout << char(194);
	gotoxy(57, 5); cout << char(194);
	gotoxy(67, 5); cout << char(194);
	gotoxy(7, 21); cout << char(193);
	gotoxy(17, 21); cout << char(193);
	gotoxy(27, 21); cout << char(193);
	gotoxy(37, 21); cout << char(193);
	gotoxy(47, 21); cout << char(193);
	gotoxy(57, 21); cout << char(193);
	gotoxy(67, 21); cout << char(193);
	gotoxy(7, 14); cout << char(197);
	gotoxy(17, 14); cout << char(197);
	gotoxy(27, 14); cout << char(197);
	gotoxy(37, 14); cout << char(197);
	gotoxy(47, 14); cout << char(197);
	gotoxy(57, 14); cout << char(197);
	gotoxy(67, 14); cout << char(197);
	gotoxy(7, 7); cout << char(197);
	gotoxy(17, 7); cout << char(197);
	gotoxy(27, 7); cout << char(197);
	gotoxy(37, 7); cout << char(197);
	gotoxy(47, 7); cout << char(197);
	gotoxy(57, 7); cout << char(197);
	gotoxy(67, 7); cout << char(197);
	gotoxy(7, 10); cout << char(197);
	gotoxy(17, 10); cout << char(197);
	gotoxy(27, 10); cout << char(197);
	gotoxy(37, 10); cout << char(197);
	gotoxy(47, 10); cout << char(197);
	gotoxy(57, 10); cout << char(197);
	gotoxy(67, 10); cout << char(197);
	gotoxy(7, 18); cout << char(197);
	gotoxy(17, 18); cout << char(197);
	gotoxy(27, 18); cout << char(197);
	gotoxy(37, 18); cout << char(197);
	gotoxy(47, 18); cout << char(197);
	gotoxy(57, 18); cout << char(197);
	gotoxy(67, 18); cout << char(197);
	gotoxy(2, 5); cout << char(195);
	gotoxy(2, 7); cout << char(195);
	gotoxy(2, 14); cout << char(195);
	gotoxy(2, 10); cout << char(195);
	gotoxy(2, 18); cout << char(195);
	gotoxy(2, 21); cout << char(195);
	gotoxy(77, 5); cout << char(180);
	gotoxy(77, 14); cout << char(180);
	gotoxy(77, 10); cout << char(180);
	gotoxy(77, 18); cout << char(180);
	gotoxy(77, 7); cout << char(180);
	gotoxy(77, 21); cout << char(180);
	gotoxy(9, 6); cout << "MONDAY";
	gotoxy(19, 6); cout << "TUESDAY";
	gotoxy(28, 6); cout << "WEDNESDAY";
	gotoxy(39, 6); cout << "THUSDAY";
	gotoxy(49, 6); cout << "FRIDAY";
	gotoxy(59, 6); cout << "SATURDAY";
	gotoxy(69, 6); cout << "SUNDAY";
	//---------------------------
	gotoxy(10, 9); cout << curschedule->Scheduledata.MonMor1;
	gotoxy(20, 9); cout << curschedule->Scheduledata.TueMor1;
	gotoxy(30, 9); cout << curschedule->Scheduledata.WedMor1;
	gotoxy(40, 9); cout << curschedule->Scheduledata.ThuMor1;
	gotoxy(50, 9); cout << curschedule->Scheduledata.FriMor1;
	gotoxy(60, 9); cout << curschedule->Scheduledata.SatMor1;
	gotoxy(70, 9); cout << curschedule->Scheduledata.SunMor1;
	//----------------------------
	gotoxy(10, 12); cout << curschedule->Scheduledata.MonMor2;
	gotoxy(20, 12); cout << curschedule->Scheduledata.TueMor2;
	gotoxy(30, 12); cout << curschedule->Scheduledata.WedMor2;
	gotoxy(40, 12); cout << curschedule->Scheduledata.ThuMor2;
	gotoxy(50, 12); cout << curschedule->Scheduledata.FriMor2;
	gotoxy(60, 12); cout << curschedule->Scheduledata.SatMor2;
	gotoxy(70, 12); cout << curschedule->Scheduledata.SunMor2;
	//----------------------------
	gotoxy(10, 16); cout << curschedule->Scheduledata.MonAft1;
	gotoxy(20, 16); cout << curschedule->Scheduledata.TueAft1;
	gotoxy(30, 16); cout << curschedule->Scheduledata.WedAft1;
	gotoxy(40, 16); cout << curschedule->Scheduledata.ThuAft1;
	gotoxy(50, 16); cout << curschedule->Scheduledata.FriAft1;
	gotoxy(60, 16); cout << curschedule->Scheduledata.SatAft1;
	gotoxy(70, 16); cout << curschedule->Scheduledata.SunAft1;
	//----------------------------
	gotoxy(10, 19); cout << curschedule->Scheduledata.MonAft2;
	gotoxy(20, 19); cout << curschedule->Scheduledata.TueAft2;
	gotoxy(30, 19); cout << curschedule->Scheduledata.WedAft2;
	gotoxy(40, 19); cout << curschedule->Scheduledata.ThuAft2;
	gotoxy(50, 19); cout << curschedule->Scheduledata.FriAft2;
	gotoxy(60, 19); cout << curschedule->Scheduledata.SatAft2;
	gotoxy(70, 19); cout << curschedule->Scheduledata.SunAft2;
	//----------------------------
	gotoxy(4, 19); cout << "4";
	gotoxy(4, 16); cout << "3";
	gotoxy(4, 12); cout << "2";
	gotoxy(4, 9); cout << "1";
}
void ViewToEditOrMakeNewSchedule(Node*AccessedUser, Node*&phead, Node5*schedulelist, string classname)
{
	Node5*curschedule = GetScheduleFromlist(classname, schedulelist);
	DrawMakeOrEditSchedule(curschedule,classname);
	ViewToEditOrMakeNewScheduleMouseDetect(AccessedUser, phead,schedulelist, classname, curschedule);
}
void ViewToEditOrMakeNewScheduleMouseDetect(Node*AccessedUser, Node*&phead, Node5*schedulelist, string classname, Node5*&curschedule) 
{
	HANDLE ScreenConsole;
	DWORD Num, Mode;
	INPUT_RECORD EventInput;

	string No;
	string classcode;
	//----------------[MONDAY]
	string MonMor1;
	string MonMor2;
	string MonAft1;
	string MonAft2;
	//----------------[TUESDAY]
	string TueMor1;
	string TueMor2;
	string TueAft1;
	string TueAft2;
	//----------------[WEDNESDAY]
	string WedMor1;
	string WedMor2;
	string WedAft1;
	string WedAft2;
	//----------------[THUSDAY]
	string ThuMor1;
	string ThuMor2;
	string ThuAft1;
	string ThuAft2;
	//----------------[FRIDAY]
	string FriMor1;
	string FriMor2;
	string FriAft1;
	string FriAft2;
	//----------------[SATURDAY]
	string SatMor1;
	string SatMor2;
	string SatAft1;
	string SatAft2;
	//----------------[SUNDAY]
	string SunMor1;
	string SunMor2;
	string SunAft1;
	string SunAft2;

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
				//---1ST COLUM
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 8 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 16 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 8 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 9)
				{
					gotoxy(10, 9);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(MonMor1, AccessedUser, phead, schedulelist, classname, curschedule, 10, 9);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 8 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 16 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 11 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 13)
				{
					gotoxy(10, 12);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(MonMor2, AccessedUser, phead, schedulelist, classname, curschedule, 10, 12);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 8 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 16 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 15 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 17)
				{
					gotoxy(10, 16);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(MonAft1, AccessedUser, phead, schedulelist, classname, curschedule, 10, 6);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 8 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 16 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 19 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 20)
				{
					gotoxy(10, 19);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(MonAft2, AccessedUser, phead, schedulelist, classname, curschedule, 10, 19);
				}
				//---2ND COLUM
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 18 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 26 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 8 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 9)
				{
					gotoxy(20, 9);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(TueMor1, AccessedUser, phead, schedulelist, classname, curschedule, 20, 9);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 18 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 26 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 11 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 13)
				{
					gotoxy(20, 12);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(TueMor2, AccessedUser, phead, schedulelist, classname, curschedule, 20, 12);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 18 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 26 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 15 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 17)
				{
					gotoxy(20, 16);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(TueAft1, AccessedUser, phead, schedulelist, classname, curschedule, 20, 16);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 18 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 26 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 19 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 20)
				{
					gotoxy(20, 19);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(TueAft2, AccessedUser, phead, schedulelist, classname, curschedule, 20, 19);
				}
				//--- 3RD COLUM
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 28 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 36 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 8 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 9)
				{
					gotoxy(30, 9);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(WedMor1, AccessedUser, phead, schedulelist, classname, curschedule, 30, 9);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 28 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 36 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 11 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 13)
				{
					gotoxy(30, 12);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(WedMor2, AccessedUser, phead, schedulelist, classname, curschedule, 30, 12);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 28 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 36 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 15 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 17)
				{
					gotoxy(30, 16);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(WedAft1, AccessedUser, phead, schedulelist, classname, curschedule, 30, 16);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 28 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 36 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 19 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 20)
				{
					gotoxy(30, 19);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(WedAft2, AccessedUser, phead, schedulelist, classname, curschedule, 30, 19);
				}
				//--- 4TH COLUM
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 38 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 46 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 8 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 9)
				{
					gotoxy(40, 9);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(ThuMor1, AccessedUser, phead, schedulelist, classname, curschedule, 40, 9);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 38 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 46 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 11 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 13)
				{
					gotoxy(40, 12);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(ThuMor2, AccessedUser, phead, schedulelist, classname, curschedule, 40, 12);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 38 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 46 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 15 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 17)
				{
					gotoxy(40, 16);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(ThuAft1, AccessedUser, phead, schedulelist, classname, curschedule, 40, 16);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 38 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 46 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 19 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 20)
				{
					gotoxy(40, 19);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(ThuAft2, AccessedUser, phead, schedulelist, classname, curschedule, 40, 19);
				}
				//--- 5TH COLUM
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 48 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 56 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 8 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 9)
				{
					gotoxy(50, 9);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(FriMor1, AccessedUser, phead, schedulelist, classname, curschedule, 50, 9);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 48 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 56 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 11 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 13)
				{
					gotoxy(50, 12);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(FriMor2, AccessedUser, phead, schedulelist, classname, curschedule, 50, 12);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 48 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 56 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 15 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 17)
				{
					gotoxy(50, 16);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(FriAft1, AccessedUser, phead, schedulelist, classname, curschedule, 50, 16);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 48 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 56 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 19 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 20)
				{
					gotoxy(50, 19);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(FriAft2, AccessedUser, phead, schedulelist, classname, curschedule, 50, 19);
				}
				//--- 6TH COLUM
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 58 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 66 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 8 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 9)
				{
					gotoxy(60, 9);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(SatMor1, AccessedUser, phead, schedulelist, classname, curschedule, 60, 9);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 58 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 66 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 11 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 13)
				{
					gotoxy(60, 12);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(SatMor2, AccessedUser, phead, schedulelist, classname, curschedule, 60, 12);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 58 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 66 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 15 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 17)
				{
					gotoxy(60, 16);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(SatAft1, AccessedUser, phead, schedulelist, classname, curschedule, 60, 16);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 58 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 66 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 19 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 20)
				{
					gotoxy(60, 19);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(SatAft2, AccessedUser, phead, schedulelist, classname, curschedule, 60, 19);
				}
				//--- 7TH COLUM
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 68 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 76 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 8 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 9)
				{
					gotoxy(70, 9);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(SunMor1, AccessedUser, phead, schedulelist, classname, curschedule, 70, 9);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 68 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 76 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 11 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 13)
				{
					gotoxy(70, 12);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(SunMor2, AccessedUser, phead, schedulelist, classname, curschedule, 70, 12);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 68 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 76 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 15 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 17)
				{
					gotoxy(70, 16);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(SunAft1, AccessedUser, phead, schedulelist, classname, curschedule, 70, 16);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 68 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 76 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 19 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 20)
				{
					gotoxy(70, 19);
					std::cout << "      ";
					setcolor(58);
					setcolor(63);
					ChangeASection(SunAft2, AccessedUser, phead, schedulelist, classname, curschedule, 70, 19);
				}
				//---------
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 25 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 55 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 23 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 25)
				{
					SaveSchedule(schedulelist);
					system("CLS");
					setcolor(63);
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					ThirdBox();
					ViewAndSearchSchedule(AccessedUser, phead);
				}
				else
				{
					ViewToEditOrMakeNewSchedule(AccessedUser, phead, schedulelist, classname);
				}
			}
		}
	}
}
void ChangeASection(string changeone, Node*AccessedUser, Node*&phead, Node5*schedulelist, string classname, Node5*&curschedule,int x,int y)
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
	setcolor(58);
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
				changeone.append(asciiValue);
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (changeone == "")
				{
					continue;
				}
				changeone.pop_back();
				gotoxy(x, y);
				std::cout << "        ";
			}
		}
		gotoxy(x, y);
		std::cout << changeone;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (CheckExitCourse(changeone)==false)
			{
				setcolor(60);
				gotoxy(x, y);
				std::cout << changeone;
				setcolor(63);
				ViewToEditOrMakeNewSchedule(AccessedUser, phead, schedulelist, classname);
			}
			else
			{
				if (changeone == "")
				{
					setcolor(58);
					gotoxy(x, y);
					changeone = "EMPTY";
					std::cout << changeone;
					setcolor(63);
					if (x == 10 && y == 9)
					{
						curschedule->Scheduledata.MonMor1 = changeone;
					}
					else if (x == 20 && y == 9)
					{
						curschedule->Scheduledata.TueMor1 = changeone;
					}
					else if (x == 30 && y == 9)
					{
						curschedule->Scheduledata.WedMor1 = changeone;
					}
					else if (x == 40 && y == 9)
					{
						curschedule->Scheduledata.ThuMor1 = changeone;
					}
					else if (x == 50 && y == 9)
					{
						curschedule->Scheduledata.FriMor1 = changeone;
					}
					else if (x == 60 && y == 9)
					{
						curschedule->Scheduledata.SatMor1 = changeone;
					}
					else if (x == 70 && y == 9)
					{
						curschedule->Scheduledata.SunMor1 = changeone;
					}
					//--- 2nd row
					else if (x == 10 && y == 12)
					{
						curschedule->Scheduledata.MonMor2 = changeone;
					}
					else if (x == 20 && y == 12)
					{
						curschedule->Scheduledata.TueMor2 = changeone;
					}
					else if (x == 30 && y == 12)
					{
						curschedule->Scheduledata.WedMor2 = changeone;
					}
					else if (x == 40 && y == 12)
					{
						curschedule->Scheduledata.ThuMor2 = changeone;
					}
					else if (x == 50 && y == 12)
					{
						curschedule->Scheduledata.FriMor2 = changeone;
					}
					else if (x == 60 && y == 12)
					{
						curschedule->Scheduledata.SatMor2 = changeone;
					}
					else if (x == 70 && y == 12)
					{
						curschedule->Scheduledata.SunMor2 = changeone;
					}
					//--- 3rd row
					else if (x == 10 && y == 16)
					{
						curschedule->Scheduledata.MonAft1 = changeone;
					}
					else if (x == 20 && y == 16)
					{
						curschedule->Scheduledata.TueAft1 = changeone;
					}
					else if (x == 30 && y == 16)
					{
						curschedule->Scheduledata.WedAft1 = changeone;
					}
					else if (x == 40 && y == 16)
					{
						curschedule->Scheduledata.ThuAft1 = changeone;
					}
					else if (x == 50 && y == 16)
					{
						curschedule->Scheduledata.FriAft1 = changeone;
					}
					else if (x == 60 && y == 16)
					{
						curschedule->Scheduledata.SatAft1 = changeone;
					}
					else if (x == 70 && y == 16)
					{
						curschedule->Scheduledata.SunAft1 = changeone;
					}
					//--- 4th row
					else if (x == 10 && y == 19)
					{
						curschedule->Scheduledata.MonAft2 = changeone;
					}
					else if (x == 20 && y == 19)
					{
						curschedule->Scheduledata.TueAft2 = changeone;
					}
					else if (x == 30 && y == 19)
					{
						curschedule->Scheduledata.WedAft2 = changeone;
					}
					else if (x == 40 && y == 19)
					{
						curschedule->Scheduledata.ThuAft2 = changeone;
					}
					else if (x == 50 && y == 19)
					{
						curschedule->Scheduledata.FriAft2 = changeone;
					}
					else if (x == 60 && y == 19)
					{
						curschedule->Scheduledata.SatAft2 = changeone;
					}
					else if (x == 70 && y == 19)
					{
						curschedule->Scheduledata.SunAft2 = changeone;
					}
					else
					{
						exit(0);
					}
				}
				else {
					setcolor(58);
					gotoxy(x, y);
					std::cout << changeone;
					setcolor(63);
					//--- 1st row
					if (x == 10 && y == 9)
					{
						curschedule->Scheduledata.MonMor1 = changeone;
					}
					else if (x == 20 && y == 9)
					{
						curschedule->Scheduledata.TueMor1 = changeone;
					}
					else if (x == 30 && y == 9)
					{
						curschedule->Scheduledata.WedMor1 = changeone;
					}
					else if (x == 40 && y == 9)
					{
						curschedule->Scheduledata.ThuMor1 = changeone;
					}
					else if (x == 50 && y == 9)
					{
						curschedule->Scheduledata.FriMor1 = changeone;
					}
					else if (x == 60 && y == 9)
					{
						curschedule->Scheduledata.SatMor1 = changeone;
					}
					else if (x == 70 && y == 9)
					{
						curschedule->Scheduledata.SunMor1 = changeone;
					}
					//--- 2nd row
					else if (x == 10 && y == 12)
					{
						curschedule->Scheduledata.MonMor2 = changeone;
					}
					else if (x == 20 && y == 12)
					{
						curschedule->Scheduledata.TueMor2 = changeone;
					}
					else if (x == 30 && y == 12)
					{
						curschedule->Scheduledata.WedMor2 = changeone;
					}
					else if (x == 40 && y == 12)
					{
						curschedule->Scheduledata.ThuMor2 = changeone;
					}
					else if (x == 50 && y == 12)
					{
						curschedule->Scheduledata.FriMor2 = changeone;
					}
					else if (x == 60 && y == 12)
					{
						curschedule->Scheduledata.SatMor2 = changeone;
					}
					else if (x == 70 && y == 12)
					{
						curschedule->Scheduledata.SunMor2 = changeone;
					}
					//--- 3rd row
					else if (x == 10 && y == 16)
					{
						curschedule->Scheduledata.MonAft1 = changeone;
					}
					else if (x == 20 && y == 16)
					{
						curschedule->Scheduledata.TueAft1 = changeone;
					}
					else if (x == 30 && y == 16)
					{
						curschedule->Scheduledata.WedAft1 = changeone;
					}
					else if (x == 40 && y == 16)
					{
						curschedule->Scheduledata.ThuAft1 = changeone;
					}
					else if (x == 50 && y == 16)
					{
						curschedule->Scheduledata.FriAft1 = changeone;
					}
					else if (x == 60 && y == 16)
					{
						curschedule->Scheduledata.SatAft1 = changeone;
					}
					else if (x == 70 && y == 16)
					{
						curschedule->Scheduledata.SunAft1 = changeone;
					}
					//--- 4th row
					else if (x == 10 && y == 19)
					{
						curschedule->Scheduledata.MonAft2 = changeone;
					}
					else if (x == 20 && y == 19)
					{
						curschedule->Scheduledata.TueAft2 = changeone;
					}
					else if (x == 30 && y == 19)
					{
						curschedule->Scheduledata.WedAft2 = changeone;
					}
					else if (x == 40 && y == 19)
					{
						curschedule->Scheduledata.ThuAft2 = changeone;
					}
					else if (x == 50 && y == 19)
					{
						curschedule->Scheduledata.FriAft2 = changeone;
					}
					else if (x == 60 && y == 19)
					{
						curschedule->Scheduledata.SatAft2 = changeone;
					}
					else if (x == 70 && y == 19)
					{
						curschedule->Scheduledata.SunAft2 = changeone;
					}
					else
					{
						exit(0);
					}
					ViewToEditOrMakeNewSchedule(AccessedUser, phead, schedulelist, classname);
				}
			}

		}
		disablePoint();
	}
}
void GetNewsClassNamesFORSCHEDULE(string &CLASSNAME)
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
				gotoxy(35, 24);
				std::cout << "                 ";
			}
		}
		gotoxy(35, 24);
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
void DrawEnter12Box()
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
	gotoxy(61, 24); cout << "Schedule!";
	gotoxy(20, 20); cout << "[ ENTER CLASS NAME TO MAKE SCHEDULE ]!";
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
	gotoxy(72, 24); cout << "SCHE-";
	gotoxy(72, 25); cout << "DULE!";
	setcolor(63);
}
void ShowNewScheduleClass(Node*AccessedUser, Node*&phead, Node5*schedulelist)
{
	disablePoint();
	gotoxy(11, 24); cout << "                                         ";
	gotoxy(26, 22); cout << "                                         ";
	string Classname = "";
	enablePoint();
	setcolor(60);
	DrawEnter12Box();
	gotoxy(11, 24); cout << "ADD SCHEDULE FOR CLASS:";
	GetNewsClassNamesFORSCHEDULE(Classname);
	Node5*Schedulelist = NULL, *cur;
	GetSchedule(Schedulelist);
	cur = Schedulelist;
	Node2*chead = NULL, *cur2;
	GetClassList(chead);
	cur2= chead;
	
	while (cur->next != NULL)
	{
		if (cur->Scheduledata.classcode == Classname)
		{
			setcolor(60);
			gotoxy(26, 22); cout << "[ THIS SCHEDULE HAS BEEN EXISTS!!! ]";
			DrawEnter1Box();
			ViewAndSearchSchedule(AccessedUser, phead);
		}
		cur = cur->next;
	}
	while (cur2->next != NULL)
	{
		if (cur2->classname == Classname)
		{
			SaveNewSchedule(schedulelist, Classname);
			ViewAndSearchSchedule(AccessedUser, phead);
		}
		cur2 = cur2->next;
	}
	if (cur->next == NULL) {
		
		setcolor(60);
		gotoxy(26, 22); cout << "[ THERE IS NO "<< Classname << " INDATABASE ]";
		DrawEnter1Box();
		ViewAndSearchSchedule(AccessedUser, phead);
	}
}
void MakeANewClassSchedule(Node*AccessedUser, Node*&phead,string classcode)
{
	Node5*Schedulelist = NULL, *curschedule;
	GetSchedule(Schedulelist);
	curschedule = Schedulelist;
	string  befNO;
	while (curschedule->next != NULL)
	{
		if (curschedule->next == NULL)
		{
			break;
		}
		befNO = curschedule->Scheduledata.No;
		curschedule = curschedule->next;
	}
	
	//----------------------------
	curschedule->next = NULL;

	SaveSchedule(Schedulelist);
	system("CLS");
	setcolor(63);
	DrawMenuUI(AccessedUser, phead);
	DrawSelectionBox();
	ThirdBox();
	ViewAndSearchSchedule(AccessedUser, phead);
}