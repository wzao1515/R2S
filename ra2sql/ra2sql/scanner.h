#ifndef R2S_SCANNER_H
#define R2S_SCANNER_H
#include "include/json/json.h"
#include <vector>
#include <unordered_map>

namespace R2S {
	class Scanner
	{
	public:
		Scanner(string s) :
			RA{ s } {};
		~Scanner(){}

		FILE *parse();

		void init_map();


	private:
		string RA;

		/*json class used to write json file*/
		Json::Value root;

		unordered_map<string, int> R_map;
	};


}

#endif 