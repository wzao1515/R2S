#include "scanner.h"

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

	FILE *Scanner::parse() {
		init_map();

	}
}