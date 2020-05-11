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
/*function name:encryptdata
input parameter:char *,char *
return type:void
*/
void encryptfile::encryptdata(char* inputfile,char *key)
{
	//	 filestream variables fin,fout
	fstream fin, fout;
	//open the fin file	
	fin.open(inputfile, ios::in);
	//open the out file	
	fout.open("encryptedfile.txt", ios::out);

	if (!fin)
	{
		cout << "error:opening output file" << endl;
		return;
	}
	cout << "enter alphanumeric" << endl;
	cin >> specialchar;
	//calling reverse function in c++
	reverseword(inputfile,key);
	//close the input file			
	fin.close();
	//close the ouput file
	fout.close();
}
/*functioname:reverseword
	input parameters:char *,char*
	output parameter:void
*/
void encryptfile::reverseword(char* inputfile,char *key)
{
	fstream fin, fout;
	//open the fin file	
	fin.open(inputfile, ios::in);
	//open the encrypted file
	fout.open("encryptedfile.txt", ios::out);
	//logic for encrypting key
	for (int val = 0; key[val] != '\0'; val++)
	{
		key[val] = toupper(key[val]);
		fout << key[val];
	}
	fout << "\n";
	//declaration of string variable
	string my_char;
	//  logic for encrypting the input fil 
	//stream extraction operator for extracting words
	while (!fin.eof() && fin >> my_char)
	{
		//read charcter for file
		fin.get(charcter);
		//comparing character with space if space found
		if (charcter == ' ')
			//replace space with special charecter		
			charcter = specialchar;
		//reverse is used to reverse exterct the word form stream extraction operator		
		reverse(my_char.begin(), my_char.end());
		//write the encrypted data in to the file		
		fout << my_char;
		//write the encrypted charcter		
		fout.put(charcter);
	}
	//close the input file			
	fin.close();
	//close the ouput file
	fout.close();
}
void encryptfile::decrypt(char* filename, char* key)
{
	//	 filestream variables fin,fout
	fstream fin, fout;
	//open the fin file		
	fin.open("encryptedfile.txt", ios::in);
	//open the decrypted file
	fout.open("decryptedfile.txt", ios::out);
	//declaring int variables
	int value = 0, linecnt = 0;

	if (!fin)
	{
		cout << "error:opening input file" << endl;
		return;
	}
	cout << "entera alphanumeric value" << endl;
	cin >> alphanum; 
	if (fin.getline(my_charcter, 100, '\n'))
	{
		//	count no of lines 
		linecnt++;
	}
		while (fin.get(charcter))
		{
				//if any special charcer found or news line found repalce with null
				if (charcter == alphanum || charcter == '\n')
				{
					my_charcter[value] = '\0';
					//reversing the charcter	
					fout << _strrev(my_charcter);
					//if enter alphanumerc charcter found replace with "space"
					if (charcter == alphanum)
						fout << ' ';
					else
						fout << charcter;
					value = 0;
				}
				else
					my_charcter[value++] = charcter;
			}
	

	//closeing in file		
	fin.close();
	//closing outfile
	fout.close();		
}

void encryptfile::passkey(char* filename, char* key)
{
	//	 filestream variables fin,fout
	fstream fin;
	//open the fin file		
	fin.open("encryptedfile.txt", ios::in);
	//open the decrypted file
	if (fin.getline(encryptstr, 100, '\n'))
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
	fin.close();
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
		encryptfile obj;
		if ((strcmp(argv[1], "-d") == 0) && (strcmp(argv[2], "-f") == 0) && (strcmp(argv[4], "-k") == 0))
			obj.passkey(argv[3], argv[5]);
		else if ((strcmp(argv[1], "-d") == 0) && (strcmp(argv[2], "-k") == 0) && (strcmp(argv[4], "-f") == 0))
			obj.passkey(argv[5], argv[3]);
		else if ((strcmp(argv[1], "-e") == 0) && (strcmp(argv[2], "-f") == 0) && (strcmp(argv[4], "-k") == 0))
			obj.encryptdata(argv[3], argv[5]);
		else if ((strcmp(argv[1], "-e") == 0) && (strcmp(argv[2], "-k") == 0) && (strcmp(argv[4], "-f") == 0))
			obj.encryptdata(argv[5], argv[3]);
		else
			cout << "wrong input" << endl;
	}
	else
		cout << "usage:-h" << endl;
}

