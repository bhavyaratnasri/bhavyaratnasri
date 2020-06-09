/*Name of the file:this program is used to encrypt and decrypt the given file
Author:M.bhavya ratna sri
Date:10-05-2020
filename:encryptdecrypt.cpp
*/
#include<iostream>
#include<fstream>
#include<string.h>
#include<algorithm>
#include "endecrypt.h"
using namespace std;
//defult constructor for initilising variables
encryptfile::encryptfile()
{
	cout << "defult constructor Invoked" << endl;
	charcter='\0';
	execute = NULL;
	strcpy(my_charcter,"\0");
}
/*function name:encryptdata
input parameter:char *,char *
return type:bool
*/
bool encryptfile::encryptdata(string inputfile, string key)
{
//creating ifstream object as finputfile
	ifstream finputfile(inputfile, ios::in);
//finding the inputfile is opened
	if (!finputfile)
	{
		cout << "error:opening input file" << endl;
		return 0;
	}

//creating ofstream object as foutputfile
	ofstream foutputfile("encryptedfile.txt");

//checking if the file is created or not
	if (!foutputfile)
	{
		cout << "error:opening output file" << endl;
	}
//logic for encrypting key
	for (int val = 0; key[val] != '\0'; val++)
	{
			key[val] = toupper(key[val]);
			foutputfile << key[val];
		
	}
	foutputfile << "\n";

//declaration of string variable
	string my_word;

//logic for encrypting the input finputfile 
//stream extraction operator for extracting words
		while (!finputfile.eof() && finputfile >> my_word)
		{
		//read charcter for file
			 finputfile.get(charcter);
			 replace(my_word.begin(), my_word.end(), '&', '^');
		//comparing character with space if space found
			  if (charcter == ' ')
		//replace space with special charecter		
					charcter = '&';
		//reverse is used to reverse exterct the word form stream extraction operator		
					reverse(my_word.begin(), my_word.end());
		//write the encrypted data in to the file		
					foutputfile << my_word;
		//write the encrypted charcter		
					foutputfile.put(charcter);
		}
	//closing finputfile
	finputfile.close();
	//closing foutputfile
	foutputfile.close();
	//function executes return 1
	return 1;
}
/*functioname:str_rev
	input parameters:char *
	output parameter:char *
*/
char* str_rev(char const* str) 
{ 
    // find length of string 
    int len = strlen(str); 
  
    // create dynamic pointer char array 
    char *rev = new char[len+1]; 
  
    // copy of string to ptr array 
    strcpy(rev, str); 
  
    // Swap character starting from two 
    // corners 
    for (int val=0, val1=len-1; val<val1; val++,val1--) 
        swap(rev[val], rev[val1]);        
      
    // return pointer of reversed string 
    return rev; 
} 
/*functioname:decrypt
	input parameters:char *,char*
	output parameter:bool
*/
bool encryptfile::decrypt()
{
	//creating ifstream object as finputfile	
	ifstream finputfile("encryptedfile.txt");
	//creating ofstream object as foutputfile
	ofstream foutputfile("decrypted.txt");
	//declaring int variables
	int value = 0, linecnt = 0;
	if (!finputfile)
	{
		cout << "error:opening input file" << endl;
		return 0;
	}
	string my_char;
	finputfile.getline(my_charcter, 100, '\n');
	while (finputfile.get(charcter))
	{
		//if any special charcer found or news line found repalce with null
		if (charcter == '&' || charcter == '\n')
		{
			my_charcter[value] = '\0';
			//reversing the charcter
				foutputfile << str_rev(my_charcter);
			//if enter alphanumerc charcter found replace with "space"
				if (charcter == '&')
					foutputfile << ' ';
				else
					foutputfile << charcter;
			value = 0;
		}
		else
			my_charcter[value++] = charcter;
	}
//closing finputfile
	finputfile.close();
//closing foutputfile
	foutputfile.close();
//if this function excutes correctly returns 1
	return 1;
}
/*functioname:decryptdata
	input parameters:string,string
	output parameter:bool
*/
bool encryptfile::decryptdata(string encryptedfile, string key)
{
	//creating ifstream object as finputfile		
	ifstream finputfile(encryptedfile, ios::in);
		if (!finputfile)
		{
			cout << "error:opening input file" << endl;
			return 0;
		}
	//declaration of encryptkey string  variable
		string encryptkey;
	//open the decrypted file
		if (getline(finputfile,encryptkey))
		{
		//logic for decrypting the key
			for (int val = 0; key[val] != '\0'; val++)
			{
				key[val] = toupper(key[val]);
			}
		//comparing encrypted ,decrypted key
			if (key.compare(encryptkey)==0)
			{
				execute = decrypt();
				if (execute == 1)
					cout << "decrypt function executed" << endl;
				else
					cout << "decrypt function not executed" << endl;
			}
			else
				cout << "key unmatched"<<endl;
	}
//closing finputfile
	finputfile.close();
//if this function excutes correctly returns 1
	return 1;
}
//destructor
encryptfile::~encryptfile()
{
	cout << "destructor" << endl;
}

