#include"HeaderFIRSTtouch.h"
void drawcoursesview()
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
	gotoxy(61, 24); cout << "GoCourse";
	gotoxy(20, 20); cout << "[ ENTER COURSES CODE TO VIEW INFOMATION ]!";
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
	gotoxy(72, 24); cout << " COU-";
	gotoxy(72, 25); cout << "RSES!";
	setcolor(63);
}
void ViewCourseBoxDraw()
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
	drawcoursesview();
}
void ViewCourseList(Node*AccessedUser, Node*&phead)
{
	ViewCourseBoxDraw();
	Node4*courselist = NULL, *cur;
	GetCourse(courselist);
	cur = courselist;
	CourseListScroll(AccessedUser, phead, courselist, cur);
}
//--------------------[1aFTERpACK]
void GetCourseNames(string &Course)

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
				Course.append(asciiValue);
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (Course == "")
				{
					continue;
				}
				Course.pop_back();
				gotoxy(11, 24);
				std::cout << "                 ";
			}
		}
		gotoxy(11, 24);
		std::cout << Course;
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
void ShowFindedCourse(Node*AccessedUser, Node*&phead)
{
	disablePoint();
	gotoxy(11, 24); cout << "                          ";
	gotoxy(26, 22); cout << "                              ";
	string CourseCode = "";
	enablePoint();
	setcolor(58);
	drawcoursesview();
	GetCourseNames(CourseCode);
	Node4*courselist = NULL, *cur;
	GetCourse(courselist);
	cur = courselist;
	while (cur->next != NULL)
	{
		if (cur->data.coursecode == CourseCode)
		{
			Node3*curstu = new Node3;
			ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, CourseCode);
		}
		cur = cur->next;
	}
	if (cur->next == NULL) {
		DrawEnter1Box();
		setcolor(60);
		gotoxy(26, 22); cout << "CANNOT FIND [" << CourseCode << "] IN DATABASE!";
		setcolor(63);
	}
	ViewAndSearchCourse(AccessedUser, phead);
}
void CourseListScroll(Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&cur)
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
						if(atoi(cur->data.No.c_str())<10)
						cout  << atoi(cur->data.No.c_str()) << "    " << cur->data.coursecode << "    " << cur->data.coursename;
						else
							cout << atoi(cur->data.No.c_str()) << "   " << cur->data.coursecode << "    " << cur->data.coursename;
						cur = cur->next;
					}
					else
					{
						cur = courselist;
						break;
					}
				}
				CourseListScroll(AccessedUser, phead, courselist, cur);
			}
			if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
			{
				ViewAndSearchMouseDetectForCourse(AccessedUser, phead);
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
					ShowFindedCourse(AccessedUser, phead);
				}
			}
		}
	}
}
void ViewAndSearchMouseDetectForCourse(Node*AccessedUser, Node*&phead)
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
					ViewCourseList(AccessedUser, phead);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 11 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 70 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 23 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 25)
				{
					ShowFindedCourse(AccessedUser, phead);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 71 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 77 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 22 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 26)
				{
					Node4*courselist = NULL, *cur;
					GetCourse(courselist);
					Node4*curcourse = new Node4;
					ViewToMakeJustANewCourse(AccessedUser, phead, courselist, curcourse);
				}
				else
				{
					system("CLS");
					setcolor(63);
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					ThirdBox();
					ViewAndSearchCourse(AccessedUser, phead);
				}
			}
		}
	}
}
void ViewAndSearchCourse(Node*AccessedUser, Node*&phead)
{
	ViewCourseBoxDraw();
	ViewAndSearchMouseDetectForCourse(AccessedUser, phead);
}
void DrawSuperSmallBox(int x, int y)
{
	gotoxy(x, y); std::cout << char(218);
	for (int i = 1; i <= 2; i++)
	{
		cout << char(196);
	}
	gotoxy(x + 3, y); cout << char(191);
	gotoxy(x + 3, y + 1); cout << char(179);
	gotoxy(x + 3, y + 2); cout << char(217);
	gotoxy(x, y + 1); cout << char(179);
	gotoxy(x, y + 2); cout << char(192);
	for (int i = 1; i <= 2; i++)
	{
		cout << char(196);
	}
}
void DrawSuperSmallBox2(int x, int y)
{
	gotoxy(x, y); std::cout << char(218);
	for (int i = 1; i <= 4; i++)
	{
		cout << char(196);
	}
	gotoxy(x + 5, y); cout << char(191);
	gotoxy(x + 5, y + 1); cout << char(179);
	gotoxy(x + 5, y + 2); cout << char(217);
	gotoxy(x, y + 1); cout << char(179);
	gotoxy(x, y + 2); cout << char(192);
	for (int i = 1; i <= 4; i++)
	{
		cout << char(196);
	}
}
void DrawSuperSmallBox3(int x, int y)
{
	gotoxy(x, y); std::cout << char(218);
	for (int i = 1; i <= 18; i++)
	{
		cout << char(196);
	}
	gotoxy(x + 19, y); cout << char(191);
	gotoxy(x + 19, y + 1); cout << char(179);
	gotoxy(x + 19, y + 2); cout << char(217);
	gotoxy(x, y + 1); cout << char(179);
	gotoxy(x, y + 2); cout << char(192);
	for (int i = 1; i <= 18; i++)
	{
		cout << char(196);
	}
}
void DrawSuperSmallBox4(int x, int y)
{
	gotoxy(x, y); std::cout << char(218);
	for (int i = 1; i <= 18; i++)
	{
		cout << char(196);
	}
	gotoxy(x + 19, y); cout << char(191);
	gotoxy(x + 19, y + 1); cout << char(179);
	gotoxy(x + 19, y + 2); cout << char(217);
	gotoxy(x, y + 1); cout << char(179);
	gotoxy(x, y + 2); cout << char(192);
	for (int i = 1; i <= 18; i++)
	{
		cout << char(196);
	}
}
void DrawSuperSmallBox5(int x, int y)
{
	gotoxy(x, y); std::cout << char(218);
	for (int i = 1; i <= 64; i++)
	{
		cout << char(196);
	}
	gotoxy(x + 65, y); cout << char(191);
	gotoxy(x + 65, y + 1); cout << char(179);
	gotoxy(x + 65, y + 2); cout << char(217);
	gotoxy(x, y + 1); cout << char(179);
	gotoxy(x, y + 2); cout << char(192);
	for (int i = 1; i <= 64; i++)
	{
		cout << char(196);
	}
}
void DrawSmallBoxSpecial2(int x, int y)
{
	gotoxy(x, y); std::cout << char(218);
	for (int i = 1; i <= 41; i++)
	{
		cout << char(196);
	}
	gotoxy(x + 42, y); cout << char(191);
	gotoxy(x + 42, y + 1); cout << char(179);
	gotoxy(x + 42, y + 2); cout << char(217);
	gotoxy(x, y + 1); cout << char(179);
	gotoxy(x, y + 2); cout << char(192);
	for (int i = 1; i <= 41; i++)
	{
		cout << char(196);
	}
}
void DrawMDY(int x, int y)
{
	DrawSuperSmallBox(x, y);
	DrawSuperSmallBox(x+5, y);
	DrawSuperSmallBox2(x+10, y);
	setcolor(58);
	gotoxy(x+1, y+2); cout << "MM";
	gotoxy(x+6, y+2); cout << "DD";
	gotoxy(x+11, y+2); cout << "YYYY";
	setcolor(63);
}
void DrawTime(int x, int y)
{
	DrawSuperSmallBox(x, y);
	DrawSuperSmallBox(x+5, y);
}
void DrawMakeNewCourse(Node4*curcourse)
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
	gotoxy(26, 22); cout << "[  EDIT COURSES INFOMATION  ]";
	gotoxy(35, 24); cout << "SAVE & EXIT";
	setcolor(63);
	//-----
	DrawSuperSmallBox3(7, 6);//Course code box +19
	DrawSmallBoxSpecial2(30, 6);//Course name box +42
	DrawSuperSmallBox5(7, 10);//Lecture name box +65
	DrawMDY(37, 14);//Day START +
	DrawMDY(57, 14);//Day END +
	DrawSuperSmallBox(26, 14);//Semeter
	DrawSuperSmallBox2(7, 14);//Begin year +
	DrawSuperSmallBox2(14, 14);//End year +
	DrawTime(16, 18);//Time begin
	DrawTime(32, 18);//Time end
	DrawSuperSmallBox4(53, 18);//Day of week +
	setcolor(58);
	gotoxy(20, 19); cout << ":";
	gotoxy(36, 19); cout << ":";
	gotoxy(13, 15); cout << "-";
	setcolor(63);
	gotoxy(7, 13); cout << "[SCHOOL YEAR]";
	gotoxy(23, 13); cout << "[SEMESTER]";
	gotoxy(37, 13); cout << "[   STARTDAY   ]";
	gotoxy(57, 13); cout  <<"[    ENDDAY    ]";
	gotoxy(8, 7); cout << "COURSE:";
	gotoxy(31, 7); cout << "COURSE NAME:";
	gotoxy(8, 11); cout << "LECTURE:";
	gotoxy(7, 19); cout << "BEGIN AT:";
	gotoxy(25, 19); cout << "END AT:";
	gotoxy(41, 19); cout << "DAY of WEEK:";
	//---------------------------------
	setcolor(58);
	if (curcourse->data.coursecode != "")
	{gotoxy(15, 7); cout << curcourse->data.coursecode;}
	if(curcourse->data.coursename !="")
	{gotoxy(50, 7); cout << curcourse->data.coursename; }
	if (curcourse->data.lecture != "")
	{gotoxy(18, 11); cout << curcourse->data.lecture; }
	if (curcourse->data.courseyear.startyears != 0)
	{gotoxy(8, 15); cout << curcourse->data.courseyear.startyears; }
	if (curcourse->data.courseyear.endyears != 0)
	{gotoxy(15, 15); cout << curcourse->data.courseyear.endyears; }
	if (curcourse->data.semeter != 0)
	{gotoxy(27, 15); cout << curcourse->data.semeter; }
	if (curcourse->data.startdate.month != "")
	{gotoxy(38, 15); cout << curcourse->data.startdate.month; }
	if (curcourse->data.startdate.day != "")
	{gotoxy(43, 15); cout << curcourse->data.startdate.day; }
	if (curcourse->data.startdate.year != "")
	{gotoxy(48, 15); cout << curcourse->data.startdate.year; }
	if (curcourse->data.enddate.month != "")
	{gotoxy(58, 15); cout << curcourse->data.enddate.month; }
	if (curcourse->data.enddate.day != "")
	{gotoxy(63, 15); cout << curcourse->data.enddate.day; }
	if (curcourse->data.enddate.year != "")
	{gotoxy(68, 15); cout << curcourse->data.enddate.year; }
	if (curcourse->data.classtime.starthours != 0)
	{gotoxy(17, 19); cout << curcourse->data.classtime.starthours; }
	if (curcourse->data.classtime.startminute != 0)
	{gotoxy(22, 19); cout << curcourse->data.classtime.startminute; }
	if (curcourse->data.classtime.endhours != 0)
	{gotoxy(33, 19); cout << curcourse->data.classtime.endhours; }
	if (curcourse->data.classtime.endminute != 0)
	{gotoxy(38, 19); cout << curcourse->data.classtime.endminute; }
	if (curcourse->data.dayinweek != 0)
	{gotoxy(54, 19); cout << GetDayInWeek(curcourse->data.dayinweek); }
	setcolor(63);
}
//---------------
void ViewToEditOrMakeNewCourse(Node*AccessedUser, Node*&phead, Node4*courselist, string course)
{
	Node4*curcourse = GetCourseFromlist(course, courselist);
	DrawMakeNewCourse(curcourse);
	ViewToEditOrMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, course, curcourse);
}
void ViewToEditOrMakeNewCoursesMouseDetect(Node*AccessedUser, Node*&phead,  Node4*courselist, string course, Node4*&curcourse)
{
	HANDLE ScreenConsole;
	DWORD Num, Mode;
	INPUT_RECORD EventInput;
	string CourseCode = "", CourseName = "", Lecture = "", schoolyearbegin = "", schoolyearend = "", startmonth = "", startday = "", startyear = "", endmonth = "", endday = "", endyear = "", beginhour = "", beginminute = "",endhour="", endminute = "", dayofweek = "",semester="";

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
				//---course box
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 7 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 26 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 6 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 8)
				{
					gotoxy(15, 7);
					std::cout << "        ";
					setcolor(58);
					DrawSuperSmallBox3(7, 6);
					setcolor(63);
					ChangeCourseCode(CourseCode, AccessedUser, phead, courselist, course, curcourse);
				}
				//---Course name box
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 30 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 72 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 6 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 8)
				{
					gotoxy(50, 7);
					std::cout << "                     ";
					setcolor(58);
					DrawSmallBoxSpecial2(30, 6);
					setcolor(63);
					ChangeCourseName(CourseName, AccessedUser, phead, courselist, course, curcourse);
				}
				//--- lecture name box
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 7 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 72 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 10 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 12)
				{
					gotoxy(18,11);
					std::cout << "                         ";
					setcolor(58);
					DrawSuperSmallBox5(7, 10);
					setcolor(63);
					ChangeLecture(Lecture, AccessedUser, phead, courselist, course, curcourse);
				}
				//--- School year begin box
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 7 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 12 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 14 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 16)
				{
					gotoxy(8, 15);
					std::cout << "    ";
					setcolor(58);
					DrawSuperSmallBox2(7, 14);
					setcolor(63);
					ChangeCourseSchoolyearbegin(schoolyearbegin, AccessedUser, phead, courselist, course, curcourse);
				}
				//--- School year end box
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 14 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 19 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 14 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 16)
				{
					gotoxy(15, 15);
					std::cout << "    ";
					setcolor(58);
					DrawSuperSmallBox2(14, 14);
					setcolor(63);
					ChangeCourseSchoolyearend(schoolyearend, AccessedUser, phead, courselist, course, curcourse);
				}
				//--- Start month box
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 37 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 41 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 14 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 16)
				{
					gotoxy(38, 15);
					std::cout << "  ";
					setcolor(58);
					DrawSuperSmallBox(37, 14);
					setcolor(63);
					ChangeCourseStartMonth(startmonth, AccessedUser, phead, courselist, course, curcourse);
				}
				//--- Start day box
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 42 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 46 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 14 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 16)
				{
					gotoxy(43, 15);
					std::cout << "  ";
					setcolor(58);
					DrawSuperSmallBox(42, 14);
					setcolor(63);
					ChangeCourseStartDay(startday, AccessedUser, phead, courselist, course, curcourse);
				}
				//--- Start year box
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 47 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 53 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 14 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 16)
				{
					gotoxy(48, 15);
					std::cout << "    ";
					setcolor(58);
					DrawSuperSmallBox2(47, 14);
					setcolor(63);
					ChangeCourseStartYear(startyear, AccessedUser, phead, courselist, course, curcourse);
				}
				//--- End month box
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 57 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 61 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 14 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 16)
				{
					gotoxy(58, 15);
					std::cout << "  ";
					setcolor(58);
					DrawSuperSmallBox(57, 14);
					setcolor(63);
					ChangeCourseEndMonth(endmonth, AccessedUser, phead, courselist, course, curcourse);
				}
				//--- End day box
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 62 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 66 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 14 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 16)
				{
					gotoxy(63, 15);
					std::cout << "  ";
					setcolor(58);
					DrawSuperSmallBox(62, 14);
					setcolor(63);
					ChangeCourseEndDay(endday, AccessedUser, phead, courselist, course, curcourse);
				}
				//--- End year box
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 67 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 73 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 14 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 16)
				{
					gotoxy(68, 15);
					std::cout << "    ";
					setcolor(58);
					DrawSuperSmallBox2(67, 14);
					setcolor(63);
					ChangeCourseEndYear(endyear, AccessedUser, phead, courselist, course, curcourse);
				}
				//--- Begin time hour
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 16 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 20 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 18 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 20)
				{
					gotoxy(17, 19);
					std::cout << "  ";
					setcolor(58);
					DrawSuperSmallBox(16, 18);
					setcolor(63);
					ChangeCourseBeginHour(beginhour, AccessedUser, phead, courselist, course, curcourse);
				}
				//--- Begin time minute
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 21 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 25 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 18 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 20)
				{
					gotoxy(22, 19);
					std::cout << "  ";
					setcolor(58);
					DrawSuperSmallBox(21, 18);
					setcolor(63);
					ChangeCourseBeginMinute(beginminute, AccessedUser, phead, courselist, course, curcourse);
				}
				//--- End time hour
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 32 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 34 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 18 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 20)
				{
					gotoxy(33, 19);
					std::cout << "  ";
					setcolor(58);
					DrawSuperSmallBox(32, 18);
					setcolor(63);
					ChangeCourseEndHour(endhour, AccessedUser, phead, courselist, course, curcourse);
				}
				//--- End time minute
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 37 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 40 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 18 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 20)
				{
					gotoxy(38, 19);
					std::cout << "  ";
					setcolor(58);
					DrawSuperSmallBox(37, 18);
					setcolor(63);
					ChangeCourseEndMinute(endminute, AccessedUser, phead, courselist, course, curcourse);
				}
				//--- DayofWeek
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 53 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 72 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 18 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 20)
				{
					gotoxy(54, 19);
					std::cout << "           ";
					setcolor(58);
					DrawSuperSmallBox4(53, 18);
					setcolor(63);
					ChangeCourseDayOfWeek(dayofweek, AccessedUser, phead, courselist, course, curcourse);
				}
				//--- Semester
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 26 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 28 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 14 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 16)
				{
					gotoxy(27, 15);
					std::cout << " ";
					setcolor(58);
					DrawSuperSmallBox(26, 14);
					setcolor(63);
					ChangeCourseSemester(semester, AccessedUser, phead, courselist, course, curcourse);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 25 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 55 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 23 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 25)
				{
					SaveCourse(courselist);
					system("CLS");
					setcolor(63);
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					ThirdBox();
					ViewAndSearchCourse(AccessedUser, phead);
				}
				else
				{
					ViewToEditOrMakeNewCourse(AccessedUser, phead,courselist, course);
				}
			}
		}
	}
}
//---------------------------------------------------
void ChangeCourseCode(string CourseCode, Node*AccessedUser, Node*&phead,  Node4*courselist, string course, Node4*&curcourse)
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
				CourseCode.append(asciiValue);
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (CourseCode == "")
				{
					continue;
				}
				CourseCode.pop_back();
				gotoxy(15, 7);
				std::cout << "        ";
			}
		}
		gotoxy(15, 7);
		std::cout << CourseCode;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (CourseCode.length()<6)
			{
				setcolor(60);
				DrawSuperSmallBox3(7, 6);
				setcolor(63);
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox3(7, 6);
				setcolor(63);
				curcourse->data.coursecode = CourseCode;
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}

		}
		disablePoint();
	}
}
void ChangeCourseName(string CourseName, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse)
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
				CourseName.append(asciiValue);
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (CourseName == "")
				{
					continue;
				}
				CourseName.pop_back();
				gotoxy(50, 7);
				std::cout << "                    ";
			}
		}
		gotoxy(50, 7);
		std::cout << CourseName;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (CourseName.length()<6)
			{
				setcolor(60);
				DrawSmallBoxSpecial2(30, 6);
				setcolor(63); 
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}
			else
			{
				setcolor(58);
				DrawSmallBoxSpecial2(30, 6);
				setcolor(63);
				curcourse->data.coursename = CourseName; 
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}

		}
		disablePoint();
	}
}
void ChangeLecture(string Lecture, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse)
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
				Lecture.append(asciiValue);
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (Lecture == "")
				{
					continue;
				}
				Lecture.pop_back();
				gotoxy(18, 11);
				std::cout << "        ";
			}
		}
		gotoxy(18, 11);
		std::cout << Lecture;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (Lecture.length() < 6)
			{
				setcolor(60);
				DrawSuperSmallBox5(7, 10);
				setcolor(63);
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox5(7, 10);
				setcolor(63);
				curcourse->data.lecture= Lecture; 
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}

		}
		disablePoint();
	}
}
void ChangeCourseSchoolyearbegin(string schoolyearbegin, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <=57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48) )
			{
				if (schoolyearbegin.length() < 4)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					schoolyearbegin.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (schoolyearbegin == "")
				{
					continue;
				}
				schoolyearbegin.pop_back();
				gotoxy(8, 15);
				std::cout << "    ";
			}
		}
		gotoxy(8, 15);
		std::cout << schoolyearbegin;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (schoolyearbegin.length()<4)
			{
				setcolor(60);
				DrawSuperSmallBox2(7, 14);
				setcolor(63); 
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox2(7, 14);
				setcolor(63);
				curcourse->data.courseyear.startyears = std::stoi(schoolyearbegin, nullptr, 10);
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}

		}
		disablePoint();
	}
}
void ChangeCourseSchoolyearend(string schoolyearend, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse)
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
			if (EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode>=48)
			{
				if (schoolyearend.length() < 4)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					schoolyearend.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (schoolyearend == "")
				{
					continue;
				}
				schoolyearend.pop_back();
				gotoxy(15, 15);
				std::cout << "    ";
			}
		}
		gotoxy(15, 15);
		std::cout << schoolyearend;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (schoolyearend.length()<4 )
			{
				setcolor(60);
				DrawSuperSmallBox2(14, 14);
				setcolor(63); 
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox2(14, 14);
				setcolor(63);
				curcourse->data.courseyear.endyears = std::stoi(schoolyearend, nullptr, 10); 
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}

		}
		disablePoint();
	}
}
void ChangeCourseStartMonth(string startmonth, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48) )
			{
				if (startmonth.length() < 2)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					startmonth.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (startmonth == "")
				{
					continue;
				}
				startmonth.pop_back();
				gotoxy(38, 15);
				std::cout << "  ";
			}
		}
		gotoxy(38, 15);
		std::cout << startmonth;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (std::stoi(startmonth,nullptr,10)<1 || std::stoi(startmonth, nullptr, 10)>12)
			{
				setcolor(60);
				DrawSuperSmallBox( 37, 14);
				setcolor(63); 
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox(37, 14);
				setcolor(63);
				curcourse->data.startdate.month = startmonth;
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}

		}
		disablePoint();
	}
}
void ChangeCourseStartDay(string startday, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48) )
			{
				if (startday.length() < 2)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					startday.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (startday == "")
				{
					continue;
				}
				startday.pop_back();
				gotoxy(43, 15);
				std::cout << "  ";
			}
		}
		gotoxy(43, 15);
		std::cout << startday;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (std::stoi(startday,nullptr,10)<1 || std::stoi(startday, nullptr, 10)>31)
			{
				setcolor(60);
				DrawSuperSmallBox(42, 14);
				setcolor(63); 
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox(42, 14);
				setcolor(63);
				curcourse->data.startdate.day = startday; 
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}

		}
		disablePoint();
	}
}
void ChangeCourseStartYear(string startyear, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48))
			{
				if (startyear.length() < 4)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					startyear.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (startyear == "")
				{
					continue;
				}
				startyear.pop_back();
				gotoxy(48, 15);
				std::cout << "    ";
			}
		}
		gotoxy(48, 15);
		std::cout << startyear;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (startyear.length()<4)
			{
				setcolor(60);
				DrawSuperSmallBox2(47, 14);
				setcolor(63);
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox2(47, 14);
				setcolor(63);
				curcourse->data.startdate.year = startyear; 
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}

		}
		disablePoint();
	}
}
void ChangeCourseEndMonth(string endmonth, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48))
			{
				if (endmonth.length() < 2)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					endmonth.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (endmonth == "")
				{
					continue;
				}
				endmonth.pop_back();
				gotoxy(58, 15);
				std::cout << "  ";
			}
		}
		gotoxy(58, 15);
		std::cout << endmonth;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (std::stoi(endmonth, nullptr, 10)<1 || std::stoi(endmonth, nullptr, 10)>12)
			{
				setcolor(60);
				DrawSuperSmallBox(57, 14);
				setcolor(63); 
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox(57, 14);
				setcolor(63);
				curcourse->data.enddate.month = endmonth;
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}

		}
		disablePoint();
	}
}
void ChangeCourseEndDay(string endday, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48))
			{
				if (endday.length() < 2)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					endday.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (endday == "")
				{
					continue;
				}
				endday.pop_back();
				gotoxy(63, 15);
				std::cout << "  ";
			}
		}
		gotoxy(63, 15);
		std::cout << endday;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (std::stoi(endday, nullptr, 10)<1 || std::stoi(endday, nullptr, 10)>31)
			{
				setcolor(60);
				DrawSuperSmallBox(62, 14);
				setcolor(63);
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox(62, 14);
				setcolor(63);
				curcourse->data.enddate.day = endday; 
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}

		}
		disablePoint();
	}
}
void ChangeCourseEndYear(string endyear, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48))
			{
				if (endyear.length() < 4)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					endyear.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (endyear == "")
				{
					continue;
				}
				endyear.pop_back();
				gotoxy(68, 15);
				std::cout << "    ";
			}
		}
		gotoxy(68, 15);
		std::cout << endyear;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (endyear.length()<4)
			{
				setcolor(60);
				DrawSuperSmallBox2(67, 14);
				setcolor(63); 
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox2(67, 14);
				setcolor(63);
				curcourse->data.enddate.year = endyear;
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}

		}
		disablePoint();
	}
}
void ChangeCourseBeginHour(string beginhour, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48) )
			{
				if (beginhour.length() < 2)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					beginhour.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (beginhour == "")
				{
					continue;
				}
				beginhour.pop_back();
				gotoxy(17, 19);
				std::cout << "  ";
			}
		}
		gotoxy(17, 19);
		std::cout << beginhour;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (std::stoi(beginhour,nullptr,10)<1 || std::stoi(beginhour, nullptr, 10)>24)
			{
				setcolor(60);
				DrawSuperSmallBox(16, 18);
				setcolor(63); 
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox(16, 18);
				setcolor(63);
				curcourse->data.classtime.starthours = std::stoi(beginhour,nullptr,10);
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}

		}
		disablePoint();
	}
}
void ChangeCourseBeginMinute(string beginminute, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48))
			{
				if (beginminute.length() < 2)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					beginminute.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (beginminute == "")
				{
					continue;
				}
				beginminute.pop_back();
				gotoxy(22, 19);
				std::cout << "  ";
			}
		}
		gotoxy(22, 19);
		std::cout << beginminute;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (std::stoi(beginminute, nullptr, 10)<0 || std::stoi(beginminute, nullptr, 10)>60)
			{
				setcolor(60);
				DrawSuperSmallBox(21, 18);
				setcolor(63); 
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox(21, 18);
				setcolor(63);
				curcourse->data.classtime.startminute = std::stoi(beginminute, nullptr, 10);
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}

		}
		disablePoint();
	}
}
void ChangeCourseEndHour(string endhour, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48))
			{
				if (endhour.length() < 2)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					endhour.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (endhour == "")
				{
					continue;
				}
				endhour.pop_back();
				gotoxy(33, 19);
				std::cout << "  ";
			}
		}
		gotoxy(33, 19);
		std::cout << endhour;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (std::stoi(endhour, nullptr, 10)<1 || std::stoi(endhour, nullptr, 10)>24)
			{
				setcolor(60);
				DrawSuperSmallBox(32, 18);
				setcolor(63); 
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox(32, 18);
				setcolor(63);
				curcourse->data.classtime.endhours = std::stoi(endhour, nullptr, 10); 
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}

		}
		disablePoint();
	}
}
void ChangeCourseEndMinute(string endminute, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48))
			{
				if (endminute.length() < 2)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					endminute.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (endminute == "")
				{
					continue;
				}
				endminute.pop_back();
				gotoxy(38, 19);
				std::cout << "  ";
			}
		}
		gotoxy(38, 19);
		std::cout << endminute;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (std::stoi(endminute, nullptr, 10)<0 || std::stoi(endminute, nullptr, 10)>60)
			{
				setcolor(60);
				DrawSuperSmallBox(37, 18);
				setcolor(63); 
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox(37, 18);
				setcolor(63);
				curcourse->data.classtime.endminute = std::stoi(endminute, nullptr, 10); 
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}

		}
		disablePoint();
	}
}
void ChangeCourseDayOfWeek(string dayofweek, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48))
			{
				if (dayofweek.length() < 1)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					dayofweek.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (dayofweek == "")
				{
					continue;
				}
				dayofweek.pop_back();
				gotoxy(54, 19);
				std::cout << "           ";
			}
		}
		gotoxy(54, 19);
		std::cout << dayofweek;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (std::stoi(dayofweek, nullptr, 10)<1 || std::stoi(dayofweek, nullptr, 10)>7)
			{
				setcolor(60);
				DrawSuperSmallBox4(53, 18);
				setcolor(63); 
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox4(53, 18);
				setcolor(63);
				curcourse->data.dayinweek = std::stoi(dayofweek, nullptr, 10); 
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}

		}
		disablePoint();
	}
}
void ChangeCourseSemester(string semester, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 51 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48))
			{
				if (semester.length() < 1)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					semester.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (semester == "")
				{
					continue;
				}
				semester.pop_back();
				gotoxy(27, 15);
				std::cout << " ";
			}
		}
		gotoxy(27, 15);
		std::cout << semester;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (std::stoi(semester, nullptr, 10)<1 || std::stoi(semester, nullptr, 10)>3)
			{
				setcolor(60);
				DrawSuperSmallBox(26, 14);
				setcolor(63); 
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox(26, 14);
				setcolor(63);
				curcourse->data.semeter = std::stoi(semester, nullptr, 10); 
				ViewToEditOrMakeNewCourse(AccessedUser, phead, courselist, course);
			}

		}
		disablePoint();
	}
}
//-----------------------------------[This one is for making a new course I will finnish it in 2 hours-That the lunch i bet it for myself]
void ViewToMakeJustANewCourse(Node*AccessedUser, Node*&phead, Node4*courselist,Node4*&curcourse)
{
	DrawMakeNewCourse(curcourse);
	ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
}
void ViewToJustMakeNewCoursesMouseDetect(Node*AccessedUser, Node*&phead, Node4*courselist,  Node4*&curcourse)
{
	HANDLE ScreenConsole;
	DWORD Num, Mode;
	INPUT_RECORD EventInput;
	string CourseCode = "", CourseName = "", Lecture = "", schoolyearbegin = "", schoolyearend = "", startmonth = "", startday = "", startyear = "", endmonth = "", endday = "", endyear = "", beginhour = "", beginminute = "", endhour = "", endminute = "", dayofweek = "", semester = "";

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
				//---course box
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 7 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 26 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 6 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 8)
				{
					gotoxy(15, 7);
					std::cout << "        ";
					setcolor(58);
					DrawSuperSmallBox3(7, 6);
					setcolor(63);
					MakeNewCourseCode(CourseCode, AccessedUser, phead, courselist,curcourse);
				}
				//---Course name box
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 30 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 72 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 6 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 8)
				{
					gotoxy(50, 7);
					std::cout << "                     ";
					setcolor(58);
					DrawSmallBoxSpecial2(30, 6);
					setcolor(63);
					MakeNewCourseName(CourseName, AccessedUser, phead, courselist, curcourse);
				}
				//--- lecture name box
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 7 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 72 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 10 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 12)
				{
					gotoxy(18, 11);
					std::cout << "                         ";
					setcolor(58);
					DrawSuperSmallBox5(7, 10);
					setcolor(63);
					MakeNewLecture(Lecture, AccessedUser, phead, courselist, curcourse);
				}
				//--- School year begin box
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 7 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 12 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 14 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 16)
				{
					gotoxy(8, 15);
					std::cout << "    ";
					setcolor(58);
					DrawSuperSmallBox2(7, 14);
					setcolor(63);
					MakeNewCourseSchoolyearbegin(schoolyearbegin, AccessedUser, phead, courselist,curcourse);
				}
				//--- School year end box
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 14 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 19 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 14 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 16)
				{
					gotoxy(15, 15);
					std::cout << "    ";
					setcolor(58);
					DrawSuperSmallBox2(14, 14);
					setcolor(63);
					MakeNewCourseSchoolyearend(schoolyearend, AccessedUser, phead, courselist, curcourse);
				}
				//--- Start month box
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 37 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 41 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 14 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 16)
				{
					gotoxy(38, 15);
					std::cout << "  ";
					setcolor(58);
					DrawSuperSmallBox(37, 14);
					setcolor(63);
					MakeNewCourseStartMonth(startmonth, AccessedUser, phead, courselist,curcourse);
				}
				//--- Start day box
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 42 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 46 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 14 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 16)
				{
					gotoxy(43, 15);
					std::cout << "  ";
					setcolor(58);
					DrawSuperSmallBox(42, 14);
					setcolor(63);
					MakeNewCourseStartDay(startday, AccessedUser, phead, courselist, curcourse);
				}
				//--- Start year box
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 47 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 53 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 14 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 16)
				{
					gotoxy(48, 15);
					std::cout << "    ";
					setcolor(58);
					DrawSuperSmallBox2(47, 14);
					setcolor(63);
					MakeNewCourseStartYear(startyear, AccessedUser, phead, courselist,curcourse);
				}
				//--- End month box
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 57 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 61 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 14 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 16)
				{
					gotoxy(58, 15);
					std::cout << "  ";
					setcolor(58);
					DrawSuperSmallBox(57, 14);
					setcolor(63);
					MakeNewCourseEndMonth(endmonth, AccessedUser, phead, courselist,  curcourse);
				}
				//--- End day box
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 62 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 66 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 14 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 16)
				{
					gotoxy(63, 15);
					std::cout << "  ";
					setcolor(58);
					DrawSuperSmallBox(62, 14);
					setcolor(63);
					MakeNewCourseEndDay(endday, AccessedUser, phead, courselist, curcourse);
				}
				//--- End year box
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 67 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 73 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 14 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 16)
				{
					gotoxy(68, 15);
					std::cout << "    ";
					setcolor(58);
					DrawSuperSmallBox2(67, 14);
					setcolor(63);
					MakeNewCourseEndYear(endyear, AccessedUser, phead, courselist, curcourse);
				}
				//--- Begin time hour
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 16 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 20 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 18 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 20)
				{
					gotoxy(17, 19);
					std::cout << "  ";
					setcolor(58);
					DrawSuperSmallBox(16, 18);
					setcolor(63);
					MakeNewCourseBeginHour(beginhour, AccessedUser, phead, courselist,  curcourse);
				}
				//--- Begin time minute
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 21 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 25 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 18 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 20)
				{
					gotoxy(22, 19);
					std::cout << "  ";
					setcolor(58);
					DrawSuperSmallBox(21, 18);
					setcolor(63);
					MakeNewCourseBeginMinute(beginminute, AccessedUser, phead, courselist,  curcourse);
				}
				//--- End time hour
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 32 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 34 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 18 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 20)
				{
					gotoxy(33, 19);
					std::cout << "  ";
					setcolor(58);
					DrawSuperSmallBox(32, 18);
					setcolor(63);
					MakeNewCourseEndHour(endhour, AccessedUser, phead, courselist, curcourse);
				}
				//--- End time minute
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 37 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 40 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 18 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 20)
				{
					gotoxy(38, 19);
					std::cout << "  ";
					setcolor(58);
					DrawSuperSmallBox(37, 18);
					setcolor(63);
					MakeNewCourseEndMinute(endminute, AccessedUser, phead, courselist, curcourse);
				}
				//--- DayofWeek
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 53 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 72 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 18 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 20)
				{
					gotoxy(54, 19);
					std::cout << "           ";
					setcolor(58);
					DrawSuperSmallBox4(53, 18);
					setcolor(63);
					MakeNewCourseDayOfWeek(dayofweek, AccessedUser, phead, courselist, curcourse);
				}
				//--- Semester
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 26 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 28 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 14 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 16)
				{
					gotoxy(27, 15);
					std::cout << " ";
					setcolor(58);
					DrawSuperSmallBox(26, 14);
					setcolor(63);
					MakeNewCourseSemester(semester, AccessedUser, phead, courselist, curcourse);
				}
				if (EventInput.Event.MouseEvent.dwMousePosition.X >= 25 &&
					EventInput.Event.MouseEvent.dwMousePosition.X <= 55 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y >= 23 &&
					EventInput.Event.MouseEvent.dwMousePosition.Y <= 25)
				{
					SaveNewCourse(courselist, curcourse);
					system("CLS");
					setcolor(63);
					DrawMenuUI(AccessedUser, phead);
					DrawSelectionBox();
					ThirdBox();
					ViewAndSearchCourse(AccessedUser, phead);
				}
				else
				{
					ViewToMakeJustANewCourse(AccessedUser, phead, courselist, curcourse);
				}
			}
		}
	}
}
//---------------------------------------------------
void MakeNewCourseCode(string CourseCode, Node*AccessedUser, Node*&phead, Node4*courselist,   Node4*&curcourse)
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
				CourseCode.append(asciiValue);
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (CourseCode == "")
				{
					continue;
				}
				CourseCode.pop_back();
				gotoxy(15, 7);
				std::cout << "        ";
			}
		}
		gotoxy(15, 7);
		std::cout << CourseCode;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (CourseCode.length()<6)
			{
				setcolor(60);
				DrawSuperSmallBox3(7, 6);
				setcolor(63);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox3(7, 6);
				setcolor(63);
				curcourse->data.coursecode = CourseCode;
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}

		}
		disablePoint();
	}
}
void MakeNewCourseName(string CourseName, Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse)
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
				CourseName.append(asciiValue);
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (CourseName == "")
				{
					continue;
				}
				CourseName.pop_back();
				gotoxy(50, 7);
				std::cout << "                    ";
			}
		}
		gotoxy(50, 7);
		std::cout << CourseName;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (CourseName.length()<6)
			{
				setcolor(60);
				DrawSmallBoxSpecial2(30, 6);
				setcolor(63);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}
			else
			{
				setcolor(58);
				DrawSmallBoxSpecial2(30, 6);
				setcolor(63);
				curcourse->data.coursename = CourseName;
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}

		}
		disablePoint();
	}
}
void MakeNewLecture(string Lecture, Node*AccessedUser, Node*&phead, Node4*courselist,  Node4*&curcourse)
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
				Lecture.append(asciiValue);
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (Lecture == "")
				{
					continue;
				}
				Lecture.pop_back();
				gotoxy(18, 11);
				std::cout << "        ";
			}
		}
		gotoxy(18, 11);
		std::cout << Lecture;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (Lecture.length() < 6)
			{
				setcolor(60);
				DrawSuperSmallBox5(7, 10);
				setcolor(63);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox5(7, 10);
				setcolor(63);
				curcourse->data.lecture = Lecture;
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}

		}
		disablePoint();
	}
}
void MakeNewCourseSchoolyearbegin(string schoolyearbegin, Node*AccessedUser, Node*&phead, Node4*courselist,  Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48))
			{
				if (schoolyearbegin.length() < 4)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					schoolyearbegin.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (schoolyearbegin == "")
				{
					continue;
				}
				schoolyearbegin.pop_back();
				gotoxy(8, 15);
				std::cout << "    ";
			}
		}
		gotoxy(8, 15);
		std::cout << schoolyearbegin;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (schoolyearbegin.length()<4)
			{
				setcolor(60);
				DrawSuperSmallBox2(7, 14);
				setcolor(63);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox2(7, 14);
				setcolor(63);
				curcourse->data.courseyear.startyears = std::stoi(schoolyearbegin, nullptr, 10);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}

		}
		disablePoint();
	}
}
void MakeNewCourseSchoolyearend(string schoolyearend, Node*AccessedUser, Node*&phead, Node4*courselist,  Node4*&curcourse)
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
			if (EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48)
			{
				if (schoolyearend.length() < 4)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					schoolyearend.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (schoolyearend == "")
				{
					continue;
				}
				schoolyearend.pop_back();
				gotoxy(15, 15);
				std::cout << "    ";
			}
		}
		gotoxy(15, 15);
		std::cout << schoolyearend;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (schoolyearend.length()<4)
			{
				setcolor(60);
				DrawSuperSmallBox2(14, 14);
				setcolor(63);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox2(14, 14);
				setcolor(63);
				curcourse->data.courseyear.endyears = std::stoi(schoolyearend, nullptr, 10);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}

		}
		disablePoint();
	}
}
void MakeNewCourseStartMonth(string startmonth, Node*AccessedUser, Node*&phead, Node4*courselist,  Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48))
			{
				if (startmonth.length() < 2)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					startmonth.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (startmonth == "")
				{
					continue;
				}
				startmonth.pop_back();
				gotoxy(38, 15);
				std::cout << "  ";
			}
		}
		gotoxy(38, 15);
		std::cout << startmonth;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (std::stoi(startmonth, nullptr, 10)<1 || std::stoi(startmonth, nullptr, 10)>12)
			{
				setcolor(60);
				DrawSuperSmallBox(37, 14);
				setcolor(63);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox(37, 14);
				setcolor(63);
				curcourse->data.startdate.month = startmonth;
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}

		}
		disablePoint();
	}
}
void MakeNewCourseStartDay(string startday, Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48))
			{
				if (startday.length() < 2)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					startday.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (startday == "")
				{
					continue;
				}
				startday.pop_back();
				gotoxy(43, 15);
				std::cout << "  ";
			}
		}
		gotoxy(43, 15);
		std::cout << startday;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (std::stoi(startday, nullptr, 10)<1 || std::stoi(startday, nullptr, 10)>31)
			{
				setcolor(60);
				DrawSuperSmallBox(42, 14);
				setcolor(63);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox(42, 14);
				setcolor(63);
				curcourse->data.startdate.day = startday;
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}

		}
		disablePoint();
	}
}
void MakeNewCourseStartYear(string startyear, Node*AccessedUser, Node*&phead, Node4*courselist,  Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48))
			{
				if (startyear.length() < 4)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					startyear.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (startyear == "")
				{
					continue;
				}
				startyear.pop_back();
				gotoxy(48, 15);
				std::cout << "    ";
			}
		}
		gotoxy(48, 15);
		std::cout << startyear;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (startyear.length()<4)
			{
				setcolor(60);
				DrawSuperSmallBox2(47, 14);
				setcolor(63);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox2(47, 14);
				setcolor(63);
				curcourse->data.startdate.year = startyear;
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}

		}
		disablePoint();
	}
}
void MakeNewCourseEndMonth(string endmonth, Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48))
			{
				if (endmonth.length() < 2)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					endmonth.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (endmonth == "")
				{
					continue;
				}
				endmonth.pop_back();
				gotoxy(58, 15);
				std::cout << "  ";
			}
		}
		gotoxy(58, 15);
		std::cout << endmonth;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (std::stoi(endmonth, nullptr, 10)<1 || std::stoi(endmonth, nullptr, 10)>12)
			{
				setcolor(60);
				DrawSuperSmallBox(57, 14);
				setcolor(63);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox(57, 14);
				setcolor(63);
				curcourse->data.enddate.month = endmonth;
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}

		}
		disablePoint();
	}
}
void MakeNewCourseEndDay(string endday, Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48))
			{
				if (endday.length() < 2)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					endday.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (endday == "")
				{
					continue;
				}
				endday.pop_back();
				gotoxy(63, 15);
				std::cout << "  ";
			}
		}
		gotoxy(63, 15);
		std::cout << endday;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (std::stoi(endday, nullptr, 10)<1 || std::stoi(endday, nullptr, 10)>31)
			{
				setcolor(60);
				DrawSuperSmallBox(62, 14);
				setcolor(63);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox(62, 14);
				setcolor(63);
				curcourse->data.enddate.day = endday;
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}

		}
		disablePoint();
	}
}
void MakeNewCourseEndYear(string endyear, Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48))
			{
				if (endyear.length() < 4)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					endyear.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (endyear == "")
				{
					continue;
				}
				endyear.pop_back();
				gotoxy(68, 15);
				std::cout << "    ";
			}
		}
		gotoxy(68, 15);
		std::cout << endyear;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (endyear.length()<4)
			{
				setcolor(60);
				DrawSuperSmallBox2(67, 14);
				setcolor(63);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox2(67, 14);
				setcolor(63);
				curcourse->data.enddate.year = endyear;
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}

		}
		disablePoint();
	}
}
void MakeNewCourseBeginHour(string beginhour, Node*AccessedUser, Node*&phead, Node4*courselist,  Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48))
			{
				if (beginhour.length() < 2)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					beginhour.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (beginhour == "")
				{
					continue;
				}
				beginhour.pop_back();
				gotoxy(17, 19);
				std::cout << "  ";
			}
		}
		gotoxy(17, 19);
		std::cout << beginhour;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (std::stoi(beginhour, nullptr, 10)<1 || std::stoi(beginhour, nullptr, 10)>24)
			{
				setcolor(60);
				DrawSuperSmallBox(16, 18);
				setcolor(63);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox(16, 18);
				setcolor(63);
				curcourse->data.classtime.starthours = std::stoi(beginhour, nullptr, 10);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}

		}
		disablePoint();
	}
}
void MakeNewCourseBeginMinute(string beginminute, Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48))
			{
				if (beginminute.length() < 2)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					beginminute.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (beginminute == "")
				{
					continue;
				}
				beginminute.pop_back();
				gotoxy(22, 19);
				std::cout << "  ";
			}
		}
		gotoxy(22, 19);
		std::cout << beginminute;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (std::stoi(beginminute, nullptr, 10)<0 || std::stoi(beginminute, nullptr, 10)>60)
			{
				setcolor(60);
				DrawSuperSmallBox(21, 18);
				setcolor(63);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox(21, 18);
				setcolor(63);
				curcourse->data.classtime.startminute = std::stoi(beginminute, nullptr, 10);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}

		}
		disablePoint();
	}
}
void MakeNewCourseEndHour(string endhour, Node*AccessedUser, Node*&phead, Node4*courselist,  Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48))
			{
				if (endhour.length() < 2)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					endhour.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (endhour == "")
				{
					continue;
				}
				endhour.pop_back();
				gotoxy(33, 19);
				std::cout << "  ";
			}
		}
		gotoxy(33, 19);
		std::cout << endhour;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (std::stoi(endhour, nullptr, 10)<1 || std::stoi(endhour, nullptr, 10)>24)
			{
				setcolor(60);
				DrawSuperSmallBox(32, 18);
				setcolor(63);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox(32, 18);
				setcolor(63);
				curcourse->data.classtime.endhours = std::stoi(endhour, nullptr, 10);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}

		}
		disablePoint();
	}
}
void MakeNewCourseEndMinute(string endminute, Node*AccessedUser, Node*&phead, Node4*courselist,  Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48))
			{
				if (endminute.length() < 2)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					endminute.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (endminute == "")
				{
					continue;
				}
				endminute.pop_back();
				gotoxy(38, 19);
				std::cout << "  ";
			}
		}
		gotoxy(38, 19);
		std::cout << endminute;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (std::stoi(endminute, nullptr, 10)<0 || std::stoi(endminute, nullptr, 10)>60)
			{
				setcolor(60);
				DrawSuperSmallBox(37, 18);
				setcolor(63);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox(37, 18);
				setcolor(63);
				curcourse->data.classtime.endminute = std::stoi(endminute, nullptr, 10);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}

		}
		disablePoint();
	}
}
void MakeNewCourseDayOfWeek(string dayofweek, Node*AccessedUser, Node*&phead, Node4*courselist,  Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48))
			{
				if (dayofweek.length() < 1)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					dayofweek.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (dayofweek == "")
				{
					continue;
				}
				dayofweek.pop_back();
				gotoxy(54, 19);
				std::cout << "           ";
			}
		}
		gotoxy(54, 19);
		std::cout << dayofweek;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (std::stoi(dayofweek, nullptr, 10)<1 || std::stoi(dayofweek, nullptr, 10)>7)
			{
				setcolor(60);
				DrawSuperSmallBox4(53, 18);
				setcolor(63);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox4(53, 18);
				setcolor(63);
				curcourse->data.dayinweek = std::stoi(dayofweek, nullptr, 10);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}

		}
		disablePoint();
	}
}
void MakeNewCourseSemester(string semester, Node*AccessedUser, Node*&phead, Node4*courselist,  Node4*&curcourse)
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
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 51 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48))
			{
				if (semester.length() < 1)
				{
					asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
					semester.append(asciiValue);
				}
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (semester == "")
				{
					continue;
				}
				semester.pop_back();
				gotoxy(27, 15);
				std::cout << " ";
			}
		}
		gotoxy(27, 15);
		std::cout << semester;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			if (std::stoi(semester, nullptr, 10)<1 || std::stoi(semester, nullptr, 10)>3)
			{
				setcolor(60);
				DrawSuperSmallBox(26, 14);
				setcolor(63);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}
			else
			{
				setcolor(58);
				DrawSuperSmallBox(26, 14);
				setcolor(63);
				curcourse->data.semeter = std::stoi(semester, nullptr, 10);
				ViewToJustMakeNewCoursesMouseDetect(AccessedUser, phead, courselist, curcourse);
			}

		}
		disablePoint();
	}
}

