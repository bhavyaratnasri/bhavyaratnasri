/*Name of the file:this program is used to encrypt and decrypt the given file
Author:M.bhavya ratna sri
Date:10-05-2020
filename:encryptdecrypt.cpp
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include "endecrypt.h"
using namespace std;
//defult constructor for initilising variables
encryptfile::encryptfile()
{
	cout << "defult constructor Invoked" << endl;
	charcter = NULL;
	alphanum = NULL;
	execute = NULL;
	strcpy_s(my_charcter, "\0");
	strcpy_s(encryptstr, "\0");
}
/*function name:encryptdata
input parameter:char *,char *
return type:bool
*/
bool encryptfile::encryptdata(char* inputfile, char* key)
{
	//creating ifstream object as finputfile
	ifstream finputfile(inputfile, ios::in);
	if (!finputfile)
	{
		cout << "error:opening output file" << endl;
		return 0;
	}
	if (!key)
	{
		cout << "error:key not found" << endl;
		return 0;
	}

	cout << "enter alphanumeric" << endl;
	cin >> alphanum;
	//creating ofstream object as foutput
	ofstream foutput("alphanum.txt");
	foutput << alphanum;
	//calling reversewords
	execute=reversewords(inputfile, key);
	if (execute == 1)
		cout << "reversewords function executed" << endl;
	else
		cout << "reverseword function not executed" << endl;
	//close finputfile
	return 1;
	finputfile.close();
	//close foutput
	foutput.close();
}
/*function name:reversewords
input parameter:char *,char *
return type:bool
*/
bool encryptfile::reversewords(char *inputfile,char *key)
{
	//creating ifstream object as finputfile
	ifstream finputfile(inputfile, ios::in);
	//creating ofstream object as foutputfile
	ofstream foutputfile("encryptedfile.txt", ios::out);
	if (!finputfile)
	{
		cout << "error:opening output file" << endl;
		return 0;
	}
	if (!key)
	{
		cout << "error:key not found" << endl;
		return 0;
	}
	//logic for encrypting key
	for (int val = 0; key[val] != '\0'; val++)
	{
		key[val] = toupper(key[val]);
		foutputfile << key[val];
	}
	foutputfile << "\n";
	//declaration of string variable
	string my_char;
	//  logic for encrypting the input finputfile 
	//stream extraction operator for extracting words
	while (!finputfile.eof() && finputfile >> my_char)
	{
		//read charcter for file
		finputfile.get(charcter);
		//comparing character with space if space found
		if (charcter == ' ')
			//replace space with special charecter		
			charcter = alphanum;
		//reverse is used to reverse exterct the word form stream extraction operator		
		reverse(my_char.begin(), my_char.end());
		//write the encrypted data in to the file		
		foutputfile << my_char;
		//write the encrypted charcter		
		foutputfile.put(charcter);
	}
	return 1;
	//close the input file			
	finputfile.close();
	//close the ouput file
	foutputfile.close();
}
	
/*functioname:decrypt
	input parameters:char *,char*
	output parameter:bool
*/
bool encryptfile::decrypt(char* filename, char* key)
{
	//creating ifstream object as finputfile	
	ifstream finputfile("encryptedfile.txt", ios::in);
	//creating ofstream object as foutputfile
	ofstream foutputfile("decryptedfile.txt", ios::out);
	//creating ifstream object as finput	
	ifstream finput("alphanum.txt");
	//declaring int variables
	int value = 0, linecnt = 0;
	if (finput.get(alphanum))
	if (!finputfile)
	{
		cout << "error:opening input file" << endl;
		return 0;
	}
	if (!key)
	{
		cout << "error:key not found" << endl;
		return 0;
	}
	if (finputfile.getline(my_charcter, 100, '\n'))
	while (finputfile.get(charcter))
	{
		//if any special charcer found or news line found repalce with null
		if (charcter ==alphanum || charcter == '\n')
		{
			my_charcter[value] = '\0';
			//reversing the charcter	
			foutputfile << _strrev(my_charcter);
			//if enter alphanumerc charcter found replace with "space"
			if (charcter == alphanum)
				foutputfile << ' ';
			else
				foutputfile << charcter;
			value = 0;
		}
		else
			my_charcter[value++] = charcter;
	}

	return 1;
	//closeing in file		
	finputfile.close();
	//closing outfile
	foutputfile.close();
}
/*functioname:passkey
	input parameters:char *,char*
	output parameter:bool
*/
bool encryptfile::passkey(char* filename, char* key)
{
	//creating ifstream object as finputfile		
	ifstream finputfile("encryptedfile.txt", ios::in);
	if (!finputfile)
	{
		cout << "error:opening input file" << endl;
		return 0;
	}
	if (!key)
	{
		cout << "error:key not found" << endl;
		return 0;
	}

	//open the decrypted file
	if (finputfile.getline(encryptstr, 100, '\n'))
	{
		//logic for decrypting the key
		for (int val = 0; key[val] != '\0'; val++)
		{
			key[val] = toupper(key[val]);
		}
		//comparing encrypted ,decrypted key
		if (strcmp(key, encryptstr) == 0)
		{
			execute = decrypt(filename, key);
			if (execute == 1)
				cout << "decrypt function executed" << endl;
			else
				cout << "decrypt function not executed" << endl;
		}
		else
			cout << "key unmatched";
	}
	return 1;
	finputfile.close();
}
//destructor
encryptfile::~encryptfile()
{
	cout << "destructor";
}
