#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <regex>

using namespace std;
// Forms an output 
class Output_class
{
private:
	string word;
	double freq;
	double freqProc;
	string Path;
public:
	Output_class()
	{
	word = "";
	freq = 0;
	freqProc = 0.0;
	};

	~Output_class()
	{
	};

	void set_word (string w)
	{
		word = w;
	};
	void set_freq (double f)
	{
		freq = f;
	};
	void set_freqProc(double sizeOftext)
	{
		freqProc = freq/sizeOftext;
	};

	string get_word ()
	{
		return word;
	};
	double get_freq ()
	{
		return freq;
	};
	double get_freqProc()
	{
		return freqProc;
	};

};


// Forms an input and reads it from file
class Input_class
{
private:
	string s, testWord;
	bool flag;
	double counter;
	string path;
	ifstream Input_file;

	vector <string> output;
	vector<string>:: iterator p;

	map<string, double > Leter_Stack;
	map<string, double >::iterator LSp;	
public:
	Input_class()
	{
	counter = 0;
	string s = "";// getString
	string test_word = "";
	string path = "d:\\GitHub\\MMDep_OOP_Autumn_2020\\MMD_OOP_Task01_Word_Counter\\MMD_OOP_Task01_Word_Counter\\The-Hobbit.txt";// filePath The-Hobbit
	Input_file.open(path);
	bool flag = Input_file.is_open(); // is file open
	};

	Input_class(string path)
	{
	counter = 0;
	string s = "";
	string test_word = "";// getString
	Input_file.open(path);
	bool flag = Input_file.is_open(); // is file open
	};

	~Input_class()
	{
		output.clear();
		Input_file.close();
	}

	vector <string> readFilePart()
	{	
		regex signs ("[!?/.,'"";:]");
		output.clear();
		while (output.size()<1000)
		{
			Input_file>>s;	
			if (Input_file.eof() == true)
			{break;}
			//cout<<s;
			if(regex_replace(s,signs,"").length()>0)
			{
			output.push_back(regex_replace(s,signs,""));
			//cout<<"  "<<regex_replace(s,signs,"")<<endl;
			}
		}	
		return output;
	};
	
	map<string, double > putInMap()
	{
		for(p = output.begin() ; p < output.end(); p++) // vector insertion into map
		{
			Leter_Stack.insert(make_pair(testWord,counter)); // Important!!
			testWord = *p;
			Leter_Stack[testWord]++;
		}
			return Leter_Stack;
	}

	double getSize()
	{
		return output.size();
	};

	bool getEof()
	{
	return Input_file.eof();
	}

};

// Processes (sort & write) output

vector <string> file_reader(vector <string> output);

bool sort_function(Output_class a,Output_class b);

void file_writer( vector <Output_class>::iterator o, vector <Output_class>::iterator o_end);
