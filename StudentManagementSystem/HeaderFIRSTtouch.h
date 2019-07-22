#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <winsock.h>
#include <string>
#include <string.h>
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include <fstream>
using namespace std;
//--------------[LOAD-SAVE-DATA]
struct UserData {
	string No;
	string mssv;
	string name;
	string PhoneNumber;
	string Mail;
	string userID;
	string Password;
	string Class;
};
struct SIC {
	string No;
	string mssv;
	string name;
	string PhoneNumber;
	string Mail;
	string userID;
	string Password;
};
struct Node {
	UserData data;
	Node*next;
};
struct Node2 {
	Node2*next;
	string classname;
};
struct Node3 {
	Node3*next;
	SIC stuudent;
};
struct Date {
	string day = "";
	string month = "";
	string year = "";
};
struct ClassTime {
	int starthours=0;
	int startminute=0;
	int endhours=0;
	int endminute=0;
};
struct StudentYear {
	int startyears=0;
	int endyears=0;
};
struct coursedata {
	string coursecode="";
	string coursename = "";
	string lecture = "";
	Date startdate;
	Date enddate;
	ClassTime classtime;
	int dayinweek=0;
	StudentYear courseyear;
	int semeter=0;
	string No = "";
};
struct Node4 {
	coursedata data;
	Node4*next;
};
struct Schedule
{
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
};
struct Node5 {
	Schedule Scheduledata;
	Node5*next;
};
void showInfoStudent(Node*phead);
void getInfoStudent(char path[], Node *&phead);
void saveInfoStudent(char path[], Node*phead);
bool CheckUserNameAndPassWord(string username, string password, char path[], Node*&useraccessed, Node*&phead);
//--------------[LOGIN]
void HUBdraw();
void gotoxy(int column, int line);
void setcolor(int k);
void Menudraw();
void Skulldraw(int i);
void LoginBox();
void usernamebox(string &username);
void PasswordBox(string &password);
void enablePoint();
void disablePoint();
void MoveToUserUI(Node*AccessedUser,Node*&phead);
void EnterUserNameAndPassword(string &username, string &password, Node*AccessedUser, Node*&phead);
void mouseEvent1(MOUSE_EVENT_RECORD mouse);
void mouseEvent2(MOUSE_EVENT_RECORD mouse);
//--------------[User-UI]
void MenuUI(Node*AccessedUser, Node*&phead);
void DrawMenuUI(Node*AccessedUser, Node*&phead);
void DrawSelectionBox();
void FirstBox();
void SecondBox();
void ThirdBox();
void FourthBox();
void MouseDetectSelection(Node*AccessedUser, Node*&phead);
void Skulldraw2(int i, int k, int g);
void ShowStatus(string status);
void ShowingInfo(Node*AccessedUser);
//--------------[Profile-BOX]
void ProfileMouseDetect(Node*AccessedUser, Node*&phead);
void ProfileBox(Node*AccessedUser, Node*&phead);
void Draw2Box();
void ChangePasswordDraw();
void ChangePasswordOldBox(string &oldpassword);
void ChangePasswordNewBox(string &newpassword);
void ChangePasswordConfirmBox(string &newconfirmpassword);
void OldNewConfirm(Node*AccessedUser, Node*&phead);
//--------------[Search-Engine]
void DrawSearchBox();
void SearchEngine(Node*AccessedUser, Node*&phead);
void SearchEngineMouseDetect(Node*AccessedUser, Node*&phead);
void GetStudentID(string &MSSV);
void ShowingSearchingInfo(Node*AccessedUser);
void ShowTheResult(Node*phead);
//--------------[Course-Class]
void Draw3Box();
void box333(int y);
void StaffBox(int y);
void StaffTaskSelection(Node*AccessedUser, Node*&phead);
void StaffTask(Node*AccessUser, Node*&phead);
//--------------[Class-Student]
void ViewClassList(Node*AccessedUser, Node*&phead);
void View1BoxDraw();
void View2BoxDraw(string classname);
void DrawEnter1Box();
void DrawEnter2Box();
void ClearViewBox();
void ViewAndSearchMouseDetect(Node*AccessedUser, Node*&phead);
void ClassListScroll(Node*AccessedUser, Node*&phead, Node2*chead, Node2*&cur);
void ViewAndSearch(Node*AccessedUser, Node*&phead);
void GetClassNames(string &CLASSNAME);
void ShowFindedClass(Node*AccessedUser, Node*&phead);
void ShowNewClassClass(Node*AccessedUser, Node*&phead);
void GetNewsClassNames(string &CLASSNAME);
void SaveAClassToList(string newclass, Node2*chead);
//-----
void View2BoxDraw(string classname);
void ViewStudentList(Node*AccessedUser, Node*&phead, string classname);
void GetStudentList(Node3*&dhead, string inputclass);
void DrawEnter2Box();
void ViewAndSearch2(Node*AccessedUser, Node*&phead, string classname);
void ViewAndSearchMouseDetect2(Node*AccessedUser, Node*&phead, string classname);
void StudentListScroll(Node*AccessedUser, Node*&phead, Node3*dhead, Node3*&cur, string classname);
//-----
void GetStudentNames(string &studentname);
void ShowFindedStudent(Node*AccessedUser, Node*&phead, string classname);
//-----
void ClearView2();
void DrawStudentChangingSpace(string classname, Node3*& student);
void DrawSmallBox(int x, int y);
void DrawSmallBoxSpecial(int x, int y);
Node3 *GetInfoFromStudentID(string studentid, Node3*&dhead);
//--------------------[Check-Six-Box-Syntax]
bool CheckRightID(string id);
bool CheckRightNAME(string name);
bool CheckRightEmail(string mail);
bool CheckRightPhoneNumber(string phonenumber);
bool CheckRightUserName(string username);
bool CheckRightPassword(string password);
//---------------
void ChangeUserNameBox(string newname, Node*AccessedUser, Node*&phead, string classname, Node3*dhead, string studentid, Node3*&curstu);
void ChangeUserIDBox(string newid, Node*AccessedUser, Node*&phead, string classname, Node3*dhead, string studentid, Node3*&curstu);
void ChangeUserEmail(string email, Node*AccessedUser, Node*&phead, string classname, Node3*dhead, string studentid, Node3*&curstu);
void ChangeUserUserName(string newusername, Node*AccessedUser, Node*&phead, string classname, Node3*dhead, string studentid, Node3*&curstu);
void ChangeUserPhoneNumber(string phonenumber, Node*AccessedUser, Node*&phead, string classname, Node3*dhead, string studentid, Node3*&curstu);
void ChangeUserPassword(string password, Node*AccessedUser, Node*&phead, string classname, Node3*dhead, string studentid, Node3*&curstu);
void CheckAndSaveStudentInfomation(string inputclass, Node3*&dhead, Node3*&curstu, Node*&phead);
//----------------
void ViewToEditOrMakeNew(Node*AccessedUser, Node*&phead, string classname, Node3*dhead, string studentid);
void ViewToEditOrMakeNewMouseDetect(Node*AccessedUser, Node*&phead, string classname, Node3*dhead, string studentid, Node3*&curstu);
//----------------
bool CheckRightClassName(string classname);
//-----------------[Make new student in class]
void MakeNewUserNameBox( Node*AccessedUser, Node*&phead, string classname, Node3*dhead, Node3*&curstu);
void MakeNewUserIDBox( Node*AccessedUser, Node*&phead, string classname, Node3*dhead, Node3*&curstu);
void MakeNewUserEmail( Node*AccessedUser, Node*&phead, string classname, Node3*dhead, Node3*&curstu);
void MakeNewUserUserName( Node*AccessedUser, Node*&phead, string classname, Node3*dhead, Node3*&curstu);
void MakeNewUserPhoneNumber( Node*AccessedUser, Node*&phead, string classname, Node3*dhead, Node3*&curstu);
void MakeNewUserPassword( Node*AccessedUser, Node*&phead, string classname, Node3*dhead, Node3*&curstu);
//-----------
void CheckAndSaveNewStudentToClass(string inputclass, Node3*&dhead, Node3*&curstu, Node*phead);
void saveInfoNewStudentInClass(char path[], Node*phead, string classname, Node3*&curstu);
bool CheckAllBeffSave(Node3*&curstu);
void ViewToMakeNewMouseDetect(Node*AccessedUser, Node*&phead, string classname, Node3*dhead, Node3*&curstu);
void ViewToMakeNew(Node*AccessedUser, Node*&phead, string classname, Node3*dhead,Node3*&curstu);
//---------------------------[Courses-Selection]
void GetCourse(Node4*&listofcourse);
void SaveCourse(Node4*listofcourse);
void drawcoursesview();
void DrawMakeNewCourse(Node4*curcourse);
void GetCourseNames(string &Course);
void ShowFindedCourse(Node*AccessedUser, Node*&phead);
void CourseListScroll(Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&cur);
void ViewAndSearchMouseDetectForCourse(Node*AccessedUser, Node*&phead);
void ViewAndSearchCourse(Node*AccessedUser, Node*&phead);
Node4 *GetCourseFromlist(string course, Node4*&courselist);
string GetDayInWeek(int day);
void ViewToEditOrMakeNewCoursesMouseDetect(Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse);
void ChangeCourseCode(string CourseCode, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse);
void ChangeCourseName(string CourseName, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse);
void ChangeLecture(string Lecture, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse);
void ChangeCourseSchoolyearbegin(string schoolyearbegin, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse);
void ChangeCourseSchoolyearend(string schoolyearend, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse);
void ChangeCourseStartMonth(string startmonth, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse);
void ChangeCourseStartDay(string startday, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse);
void ChangeCourseStartYear(string startyear, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse);
void ChangeCourseEndMonth(string endmonth, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse);
void ChangeCourseEndDay(string endday, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse);
void ChangeCourseEndYear(string endyear, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse);
void ChangeCourseBeginHour(string beginhour, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse);
void ChangeCourseBeginMinute(string beginminute, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse);
void ChangeCourseEndHour(string endhour, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse);
void ChangeCourseEndMinute(string endminute, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse);
void ChangeCourseDayOfWeek(string dayofweek, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse);
void ChangeCourseSemester(string semester, Node*AccessedUser, Node*&phead, Node4*courselist, string course, Node4*&curcourse);
void ViewToEditOrMakeNewCourse(Node*AccessedUser, Node*&phead, Node4*courselist, string course);
void DrawSuperSmallBox(int x, int y);
void DrawSuperSmallBox2(int x, int y);
void DrawSuperSmallBox3(int x, int y);
void DrawSuperSmallBox4(int x, int y);
void DrawSuperSmallBox5(int x, int y);
void DrawSmallBoxSpecial2(int x, int y);
void DrawMDY(int x, int y);
void DrawTime(int x, int y);
void SaveNewCourse(Node4*listofcourse, Node4*curcourse);
void CheckAndSaveNewStudentToClass(string inputclass, Node3*&dhead, Node3*&curstu, Node*phead);
void ViewToMakeJustANewCourse(Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse);
void ViewToJustMakeNewCoursesMouseDetect(Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse);
void MakeNewCourseCode(string CourseCode, Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse);
void MakeNewCourseName(string CourseName, Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse);
void MakeNewLecture(string Lecture, Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse);
void MakeNewCourseSchoolyearbegin(string schoolyearbegin, Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse);
void MakeNewCourseSchoolyearend(string schoolyearend, Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse);
void MakeNewCourseStartMonth(string startmonth, Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse);
void MakeNewCourseStartDay(string startday, Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse);
void MakeNewCourseStartYear(string startyear, Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse);
void MakeNewCourseEndMonth(string endmonth, Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse);
void MakeNewCourseEndDay(string endday, Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse);
void MakeNewCourseEndYear(string endyear, Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse);
void MakeNewCourseBeginHour(string beginhour, Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse);
void MakeNewCourseBeginMinute(string beginminute, Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse);
void MakeNewCourseEndHour(string endhour, Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse);
void MakeNewCourseEndMinute(string endminute, Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse);
void MakeNewCourseDayOfWeek(string dayofweek, Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse);
void MakeNewCourseSemester(string semester, Node*AccessedUser, Node*&phead, Node4*courselist, Node4*&curcourse);
//-------------------------------------[Schedule]
void SaveSchedule(Node5*schedulelist);
void GetSchedule(Node5*&schedulelist);
void DrawMakeOrEditSchedule(Node5*curschedule,string classname);
void DrawSchedule();
void ViewsScheduleBoxDraw();
void ViewScheduleList(Node*AccessedUser, Node*&phead);
void GetScheduleNames(string &Schedule);
void ShowFindedSchedule(Node*AccessedUser, Node*&phead);
void ScheduleListScroll(Node*AccessedUser, Node*&phead, Node5*schedulelist, Node5*&cur);
void ViewAndSearchMouseDetectForSchedule(Node*AccessedUser, Node*&phead);
void ViewAndSearchSchedule(Node*AccessedUser, Node*&phead);
Node5 *GetScheduleFromlist(string classname, Node5*&schedulelist);
void ChangeASection(string changeone, Node*AccessedUser, Node*&phead, Node5*schedulelist, string classname, Node5*&curschedule, int x, int y);
bool CheckExitCourse(string course);
void ViewToEditOrMakeNewScheduleMouseDetect(Node*AccessedUser, Node*&phead, Node5*schedulelist, string classname, Node5*&curschedule);
void ViewToEditOrMakeNewSchedule(Node*AccessedUser, Node*&phead, Node5*schedulelist, string classname);
void GetClassList(Node2*&chead);
void GetNewsClassNamesFORSCHEDULE(string &CLASSNAME);
void ShowNewScheduleClass(Node*AccessedUser, Node*&phead, Node5*schedulelist);
void SaveNewSchedule(Node5*schedulelist, string classname);
void DrawEnter12Box();