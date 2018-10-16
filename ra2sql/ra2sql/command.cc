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

	void Command::run() 
	{
		if (parse_command() == false) {
			print_usage(stderr);
			return;
		}

	}
}