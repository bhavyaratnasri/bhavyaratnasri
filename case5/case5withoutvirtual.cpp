/*Name of program:constructorand destructorwithoutvirtual
filename:case5withoutvirtual.cpp
Author:M.Bhavya Ratna sri
Date:11-04-2020
*/
#include<iostream>
using namespace std;
class vehicle
{
int iNoofwheels;
public:
	//default constructor
	vehicle()
	{
	cout<<"vehical class constructor"<<endl;
	}
	//parametrised constructor
	vehicle(int x)
	{
	cout<<"Inparametrised vehicle constructor"<<endl;
	iNoofwheels=x;
	}
	//default constructor
	~vehicle()
	{
	cout<<"vehicle class destructor"<<endl;
	}
};
inheritinf vehicle to car
class car:public vehicle
{
string iName;
public:
	car()
	{
	cout<<"car class constructor"<<endl;
	}
	car(string iName)
	{
	cout<<"In car class parametrised constructor"<<endl;
	this->iName=iName;
	}
	~car()
	{
	cout<<"car class destructor"<<endl;
	}
};
class bus:public vehicle
{
int Noofseats;
public:
	bus()
	{
	cout<<"bus class constructor"<<endl;
	}
	bus(int Noofseats)
	{
	cout<<"bus parrametrise constructor"<<endl;
	this->Noofseats=Noofseats;
	}
	~bus()
	{
	cout<<"Bus destructor"<<endl;
	}
};
int main(int argc,char **argv)
{
    if(argc==2)
	{
	cout<<"usage: ./a.out"<<endl;
	cout<<"This program gives description of orderof constructor and destructors execution"<<endl;
	}
	else
	{
	//declaration of objects
	vehicle vl(4);
	car cl("nano");
	car c2;
	bus bl(20);
	bus b2;
	}
}

	
