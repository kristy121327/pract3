#ifdef _DEBUG﻿
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DBG_NEW new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define newDBG_NEW
#endif


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <clocale>

#include "Data.h"
#include "Owner.h"

using namespace std;

void input(ifstream& ist, vector <Owner>& owners) {
    while (false == ist.eof()) {
        Owner owner;
        ist >> owner;
        owners.push_back(owner);
    }
}

void output(vector <Owner> owners) {
    for (auto const& owner : owners) {
        cout << owner;
    }
}


int main()
{
    setlocale(0, "Rus");
    ifstream ist("in.txt");
    vector <Owner> owners;

    try 
    {
        input(ist, owners);
        output(owners);
    }
    catch (std::runtime_error& err) 
    {
        std::cerr << err.what();
    }

    return 0;
    _CrtDumpMemoryLeaks();
}
