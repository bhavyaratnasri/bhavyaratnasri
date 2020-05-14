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
	cout << "defult" << endl;
	charcter = NULL;
	alphanum = NULL;
	specialchar = NULL;
	strcpy_s(my_charcter, "\0");
	strcpy_s(encryptstr, "\0");
}
/*function name:encryptdata
input parameter:char *,char *
return type:void
*/
void encryptfile::encryptdata(char* inputfile, char* key)
{
	//	 filestream variables fin,fout
	fstream finputfile, foutputfile;
	//open the fin file	
	finputfile.open(inputfile, ios::in);
	if (!finputfile)
	{
		cout << "error:opening output file" << endl;
		return;
	}
	cout << "enter alphanumeric" << endl;
	cin >> specialchar;
	//open the encrypted file
	foutputfile.open("encryptedfile.txt", ios::out);
	//logic for encrypting key
	for (int val = 0; key[val] != '\0'; val++)
	{
		key[val] = toupper(key[val]);
		foutputfile << key[val];
	}
	foutputfile << "\n";
	//declaration of string variable
	string my_char;
	//  logic for encrypting the input fil 
	//stream extraction operator for extracting words
	while (!finputfile.eof() && finputfile >> my_char)
	{
		//read charcter for file
		finputfile.get(charcter);
		//comparing character with space if space found
		if (charcter == ' ')
			//replace space with special charecter		
			charcter = specialchar;
		//reverse is used to reverse exterct the word form stream extraction operator		
		reverse(my_char.begin(), my_char.end());
		//write the encrypted data in to the file		
		foutputfile << my_char;
		//write the encrypted charcter		
		foutputfile.put(charcter);
	}
	//close the input file			
	finputfile.close();
	//close the ouput file
	foutputfile.close();
}
/*functioname:decrypt
	input parameters:char *,char*
	output parameter:void
*/
void encryptfile::decrypt(char* filename, char* key)
{
	//	 filestream variables finputfile,foutputfile
	fstream finputfile, foutputfile;
	//open the finputfile file		
	finputfile.open("encryptedfile.txt", ios::in);
	//open the decrypted file
	foutputfile.open("decryptedfile.txt", ios::out);
	//declaring int variables
	int value = 0, linecnt = 0;

	if (!finputfile)
	{
		cout << "error:opening input file" << endl;
		return;
	}
	cout << "entera alphanumeric value" << endl;
	cin >> alphanum;
	if (finputfile.getline(my_charcter, 100, '\n'))
	{
		//	count no of lines 
		linecnt++;
	}
	while (finputfile.get(charcter))
	{
		//if any special charcer found or news line found repalce with null
		if (charcter == alphanum || charcter == '\n')
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


	//closeing in file		
	finputfile.close();
	//closing outfile
	foutputfile.close();
}
/*functioname:passkey
	input parameters:char *,char*
	output parameter:void
*/
void encryptfile::passkey(char* filename, char* key)
{
	//	 filestream variables finputfile,foutputfile
	fstream finputfile;
	//open the finputfile file		
	finputfile.open("encryptedfile.txt", ios::in);
	if (!finputfile)
	{
		cout << "error:opening input file" << endl;
		return;
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
			decrypt(filename, key);
		else
			cout << "key unmatched";
	}
	finputfile.close();
}
//destructor
encryptfile::~encryptfile()
{
	cout << "destructor";
}
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
		 if ((strcmp(argv[1], "-e") == 0) && (strcmp(argv[2], "-f") == 0) && (strcmp(argv[4], "-k") == 0))
		        encryptfileobj.encryptdata(argv[3], argv[5]);
		else if ((strcmp(argv[1], "-e") == 0) && (strcmp(argv[2], "-k") == 0) && (strcmp(argv[4], "-f") == 0))
		          encryptfileobj.encryptdata(argv[5], argv[3]); 
		else if ((strcmp(argv[1], "-d") == 0) && (strcmp(argv[2], "-f") == 0) && (strcmp(argv[4], "-k") == 0))
		       	   encryptfileobj.passkey(argv[3], argv[5]);
		else if ((strcmp(argv[1], "-d") == 0) && (strcmp(argv[2], "-k") == 0) && (strcmp(argv[4], "-f")==0))
			    encryptfileobj.passkey(argv[5], argv[3]);
		else
			cout << "wrong input" << endl;
	}
	else
		cout << "usage:-h" << endl;
}
