#include "stdafx.h"
#include "Header.h"

Read_from_file file_reader(vector <string> v, bool flag)
{
		Read_from_file output;
		string s;
		regex signs("[!?/.,]");
		int ii = 0;
		string result;

ifstream Input_file ("d:\\GitHub\\MMDep_OOP_Autumn_2020\\MMD_OOP_Task01_Word_Counter\\MMD_OOP_Task01_Word_Counter\\The-Hobbit.txt");
	if (Input_file.is_open())
	{			cout<<"init"<<endl;
		while (Input_file.eof()!=true)
		{

			Input_file>>s;	
			if(regex_replace(s,signs,"").length()>0)
			{
			output.v.push_back(regex_replace(s,signs,""));
			ii++;
			cout<<ii<<endl;
			}

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