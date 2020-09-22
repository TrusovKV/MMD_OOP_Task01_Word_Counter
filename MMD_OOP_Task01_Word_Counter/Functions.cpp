#include "stdafx.h"
#include "Header.h"

Read_from_file file_reader(vector <string> v, bool flag)
{
	Read_from_file output;
		string s;
		
ifstream Input_file ("d:\\visual studio 2012\\Projects\\ConsoleApplication1\\ConsoleApplication1\\Input.txt");
	if (Input_file.is_open())
	{
		while (Input_file.eof()!=true)
		{
			Input_file>>s;// regex
			output.v.push_back(s);
			
		}
		output.flag = true;
	}
	else
	{

		output.flag = false;
	}
	
	Input_file.close();
	return output;
}

bool sort_function(double a,double b)
{
	cout<<a<<" "<<b<<endl;
	return a<b;
}