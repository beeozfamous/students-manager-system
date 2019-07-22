#include"Header.h"
void getInfoStudent(char path[], Node *&phead)
{
	phead = new Node;
	ifstream fin;
	string tempname, tempmssv, tempnumber,tempphonenumber,tempmail,tempuserid,temppass,tempclass,check;
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
			getline(fin, tempclass,',');
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
void saveInfoStudent( char path[],Node*phead)
{
	ofstream fout;
	fout.open(path);
	Node*cur = phead;
	while (cur->next != NULL)
	{

		fout << cur->data.No << "," << cur->data.mssv << "," << cur->data.name << "," << cur->data.PhoneNumber << "," << cur->data.Mail << "," << cur->data.userID <<","<< cur->data.Password << "," << cur->data.Class << ","<<endl;
		cur = cur->next;
	}
	fout.close();
}
void BuyingGift()
{
	cout << "Pls enter the amount of these item:";
	int amo;
	cin >> amo;
	cout << endl;
	cout << "Pls enter the cost od each item";
	int a[100];
	for (int i = 0; i < amo; i++)
	{
		cout << "item[" << i << "]=";
		cin >> a[i];
		cout << endl;
	}
	
}
void GetGift(int a[], int amo)
{
	
}

void GetCourse(Node4*&listofcourse)
{
	listofcourse = new Node4;
	ifstream fin;
	string start1="", start2 = "", end1 = "", end2 = "",semeter = "",year1 = "",year2 = "",mon = "",tus = "",wed = "",thus = "",fri = "",sat = "",sun = "";
	fin.open("CoursesList.csv");
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
	getline(fin, semeter, ',');listofcourse->data.semeter= atoi(semeter.c_str());
	getline(fin, year1, ',');listofcourse->data.courseyear.startyears= atoi(year1.c_str());
	getline(fin, year2, ','); listofcourse->data.courseyear.endyears = atoi(year2.c_str());
	getline(fin, mon, ','); listofcourse->data.dayaweek[0] = atoi(mon.c_str());
	getline(fin, tus, ','); listofcourse->data.dayaweek[1] = atoi(tus.c_str());
	getline(fin, wed, ','); listofcourse->data.dayaweek[2] = atoi(wed.c_str());
	getline(fin, thus, ','); listofcourse->data.dayaweek[3] = atoi(thus.c_str());
	getline(fin, fri, ','); listofcourse->data.dayaweek[4] = atoi(fri.c_str());
	getline(fin, sat, ','); listofcourse->data.dayaweek[5] = atoi(sat.c_str());
	getline(fin, sun, ','); listofcourse->data.dayaweek[6] = atoi(sun.c_str());
	listofcourse->next == NULL;
	Node4*cur = listofcourse;
	while (!fin.eof())
	{
		cur->next = new Node4;
		cur = cur->next;
		start1 = "", start2 = "", end1 = "", end2 = "", semeter = "", year1 = "", year2 = "", mon = "", tus = "", wed = "", thus = "", fri = "", sat = "", sun = "";
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
		getline(fin, mon, ','); cur->data.dayaweek[0] = atoi(mon.c_str());
		getline(fin, tus, ','); cur->data.dayaweek[1] = atoi(tus.c_str());
		getline(fin, wed, ','); cur->data.dayaweek[2] = atoi(wed.c_str());
		getline(fin, thus, ','); cur->data.dayaweek[3] = atoi(thus.c_str());
		getline(fin, fri, ','); cur->data.dayaweek[4] = atoi(fri.c_str());
		getline(fin, sat, ','); cur->data.dayaweek[5] = atoi(sat.c_str());
		getline(fin, sun, ','); cur->data.dayaweek[6] = atoi(sun.c_str());
		cur->next = NULL;
	}
	fin.close();
}
void SaveCourse(Node4*listofcourse)
{
	ofstream fout;
	fout.open("CoursesList2.csv");
	Node4*cur = listofcourse;
	while (cur->next != NULL)
	{
		fout << cur->data.coursecode << "," << cur->data.coursename << "," << cur->data.startdate.day << "," << cur->data.startdate.month << "," << cur->data.startdate.year << "," << cur->data.enddate.day << "," << cur->data.enddate.month << "," << cur->data.enddate.year << "," << cur->data.classtime.starthours << "," << cur->data.classtime.startminute << "," << cur->data.classtime.endhours << "," << cur->data.classtime.endminute << "," << cur->data.semeter << "," << cur->data.courseyear.startyears << "," << cur->data.courseyear.endyears << "," << cur->data.dayaweek[0] << "," << cur->data.dayaweek[1] << "," << cur->data.dayaweek[2] << "," << cur->data.dayaweek[3] << "," << cur->data.dayaweek[4] << "," << cur->data.dayaweek[5] << "," << cur->data.dayaweek[6]<<",";
		cur = cur->next;
	}
	fout.close();
}
//---------------------------[Shedule]
void GetShedule(Node5*&schedulelist)
{
	ifstream fin;
	fin.open("ScheduleList.csv");
	if (!fin.is_open())
	{
		system("CLS"); cout << "ERROR CANT READ FILE"; system("pause"); exit(0);
	}
	schedulelist = new Node5;
	getline(fin, schedulelist->Sheduledata.No, ',');
	getline(fin, schedulelist->Sheduledata.classcode, ',');
	getline(fin, schedulelist->Sheduledata.MonMor1, ',');
	getline(fin, schedulelist->Sheduledata.MonMor2, ',');
	getline(fin, schedulelist->Sheduledata.MonAft1, ',');
	getline(fin, schedulelist->Sheduledata.MonAft2, ',');
	getline(fin, schedulelist->Sheduledata.TueMor1, ',');
	getline(fin, schedulelist->Sheduledata.TueMor2, ',');
	getline(fin, schedulelist->Sheduledata.TueAft1, ',');
	getline(fin, schedulelist->Sheduledata.TueAft2, ',');
	getline(fin, schedulelist->Sheduledata.WedMor1, ',');
	getline(fin, schedulelist->Sheduledata.WedMor2, ',');
	getline(fin, schedulelist->Sheduledata.WedAft1, ',');
	getline(fin, schedulelist->Sheduledata.WedAft2, ',');
	getline(fin, schedulelist->Sheduledata.ThuMor1, ',');
	getline(fin, schedulelist->Sheduledata.ThuMor2, ',');
	getline(fin, schedulelist->Sheduledata.ThuAft1, ',');
	getline(fin, schedulelist->Sheduledata.ThuAft2, ',');
	getline(fin, schedulelist->Sheduledata.FriMor1, ',');
	getline(fin, schedulelist->Sheduledata.FriMor2, ',');
	getline(fin, schedulelist->Sheduledata.FriAft1, ',');
	getline(fin, schedulelist->Sheduledata.FriAft2, ',');
	getline(fin, schedulelist->Sheduledata.SatMor1, ',');
	getline(fin, schedulelist->Sheduledata.SatMor2, ',');
	getline(fin, schedulelist->Sheduledata.SatAft1, ',');
	getline(fin, schedulelist->Sheduledata.SatAft2, ',');
	getline(fin, schedulelist->Sheduledata.SunMor1, ',');
	getline(fin, schedulelist->Sheduledata.SunMor2, ',');
	getline(fin, schedulelist->Sheduledata.SunAft1, ',');
	getline(fin, schedulelist->Sheduledata.SunAft2, ',');
	schedulelist->next = NULL;
	Node5*cur = schedulelist;
	while (!fin.eof())
	{
		cur->next = new Node5;
		cur = cur->next;
		getline(fin, cur->Sheduledata.No, ',');
		getline(fin, cur->Sheduledata.classcode, ',');
		getline(fin, cur->Sheduledata.MonMor1, ',');
		getline(fin, cur->Sheduledata.MonMor2, ',');
		getline(fin, cur->Sheduledata.MonAft1, ',');
		getline(fin, cur->Sheduledata.MonAft2, ',');
		getline(fin, cur->Sheduledata.TueMor1, ',');
		getline(fin, cur->Sheduledata.TueMor2, ',');
		getline(fin, cur->Sheduledata.TueAft1, ',');
		getline(fin, cur->Sheduledata.TueAft2, ',');
		getline(fin, cur->Sheduledata.WedMor1, ',');
		getline(fin, cur->Sheduledata.WedMor2, ',');
		getline(fin, cur->Sheduledata.WedAft1, ',');
		getline(fin, cur->Sheduledata.WedAft2, ',');
		getline(fin, cur->Sheduledata.ThuMor1, ',');
		getline(fin, cur->Sheduledata.ThuMor2, ',');
		getline(fin, cur->Sheduledata.ThuAft1, ',');
		getline(fin, cur->Sheduledata.ThuAft2, ',');
		getline(fin, cur->Sheduledata.FriMor1, ',');
		getline(fin, cur->Sheduledata.FriMor2, ',');
		getline(fin, cur->Sheduledata.FriAft1, ',');
		getline(fin, cur->Sheduledata.FriAft2, ',');
		getline(fin, cur->Sheduledata.SatMor1, ',');
		getline(fin, cur->Sheduledata.SatMor2, ',');
		getline(fin, cur->Sheduledata.SatAft1, ',');
		getline(fin, cur->Sheduledata.SatAft2, ',');
		getline(fin, cur->Sheduledata.SunMor1, ',');
		getline(fin, cur->Sheduledata.SunMor2, ',');
		getline(fin, cur->Sheduledata.SunAft1, ',');
		getline(fin, cur->Sheduledata.SunAft2, ',');
		cur->next = NULL;
	}
	fin.close();
}
void SaveSchedule(Node5*schedulelist)
{
	ofstream fout;
	fout.open("ScheduleList2.csv");
	Node5*cur = schedulelist;

	while (cur->next != NULL)
	{
		fout << cur->Sheduledata.No << "," << cur->Sheduledata.classcode << ","
			<< cur->Sheduledata.MonMor1 << "," << cur->Sheduledata.MonMor2 << ","
			<< cur->Sheduledata.MonAft1 << "," << cur->Sheduledata.MonAft1 << ","
			<< cur->Sheduledata.TueMor1 << "," << cur->Sheduledata.TueMor2 << ","
			<< cur->Sheduledata.TueAft1 << "," << cur->Sheduledata.TueAft1 << ","
			<< cur->Sheduledata.WedMor1 << "," << cur->Sheduledata.WedMor2 << ","
			<< cur->Sheduledata.WedAft1 << "," << cur->Sheduledata.WedAft1 << ","
			<< cur->Sheduledata.ThuMor1 << "," << cur->Sheduledata.ThuMor2 << ","
			<< cur->Sheduledata.ThuAft1 << "," << cur->Sheduledata.ThuAft1 << ","
			<< cur->Sheduledata.FriMor1 << "," << cur->Sheduledata.FriMor2 << ","
			<< cur->Sheduledata.FriAft1 << "," << cur->Sheduledata.FriAft1 << ","
			<< cur->Sheduledata.SatMor1 << "," << cur->Sheduledata.SatMor2 << ","
			<< cur->Sheduledata.SatAft1 << "," << cur->Sheduledata.SatAft1 << ","
			<< cur->Sheduledata.SunMor1 << "," << cur->Sheduledata.SunMor2 << ","
			<< cur->Sheduledata.SunAft1 << "," << cur->Sheduledata.SunAft1 << ",";
		cur = cur->next;
	}
	fout.close();
}
