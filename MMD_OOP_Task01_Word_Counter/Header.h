#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

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
	int freq;
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
	void set_freq (int f)
	{
		freq = f;
	};
	void set_freqProc(int sizeOftext)
	{
		freqProc = (double)freq/(double)sizeOftext;
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

bool sort_function(double a,double b);