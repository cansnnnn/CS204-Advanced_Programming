//00029126
//Cansin Narsahin

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "cansinnarsahin_Narsahin_Cansin_hw4_DynStackHW4.h"
using namespace std;

bool Symbol(const string & sline, const int & lineNum, DynStack & mystack)
{
	for(int i=0;i<sline.length();i++)
	{
		if(sline.at(i)=='(' || sline.at(i)=='{' || sline.at(i)=='[')
		{
			cout<<"Found the opening symbol "<<sline.at(i)<<" at line "<<lineNum<<endl;
			mystack.push(sline.at(i),lineNum);
		}
		if(sline.at(i)==')' || sline.at(i)=='}' || sline.at(i)==']')
		{
			if(mystack.isEmpty())
			{
				cout<<"ERROR!!! Found the closing symbol "<<sline.at(i)<<" but there are no unclosed opening symbols!"<<endl;
				return false;
			}

			else
			{
				char pre; int preLine;
				mystack.pop(pre,preLine);

				if((sline.at(i)==')' && pre=='(') || (sline.at(i)==']' && pre=='[') || (sline.at(i)=='}' && pre=='{'))
				{
					cout<<"Found the closing symbol "<<sline.at(i)<<" at line "<<lineNum<<
						" which closes the opening symbol "<<pre<<" at line "<<preLine<<endl;
				}

				else
				{
					cout<<"ERROR!!! Found the closing symbol "<<sline.at(i)<<" at line "<<lineNum<<
						" but the last unclosed opening symbol is "<<pre<<" at line "<<preLine<<endl;
					return false;
				}
			}
		}
	}
	return true;
}

void empty(DynStack & mystack)
{
	cout<<"ERROR!!! The following opening symbols were not closed:"<<endl;
	while (!mystack.isEmpty())
	{
		char del; int delLine;
		mystack.pop(del,delLine);
		cout<<"Symbol "<<del<<" at line "<<delLine<<endl;
	}
}


int main()
{
    string fileName;
    ifstream file;
	do
    {
        cout << "Please enter the file name: ";
        cin >> fileName;
        file.open(fileName);
		if(file.fail()) {cout<<"File not found."<<endl;}
    } while (file.fail());

	string s;
	int numLines=0;
	DynStack mystack;
	bool continuee=true;
	while(getline(file,s)&&continuee)
	{
		numLines++;
		istringstream line(s);
		string sline="";
		while ( line >> s) 
		{
			sline=sline+s+" ";
		}
		sline=sline.substr(0,sline.length()-1);
		continuee=Symbol(sline,numLines,mystack);
	}

	if(continuee && mystack.isEmpty())
	{cout<<"File processed successfully. No errors were found."<<endl;}

	if(continuee && !mystack.isEmpty())
	{empty(mystack);}


	return 0;
}