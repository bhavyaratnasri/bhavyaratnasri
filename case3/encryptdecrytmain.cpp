/*Name of the file:this program is used to encrypt and decrypt the given file
Author:M.bhavya ratna sri
Date:10-05-2020
filename:encryptdecryptmain.cpp
*/
#include<iostream>
#include<cstring>
#include "endecrypt.h"
using namespace std;
int main(int argc, char** argv)
{
	//displaing usage
	if (argc == 2 && strcmp(argv[1], "-h") == 0)
	{
		cout << " -e -f [filename] -k [key]" << endl;
		cout << " -d -f [filename] -k [key]" << endl;
	}
	//if argument 	more than 2
	else if (argc > 2)
	{
		//creating object for the class
		encryptfile encryptfileobj;
		//declaring bool variable find
		bool find;
		if ((strcmp(argv[1], "-e") == 0) && (strcmp(argv[2], "-f") == 0) && (strcmp(argv[4], "-k") == 0))
		{
			find = encryptfileobj.encryptdata(argv[3], argv[5]);
			if (find == 1)
				cout << "encryptdata function executed" << endl;
			else
				cout << "encryptdata function not excuted" << endl;
		}
		else if ((strcmp(argv[1], "-e") == 0) && (strcmp(argv[2], "-k") == 0) && (strcmp(argv[4], "-f") == 0))
		{
			find = encryptfileobj.encryptdata(argv[5], argv[3]);
			if (find == 1)
				cout << "encryptdata function executed" << endl;
			else
				cout << "encryptdata function not excuted" << endl;
		}
		else if ((strcmp(argv[1], "-d") == 0) && (strcmp(argv[2], "-f") == 0) && (strcmp(argv[4], "-k") == 0))
		{
			find = encryptfileobj.passkey(argv[3], argv[5]);
			if (find == 1)
				cout << "passkey function executed" << endl;
			else
				cout << "passkey function not excuted" << endl;
		}
		else if ((strcmp(argv[1], "-d") == 0) && (strcmp(argv[2], "-k") == 0) && (strcmp(argv[4], "-f") == 0))
		{
			find = encryptfileobj.passkey(argv[5], argv[3]);
			if (find == 1)
				cout << "passkey function executed" << endl;
			else
				cout << "passkey function not excuted" << endl;
		}
		else
			cout << "wrong input" << endl;
	}
	else
		cout << "usage:-h" << endl;
}