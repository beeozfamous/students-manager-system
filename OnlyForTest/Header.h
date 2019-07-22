#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
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
	string MSSV;
};
struct Date {
	string day;
	string month;
	string year;
};
struct ClassTime {
	int starthours;
	int startminute;
	int endhours;
	int endminute;
};
struct StudentYear {
	int startyears;
	int endyears;
};
struct coursedata {
	string coursecode;
	string coursename;
	string lecture;
	Date startdate;
	Date enddate;
	ClassTime classtime;
	bool dayaweek[6];
	StudentYear courseyear;
	int semeter;
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
	Schedule Sheduledata;
	Node5*next;
};
void GetClassList(Node2*&chead);
void showInfoStudent(Node*phead);
void getInfoStudent(char path[], Node *&phead);
void saveInfoStudent(char path[], Node*phead);
void GetCourse(Node4*&listofcourse);
void SaveCourse(Node4*listofcourse);
void GetShedule(Node5*&schedulelist);
void SaveSchedule(Node5*schedulelist);
