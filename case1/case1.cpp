/*Name of the program:parse the command line and dispaly the output
filename:case_1.cpp
date:07-04-2020
Author:M.Bhavya ratna sri
*/
#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
/*function name:check
input parameters:string
return type:bool
*/
//function to check length of string is '1' 0r not
bool 
check(string sStr)
{
int INTK;
for(INTK=0;sStr.length()==1;iNTK++)
{
return true;	//if the condition satisfifies it return '1'.
}
}
//main usig command line arguments.
int main(int argc,char *argv[])
{
int IntG,IntJ;		//declaring integer variables
float FloatH;		//declaring float variable
if(argc==2 && (strcmp(argv[1]=='-h')==1))
{
cout<<"usage: case1.exe arg1 arg2 arg3 arg4(arguments can be int,float,char,sting)"<<endl;
cout<<"used for finding type and size of given argument"<<endl; 
}
else 
{
cout<<"type"<<"\t"<<"value"<<"\t"<<"sizeof"<<endl;
for(IntG=1;IntG<argc;IntG++)
{
	IntJ=atoi(argv[IntG]);		//atoi convert ascii to int
	FloatH=atof(argv[IntG]);		//atof convert ascii to float
   if(IntJ==0)
	{
		if(check(argv[IntG]))	//if condition satisfies means it will print char
		{
		cout<<"char";
		cout<<"\t"<<argv[IntG]<< "\t"<<strlen(argv[IntG])<<endl;
		}
		else		//it will print string
		{
		cout<<"string";
		cout<<"\t"<<argv[IntG]<< "\t"<<sizeof(argv[IntG])<<endl;
		}
	}
	else
	{
		if(IntJ==IntH)	//if condition  that stisfied means it will print int 
		cout<<"int"<< "\t"<<IntJ<<"\t"<<sizeof(IntJ)<<endl;
		else		//else it will print float
		cout<<"float"<< "\t"<<FloatH<<"\t"<<sizeof(FloatH)<<endl;
	}
}
}
	return 0;
}

