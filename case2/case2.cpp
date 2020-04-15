
/*Name of the program:finding the formula for given expression.
and write the program for Input.
filename:case2.cpp
date:08-04-2020
Author:M.Bhavya ratna sri
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
/*function name:square
input parameter:int
output parameter:int
*/
int 
square(int inum)
{
int iRes;
iRes=(inum*(inum+1)*(2*inum+1))/6;	//formula for given expression
return iRes;			//return sum;
}

int main(int argc,char**argv)
{
//this is for dispalying the usage of program
if(argc==2 && (strcmp(argv[1],"-h")==0))
{
cout<<"usage:case2.exe"<<endl;
cout<<"used for displaying sum of squares of given number"<<endl;
}
else 
{
  int IntValue,Intresult;
  if(IntValue>0)
  {
cout<<"Input:";
cin>>IntValue;
Intresult=square(IntValue);		//calling square function
cout<<"output:"<<iz<<endl;//for displaying output
  }
  else
  {
    cout<<"enter only positive numbers"<<endl;
  }
}   
}
