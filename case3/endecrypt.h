#include<iostream>
using namespace std;
//encryptfile class contains datamembers,member variables constructors
class encryptfile
{
//declaration of variables in private
	char charcter;
	char my_charcter[100];
	bool execute;
//function declaration for decrypt 
	bool decrypt();
public:
//defult constructors
	encryptfile();		
//function dexclaration for encrypt data
	bool encryptdata(string, string);
//function declaration for passkey
	bool decryptdata(string, string);
//destructor
	~encryptfile();
};
