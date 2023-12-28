#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Nedv.h"

struct Owner {
	std::string name;
	std::vector<Nedv> nevds;

	friend std::istream& operator >> (istream& ist, Owner& owner);
	friend std::ostream& operator << (ostream& ost, const Owner& owner);

	bool is_valid();
};

