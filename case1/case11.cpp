/*Name of the program:parse the command line and dispaly the output
filename:case11.cpp
date:07-04-2020
Author:M.Bhavya ratna sri
*/
#include<iostream>
#include<stdlib.h>
#include<typeinfo>
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
int iK;
for(iK=0;sStr.length()==1;iK++)
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
for(int i=0;i<str.length();i++)
{
//condition for checking real no
if(str[i]=='.')		
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
int iG,iJ;		//declaring integer variables
float fH;		//declaring float variable
if(argc==2)
{
cout<<"usage: ./program.exe arg1 arg2 arg3 arg4(arguments can be int,float,char,sting)"<<endl;
cout<<"used for finding type and size of given argument"<<endl; 
}
else
{
cout<<"type"<<"\t"<<"value"<<"\t"<<"sizeof"<<endl;
for(iG=1;iG<argc;iG++)
{
	iJ=atoi(argv[iG]);	//atoi convert ascii to string
   if(iJ==0)
	{
		if(check(argv[iG]))	//if condition satisfies means it will print char
		{
		cout<<"char";
		cout<<"\t"<<argv[iG]<< "\t"<<strlen(argv[iG])<<endl;
		}
		else		//it will print string
		{
		cout<<"string";
		cout<<"\t"<<argv[iG]<< "\t"<<sizeof(argv[iG])<<endl;
		}
	}
	else
	
		check_number(argv[iG]);	//if condition  that stisfied means it will print int 
}
}
	return 0;
}

