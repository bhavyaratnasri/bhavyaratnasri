//encryptfile class contains datamembers,member variables constructors
class encryptfile
{
//declaration of variables in private
	char charcter, alphanum;
	char my_charcter[100], encryptstr[100];
	bool execute;
//function declaration for decrypt 
	bool decrypt(char*, char*);
//function declaration for reversewords
	bool reversewords(char*, char*);
public:
//defult constructors
	encryptfile();		
//function dexclaration for encrypt data
	bool encryptdata(char*,char*);
//function declaration for passkey
	bool passkey(char*, char*);
//destructor
	~encryptfile();
};
