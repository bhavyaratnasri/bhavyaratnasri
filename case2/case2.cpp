
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
square(int in)
{
int iRes;
iRes=(in*(in+1)*(2*in+1))/6;	//formula for given expression
return iRes;			//return sum;
}

int main(int argc,char**argv)
{
int ik,iz;
//this is for dispalying the usage of program
if(argc==2)
{
cout<<"usage:./a.out"<<endl;
cout<<"used for displaying sum of squares of given number"<<endl;
}
else
{
cout<<"Input:";
cin>>ik;
iz=square(ik);		//calling square function
cout<<"output:"<<iz<<endl;	//for displaying output
}
}
