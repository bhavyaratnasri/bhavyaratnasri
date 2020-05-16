#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
//class name phoneno contains datamembers,member variables
class phoneno
{
    //declaration variables
    int value;
    int value1;
    bool execute;
    //arrstr of string type
    string arrstr[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs","tuv", "wxyz" };
    vector<string> answer;
    //combination function declaration
    bool combination(string, string);
public:
    //constructor
    phoneno();
    //declartion of letter function
    vector<string> letters(string digits);
    //destructors
    ~phoneno();
};