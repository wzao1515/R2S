#ifndef R2S_COMMAND_H
#define R2S_COMMAND_H
#include <vector>
#include <iostream>
#include "main.h"

using namespace std;

namespace R2S {
	class Command
	{
	public:

		Command(vector<string>* c) :
			commands{ *c } {};

		virtual ~Command() {}

		bool parse_command();
		
		void run();

	private:
		vector<string> commands;
	protected:
		
		
	};


}

#endif
