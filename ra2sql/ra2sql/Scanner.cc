#include "scanner.h"
#include <fstream>
#include <sstream>
#pragma warning(1:4996)
using namespace std;

namespace R2S {


	/*
	 * This map contains all the "keywords" in relational
	 * algebra. If its value is 1, we have realized it.
	 * If is 0, we have not already realized it yet.
	 */
	void Scanner::init_map() {
		R_map["project"] = 1;
		R_map["select"] = 1;
		R_map["natural join"] = 0;
		R_map["join"] = 0;
		R_map["rename"] = 1;
		R_map["-"] = 1;
	}

	/*
	 * Split function is a helper function in
	 * spliting strings
	 */
	std::vector<string> &split(const string &str, char delim, vector<string> &elems) {
		std::istringstream iss(str);

		while (iss.good())
		{
			string substr;
			getline(iss, substr, delim);
			elems.push_back(substr);
		}
		return elems;
	}

	void Scanner::exec_proj_or_sele(Json::Value *node, int *i) {
		(*i)++;
		/*get condition*/
		vector<std::string> conditions;
		split(splited_RA[*i], ',', conditions);
		for (int j = 0; j < conditions.size(); j++) {
			(*node)["condition"].append(conditions[j]);
		}
		(*i)++;
		/*get table*/
		(*node)["table"] = splited_RA[*i];
	}

	Json::Value Scanner::generate_child(int* index) {
		unordered_map<std::string, int>::iterator it;

		it = R_map.find(splited_RA[*index]);
		if (it == R_map.end()||(*it).second==0) {
			print_usage(stderr);
			exit(1);
		}
		Json::Value *node=new Json::Value;
		std::string comm = (*it).first;
		cout << comm << endl;

		(*node)["inst"] = comm;

		if (comm == "project" || comm == "select") {
			exec_proj_or_sele(node, index);
		}
		return *node;
	}

	FILE *Scanner::parse() {
		init_map();
		root["RA_unit"] = "RA";
		auto *current = &root;
		

		split(RA, ' ', splited_RA);
		for (auto i = 0; i < splited_RA.size(); i++) {
			auto node = generate_child(&i);
			(*current)["child"].append(node);
		}
		ofstream os;
		Json::StyledWriter sw;

		os.open("test.json");
		os << sw.write(root);
		os.close();
		return stderr;
	}
}