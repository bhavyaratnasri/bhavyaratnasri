/*Nameofprogram:constructor  and destructor with virtual
filename:case5b.cpp
author:M.bhvya ratna sri
Date:11-04-2020
*/
#include<iostream>
using namespace std;
class teacher
{
	int x;
public:
	teacher()
	{
	cout<<"in teacher constructor"<<endl;
	}
	virtual ~teacher()
	{
	cout<<"In teacher desctrucyor:"<<endl;
	}
};
class student:public teacher
{
	public:
	student()
	{
	cout<<"student constructor"<<endl;
	}
	~student()

	{
	cout<<"student desctructor"<<endl;
	}
};
int main(int argc,char  **argv)
{
	 
    if(argc==2)
	{
	cout<<"usage: ./a.out"<<endl;
	cout<<"This program gives description of orderof constructor and destructors execution"<<endl;
	}
    else
	{
	//declaration of objects
	student *q=new student();
	    teacherr *p=q;
	    delete p;
	}
}
