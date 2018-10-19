#ifndef R2S_COMMAND_H
#define R2S_COMMAND_H
#include <vector>
#include <iostream>
#include <fstream>
#include "main.h"
#include "scanner.h"

using namespace std;

namespace R2S {
	class Command
	{
	public:

		Command(vector<string>* c) :
			commands{ *c } {};

		virtual ~Command() {}

		bool parse_command();

		string read_file(string dir);
		
		void run();

	private:
		vector<string> commands;
		string RA;

	protected:
		
		
	};


}

#endif
