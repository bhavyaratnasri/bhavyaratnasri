/*Name of the file:this program is used to encrypt and decrypt the given file
Author:M.bhavya ratna sri
Date:10-05-2020
filename:encryptdecryptmain.cpp
*/
#include<iostream>
#include<cstring>
#include "endecrypt.h"
using namespace std;
int main(int argc, char* argv[])
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
//declaring bool variable
		bool find;
//declariaring string variables
		string filename, keyargument;
		for (int arg = 0; arg < argc; arg++)
		{
			if (strcmp(argv[arg], "-f") == 0)
				filename = argv[arg + 1];
			else  if (strcmp(argv[arg], "-k") == 0)
				keyargument = argv[arg + 1];
		}
		if (strcmp(argv[1], "-e") == 0)
		{
			find = encryptfileobj.encryptdata(filename, keyargument);
			if (find == 1)
				cout << "encryptdata function executed" << endl;
			else
				cout << "encryptdata function not  executed" << endl;
		}
		else if (strcmp(argv[1], "-d") == 0)
		{
			find = encryptfileobj.decryptdata(filename, keyargument);
			if (find == 1)
				cout << "decryptdata function executed" << endl;
			else
				cout << "decrypt data function not executed" << endl;
		}

	}
}
