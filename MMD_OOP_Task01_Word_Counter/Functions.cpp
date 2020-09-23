#include "stdafx.h"
#include "Header.h"

vector <string> file_reader(vector <string> output)
{
		//vector <string> output;
		string s;
		regex signs("[!?/.,]");
		int ii = 0;
		string result;

ifstream Input_file ("d:\\GitHub\\MMDep_OOP_Autumn_2020\\MMD_OOP_Task01_Word_Counter\\MMD_OOP_Task01_Word_Counter\\The-Hobbit.txt");
	if (Input_file.is_open())
	{
		cout<<"File oppened succesfully"<<endl<<"File reading started"<<endl;
		while (Input_file.eof()!=true)
		{

			Input_file>>s;	
			if(regex_replace(s,signs,"").length()>0)
			{
			output.push_back(regex_replace(s,signs,""));
			//ii++;
			//cout<<ii<<endl;
			}

		}
		cout<<"File reading done"<<endl
	}
	else
	{
	cout<<"File not oppened"<<endl;
	}	
	Input_file.close();
	return output;
}

bool sort_function(Output_class a,Output_class b)
{
	return a.get_freq()>b.get_freq();
}

void file_writer( vector <Output_class>::iterator o, vector <Output_class>::iterator o_end)
{
	ofstream Output_file("d:\\GitHub\\MMDep_OOP_Autumn_2020\\MMD_OOP_Task01_Word_Counter\\MMD_OOP_Task01_Word_Counter\\Output.txt");
	if (Output_file.is_open())
	{
		while (o!=o_end)
		{
			Output_file<<o->get_word()<<","<<o->get_freq()<<","<<o->get_freqProc()<<endl;
			o++;
		}
	}
	else
	{
		cout<< "File not oppened" <<endl;
	}
	
	Output_file.close();

}