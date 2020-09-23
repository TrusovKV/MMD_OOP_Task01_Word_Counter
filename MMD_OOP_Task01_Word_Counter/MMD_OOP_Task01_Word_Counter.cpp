// MMD_OOP_Task01_Word_Counter.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Header.h"

int main()
{
	int Text_size = 0;
	double counter =  0;
	bool IS_file_OPEN = true;
	Output_class Out;
	string test_word = "bear";
	double  sizeOftext;

	vector<string> Input; 
	vector<string>:: iterator p;
	vector<Output_class> Output;
	vector<Output_class>::iterator Outp;

	map<string, double > Leter_Stack;
	map<string, double >::iterator LSp;	

	Input = file_reader( Input, IS_file_OPEN).v;
	IS_file_OPEN = file_reader( Input, IS_file_OPEN).flag;

		if ( IS_file_OPEN == true)
		{
		cout << "OK =D"<<endl;
			for(p = Input.begin() ; p < Input.end()-1; p++) // vector insertion into map
				{
					Leter_Stack.insert(make_pair(test_word,counter)); // Important!!
					test_word = *p;
					Leter_Stack[test_word]++;
					cout<<test_word<<endl;
				}
			//кладём слова в аутпут
			sizeOftext = Input.size(); // Чтоб по 100...000 раз не вызывать метод size()

			for (LSp=Leter_Stack.begin();LSp!=Leter_Stack.end();LSp++)
				{
					Out.set_word(LSp->first);
					Out.set_freq(LSp->second);
					Out.set_freqProc(sizeOftext);
					Output.push_back(Out);
				}

			sort(Output.begin(),Output.end(),sort_function); // sortig
			// выводим на экран
			/*for(Outp = Output.begin() ; Outp < Output.end()-1; Outp++) 
				{
					cout<<Outp->get_word()<<" "<<Outp->get_freq()<<" "<<Outp->get_freqProc()<<endl;
				}
			*/
			file_writer(Output.begin(),Output.end());

		return 0;
		}

		else
			cout<< "File not oppened" <<endl;


	return 0;
}

