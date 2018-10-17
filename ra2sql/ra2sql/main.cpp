#include "main.h"
#include "util.h"
#include "command.h"
#include <stdlib.h>
#include <iostream>

namespace R2S {
	/*show version and quit*/
	static bool show_version = false;
	
	void print_version(FILE *out)
	{
		fprintf(out, "R2S version %s\n", "0.1");
	}

	void print_usage(FILE *out)
	{
		print_version(out);
		fputs("Global options:\n" 
			"	-f, file" 
			"	file ", out);
	}

	static void init_random()
	{
		int key;
		good_random(&key, sizeof(key));
		srand(key);
	}

}

using namespace R2S;

int main(int argc, char *argv[])
{
	init_random();

	std::vector <std::string> args;

	for (int i = 1; i < argc; i++)
		args.push_back(argv[i]);

	if (args.size() == 0) {
		print_usage(stderr);
		return 1;
	}
		
	Command com(&args);
	com.run();
	system("pause");
	return 0;
}