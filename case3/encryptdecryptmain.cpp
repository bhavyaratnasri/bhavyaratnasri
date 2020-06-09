/*name of program:To display output file from the given input file
filename:case8.cpp
author:M.bhavya ratna sri
date:21-4-2020
*/

#include <iostream>
#include<string>
#include <fstream>
#include <regex>
using namespace std;
class parser
{
    int pos,pos1,pos2;
    string path;
    int found;
    public:
/*function name:Filename
Input paramerters:conststring &str
return type:string*/

string FileName(const string& str)
{
	 found = str.find_last_of("/\\");
	  path = str.substr(found + 1); // check that is OK
	return path;
}
/*function name:dirnameof
Input paramerters:const string &fname
return type:string*/



string dirnameOf(const string& fname)
{
	pos = fname.find_last_of("\\/");
	return (string::npos == pos)
		? ""
		: fname.substr(0, pos);
}

/*function name:HasIBM
Input paramerters:string str,string serch string
return type:bool*/


bool HasIBM(string str, string searchString)
{
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	transform(searchString.begin(), searchString.end(), searchString.begin(), ::toupper);
	if (str.find(searchString) != string::npos)
	{
		return true;
	}
	return false;
}
/*function name:copyright
Input paramerters:string str
return type:string*/



string Copyright(string str)
{
	if (HasIBM(str, "Confidential"))
	{
		return "Copyright";
	}
	else if (HasIBM(str, "Copyright") && HasIBM(str, "Corp"))
	{
		return "Copyright";
	}
	return "";
}
/*function name:isMacro
Input paramerters:string str
return type:string*/


string isMacro(string str)
{
	if (HasIBM(str, "#define"))
	{
		if (HasIBM(str, ".ibm.")) return "MacroWith.com";
		else if(HasIBM(str, "KEY")) return "MacroWithRegistry";
		else 
		return "Macro";
	}
	return "";
}

string url(string str)
{
	if (HasIBM(str, "http:") || HasIBM(str, "https:"))
	{		
		return "URL";
	}
	return "";
}
/*function name:ServerName
Input paramerters:string str
return type:string*/


string ServerName(string str)
{
	if (HasIBM(str, "O=IBM") && HasIBM(str, "CN=") )
	{
		return "ServerName";
	}
	return "";
}
/*function name:registry
Input paramerters:string str
return type:string*/


string registry(string str)
{
	if (HasIBM(str, "HKLM"))
	{
		return "Registry";
	}
	return "";
}
/*function name:os
Input paramerters:string str
return type:string*/


string os(string str)
{
	if (HasIBM(str, "IBMRT") || HasIBM(str, "IBMPC") ||
		HasIBM(str, "ibmOS390") || HasIBM(str, "IBMCP") || HasIBM(str, "ibmAS400")
		|| HasIBM(str, "OS2") || HasIBM(str, "IBMC") || HasIBM(str, "IBMRT"))
	{
		return "OS Specific";
	}
	return "";
}
/*function name:comment
Input paramerters:string str
return type:string*/


string comment(string str)
{
	string pattern("(/\\*([^*]|[\r\n]|(\\*+([^*/]|[\r\n])))*\\*+/)|(//.*)");
	regex r(pattern, regex_constants::egrep);
	string s1("//");
	string s2("/*");
	string s3(" * ");
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	for (sregex_iterator it(str.begin(), str.end(), r), end;
		it != end;
		++it)
	{		
		pos = str.find(s1);
		pos1 = str.find("IBM");
		pos2 = str.find(s2);
		if (pos == 0 || (pos > 0 && pos1 > pos))
		{
			return "CommentedLine";
		}
		else if( pos2 >= 0)
		{
			return "CommentedLine";
		}		
	} 
	 pos = str.find(s2);
	 pos1 = str.find("IBM");
	if (pos == 0 || (pos > 0 && pos1 > pos))
	{
		return "CommentedLine";
	}
	pos = str.find(s3);
	if (pos == 0)
	{
		return "CommentedLine";
	}
	return "";
}
/*function name:debug
Input paramerters:string str
return type:string*/



string debug(string str)
{
	string str1("xprintf");
	 pos = str.find(str1);
	if (pos >= 0)
	{
		return "Debug";
	}
	return "";
}
/*function name:washtype
Input paramerters:string str
return type:string*/


string washType(string str)
{
	string type;
	type.append(Copyright(str));
	type.append(isMacro(str));
	type.append(os(str));
	type.append(registry(str));
	type.append(ServerName(str));
	type.append(url(str));	
	type.append(comment(str));
	type.append(debug(str));
	return type;
}
/*function name:fileType
Input paramerters:string fileName,string filepath
return type:string*/


string fileType(string filename, string filepath)
{
	string filetype;
	if (HasIBM(filename, "IBM"))
	{
		filetype = "FileNameHasIBM";
	}
	if (HasIBM(filepath, "IBM"))
	{
		filetype = "PathNameHasIBM";
	}
	if (HasIBM(filename, "IBM") && HasIBM(filepath, "IBM"))
	{
		filetype = "File&PathNameHasIBM";
	}
	if (filename.substr(filename.length() - 3) == ".rc" || filename.substr(filename.length() - 4) == ".dlg")
	{
		filetype = "UI";
	}
	if (filename.substr(filename.length() - 4) == ".def")
	{
		filetype = "External API";
	}
	if (filename.substr(filename.length() - 3) == ".sh")
	{
		filetype = "Script";
	}
	return filetype;
}
/*function name:getIBM
Input paramerters:string fileName
return type:bool*/
bool getIBM(string fileName)
{
	ifstream file(fileName);
	ofstream myfile;
	string newFile = fileName.c_str();
	string toReplace(".txt");
	int pos = newFile.find(toReplace);
	newFile.replace(pos, toReplace.length(), "_updated.txt");
	myfile.open(newFile);
	if (file.is_open()) {
		string line;
		string filename;
		string LineNumber;
		string filepath;
		string existingFormat;
		string filetype;
		string type;
		regex r("[0-9]: +");
		printf("\nFileName File Path LineNumber Existing Format\n");
		while (getline(file, line))
		{	
			cmatch results;
			if (regex_search(line.c_str(), results, r))
			{
				string delimiter = ":";
				size_t pos = 0;
				
				pos = line.find(delimiter);
				LineNumber = line.substr(0, pos);
				line.erase(0, pos + delimiter.length());
				existingFormat = line;
				type = washType(line);
	cout<< filetype.c_str()<<filename.c_str()<< filepath.c_str()<<LineNumber.c_str()<<existingFormat.c_str()<< type.c_str();
				myfile << filetype.c_str() << "^" << filename.c_str() 
					   << "^" << filepath.c_str() << "^" << LineNumber.c_str() << "^" 
					   << existingFormat.c_str() << "^" << type.c_str() << endl;
			}
			else
			{
				 filetype = "---";
				 filename = FileName(line.c_str());
				 filepath = dirnameOf(line.c_str());
				 if (filepath.empty())
				 {
					 filepath = "*****";
				 }
				 else
				 {
					 filetype = fileType(filename, filepath);
				 }
			}
			
		}
		myfile.close();
		file.close();
	}
	return false;
}

};


int main(int argc, char *argv[])
{
	if (argc ==2&&strcmp(argv[1],"-h")==0)
	{
		cout<<"Usage PerselIBMString:parserstring.exe  <<inputFileName>>.txt"<<endl;
		return -1;
	}
	else if(argc==1)
	{
	    cout<<"use"<<argv[0]<<" -h command";
	}   
	else
	{
	parser k;
	k.getIBM(argv[1]);
	}
	return 0;
}

