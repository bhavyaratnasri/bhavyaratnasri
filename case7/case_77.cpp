/*Name of program: to perform list of operations addconfig,delete config,serch config,display string
filename:case_77.cpp
Author:m.bhavya ratna sri
date:16-4-2020
*/
#include<iostream>
#include<list>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class config{
    char Key[100];
    char Value[100];
public:

/*Function Name :setkey
  Parameters    :no parameter
  Return Type   :no return type
  */

    void setkey()
    {
        cout<<"Enter key:";
        getchar();
        cin.get(Key,100,'\n');
    }

/*Function Name :setvalue
  Parameters    :no parameter
  Return Type   :no return type
  */

    void setvalue()
    {
        cout<<"Enter value:";
        getchar();
        cin.get(Value,100,'\n');
    }

/*Function Name :putkey
  Parameters    :no parameter
  Return Type   :char return type
  */

    char* putkey()
    {
        return Key;
    }

/*Function Name :putvalue
  Parameters    :no parameter
  Return Type   :string return type
  */

    char* putvalue()
    {
        return Value;
    }
};

/*Function Name :removefile
  Parameters    :no parameter
  Return Type   :no return type
  */

void removefile()
{
    config c;
    int Count=0;
    ifstream infile("notes.ini",ios::in);
    while(1)
    {
        //reading the contents in file
        infile.read((char*)&c,sizeof(c));
        Count++;
        //checking for end of file
        if(infile.eof())break;
    }
    if(Count==0)
    {
        cout<<"file is deleted"<<endl;
        //to remove file
        remove("notes.ini");
    }
}

/*Function Name :searchupdateconfig
  Parameters    :list object
  Return Type   :void return type
  */

void searchupdateconfig(list<config> &std)
{
    config c;
   char ckey[1000];
    list<config>:: iterator Itr;
    ofstream outfile("notes.ini",ios::trunc|ios::out);
    cout<<"Enter the key to update:";
    getchar();
    cin.get(ckey,1000,'\n');
    for(Itr=std.begin();Itr!=std.end();++Itr)
    {
        c=*Itr;
        if(strcmp(c.putkey(),ckey)==0)
        {
            //the value is been deleted
            std.erase(Itr);
            cout<<"Enter value to update"<<endl;
            c.setvalue();
	    cout<<"updated"<<endl;
            //the new value is pushed into file
            std.push_front(c);
	
	}
    }
    for(Itr=std.begin();Itr!=std.end();Itr++)
    {
        c=*Itr;
            outfile<<c.putkey()<<"="<<c.putvalue()<<"\n";
        //the file again written with updated values
    }
    outfile.close();
}
/*Function Name :addconfig
  Parameters    :one list object parameter
  Return Type   :no return type*/

void addconfig(list<config> &std)
{
    config c;
    list<config>:: iterator Itr;
    char option='y';
    while(option=='y' || option=='Y')
    {
        ofstream outfile("notes.ini",ios::trunc|ios::out);
        c.setkey();
            c.setvalue();
            std.push_back(c);
            for(Itr=std.begin();Itr!=std.end();Itr++)
            {
                c=*Itr;
                outfile<<c.putkey()<<"="<<c.putvalue()<<endl;
            }
      
        cout<<"Do you want to append configaration data(y/n)?";
        cin>>option;
        outfile.close();
    }
}

/*Function Name :deleteconfig
  Parameters    :one list object parameter
  Return Type   :no return type
  */

void deleteconfig(list<config> &std)
{
    char ckey[100];
    config cn;
    list<config>:: iterator it;
    ofstream outfile("notes.ini",ios::trunc|ios::out);
    cout<<"Enter the key to delete:";
    getchar();
    cin.get(ckey,100,'\n');
    
    for(it=std.begin();it!=std.end();it++)
    {
        	cn=*it;
        if((strcmp(cn.putkey(),ckey)==0))
        {
            std.erase(it);
	    cout<<"deleted"<<endl;
		break;
        }
    }
   removefile();
    for(it=std.begin();it!=std.end();it++)
	{
		cn=*it;
            outfile<<cn.putkey()<<"="<<cn.putvalue()<<"\n";
	}
    outfile.close();
}
/*Function Name :displayconfig
  Parameters    :no parameter
  Return Type   :no return type
  */

void displayconfig()
{
    config cg;
    ifstream infile("notes.ini",ios::in);
    char info[100];
    while(!infile.eof())
    {
        infile.getline(info,100);
        cout<<info<<endl;
    }
}
/*Function Name :searchconfigaration
  Parameters    :one list object parameter
  Return Type   :no return type
  */

void searchconfig(list<config> &std)
{
    config ch;
    char option;
    char Searchkey[500];
    char Searchvalue[100];
    list<config>:: iterator iTR;
    ifstream infile("notes.ini",ios::in);
    cout<<"do u want search key or value(k/v):";
    cin>>option;
    if(option=='k'||option=='K')
    {
        cout<<"Enter key u want to search:";
        getchar();
        cin.get(Searchkey,500,'\n');
        for(iTR=std.begin();iTR!=std.end();iTR++)
        {
            ch=*iTR;
            if(strcmp(Searchkey,ch.putkey())==0)
                cout<<ch.putkey()<<"="<<ch.putvalue()<<endl;
        }
    }
    else if(option=='v'||option =='V')
    {
        cout<<"Enter value u want to search:";
        getchar();
        cin.get(Searchvalue,100,'\n');
        for(iTR=std.begin();iTR!=std.end();iTR++)
        {
            ch=*iTR;
            if(strcmp(Searchvalue,ch.putvalue())==0)
                cout<<ch.putkey()<<"="<<ch.putvalue()<<endl;
        }
    }
    else

        cout<<"Enter k or v"<<endl;
}
int main(int argc,char* argv[])
{
    if(argc==2)
    {
        if(strcmp(argv[1],"-h")==0)
        {
	    cout<<"usage:  caselist.exe"<<endl;
            cout<<"select required option"<<endl;
        }
    }
    else
    {
        list<config> std;
        list<config>:: iterator Itr;
        char Opt;
        while(1)
        {
            cout<<"Select your option:"<<endl<<" 1.add"<<endl<<" 2.delete"<<endl<<" 3.display"<<endl<<" 4.serchupdate"<<endl<<" 5.serch"<<endl<<" 6.exit"<<endl;
            cin>>Opt;
            switch(Opt)
            {
                case '1':
                        addconfig(std);
                        break;
                case '2':
                        deleteconfig(std);
                        break;
                case '3':
                        displayconfig();
                        break;
			case '4':
				   searchupdateconfig(std);
					break;
		     case '5':
			         searchconfig(std);
			         break;
		     case '6':
			         exit(0);
			         break;
                default:
                        return 0;
            }
        }
    }
return 0;
}
