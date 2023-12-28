#include <iostream>
#include <fstream>
#include "Nedv.h"
#include <cctype> 

using namespace std;

istream& operator >> (istream& ist, Nedv& nedv) {
    
    ist >> nedv.data;
    ist >> nedv.price;

    if (ist.fail()) {
        throw std::runtime_error("Read from stream failed");
    }

    return ist;
}


ostream& operator << (ostream& ost, const Nedv& nedv)
{
    ost << nedv.data << " " << nedv.price << endl;
    return ost;
}

bool Nedv::is_valid() const
{
    return true;
}
