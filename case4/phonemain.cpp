#include "phone.h"
int main(int argc, char** argv)
{
    if  (argc == 2 && (strcmp(argv[1], "-h") == 0))
        cout << "arg1" << endl;
    else
    {
        //declaring object for phone classs
        phoneno phoneobj;
        //string variable declaration
        string number;
        cout << "Input(enter values between 0-9):" << endl;
        cin >> number;
        int result=0;
        
       for(int i=0;i<number.length();i++)
        {
            //checking string contains number or not
            if ((number[i]>=50 && number[i]<=57))
            {
                continue;
            }
            //if string doesnot contains number
            else
            {
                cout<<"string contains special charcter so function failed to excute.\n";
                cout<<"enter number only"<<endl;
                result=1;
                break;
            }
        }
            
             if(result==0)
            {
                cout<<"There is no special character in the string.\n";
                phoneobj.letters(number); 
            }
    }
    return 0;
}
    
                