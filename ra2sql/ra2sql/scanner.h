#ifndef R2S_SCANNER_H
#define R2S_SCANNER_H
#include "include/json/json.h"
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cstring>
#include "main.h"

namespace R2S {
	class Scanner
	{
	public:
		Scanner(std::string s) :
			RA{ s } {};
		~Scanner(){}

		FILE *parse();

		void exec_proj_or_sele(Json::Value *, int*);

		void init_map();

		Json::Value generate_child(int*);


	private:
		std::string RA;
		std::vector<std::string> splited_RA;

		/*json class used to write json file*/
		Json::Value root;

		std::unordered_map<std::string, int> R_map;
	};


}

#endif 