#include "Owner.h"
#include <sstream>


istream& operator >> (istream& ist, Owner& owner) {
    string line;
    owner.name.clear();
    owner.nevds.clear();
    ist >> line;
    for (auto const& symb : line) {
        if (isalpha(symb)) {
            owner.name.push_back(symb);
        }
    }
    string line1, line2;
    std::stringstream nedv_line;
    ist >> line1;
    while (line1.find(']') > line1.size()) {
        ist >> line2;
        nedv_line << line1 << ' ' << line2;
        if (ist.fail()) {
            throw std::runtime_error("Read from stream failed");
        }
        Nedv nedv;
        nedv_line >> nedv;
        owner.nevds.push_back(nedv);
        ist >> line1;
        nedv_line.clear();
    }
    owner.is_valid();
    return ist;
}


ostream& operator << (ostream& ost, const Owner& owner)
{
    for (auto const& nedv : owner.nevds) {
        ost << owner.name << ' ' << nedv;
    }
    return ost;
}


bool Owner::is_valid()
{
    if (!isupper(name[0])) 
    {
        throw std::runtime_error("The name does not start with a capital letter");
    }
    
    for (size_t i = 1; i < name.length(); ++i) {
        if (!islower(name[i])) 
        {
            throw std::runtime_error("The name does not continue from lowercase letters");
        }
    }
}