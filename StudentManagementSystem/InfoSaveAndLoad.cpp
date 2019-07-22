#include"HeaderFIRSTtouch.h"
void getInfoStudent(char path[], Node *&phead)
{
	phead = new Node;
	ifstream fin;
	string tempname, tempmssv, tempnumber, tempphonenumber, tempmail, tempuserid, temppass, tempclass, check;
	fin.open(path);
	getline(fin, tempnumber, ',');
	getline(fin, tempmssv, ',');
	getline(fin, tempname, ',');
	getline(fin, tempphonenumber, ',');
	getline(fin, tempmail, ',');
	getline(fin, tempuserid, ',');
	getline(fin, temppass, ',');
	getline(fin, tempclass, ',');
	phead->data.No = tempnumber;
	phead->data.mssv = tempmssv;
	phead->data.name = tempname;
	phead->data.PhoneNumber = tempphonenumber;
	phead->data.Mail = tempmail;
	phead->data.userID = tempuserid;
	phead->data.Password = temppass;
	phead->data.Class = tempclass;
	phead->next = NULL;
	Node*cur = phead;
	while (!fin.eof())
	{
		cur->next = new Node;
		cur = cur->next;
		getline(fin, tempnumber, ',');
		getline(fin, tempmssv, ',');
		getline(fin, tempname, ',');
		getline(fin, tempphonenumber, ',');
		getline(fin, tempmail, ',');
		getline(fin, tempuserid, ',');
		getline(fin, temppass, ',');
		getline(fin, tempclass, ',');
		cur->data.No = tempnumber;
		cur->data.mssv = tempmssv;
		cur->data.name = tempname;
		cur->data.PhoneNumber = tempphonenumber;
		cur->data.Mail = tempmail;
		cur->data.userID = tempuserid;
		cur->data.Password = temppass;
		cur->data.Class = tempclass;
		cur->next = NULL;
	}
	fin.close();
}
void showInfoStudent(Node*phead)
{
	Node*cur = phead;

	while (cur->next != NULL)
	{
		cout << cur->data.No << " " << cur->data.mssv << " " << cur->data.name << " " << cur->data.PhoneNumber << " " << cur->data.Mail << " " << cur->data.userID << " " << cur->data.Password << " " << cur->data.Class << endl;
		cur = cur->next;
	}
}
void saveInfoStudent(char path[], Node*phead)
{
	ofstream fout;
	fout.open(path);
	Node*cur = phead;
	while (cur->next != NULL)
	{

		fout << cur->data.No << "," << cur->data.mssv << "," << cur->data.name << "," << cur->data.PhoneNumber << "," << cur->data.Mail << "," << cur->data.userID << "," << cur->data.Password << "," << cur->data.Class << "," ;
		cur = cur->next;
	}
	fout.close();
}
bool CheckUserNameAndPassWord(string username, string password,char path[],Node*&useraccessed,Node*&phead)
{
	getInfoStudent(path, phead);
	Node*cur = phead;
	while (cur->next != NULL) {
		if (cur->data.userID == username && cur->data.Password == password) {
			return true;
		}
		cur = cur->next;
		useraccessed = cur;
	}
}
//----------------------
void SaveAClassToList(string newclass, Node2*chead)
{
	ofstream fout;
	fout.open("ClassList.csv");
	if (!fout.is_open())
	{
		system("CLS");
		setcolor(60);
		cout << "CRASHHH CUS CANNOT OPEN SOURCE";
		system("pause");
		exit(0);
	}
	Node2*cur = chead;
	while (cur->next != NULL)
	{
		fout << cur->classname << ",";
		cur = cur->next;
	}
	fout << newclass << ",";
	fout.close();
}
Node3 *GetInfoFromStudentID(string studentid,Node3*&dhead)
{
	Node3*cur = dhead;
	while (cur->next != NULL)
	{
		if (cur->stuudent.mssv == studentid)
			return cur;
		cur = cur->next;
	}
}
Node4 *GetCourseFromlist(string course, Node4*&courselist)
{
	Node4*cur = courselist;
	while (cur->next != NULL)
	{
		if (cur->data.coursecode == course)
			return cur;
		cur = cur->next;
	}
}
Node5 *GetScheduleFromlist(string classname, Node5*&schedulelist)
{
	Node5*cur = schedulelist;
	while (cur->next != NULL)
	{
		if (cur->Scheduledata.classcode == classname)
			return cur;
		cur = cur->next;
	}
}
bool CheckRightID(string id)
{
	for (int i = 0; i < id.length(); i++)
	{
		if (id[i]<char(48) || id[i]>char(57))
		{
			return false;
		}
	}
	if (id.length() < 6)
		return false;
	return true;
}
bool CheckRightNAME(string name)
{
	for (int i = 0; i < name.length(); i++)
	{
		if (name[i]<char(65) && name[i]>char(122))
		{
			return false;
		}
	}
	if (name.length() < 6)
		return false;
	return true;
}
bool CheckRightEmail(string mail)
{
	int flag=0,flag2=0;
	for (int i = 0; i < mail.length(); i++)
	{
		if (mail[i]<char(65) && mail[i]>char(122))
		{
			return false;
		}
		if (mail[i] == char(64))
		{
			flag++;
		}
		if (mail[i] == char(64))
		{
			flag2++;
		}
	}
	if (mail.length() < 6)
		return false;
	else if (flag == 0 || flag2 == 0)
		return false;
	return true;
}
bool CheckRightPhoneNumber(string phonenumber)
{
	for (int i = 0; i < phonenumber.length(); i++)
	{
		if (phonenumber[i]<char(48) || phonenumber[i]>char(57))
			return false;
	}
	if (phonenumber.length() < 11)
		return false;
	return true;
}
bool CheckRightUserName(string username)
{
	for (int i = 0; i < username.length(); i++)
	{
		if (username[i]<char(48) || username[i]>char(122))
		{
			return false;
		}
	}
	if (username.length() < 6)
		return false;
	return true;
}
bool CheckRightPassword(string password)
{
	for (int i = 0; i < password.length(); i++)
	{
		if (password[i]<char(48) || password[i]>char(122))
			return false;
	}
	if (password.length() < 6)
		return false;
	return true;
}
bool CheckAllBeffSave(Node3*&curstu)
{

	if (CheckRightID(curstu->stuudent.mssv) == false)
	{
		return false;
	}
	if (CheckRightNAME(curstu->stuudent.name) == false)
	{
		return false;
	}
	if (CheckRightEmail(curstu->stuudent.Mail) == false)
	{
		return false;
	}
	if (CheckRightPhoneNumber(curstu->stuudent.PhoneNumber) == false)
	{
		return false;
	}
	if (CheckRightUserName(curstu->stuudent.userID) == false)
	{
		return false;
	}
	if (CheckRightPassword(curstu->stuudent.Password) == false)
	{
		return false;
	}
	return true;
}
bool CheckAllCourseBeSave(Node4*curcourse)
{
	if (curcourse->data.coursecode.length() < 6)
		return false;
	if (curcourse->data.coursename.length() < 6)
		return false;
	if (curcourse->data.lecture.length() < 6)
		return false;
	if (curcourse->data.courseyear.startyears < 2000)
		return false;
	if (curcourse->data.courseyear.endyears < 2000)
		return false;
	if (curcourse->data.startdate.month.length() < 1)
		return false;
	if (curcourse->data.startdate.day.length() < 1)
		return false;
	if (curcourse->data.startdate.year.length() < 4)
		return false;
	if (curcourse->data.enddate.month.length() < 1)
		return false;
	if (curcourse->data.enddate.day.length() < 1)
		return false;
	if (curcourse->data.enddate.year.length()< 4)
		return false;
	if (curcourse->data.startdate.month.length() < 1)
		return false;
	if (curcourse->data.classtime.starthours < 1 || curcourse->data.classtime.starthours==NULL)
		return false;
	if (curcourse->data.classtime.startminute < 0)
		return false;
	if (curcourse->data.classtime.endhours < 1 || curcourse->data.classtime.endhours == NULL)
		return false;
	if (curcourse->data.classtime.endminute < 0)
		return false;
	if (curcourse->data.dayinweek< 1 || curcourse->data.dayinweek== NULL)
		return false;
	if (curcourse->data.semeter< 1 || curcourse->data.semeter == NULL)
		return false;
	return true;
}
void CheckAndSaveStudentInfomation(string inputclass, Node3*&dhead,Node3*&curstu,Node*&phead)
{
	ofstream fout;
	string link = inputclass + ".csv";
	link = "Class/" + link;
	fout.open(link);
	Node3*cur = dhead;
	while (cur->next != NULL)
	{

		fout << cur->stuudent.No << "," << cur->stuudent.mssv << "," << cur->stuudent.name << "," << cur->stuudent.PhoneNumber << "," << cur->stuudent.Mail << "," << cur->stuudent.userID << "," << cur->stuudent.Password << "," ;
		cur = cur->next;
	}
	fout.close();
	Node*cur2 = phead;
	while (cur2->next != NULL)
	{
		if (curstu->stuudent.mssv == cur2->data.mssv)
		{
			cur2->data.name = curstu->stuudent.name;
			cur2->data.mssv = curstu->stuudent.mssv;
			cur2->data.PhoneNumber = curstu->stuudent.PhoneNumber;
			cur2->data.Password = curstu->stuudent.Password;
			cur2->data.userID = curstu->stuudent.userID;
			cur2->data.Mail = curstu->stuudent.Mail;
		}
		cur2 = cur2->next;
	}
	
	saveInfoStudent("UserData.csv", phead);
}
//-----------
bool CheckRightClassName(string classname)
{
	for (int i = 0; i < classname.length(); i++)
	{
		if (classname[i]>char(48) && classname[i]<char(122))
		{
			return false;
		}
	}
	if (classname.length() < 6)
		return false;
	return true;
}
void CheckAndSaveNewStudentToClass(string inputclass, Node3*&dhead, Node3*&curstu, Node*phead)
{
	if (CheckAllBeffSave(curstu)==true)
	{
		ofstream fout;
		string link = inputclass + ".csv";
		link = "Class/" + link;
		fout.open(link);
		Node3*cur = dhead;
		string befNO;
		while (cur->next != NULL)
		{
			fout << cur->stuudent.No << "," << cur->stuudent.mssv << "," << cur->stuudent.name << "," << cur->stuudent.PhoneNumber << "," << cur->stuudent.Mail << "," << cur->stuudent.userID << "," << cur->stuudent.Password << ",";
			befNO = cur->stuudent.No;
			cur = cur->next;
		}
		fout << endl;
		int k = atoi(befNO.c_str()) + 1;
		fout << k << "," << curstu->stuudent.mssv << "," << curstu->stuudent.name << "," << curstu->stuudent.PhoneNumber << "," << curstu->stuudent.Mail << "," << curstu->stuudent.userID << "," << curstu->stuudent.Password << ",";
		fout.close();
		saveInfoNewStudentInClass("UserData.csv", phead, inputclass, curstu);
		setcolor(58);
		DrawSmallBoxSpecial(33, 6);
		DrawSmallBox(40, 10);
		DrawSmallBox(40, 14);
		DrawSmallBox(40, 18);
		DrawSmallBox(9, 14);
		DrawSmallBox(9, 18);
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
		gotoxy(5, 4); cout << "[ SYSTAX: ALL RIGHT ]";
		setcolor(60);

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
		gotoxy(29, 22); cout << "[   SAVING SUCCESSFUL  ]";
		gotoxy(35, 24); cout << "   SAVED    ";
		setcolor(63);
		_getch();
	}
	else
	{

		setcolor(60);
		DrawSmallBoxSpecial(33, 6);
		DrawSmallBox(40, 10);
		DrawSmallBox(40, 14);
		DrawSmallBox(40, 18);
		DrawSmallBox(9, 14);
		DrawSmallBox(9, 18);
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
		setcolor(60);
		gotoxy(5, 4); cout << "[ PLS WRITE AGAIN ]";
		setcolor(60);

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
		setcolor(60);
		gotoxy(26, 22); cout << "[  CANNOT SAVE: WRONG SYNTAX  ]";
		gotoxy(33, 24); cout << "    CANT SAVE  ";
		setcolor(63);
		_getch();
	}
}
void saveInfoNewStudentInClass(char path[], Node*phead,string classname,Node3*&curstu)
{
	ofstream fout;
	fout.open(path);
	Node*cur = phead;
	string befNO;
	while (cur->next != NULL)
	{
		fout << cur->data.No << "," << cur->data.mssv << "," << cur->data.name << "," << cur->data.PhoneNumber << "," << cur->data.Mail << "," << cur->data.userID << "," << cur->data.Password << "," << cur->data.Class << ",";
		befNO = cur->data.No;
		cur = cur->next;
	}
	int k = atoi(befNO.c_str()) + 1;
	fout << endl;
	fout << k << "," << curstu->stuudent.mssv << "," << curstu->stuudent.name << "," << curstu->stuudent.PhoneNumber << "," << curstu->stuudent.Mail << "," << curstu->stuudent.userID << "," << curstu->stuudent.Password << "," << classname << ",";
	fout.close();
}
//---------------------------[Course]
void GetCourse(Node4*&listofcourse)
{
	listofcourse = new Node4;
	ifstream fin;
	string start1 = "", start2 = "", end1 = "", end2 = "", semeter = "", year1 = "", year2 = "", mon = "", tus = "", wed = "", thus = "", fri = "", sat = "", sun = "";
	fin.open("CoursesList.csv");
	getline(fin, listofcourse->data.No, ',');
	getline(fin, listofcourse->data.coursecode, ',');
	getline(fin, listofcourse->data.coursename, ',');
	getline(fin, listofcourse->data.lecture, ',');
	getline(fin, listofcourse->data.startdate.day, ',');
	getline(fin, listofcourse->data.startdate.month, ',');
	getline(fin, listofcourse->data.startdate.year, ',');
	getline(fin, listofcourse->data.enddate.day, ',');
	getline(fin, listofcourse->data.enddate.month, ',');
	getline(fin, listofcourse->data.enddate.year, ',');
	getline(fin, start1, ','); listofcourse->data.classtime.starthours = atoi(start1.c_str());
	getline(fin, start2, ','); listofcourse->data.classtime.startminute = atoi(start2.c_str());
	getline(fin, end1, ','); listofcourse->data.classtime.endhours = atoi(end1.c_str());
	getline(fin, end2, ','); listofcourse->data.classtime.endminute = atoi(end2.c_str());
	getline(fin, semeter, ','); listofcourse->data.semeter = atoi(semeter.c_str());
	getline(fin, year1, ','); listofcourse->data.courseyear.startyears = atoi(year1.c_str());
	getline(fin, year2, ','); listofcourse->data.courseyear.endyears = atoi(year2.c_str());
	getline(fin, mon, ','); listofcourse->data.dayinweek = atoi(mon.c_str());
	listofcourse->next == NULL;
	Node4*cur = listofcourse;
	while (!fin.eof())
	{
		cur->next = new Node4;
		cur = cur->next;
		start1 = "", start2 = "", end1 = "", end2 = "", semeter = "", year1 = "", year2 = "", mon = "", tus = "", wed = "", thus = "", fri = "", sat = "", sun = "";
		getline(fin, cur->data.No, ',');
		getline(fin, cur->data.coursecode, ',');
		getline(fin, cur->data.coursename, ',');
		getline(fin, cur->data.lecture, ',');
		getline(fin, cur->data.startdate.day, ',');
		getline(fin, cur->data.startdate.month, ',');
		getline(fin, cur->data.startdate.year, ',');
		getline(fin, cur->data.enddate.day, ',');
		getline(fin, cur->data.enddate.month, ',');
		getline(fin, cur->data.enddate.year, ',');
		getline(fin, start1, ','); cur->data.classtime.starthours = atoi(start1.c_str());
		getline(fin, start2, ','); cur->data.classtime.startminute = atoi(start2.c_str());
		getline(fin, end1, ','); cur->data.classtime.endhours = atoi(end1.c_str());
		getline(fin, end2, ','); cur->data.classtime.endminute = atoi(end2.c_str());
		getline(fin, semeter, ','); cur->data.semeter = atoi(semeter.c_str());
		getline(fin, year1, ','); cur->data.courseyear.startyears = atoi(year1.c_str());
		getline(fin, year2, ','); cur->data.courseyear.endyears = atoi(year2.c_str());
		getline(fin, mon, ','); cur->data.dayinweek = atoi(mon.c_str());
		cur->next = NULL;
	}
	fin.close();
}
void SaveCourse(Node4*listofcourse)
{
	ofstream fout;
	fout.open("CoursesList.csv");
	Node4*cur = listofcourse;

	while (cur->next != NULL)
	{
		fout << cur->data.No << "," << cur->data.coursecode << "," << cur->data.coursename << "," << cur->data.lecture << "," << cur->data.startdate.day << "," << cur->data.startdate.month << "," << cur->data.startdate.year << "," << cur->data.enddate.day << "," << cur->data.enddate.month << "," << cur->data.enddate.year << "," << cur->data.classtime.starthours << "," << cur->data.classtime.startminute << "," << cur->data.classtime.endhours << "," << cur->data.classtime.endminute << "," << cur->data.semeter << "," << cur->data.courseyear.startyears << "," << cur->data.courseyear.endyears <<"," << cur->data.dayinweek << ",";
		cur = cur->next;
	}
	fout.close();
}
//----------------------------[Check right for course]
string GetDayInWeek(int day)
{
	switch (day)
	{
	case(1):return"Monday";
	case(2):return"Tuesday";
	case(3):return"Wednesday";
	case(4):return"Thusday";
	case(5):return"Friday";
	case(6):return"Saturday";
	case(7):return"Sunday";
	default:
		return nullptr;
	}
}
void SaveNewCourse(Node4*listofcourse,Node4*curcourse)
{
	if (CheckAllCourseBeSave(curcourse) == true)
	{
		ofstream fout;
		fout.open("CoursesList.csv");
		Node4*cur = listofcourse;
		string  befNO;
		while (cur->next != NULL)
		{
			fout << cur->data.No << "," << cur->data.coursecode << "," << cur->data.coursename << "," << cur->data.lecture << "," << cur->data.startdate.day << "," << cur->data.startdate.month << "," << cur->data.startdate.year << "," << cur->data.enddate.day << "," << cur->data.enddate.month << "," << cur->data.enddate.year << "," << cur->data.classtime.starthours << "," << cur->data.classtime.startminute << "," << cur->data.classtime.endhours << "," << cur->data.classtime.endminute << "," << cur->data.semeter << "," << cur->data.courseyear.startyears << "," << cur->data.courseyear.endyears << "," << cur->data.dayinweek << ",";
			befNO = cur->data.No;
			cur = cur->next;
		}
		fout << endl;
		int k = atoi(befNO.c_str()) + 1;
		fout << k << "," << curcourse->data.coursecode << "," << curcourse->data.coursename << "," << curcourse->data.lecture << "," << curcourse->data.startdate.day << "," << curcourse->data.startdate.month << "," << curcourse->data.startdate.year << "," << curcourse->data.enddate.day << "," << curcourse->data.enddate.month << "," << curcourse->data.enddate.year << "," << curcourse->data.classtime.starthours << "," << curcourse->data.classtime.startminute << "," << curcourse->data.classtime.endhours << "," << curcourse->data.classtime.endminute << "," << curcourse->data.semeter << "," << curcourse->data.courseyear.startyears << "," << curcourse->data.courseyear.endyears << "," << curcourse->data.dayinweek << ",";
		fout.close();
		setcolor(58);
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
	
		gotoxy(26, 22); cout << "[  SUCCESS TO MAKE A COURSE  ]";
		gotoxy(35, 24); cout << "SAVE SUCCESS";

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

		gotoxy(20, 19); cout << ":";
		gotoxy(36, 19); cout << ":";
		gotoxy(13, 15); cout << "-";

		gotoxy(7, 13); cout << "[SCHOOL YEAR]";
		gotoxy(23, 13); cout << "[SEMESTER]";
		gotoxy(37, 13); cout << "[   STARTDAY   ]";
		gotoxy(57, 13); cout << "[    ENDDAY    ]";
		gotoxy(8, 7); cout << "COURSE:";
		gotoxy(31, 7); cout << "COURSE NAME:";
		gotoxy(8, 11); cout << "LECTURE:";
		gotoxy(7, 19); cout << "BEGIN AT:";
		gotoxy(25, 19); cout << "END AT:";
		gotoxy(41, 19); cout << "DAY of WEEK:";
		setcolor(63);
		_getch();
	}
	else
	{
		setcolor(60);
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

		gotoxy(26, 22); cout << "[  FAIL TO MAKE A COURSE  ]";
		gotoxy(35, 24); cout << "CANT - SAVE";

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

		gotoxy(20, 19); cout << ":";
		gotoxy(36, 19); cout << ":";
		gotoxy(13, 15); cout << "-";

		gotoxy(7, 13); cout << "[SCHOOL YEAR]";
		gotoxy(23, 13); cout << "[SEMESTER]";
		gotoxy(37, 13); cout << "[   STARTDAY   ]";
		gotoxy(57, 13); cout << "[    ENDDAY    ]";
		gotoxy(8, 7); cout << "COURSE:";
		gotoxy(31, 7); cout << "COURSE NAME:";
		gotoxy(8, 11); cout << "LECTURE:";
		gotoxy(7, 19); cout << "BEGIN AT:";
		gotoxy(25, 19); cout << "END AT:";
		gotoxy(41, 19); cout << "DAY of WEEK:";
		setcolor(63);
		_getch();
	}

}
//---------------------------[Schedule]
void GetSchedule(Node5*&schedulelist)
{
	ifstream fin;
	fin.open("ScheduleList.csv");
	if (!fin.is_open())
	{
		system("CLS"); cout << "ERROR CANT READ FILE"; system("pause"); exit(0);
	}
	schedulelist = new Node5;
	getline(fin, schedulelist->Scheduledata.No, ',');
	getline(fin, schedulelist->Scheduledata.classcode, ',');
	getline(fin, schedulelist->Scheduledata.MonMor1, ',');
	getline(fin, schedulelist->Scheduledata.MonMor2, ',');
	getline(fin, schedulelist->Scheduledata.MonAft1, ',');
	getline(fin, schedulelist->Scheduledata.MonAft2, ',');
	getline(fin, schedulelist->Scheduledata.TueMor1, ',');
	getline(fin, schedulelist->Scheduledata.TueMor2, ',');
	getline(fin, schedulelist->Scheduledata.TueAft1, ',');
	getline(fin, schedulelist->Scheduledata.TueAft2, ',');
	getline(fin, schedulelist->Scheduledata.WedMor1, ',');
	getline(fin, schedulelist->Scheduledata.WedMor2, ',');
	getline(fin, schedulelist->Scheduledata.WedAft1, ',');
	getline(fin, schedulelist->Scheduledata.WedAft2, ',');
	getline(fin, schedulelist->Scheduledata.ThuMor1, ',');
	getline(fin, schedulelist->Scheduledata.ThuMor2, ',');
	getline(fin, schedulelist->Scheduledata.ThuAft1, ',');
	getline(fin, schedulelist->Scheduledata.ThuAft2, ',');
	getline(fin, schedulelist->Scheduledata.FriMor1, ',');
	getline(fin, schedulelist->Scheduledata.FriMor2, ',');
	getline(fin, schedulelist->Scheduledata.FriAft1, ',');
	getline(fin, schedulelist->Scheduledata.FriAft2, ',');
	getline(fin, schedulelist->Scheduledata.SatMor1, ',');
	getline(fin, schedulelist->Scheduledata.SatMor2, ',');
	getline(fin, schedulelist->Scheduledata.SatAft1, ',');
	getline(fin, schedulelist->Scheduledata.SatAft2, ',');
	getline(fin, schedulelist->Scheduledata.SunMor1, ',');
	getline(fin, schedulelist->Scheduledata.SunMor2, ',');
	getline(fin, schedulelist->Scheduledata.SunAft1, ',');
	getline(fin, schedulelist->Scheduledata.SunAft2, ',');
	schedulelist->next = NULL;
	Node5*cur = schedulelist;
	while (!fin.eof())
	{
		cur->next = new Node5;
		cur = cur->next;
		getline(fin, cur->Scheduledata.No, ',');
		getline(fin, cur->Scheduledata.classcode, ',');
		getline(fin, cur->Scheduledata.MonMor1, ',');
		getline(fin, cur->Scheduledata.MonMor2, ',');
		getline(fin, cur->Scheduledata.MonAft1, ',');
		getline(fin, cur->Scheduledata.MonAft2, ',');
		getline(fin, cur->Scheduledata.TueMor1, ',');
		getline(fin, cur->Scheduledata.TueMor2, ',');
		getline(fin, cur->Scheduledata.TueAft1, ',');
		getline(fin, cur->Scheduledata.TueAft2, ',');
		getline(fin, cur->Scheduledata.WedMor1, ',');
		getline(fin, cur->Scheduledata.WedMor2, ',');
		getline(fin, cur->Scheduledata.WedAft1, ',');
		getline(fin, cur->Scheduledata.WedAft2, ',');
		getline(fin, cur->Scheduledata.ThuMor1, ',');
		getline(fin, cur->Scheduledata.ThuMor2, ',');
		getline(fin, cur->Scheduledata.ThuAft1, ',');
		getline(fin, cur->Scheduledata.ThuAft2, ',');
		getline(fin, cur->Scheduledata.FriMor1, ',');
		getline(fin, cur->Scheduledata.FriMor2, ',');
		getline(fin, cur->Scheduledata.FriAft1, ',');
		getline(fin, cur->Scheduledata.FriAft2, ',');
		getline(fin, cur->Scheduledata.SatMor1, ',');
		getline(fin, cur->Scheduledata.SatMor2, ',');
		getline(fin, cur->Scheduledata.SatAft1, ',');
		getline(fin, cur->Scheduledata.SatAft2, ',');
		getline(fin, cur->Scheduledata.SunMor1, ',');
		getline(fin, cur->Scheduledata.SunMor2, ',');
		getline(fin, cur->Scheduledata.SunAft1, ',');
		getline(fin, cur->Scheduledata.SunAft2, ',');
		cur->next = NULL;
	}
	fin.close();
}
void SaveSchedule(Node5*schedulelist)
{
	ofstream fout;
	fout.open("ScheduleList.csv");
	Node5*cur = schedulelist;

	while (cur->next != NULL)
	{
		fout << cur->Scheduledata.No << "," << cur->Scheduledata.classcode << ","
			<< cur->Scheduledata.MonMor1 << "," << cur->Scheduledata.MonMor2 << ","
			<< cur->Scheduledata.MonAft1 << "," << cur->Scheduledata.MonAft1 << ","
			<< cur->Scheduledata.TueMor1 << "," << cur->Scheduledata.TueMor2 << ","
			<< cur->Scheduledata.TueAft1 << "," << cur->Scheduledata.TueAft1 << ","
			<< cur->Scheduledata.WedMor1 << "," << cur->Scheduledata.WedMor2 << ","
			<< cur->Scheduledata.WedAft1 << "," << cur->Scheduledata.WedAft1 << ","
			<< cur->Scheduledata.ThuMor1 << "," << cur->Scheduledata.ThuMor2 << ","
			<< cur->Scheduledata.ThuAft1 << "," << cur->Scheduledata.ThuAft1 << ","
			<< cur->Scheduledata.FriMor1 << "," << cur->Scheduledata.FriMor2 << ","
			<< cur->Scheduledata.FriAft1 << "," << cur->Scheduledata.FriAft1 << ","
			<< cur->Scheduledata.SatMor1 << "," << cur->Scheduledata.SatMor2 << ","
			<< cur->Scheduledata.SatAft1 << "," << cur->Scheduledata.SatAft1 << ","
			<< cur->Scheduledata.SunMor1 << "," << cur->Scheduledata.SunMor2 << ","
			<< cur->Scheduledata.SunAft1 << "," << cur->Scheduledata.SunAft1 << ",";
		cur = cur->next;
	}
	fout.close();
}
bool CheckExitCourse(string course)
{
	Node4*listofcourse = NULL;
	GetCourse(listofcourse);
	Node4 *  cur = listofcourse;
	if (course == "")return true;
	while (cur->next != NULL)
	{
		if (cur->data.coursecode == course)return true;
		cur = cur->next;
	}
	return false;
}
void SaveNewSchedule(Node5*schedulelist,string classname)
{
	ofstream fout;
	fout.open("ScheduleList.csv");
	Node5*cur = schedulelist;
	string  befNO;
	while (cur->next != NULL)
	{
		fout << cur->Scheduledata.No << "," << cur->Scheduledata.classcode << ","
			<< cur->Scheduledata.MonMor1 << "," << cur->Scheduledata.MonMor2 << ","
			<< cur->Scheduledata.MonAft1 << "," << cur->Scheduledata.MonAft1 << ","
			<< cur->Scheduledata.TueMor1 << "," << cur->Scheduledata.TueMor2 << ","
			<< cur->Scheduledata.TueAft1 << "," << cur->Scheduledata.TueAft1 << ","
			<< cur->Scheduledata.WedMor1 << "," << cur->Scheduledata.WedMor2 << ","
			<< cur->Scheduledata.WedAft1 << "," << cur->Scheduledata.WedAft1 << ","
			<< cur->Scheduledata.ThuMor1 << "," << cur->Scheduledata.ThuMor2 << ","
			<< cur->Scheduledata.ThuAft1 << "," << cur->Scheduledata.ThuAft1 << ","
			<< cur->Scheduledata.FriMor1 << "," << cur->Scheduledata.FriMor2 << ","
			<< cur->Scheduledata.FriAft1 << "," << cur->Scheduledata.FriAft1 << ","
			<< cur->Scheduledata.SatMor1 << "," << cur->Scheduledata.SatMor2 << ","
			<< cur->Scheduledata.SatAft1 << "," << cur->Scheduledata.SatAft1 << ","
			<< cur->Scheduledata.SunMor1 << "," << cur->Scheduledata.SunMor2 << ","
			<< cur->Scheduledata.SunAft1 << "," << cur->Scheduledata.SunAft1 << ",";
		befNO = cur->Scheduledata.No;
		cur = cur->next;
	}
	int k = atoi(befNO.c_str()) + 1;
	fout << endl;
	fout << k << ',' << classname<<',';
	for (int i = 0; i <= 28; i++)
		fout << "EMPTY" << ',';
	fout.close();
}

