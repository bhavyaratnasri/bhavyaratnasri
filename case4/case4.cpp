/*Name of the program:purpose and difference in public,private
and protected accesspecifier
filename`:case4.cpp
date:09-04-2020
Author:M.Bhavya ratna sri
*/
#include<iostream>
#include<cstdlib>
using namespace std;
class person
{
protected:
	int iAge;
	string sName;
	string sGendar;
public:
//default constructor
	person();
//parametrised constructor
	person(int,string,string);
//destructor
	~person();
//display function 
	void display();
};
person::person()
{
	cout<<"In person default constructor:"<<endl;
	cout<<"enter age:"<<endl;
	cin>>iAge;
	cout<<"enter Name"<<endl;
	cin>>sName;
	cout<<"enter gendar"<<endl;
	cin>>sGendar;
}
person::person (int d,string n,string g)
{
	cout<<"In person parametrised constructor:"<<endl;
	iAge=d;
	sName=n;
	sGendar=g;
}
person::~person()
{
	cout<<"person destructor"<<endl;
}
void person::display()
{
	cout<<"age:"<<iAge<<endl;
	cout<<"name:"<<sName<<endl;
	cout<<"gendar:"<<sGendar<<endl;
}
class student:protected person
{
//declaration of variable in private
	string sId;
	float fPer;
	string sGrade;
	string Squal;
public:
//default constructor
	student();
//parametrised constructor
	student(int,string,string,string,string,float);
//destructor
	~student();
//student displayfunction
	void studentdisplay();
};
student::student()
{
	cout<<"In student default constructor:"<<endl;
	cout<<"enter student id:"<<endl;
	cin>>sId;
	cout<<"enter the qual:"<<endl;
	cin>>Squal;
	cout<<"enter percentade:"<<endl;
	cin>>fPer;
}
student::student(int a,string n,string g,string i,string q,float p):person(a,n,g)
{
cout<<"in student para cons:"<<endl;
	sId=i;
	Squal=q;
	fPer=p;
}
student::~student()
{

	cout<<"student destructor"<<endl;
}
//function definition of studentdisplay()
void student :: studentdisplay()
{
	cout<<"strudent display:"<<endl;
	person::display();
	cout<<"student id:"<<sId<<endl;
	cout<<"student qualification:"<<Squal<<endl;
	cout<<"student percentage:"<<fPer<<endl;
}
//commandline argumenys
int main(int argc,char **argv)
{
if(argc==2)
{
	cout<<"usage:./a.out"<<endl;
	cout<<"this program gives the usage of acces specifiers:"<<endl;
}
else
{
//declaration of objects for student and person class.
	person pobj;
	student sobj;
	cout<<"PersonDetails"<<endl;
	//acessing member functions.
	pobj.display();
	cout<<"student details"<<endl;
	sobj.studentdisplay();
}
}
