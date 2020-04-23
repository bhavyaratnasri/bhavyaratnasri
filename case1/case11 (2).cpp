/*Name of the program:parse the command line and dispaly the output
filename:case11.cpp
date:07-04-2020
Author:M.Bhavya ratna sri
*/
#include<iostream>
#include<math.h>
#include<sstream>
#include<cstring>
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
return type :void
input parameter:char *
*/
void check_number(char * str)
{
int iflag=0;
float fnum=0;
float frange=1e-12;
stringstream value(str);
if(value>>fnum)
{
iflag=(int)fnum;
if(fabs(fnum-iflag)/fnum>frange)
cout<<"float"<< "\t"<<str<<"\t"<<sizeof(str)<<endl;
else 
cout<<"int"<< "\t"<<str<<"\t"<<sizeof(str)<<endl;
}
else
{

		if(check(str))//if condition satisfies means it will print char
		{
		cout<<"char";
		cout<<"\t"<<str<< "\t"<<strlen(str)<<endl;
		}
		else		//it will print string
		{
		cout<<"string";
		cout<<"\t"<<str<< "\t"<<strlen(str)<<endl;
		}
}
}
//main usig command line arguments.
int main(int argc,char *argv[])
{
int IntG;
if(argc==2&&(strcmp(argv[1],"-h")==0))
{

cout<<"usage: ./program.exe arg1 arg2 arg3 arg4(arguments can be int,float,char,sting)"<<endl;
cout<<"used for finding type and size of given argument"<<endl; 
}
else if(argc>2)
{
cout<<"type"<<"\t"<<"value"<<"\t"<<"sizeof"<<endl;
for(IntG=1;IntG<argc;IntG++)
{
	
		check_number(argv[IntG]);	 
}
}
	return 0;
}

