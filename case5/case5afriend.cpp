/*Name OF PROGRAM:Initialisation of private variable in a class
filename:case5a.cpp
date:10-04-2020
Author:M.Bhavya ratna sri
*/
#include<iostream>
using namespace std;
class Rectangle
{ 
	//declaration int variable
	      int iwidth;
	      int iheight;
public:
		void set_values(int a,int b)
		{
		iwidth=a;
		iheight=b;
		}
		int find()
		{
		return(iwidth *iheight);
		}
		friend Rectangle calculate(Rectangle);

};
Rectangle calculate(Rectangle d)
{
 Rectangle rectres;
  rectres.iwidth=d.iwidth*2;
  rectres.iheight=d.iheight*2;
	return rectres;
} 
int main(int argc ,char **argv)
{
	//declaration of object for rectangle class
        Rectangle rect,rectb;
	if(argc==2)
	{
	cout<<"./program.exe "<<endl;
	cout<<"private access specifiers intialization"<<endl;
	}
	else
	{
	//accessing calculatearea function
	rect.set_values(4,7);
	rectb=calculate(rect);
	cout<<"res:"<<rectb.find();
        return 0;
	}
}
