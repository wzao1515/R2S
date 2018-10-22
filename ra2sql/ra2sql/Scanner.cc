#include "scanner.h"
#include <iostream>
#include <fstream>

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

	Json::Value Scanner::generate_child(int* index) {

	}

	/*
	 * Split function is a helper function in
	 * spliting strings
	 */
	vector<string> &split(const string &str, char delim, vector<string> &elems, bool skip_empty = true) {
		istringstream iss(str);
		for (string item; getline(iss, item, delim); )
			if (skip_empty && item.empty()) continue;
			else elems.push_back(item);
		return elems;
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
	}
}