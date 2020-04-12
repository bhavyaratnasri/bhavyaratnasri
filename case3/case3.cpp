/*Name of the program:this program expains you the variablescope
Author:M.bhavya ratna sri
filename:global.cpp
date:07-04-2020
*/
#include<iostream>
using namespace std;
int iL_g=6,iK_g=7;	//global variable declaration
void Fun1();	//Func1 declaratin 
void Fun2();	//Func2 declaration
void Modifiertype();  //Modifiertype function declaration
int main(int argc,char **argv )
{
if(argc==2)
cout<<"usage:./program.exe"<<endl;
	else
	{
		int iJ,il_g;
		cout<<"enter the values of int"<<endl;
		cin>>iJ>>il_g;
		cout<<"The value of within main are:"<<"\t"<<iJ<<"\t"<<il_g<<endl;
		Fun1();	//calling  Fun1
		Fun2();	//calling  Fun2
		Modifiertype();	//calling modifier type
	}
}
/*
function name:Fun1
input parameter:0
return type:void
*/
void Fun1()
{
cout<<"Funct1 used for displaying global variable:"<<iL_g<<"\t"<<iK_g<<endl;
}
/*
function name:Fun2
input parameter:0
return type:void
*/
void Fun2()
{
int iK=2;
int il_g=5;
cout<<"Funct2 used for displaying values within functions:"<<il_g<<"\t"<<iK<<endl;
}
/*function name:Modifiertype
input parameter:0
return type: void
*/
void Modifiertype()
{
	
	unsigned short int usival;
 	short int sivl,sik;
	unsigned long int ulik;
	long int lig;
	cout<<"enter the values (usival,sivl,sik,ulik,lig)"<<endl;
	cin>>usival>>sik>>ulik>>lig;
	sivl=usival;
	
	cout<<"the value of int are(unsignedshort&short):"<<usival<<" "<<sivl<<" "<<sik<<endl;
	cout<<"the value of int are(unsigned long & long):"<<" "<<ulik<<" "<<lig<<endl;
}
