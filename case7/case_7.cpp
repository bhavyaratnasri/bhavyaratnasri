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
        out<<s.Name<<endl;

        return out;
}
istream& operator>>(istream &in,student &s)
{
        cout<<"Enter keyvalue";
        in>>s.sno;
        cout<<"Enter configaration";
        getchar();
 	 in.get(s.Name,30,'\n');
        return in;
}
/*function name:addconfig
return type:void
input parameter:set<student> &std
*/
void addconfig(set<student> &std)
{
        student s;
        set<student>:: iterator it;
        char option='y';
        while(option=='y')
        {
                ofstream outfile("notes.ini",ios::trunc|ios::out|ios::binary);
                cin>>s;
                std.insert(s);
                for(it=std.begin();it!=std.end();it++)
                        outfile.write((char*)&(*it),sizeof(s));
                cout<<"Do you want to append configaration(y/n)?";
                getchar();
                cin>>option;
        outfile.close();
        }
}
/*function name:deleteconfig
return type:void
input parameter:set<student> &std
*/
void deleteconfig(set<student> &std)
{
        int no;
        student s;
        set<student>:: iterator it;
        ofstream outfile("notes.ini",ios::trunc|ios::out|ios::binary);       
	cout<<"Enter the key for deleting the configaration from file";       
	cin>>no;
        for(it=std.begin();it!=std.end();it++)
        {
                s=*it;
                if(s.getsno()==no)
                        std.erase(it);
   }
        for(it=std.begin();it!=std.end();it++)
        outfile.write((char*)&(*it),sizeof(s));
    outfile.close();
}
/*function name:displayconfig
return type:void
*/

void displayconfig()
{
        student s;
        ifstream in("notes.ini",ios::in|ios::binary);
        while(1)
        {
                in.read((char*)&s,sizeof(s));
                if(in.eof())break;
                cout<<s;
        }
        in.close();
}
/*function name:serchupdateconfig
return type:void
input parameter:set<student> &std
*/
void searchupdateconfig(set<student> &std)
{
        int no;
        student s;
        set<student>:: iterator it;
        ofstream outfile("notes.ini",ios::trunc|ios::out|ios::binary);
        cout<<"Enter the rollno of student to update details in database";
        cin>>no;
        for(it=std.begin();it!=std.end();it++)
        {
                s=*it;
                if(s.getsno()==no)
                {
                        std.erase(it);
                        break;
                }
        }
        cout<<"Enter details to update";
        cin>>s;
        std.insert(s);
        cout<<"Updated"<<endl;
        for(it=std.begin();it!=std.end();it++)
        outfile.write((char*)&(*it),sizeof(s));
        outfile.close();
}
int main(int argc,char **argv)
{
	if(argc==2)
	{
	cout<<"programname.exe"<<endl;
	cout<<"this program is used add ,delete,update data to file"<<endl;
	}
	else
	{
	set<student> std;
	set<student>:: iterator it;
        student s;
        char option;
        addconfig(std);
        while(1)
        {
        cout<<"Select your option"<<endl<<" 1.add"<<endl<<" 2.delete"<<endl<<" 3.search"<<endl<<"4.display"<<endl<<"5.exit"<<endl;
        getchar();
        cin>>option;
        switch(option){
                case '1':
                        addconfig(std);
                        break;
                case '2':
                        deleteconfig(std);
                        break;
                case '3':
                        searchupdateconfig(std);
                        break;
                case '4':
                        displayconfig();
                        break;
		case '5':
			exit(0);
			break;
                default:
                        return 0;
        }
        }
	}

}
