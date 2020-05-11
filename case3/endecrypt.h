class encryptfile
{
	//eclaration of variables in private
	char charcter, specialchar, alphanum;
	char my_charcter[100], encryptstr[100];
public:
	//function dexclaration for encrypt data
	void encryptdata(char*, char*);
	//function declaration for reverseword
	void reverseword(char*,char *);
	//function declaration for decrypt 
	void decrypt(char*, char*);
	//function declaration for passkey
	void passkey(char*, char*);
};
