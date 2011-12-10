#ifndef _CAT_H
#define _CAT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Cat
{
    string CurrentLine;
    vector <string> Args;
public:
    Cat (int , char**);

    void print (ostream*);

    string getFile (string);

};

#endif
