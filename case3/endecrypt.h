//encryptfile class contains datamembers,member variables constructors
class encryptfile
{
//declaration of variables in private
	char charcter, specialchar, alphanum;
	char my_charcter[100], encryptstr[100];
//function declaration for decrypt 
	void decrypt(char*, char*);
public:
//defult constructors
	encryptfile();
//function dexclaration for encrypt data
	void encryptdata(char*,char*);
//function declaration for passkey
	void passkey(char*, char*);
//destructor
	~encryptfile();
};
