#include"HeaderFIRSTtouch.h"
void HUBdraw()
{
	enablePoint();
	HWND console = GetConsoleWindow();
	RECT r;
	string username,password;
	Node*AccessedUser=NULL,*phead=NULL;
	setcolor(63);
	system("CLS");
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 800, 600, TRUE); 
	Menudraw();
	EnterUserNameAndPassword(username, password,AccessedUser,phead);
	_getch();
}
void Menudraw()
{
	gotoxy(0, 0);
	Skulldraw(0);
	LoginBox();
}
void Skulldraw(int i)
{
	if (i == 1)
	{
		cout << "                                     ______            \n";
		cout << "                                  .-'      '-.         \n";
		cout << "                                 |            |        \n";
		cout << "                                |              |       \n";
		cout << "                                |,  .-.  .-.  ,|       \n";
		cout << "                                | )(o)|  |(o)( |       \n";
		cout << "                                ||     ||     ||       \n";
		cout << "                                (_     ^^     _)       \n";
		cout << "                                 |__|IIIIII|__|        \n";
		cout << "                                  |          |         \n";
		cout << "                                  | |IIIIII| |         \n";
		cout << "                                   `--------`          \n";
	}
	else if(i==0)
	{
		cout << "                                     ______            \n";
		cout << "                                  .-'      '-.         \n";
		cout << "                                 |            |        \n";
		cout << "                                |              |       \n";
		cout << "                                |,  .-.  .-.  ,|       \n";
		cout << "                                | )(x)|  |(x)( |       \n";
		cout << "                                ||     ||     ||       \n";
		cout << "                                (_     ^^     _)       \n";
		cout << "                                 |__|IIIIII|__|        \n";
		cout << "                                  | |IIIIII| |         \n";
		cout << "                                  |          |         \n";
		cout << "                                   `--------`          \n";
	}
	else if (i == 4)
	{
		cout << "              ______     \n";
		cout << "           .-'      '-.  \n";
		cout << "          |            | \n";
		cout << "         |              |\n";
		cout << "         |,  .-.  .-.  ,|\n";
		cout << "         | )(o)|  |(o)( |\n";
		cout << "         ||     ||     ||\n";
		cout << "         (_     ^^     _)\n";
		cout << "          |__|IIIIII|__| \n";
		cout << "           |          |  \n";
		cout << "           | |IIIIII| |  \n";
		cout << "            `--------`   \n";
	}
}
void LoginBox()
{
	//######################
	gotoxy(19, 13);
	cout << (char)201;
	gotoxy(20, 13);
	for (int i = 1; i <= 40; i++)
	{
		cout << char(196);
	}
	gotoxy(60, 13);
	cout << (char)187;
	//---------------
	gotoxy(60, 14);
	cout << (char)179;
	gotoxy(60, 15);
	cout << (char)179;
	gotoxy(60, 16);
	cout << (char)179;
	gotoxy(60, 17);
	cout << (char)179;
	gotoxy(60, 18);
	cout << (char)179;
	gotoxy(60, 19);
	cout << (char)179;
	gotoxy(60, 20);
	cout << (char)179;
	//---------------
	gotoxy(60, 21);
	cout << (char)188;
	//---------------
	gotoxy(20, 21);
	for (int i = 1; i <= 40; i++)
	{
		cout << char(196);
	}
	//---------------
	gotoxy(19, 21);
	cout << (char)200;
	//---------------
	gotoxy(19, 14);
	cout << (char)179;
	gotoxy(19, 15);
	cout << (char)179;
	gotoxy(19, 16);
	cout << (char)179;
	gotoxy(19, 17);
	cout << (char)179;
	gotoxy(19, 18);
	cout << (char)179;
	gotoxy(19, 19);
	cout << (char)179;
	gotoxy(19, 20);
	cout << (char)179;
	//---------------
	gotoxy(20, 17);
	for (int i = 1; i <= 40; i++)
	{
		cout << (char)196;
	}
	//---------------
	gotoxy(20, 15);
	cout << "USERNAME:";
	gotoxy(20, 19);
	cout << "PASSWORD:";
	//######################
	//-------hhh--------
	gotoxy(31, 22);
	cout << (char)201;
	gotoxy(32, 22);
	for (int i = 1; i <= 16; i++)
	{
		cout << (char)196;
	}
	//-------hhh--------
	gotoxy(48, 22);
	cout << (char)187;
	//--------hhh-------
	gotoxy(48, 23);
	cout << (char)179;
	//--------hhh-------
	gotoxy(48, 24);
	cout << (char)188;
	//--------hhh-------
	gotoxy(32, 24);
	for (int i = 1; i <= 16; i++)
	{
		cout << (char)196;
	}
	//-------hhh--------
	gotoxy(31, 24);
	cout << (char)200;
	//--------hhh-------
	gotoxy(31, 23);
	cout << (char)179;
	//--------hhh-------
	gotoxy(37, 23);
	cout << "LOGIN";
	//######################
	//--------QQQ-------
	gotoxy(69, 24);
	cout << (char)201;
	gotoxy(69, 25);
	cout << (char)179;
	gotoxy(76, 25);
	cout << (char)179;
	gotoxy(76, 24);
	cout << (char)187;
	gotoxy(76, 26);
	cout << (char)188;
	gotoxy(69, 26);
	cout << (char)200;
	gotoxy(70, 25);
	cout << " EXIT";
	gotoxy(70, 24);
	for (int i = 1; i <= 6; i++)
		cout << (char)196;
	gotoxy(70, 26);
	for (int i = 1; i <= 6; i++)
		cout << (char)196;

}
void usernamebox(string &username) {
	char key;
	string password ,asciiValue;
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
		mouseEvent1(EventInput.Event.MouseEvent);
		if (EventInput.EventType == KEY_EVENT && EventInput.Event.KeyEvent.bKeyDown == true)
		{
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 112 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 65) ||
				(EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48) ||
				EventInput.Event.KeyEvent.wVirtualKeyCode == 32)
			{
				asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
				username.append(asciiValue);
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (username == "")
				{
					continue;
				}
				username.pop_back();
				gotoxy(29, 15);
				std::cout << "                 ";
			}
		}
		gotoxy(29, 15);
		std::cout << username;
		if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
		{
			gotoxy(29, 19);
			FlushConsoleInputBuffer(ScreenConsole);
			ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
			break;
		}
		enablePoint;
	}
}
void PasswordBox(string &password)
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
		mouseEvent2(EventInput.Event.MouseEvent);
		if (EventInput.EventType == KEY_EVENT && EventInput.Event.KeyEvent.bKeyDown == true)
		{
			if ((EventInput.Event.KeyEvent.wVirtualKeyCode <= 112 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 65) ||
				(EventInput.Event.KeyEvent.wVirtualKeyCode <= 57 && EventInput.Event.KeyEvent.wVirtualKeyCode >= 48) ||
				EventInput.Event.KeyEvent.wVirtualKeyCode == 32)
			{
				asciiValue = EventInput.Event.KeyEvent.uChar.AsciiChar;
				password.append(asciiValue);
				asterisk.append("*");
			}
			else if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{
				if (password == "")
				{
					continue;
				}
				password.pop_back();
				asterisk.pop_back();
				gotoxy(29, 19);
				std::cout<< "                 ";
			}
		}
		gotoxy(29, 19);
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
void mouseEvent1(MOUSE_EVENT_RECORD mouse)
{
	int mouse_x = mouse.dwMousePosition.X;
	int mouse_y = mouse.dwMousePosition.Y;

	if (mouse_x <= 76 && mouse_x >= 70 && mouse_y <= 26 && mouse_y >= 24) {
		if (mouse.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
			setcolor(60);
			gotoxy(0, 0);
			Skulldraw(1);
			Sleep(100);
			exit(0);
		}
	}
	if (mouse_x <= 60 && mouse_x >= 19 && mouse_y >= 13 && mouse_y <= 17) {
		gotoxy(29, 15);
	}
}
void mouseEvent2(MOUSE_EVENT_RECORD mouse)
{
	int mouse_x = mouse.dwMousePosition.X;
	int mouse_y = mouse.dwMousePosition.Y;

	if (mouse_x <= 76 && mouse_x >= 70 && mouse_y <= 26 && mouse_y >= 24) {
		if (mouse.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
			setcolor(60);
			gotoxy(0, 0);
			Skulldraw(1);
			Sleep(100);
			exit(0);
		}
	}
	if (mouse_x <= 60 && mouse_x >= 19 && mouse_y >= 17 && mouse_y <= 21) {
		gotoxy(29, 19);
	}
}
void MoveToUserUI(Node*AccessedUser,Node*&phead)
{
	INPUT_RECORD EventInput;
	HANDLE ScreenConsole;
	DWORD Num, Mode;

	ScreenConsole = GetStdHandle(STD_INPUT_HANDLE);
	if (ScreenConsole == INVALID_HANDLE_VALUE)
		return;
	Mode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(ScreenConsole, Mode))
		return;
	Mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(ScreenConsole, Mode)) return;
	FlushConsoleInputBuffer(ScreenConsole);
	ReadConsoleInput(ScreenConsole, &EventInput, 1, &Num);
	if (EventInput.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
	{
		MenuUI(AccessedUser, phead);
	}
}
void EnterUserNameAndPassword(string &username, string &password, Node*AccessedUser, Node*&phead)
{
	username = ""; password = "";
	usernamebox(username);
	PasswordBox(password);
	if (CheckUserNameAndPassWord(username, password, "UserData.csv", AccessedUser, phead) == true)
	{
		setcolor(58);
		gotoxy(0, 0);
		Skulldraw(1);
		gotoxy(30, 12);
		cout << " SUCCESSFUL ACCESS";
		setcolor(63);
		MoveToUserUI(AccessedUser, phead);
	}
	else
	{
		setcolor(60);
		gotoxy(0, 0);
		Skulldraw(1);
		gotoxy(30, 12);
		cout << "   FAIL TO ACCESS";
		setcolor(63);
		gotoxy(29, 19);
		std::cout << "                 ";
		gotoxy(29, 15);
		std::cout << "                 ";
		gotoxy(29, 15);
		EnterUserNameAndPassword(username, password, AccessedUser, phead);
	}
}