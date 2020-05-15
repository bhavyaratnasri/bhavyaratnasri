#include "phone.h"
int main(int argc, char** argv)
{
    //declaring object for phone classs
    phoneno phoneobj;
    //declaration of bool value
    bool value;
    if (argc == 2 && (strcmp(argv[1], "-k") == 0))
    {
        cout << "arg1" << endl;
    }
    else
    {
        //string variable declaration
        string stringvalue;
        cout << "INPUT:";
        cin >> stringvalue;
        cout << endl;
        //calling lettercombination function
        phoneobj.letters(stringvalue);
    }
}