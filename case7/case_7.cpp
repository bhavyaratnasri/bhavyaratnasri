
/*Name of program:add,delete,display,serchupdate files in a program
filename:case7.cpp
Author:M.bhavya ratna sri
Date:07-04-2020
*/
#include<iostream>
#include<set>
#include<stdlib.h>
#include<iomanip>
#include<fstream>
using namespace std;
class student{
        int sno;
        char Name[50];
public:
	//friend fumction
        friend ostream& operator<<(ostream &,student &);
        friend istream& operator>>(istream &,student &);
        bool operator<(const student &s)const
        {
                return sno<s.sno;
        }
        bool operator==(const student &s)const
        {
                return sno==s.sno;
        }
        int getsno()
        {
                return sno;
        }
};
ostream& operator<<(ostream &out,student &s)
{
        out<<"serial no: "<<s.sno<<endl;
        out<<"Name: "<<s.Name<<endl;

        return out;
}
istream& operator>>(istream &in,student &s)
{
        cout<<"Enter Roll no:";
        in>>s.sno;
        cout<<"Enter Name";
        getchar();
 	 in.get(s.Name,30,'\n');
        return in;
}
/*function name:addconfig
return type:void
input parameter:set<student> &std
