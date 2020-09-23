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



struct Read_from_file
{
	vector <string> v;
	bool flag;
	int Text_size;
};

class Output_class
{
private:
	string word;
	double freq;
	double freqProc;
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



Read_from_file file_reader(vector <string> v, bool flag);

bool sort_function(Output_class a,Output_class b);

void file_writer( vector <Output_class>::iterator o, vector <Output_class>::iterator o_end);
