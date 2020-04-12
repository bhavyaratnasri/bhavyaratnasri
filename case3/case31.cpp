/*Name of the program:this program expains you about storage clases
Author:M.bhavya ratna sri
filename:case31.cpp
date:09-04-2020
*/
#include<iostream>
using namespace std;
static int iS_g=10; /*gobal variable*/
int iEx;
class storage
{
public:
mutable int iM;		//mutable variable
int iN;
	//default constructor
 	storage()
	{
		iM=78;
		iN=45;
	}
};
/*function name:externstorage
return type:void
*/
//function definition externstorage
void externstorage()
{
extern int iEx;
	cout<<"the default value of extern variable:"<<iEx<<endl;
	iEx=9;
	cout<<"the modified value of exatern variable:"<<iEx<<endl;
}
/*function name:registerstorage
return type:void
*/
//function definition for staticstorage
void staticstorage()
{
 static int iB_s;
 
 cout<<"default value static storage class:"<<iB_s<<endl;
 static int iS_s=6; /*local static varaible*/	
 iS_s++;
 cout<<"enter the static value:";
 cout<<"the value local static variable:"<<iS_s<<endl;
 cout<<"the value global static variable:"<<iS_g<<endl;
}
/*function name:registerstorage
return type:void
*/
//function definition for registor storage
void registerstorage()
{
 register int iR;
 cout<<"default value register storage class:"<<iR<<endl;
 cout<<"enter registar value"<<endl;
 cin>>iR;
 cout<<"the value of register variable:"<<iR<<endl;
}
/*function name:autostorage
return type:void
*/
//function definition for autostorage
void 
autostorage()
{
	auto int iA;	//declaring auto storage class variable
 cout<<"default value auto storage class:"<<iA<<endl;
  cout<<"enter auto variable"<<endl;
  cin>>iA;
  cout<<"the value of auto avariable:"<<iA<<endl;
}
int main(int argc,char **argv)
{
const storage x;  //declaration of object for class storage
x.iM=678; 	  //accessing mutable storage class value
  if(argc==2)
	{
		cout<<"Usage:"<<endl;
		cout<<"./program.exe"<<endl;
		cout<<"This program gives understanding about all storage classes"<<endl;
	}
	else
	{
	autostorage();	//calling autostorage function
	registerstorage();	//calling registerstorage function
	
	staticstorage();	//calling staticstorage function
	staticstorage();	//calling staticstorage function
	externstorage();	//calling externstorage function
	cout<<"the value of mutable is:"<<x.iM<<endl;//dispalying mutable value.
	}
}	
