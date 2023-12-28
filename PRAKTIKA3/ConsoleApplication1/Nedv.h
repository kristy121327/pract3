#pragma once
#include <iostream>
#include <fstream>
#include "Price.h"
#include "Data.h"

using namespace std;

struct Nedv
{
    Data data;
    Price price;
    bool is_valid() const;

    friend std::istream& operator >> (istream& ist, Nedv& nedv);
    friend std::ostream& operator << (ostream& ost, const Nedv& nedv);
};

