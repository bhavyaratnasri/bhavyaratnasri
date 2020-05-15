#include"phone.h"
//constructor
phoneno::phoneno()
{
    cout << "default constructor" << endl;
    value1 = 0;
    value = 0;
    execute = 0;
}
/*functionname:combination
input parameter:string,string
return type:bool
*/
bool phoneno::combination(string strings, string digits)
{
    if (digits.empty())
    {
        cout << strings << " ";
    }
    else
    {
        for (int value1 = 0; value1 < arrstr[digits[0] - '0'].size(); ++value1)
        {
            //calling of combination function recursively
            combination(strings + arrstr[digits[0] - '0'][value1], digits.substr(1, digits.size()));
        }
    }
    return 1;
}
/*functionname:letters
inputpaameters:strings
returntype:vector<string>
*/
vector<string>phoneno::letters(string digits)
{
    if (digits.empty())
        return answer;
    //declaration of string str type
    string str = "";
    for (value = 0; value < arrstr[digits[0] - '0'].size(); ++value)
    {
        //call to combination for each character mapping
        execute = combination(str + arrstr[digits[0] - '0'][value], digits.substr(1, digits.size()));
        if (execute == 1)
            cout << "combination function executed" << endl;
        else
            cout << "combination function not executed" << endl;
    }
    return answer;
}
//destructor
phoneno::~phoneno()
{
    cout << "destructor";
}
