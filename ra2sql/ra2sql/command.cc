#include "command.h"

namespace R2S {

	bool Command::parse_command()
	{
		if (commands.size() == 1)
			return true;
		if (commands.size() == 2) {
			if (commands[0][0] != '-')
				return false;
			if (commands[0][1] != 'f')
				return false;
			return true;
		}
		return false;
	}

	string Command::read_file(string dir)
	{
		string ra = "";
		char temp[256];

		ifstream in(dir);
		if (in.is_open()) {
			while (!in.eof()) {
				in.getline(temp, 100);
				ra += temp;
			}
		}
		else {
			print_usage(stderr);
			exit(1);
		}
		return ra;
	}

	void Command::run() 
	{
		/*judge if the arguments are right*/
		if (parse_command() == false) {
			print_usage(stderr);
			return;
		}

		/*read file and get the string*/
		RA = read_file(commands[1]);
		//cout << RA << endl;


	}
}