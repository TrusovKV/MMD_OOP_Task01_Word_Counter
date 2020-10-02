// MMD_OOP_Task01_Word_Counter.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <stdlib.h>
#include <crtdbg.h>

#include "Header.h"
#define _CRTDBG_MAP_ALLOC

int main()
{
_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
_CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_FILE );
_CrtSetReportFile( _CRT_WARN, _CRTDBG_FILE_STDOUT );
_CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_FILE );
_CrtSetReportFile( _CRT_ERROR, _CRTDBG_FILE_STDOUT );
_CrtSetReportMode( _CRT_ASSERT, _CRTDBG_MODE_FILE );
_CrtSetReportFile( _CRT_ASSERT, _CRTDBG_FILE_STDOUT );
_CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_DEBUG );

	double Text_size = 0;
	double counter =  0;
	Output_class Out;
	string test_word = "bear";
	double  sizeOftext;
	
	map<string, double > Leter_Stack;
	map<string, double >::iterator LSp;
	vector<string> Input; 
	vector<string>:: iterator p;
	vector<Output_class> Output;
	vector<Output_class>::iterator Outp;

	
	cout << "Hello world" << endl;
	Input_class input;
	int i = 0;
	while(input.getEof()!=true)
	{
		cout << "Ineration#" << i << endl;
	Input = input.readFilePart();
	Text_size += input.getSize();
	Leter_Stack = input.putInMap();
	i++;
	}
				for (LSp=Leter_Stack.begin();LSp!=Leter_Stack.end();LSp++)
				{
					Out.set_word(LSp->first);
					Out.set_freq(LSp->second);
					Out.set_freqProc(Text_size);
					Output.push_back(Out);
				}

			cout << "Started sorting"<<endl;
			sort(Output.begin(),Output.end(),sort_function); // sortig
			cout << "Sorting done"<<endl<<endl;

			cout << "Started writing to file"<<endl;			
			
			file_writer(Output.begin(),Output.end());
			cout << "Writing to file done"<<endl;
	/*Input = file_reader(Input);

			cout <<"Started map generation"<<endl;
			for(p = Input.begin() ; p < Input.end()-1; p++) // vector insertion into map
				{
					Leter_Stack.insert(make_pair(test_word,counter)); // Important!!
					test_word = *p;
					Leter_Stack[test_word]++;
				}
			cout << "Map generation done"<<endl<<endl;
			//кладём слова в аутпут
			sizeOftext = Input.size(); // Чтоб по 100...000 раз не вызывать метод size()

			for (LSp=Leter_Stack.begin();LSp!=Leter_Stack.end();LSp++)
				{
					Out.set_word(LSp->first);
					Out.set_freq(LSp->second);
					Out.set_freqProc(sizeOftext);
					Output.push_back(Out);
				}

			cout << "Started sorting"<<endl;
			sort(Output.begin(),Output.end(),sort_function); // sortig
			cout << "Sorting done"<<endl<<endl;
		
			cout << "Started writing to file"<<endl;			
			file_writer(Output.begin(),Output.end());
			cout << "Writing to file done"<<endl;*/
	
	/*	for(int i = 0; i< Text_size; i++)
	{
		cout<<Input.at(i)<<endl;	
	}
	for(LSp=Leter_Stack.begin();LSp!=Leter_Stack.end();LSp++)
	{
		cout<<LSp->first<<" "<<LSp->second<<endl;	
	}*/
	cout << "Started memory leak search"<<endl;	
	cout<<_CrtDumpMemoryLeaks()<<endl;
	return 0;
}

