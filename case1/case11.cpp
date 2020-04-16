/*Name of the program:parse the command line and dispaly the output
filename:case11.cpp
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
int IntK;
for(IntK=0;sStr.length()==1;IntK++)
{
return true;
}
}
/*function name:check_number
return type :bool
input parameter:string
*/
bool check_number(string str)
{
int flag=0;
for(int pos=0;pos<str.length();pos++)
{
//condition for checking real no
if(str[pos]=='.')		
{
flag=1;
break;
}
}
//condition wheather the input sring is integer or float
if(flag)
cout<<"float"<< "\t"<<str<<"\t"<<sizeof(str)<<endl;
else
cout<<"int"<< "\t"<<str<<"\t"<<sizeof(str)<<endl;
}
//main usig command line arguments.
int main(int argc,char *argv[])
{
int INTG,INTJ;		//declaring integer variables
float FLOATH;		//declaring float variable
if(argc==2&&(strcmp(argv[1],"-h")==0))
{
cout<<"usage: case1.exe arg1 arg2 arg3 arg4(arguments can be int,float,char,sting)"<<endl;
cout<<"used for finding type and size of given argument"<<endl; 
}
else
{
cout<<"type"<<"\t"<<"value"<<"\t"<<"sizeof"<<endl;
for(INTG=1;INTG<argc;INTG++)
{
	INTJ=atoi(argv[INTG]);	//atoi convert ascii to string
   if(INTJ==0)
	{
		if(check(argv[INTG]))	//if condition satisfies means it will print char
		{
		cout<<"char";
		cout<<"\t"<<argv[INTG]<< "\t"<<strlen(argv[INTG])<<endl;
		}
		else		//it will print string
		{
		cout<<"string";
		cout<<"\t"<<argv[INTG]<< "\t"<<sizeof(argv[INTG])<<endl;
		}
	}
	else
	
		check_number(argv[INTG]);	//if condition  that stisfied means it will print int 
}
}
	return 0;
}

